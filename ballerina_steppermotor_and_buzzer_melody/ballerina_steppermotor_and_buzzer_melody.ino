#include "pitches.h"
#include <Stepper.h>

#define BALLERINA 7

const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 1, 2, 3, 4);

unsigned long currentMillis = 0;

unsigned long spinPreviousMillis = 0;
unsigned long spinPeriod = 2;

unsigned long notePreviousMillis = 0;
unsigned long notePeriod = 0;

int melody[] = {
  NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4,

  NOTE_C5, NOTE_AS4, NOTE_A4,
  NOTE_A4, NOTE_AS4, NOTE_C5,
  NOTE_D5, NOTE_AS4, NOTE_A4, NOTE_G4,

  NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_A4,
  NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_A4,

  NOTE_F4, NOTE_D4, NOTE_E4, NOTE_C4,
  NOTE_A3, NOTE_E4, NOTE_D4, NOTE_D4,
};

int noteDurations[] = {
  4, 8, 4, 8, 4,
  
  16, 16, 4,
  4, 8, 4,
  16, 16, 4, 8,
  
  4, 4, 8, 4, 
  8, 4, 16, 16,

  4, 8, 4, 8,
  4, 8, 4, 4,
};

int currentNote = 0;
int previousNote = currentNote;
int state = 0;

void spinMotor() {
  if (currentMillis - spinPreviousMillis >= spinPeriod) {
    spinPreviousMillis = currentMillis;
    myStepper.step(1);
  }
}

void playMelody() {
  unsigned long noteDuration = 4000 / noteDurations[currentNote];

  if (currentMillis - notePreviousMillis >= noteDuration) {
    notePreviousMillis = currentMillis;
    tone(BALLERINA, melody[currentNote], noteDuration);
    previousNote = currentNote;
    currentNote++;

    if (currentNote >= 21) {
      // Melody is finished
      state = 0;
      noTone(BALLERINA); 
      currentNote=0;
    }

    int notePause = noteDuration * 1.30;
  }
}

void setup() {
  pinMode(BALLERINA, OUTPUT);
  myStepper.setSpeed(60);
}

void loop() {
  currentMillis = millis();
  spinMotor();
  playMelody();
}
