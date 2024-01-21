#include <Servo.h>

#define SERVO_PIN 8

Servo servo;
int servoAngle = 90;

const int LRpin = A0;
const int UDpin = A1;
const int joystickSwitch = A2;

int LR_neutral[] = {500, 530};
int UD_neutral[] = {500, 530};
int LR_neutral_min = LR_neutral[0];
int LR_neutral_max = LR_neutral[1];

int LR;
int UD;
int jSwitch;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  // LR_neutral = analogRead(LRpin);
  // UD_neutral = analogRead(UDpin);
}

void loop() {
  LR = analogRead(LRpin);
  UD = analogRead(UDpin);
  jSwitch = analogRead(joystickSwitch);

  Serial.print("LR: ");
  Serial.print(LR);
  Serial.print(" UD: ");
  Serial.println(UD);

  rotateServo();
}

void rotateServo() {
  int angleRange = 180;

  if (LR >= LR_neutral_max) {
    servoAngle = constrain(servoAngle + map(LR, LR_neutral_max, 1023, 0, angleRange), 0, 255);
    delay(5);
  }
  else if (LR <= LR_neutral_min) {
    servoAngle = constrain(servoAngle + map(LR, LR_neutral_min, 0, -angleRange, 0), 0, 255);
    delay(5);
  }

  servo.write(servoAngle);
  delay(5);
}
