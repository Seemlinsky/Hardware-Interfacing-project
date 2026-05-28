const int ledPin = 11;
const int buttonPin = 2;

int teller = 0;
int vorigeKnopStatus = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int knopStatus = digitalRead(buttonPin);

  // Dit gebeurt alleen op het moment dat de knop net wordt ingedrukt
  if (knopStatus == HIGH && vorigeKnopStatus == LOW) {
    teller++;
    delay(50); // tegen contactdender
  }

  // Als teller even is, LED uit
  if (teller % 2 == 0) {
    digitalWrite(ledPin, LOW);
  } 
  // Als teller oneven is, LED aan
  else {
    digitalWrite(ledPin, HIGH);
  }

  // onthoud de knopstatus voor de volgende loop
  vorigeKnopStatus = knopStatus;
}