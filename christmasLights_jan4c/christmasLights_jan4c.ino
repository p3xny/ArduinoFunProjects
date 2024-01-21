int pot;
int led;
int DELAY_TIME = 500;

void setup() {
pinMode(A0,INPUT);
pinMode(3,OUTPUT);

pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
}

void loop() {
// POTENTIOMETER
pot = analogRead(A0);
led = map(pot, 0, 1023, 0, 255);
analogWrite(3, led);

// RED LIGHT
digitalWrite(12,HIGH);
digitalWrite(13,HIGH);
delay(DELAY_TIME);
digitalWrite(12,LOW);
digitalWrite(13,LOW);

// YELLOW LIGHT
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
delay(DELAY_TIME);
digitalWrite(9,LOW);
digitalWrite(10,LOW);

// GREEN LIGHT
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
delay(DELAY_TIME);
digitalWrite(6,LOW);
digitalWrite(7,LOW);

}
