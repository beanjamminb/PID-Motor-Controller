#define AIN1  26
#define AIN2  27
#define PWMA  25
#define STBY  14

#define PWM_CHANNEL 0
#define PWM_FREQ    20000   // 20 kHz (quiet, professional)
#define PWM_RES     8       // 8-bit (0–255)

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);

  // Direction
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

  // PWM setup
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWMA, PWM_CHANNEL);

  ledcWrite(PWM_CHANNEL, 128); // ~50% speed
}

void loop() {
  // Forward
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  ledcWrite(PWM_CHANNEL, 150);
  delay(3000);

  // Stop
  ledcWrite(PWM_CHANNEL, 0);
  delay(1000);

  // Reverse
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  ledcWrite(PWM_CHANNEL, 150);
  delay(3000);

  // Stop
  ledcWrite(PWM_CHANNEL, 0);
  delay(2000);

}
