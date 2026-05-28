const int potPin = A0;

int ledPins[] = {12, 11, 10, 9, 8, 7, 6};
int aantalLeds = 7;

int potWaarde = 0;
int aantalAan = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < aantalLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  potWaarde = analogRead(potPin);

  // Zet de potmeterwaarde 0-1023 om naar 0-7 LED's
  aantalAan = map(potWaarde, 0, 1023, 0, aantalLeds + 1);

  if (aantalAan > aantalLeds) {
    aantalAan = aantalLeds;
  }

  for (int i = 0; i < aantalLeds; i++) {
    if (i < aantalAan) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  Serial.print("Potmeter waarde: ");
  Serial.print(potWaarde);
  Serial.print(" | LEDs aan: ");
  Serial.println(aantalAan);

  delay(100);
}