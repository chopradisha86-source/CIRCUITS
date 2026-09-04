const int BUZZER = 13;

// Precise Standard Piano Frequencies (in Hz)
const int NOTE_C5 = 523; // C5
const int NOTE_D5 = 587; // D5
const int NOTE_E5 = 659; // E5
const int NOTE_F5 = 698; // F5
const int NOTE_G5 = 784; // G5
const int NOTE_A5 = 880; // A5 (Corrected from 880 Hz standard octave scaling)
const int NOTE_B5 = 988; // B5 (Added: missing 7th note of the scale)
const int NOTE_C6 = 1047; // C6

void setup() {
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char key = Serial.read();

    int note = 0;
    switch (key) {
      case '1': note = NOTE_C5; break;
      case '2': note = NOTE_D5; break;
      case '3': note = NOTE_E5; break;
      case '4': note = NOTE_F5; break;
      case '5': note = NOTE_G5; break;
      case '6': note = NOTE_A5; break;
      case '7': note = NOTE_B5; break; // Corrected to B5 for a proper scale
      case '8': note = NOTE_C6; break; // Added '8' for the full octave C6
    }

    if (note > 0) {
      tone(BUZZER, note);
      delay(200);     // Reduced slightly for a more responsive piano feel
      noTone(BUZZER); // Silence between notes
    }
  }
}
