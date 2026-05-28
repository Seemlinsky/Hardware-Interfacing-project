const int potPin = A0;

int ledPins[] = {12, 11, 10, 9, 8, 7, 6};
int aantalLeds = 7;

int potWaarde = 0;
int aantalAan = 0;

void setup() {
  // Serial Monitor starten om waardes te kunnen controleren
  Serial.begin(9600);

  // Alle LED pinnen instellen als output
  for (int i = 0; i < aantalLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Potmeter uitlezen
  potWaarde = analogRead(potPin);

  // Potmeterwaarde omzetten naar hoeveel LED's aan moeten
  aantalAan = map(potWaarde, 0, 1023, 0, aantalLeds + 1);

  // Voor de zekerheid niet meer dan 7 LED's aanzetten
  if (aantalAan > aantalLeds) {
    aantalAan = aantalLeds;
  }

  // LED's aan of uit zetten op basis van de potmeter
  for (int i = 0; i < aantalLeds; i++) {
    if (i < aantalAan) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  // Waardes tonen in de Serial Monitor
  Serial.print("Potmeter waarde: ");
  Serial.print(potWaarde);
  Serial.print(" | LEDs aan: ");
  Serial.println(aantalAan);

  delay(100);
}