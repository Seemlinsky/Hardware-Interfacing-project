const int ledPin = 11;
const int buttonPin = 2;

int teller = 0;
int vorigeKnopStatus = LOW;

void setup() {
  // LED instellen als output
  pinMode(ledPin, OUTPUT);

  // Drukknop instellen als input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Knop uitlezen
  int knopStatus = digitalRead(buttonPin);

  // Alleen tellen als de knop net is ingedrukt
  if (knopStatus == HIGH && vorigeKnopStatus == LOW) {
    teller++;
    delay(50); // kleine pauze tegen contactdender
  }

  // Bij een even teller staat de LED uit
  if (teller % 2 == 0) {
    digitalWrite(ledPin, LOW);
  }

  // Bij een oneven teller staat de LED aan
  else {
    digitalWrite(ledPin, HIGH);
  }

  // De huidige knopstatus onthouden voor de volgende ronde
  vorigeKnopStatus = knopStatus;
}