/*
* Author: Stan Fortoński
* Year: 2019
* 
* Arduino: Ode to Joy
* Attach sound output to 8 pin in your arduino to hear melody.
*/

#include "pitches.h"

const int SOUND_OUTPUT_PIN = 8;

int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5,
  NOTE_C4, NOTE_G4, NOTE_C4, NOTE_G4,
  
  NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_C4, NOTE_G4, NOTE_C4, NOTE_G4, NOTE_C4,

  NOTE_D5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5,

  NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_C4, NOTE_G4, NOTE_C4, NOTE_G4, NOTE_C4
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 8, 2,
  1, 1, 1, 1,

  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 8, 2,
  1, 1, 1, 2, 2,

  4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 4,
  1, 1, 1, 1, 2,

  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 8, 2,
  1, 1, 1, 2, 2
};


void setup(){
  pinMode(SOUND_OUTPUT_PIN, OUTPUT);
}

void loop(){
  for (int thisNote = 0; thisNote < 80; thisNote++){
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(SOUND_OUTPUT_PIN, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    noTone(SOUND_OUTPUT_PIN);
  }
}
