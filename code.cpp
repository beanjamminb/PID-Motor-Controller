//Pins
#define ENCODER_A    18
#define ENCODER_B    19
#define MOTOR_PWMA   25
#define MOTOR_AIN1   26
#define MOTOR_AIN2   27

//PWM
#define PWM_CHANNEL  0
#define PWM_FREQ     20000
#define PWM_RES      8
#define PPR          540

// PID Parameters
float Kp = 1.5;
float Ki = 0.08;
float Kd = 0.05;
float setpoint = 60.0;
float integral  = 0.0;
float prevError = 0.0;

//Encoder
volatile long encoderCount = 0;
long lastCount = 0;

// Timing
unsigned long lastTime = 0;
const int PID_INTERVAL = 20;

//Interrupt
void IRAM_ATTR encoderISR() {
  if (digitalRead(ENCODER_B) == HIGH) {
    encoderCount++;
  } else {
    encoderCount--;
  }
}

//Set motor to either ccw or cw (forwards or backwards)
void setMotor(int speed) {
  if (speed > 0) {
    digitalWrite(MOTOR_AIN1, HIGH);
    digitalWrite(MOTOR_AIN2, LOW);
    ledcWrite(PWM_CHANNEL, speed);
  } 
  else if (speed < 0) {
    digitalWrite(MOTOR_AIN1, LOW);
    digitalWrite(MOTOR_AIN2, HIGH);
    ledcWrite(PWM_CHANNEL, -speed);
  } 
  else {
    digitalWrite(MOTOR_AIN1, HIGH);
    digitalWrite(MOTOR_AIN2, HIGH);
    ledcWrite(PWM_CHANNEL, 0);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), encoderISR, RISING);

  pinMode(MOTOR_AIN1, OUTPUT);
  pinMode(MOTOR_AIN2, OUTPUT);

  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(MOTOR_PWMA, PWM_CHANNEL);

  lastTime = millis();
  Serial.println("Ready");
}

void loop() {
  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;

  if (dt >= (PID_INTERVAL / 1000.0)) {

    long currentCount = encoderCount;
    long deltaCounts  = currentCount - lastCount;
    lastCount         = currentCount;

    float measuredRPM = (deltaCounts / (float)PPR) / (dt / 60.0);

    float error      = setpoint - measuredRPM;
    integral        += error * dt;
    integral         = constrain(integral, -255, 255);
    float derivative = (error - prevError) / dt;

    float output = (Kp * error) + (Ki * integral) + (Kd * derivative);

    //Clamp output
    output       = constrain(output, -255, 255);

    prevError = error;
    lastTime  = now;

    setMotor((int)output);

    Serial.print("Setpoint:"); Serial.print(setpoint);
    Serial.print(" RPM:");     Serial.print(measuredRPM);
    Serial.print(" Error:");   Serial.print(error);
    Serial.print(" Output:");  Serial.println(output);
  }

  if (Serial.available()) {
    float newSetpoint = Serial.parseFloat();
    if (newSetpoint >= 0 && newSetpoint <= 130) {
      setpoint = newSetpoint;
      integral = 0;
      Serial.print("New setpoint: ");
      Serial.println(setpoint);
    }
  }
}
