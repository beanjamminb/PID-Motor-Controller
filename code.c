#include <Arduino.h>

// Motor pins
const int pwmPin = 25;      // PWM output to motor driver
const int dirPin1 = 26;     // Direction control pin A
const int dirPin2 = 27;     // Direction control pin B

// Encoder pins
const int encoderPinA = 32;
const int encoderPinB = 33;
volatile long encoderCount = 0;

// PWM configuration
const int pwmChannel = 0;
const int pwmFreq = 20000;   
const int pwmResolution = 8; 

// Need to test PID parameters
float Kp = 0;
float Ki = 0;
float Kd = 0;

// PID variables
float integral = 0;
float lastError = 0;

// Target motor speed (counts per second) 
// I put some random value there, will change later
float targetSpeed = 200;

// Timing
unsigned long lastTime = 0;
long lastEncoderCount = 0;


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
