#define TRIG 2
#define ECHO 3
#define MACHINE_SWITCH 8

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(MACHINE_SWITCH, OUTPUT);
  Serial.begin(9600);
}

float measurement() {
  unsigned long time;
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  time = pulseIn(ECHO, HIGH);
  return time / 58.00;
}

void loop() {
  float distance = measurement();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  
  if (distance < 8.00) {
    digitalWrite(MACHINE_SWITCH, HIGH);
  } else {
    digitalWrite(MACHINE_SWITCH, LOW);
  }
  delay(300);
}