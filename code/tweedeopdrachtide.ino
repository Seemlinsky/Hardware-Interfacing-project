int pinArray[] = {12, 11, 10, 9, 8, 7, 6, 5};
int aantalLeds = 8;

void setup() {
  // Alle LED pinnen instellen als output
  for (int i = 0; i < aantalLeds; i++) {
    pinMode(pinArray[i], OUTPUT);
  }
}

void loop() {
  // De LED's gaan één voor één naar rechts
  for (int i = 0; i < aantalLeds; i++) {
    digitalWrite(pinArray[i], HIGH);
    delay(150);
    digitalWrite(pinArray[i], LOW);
  }

  // De LED's gaan daarna weer terug naar links
  // Ik begin bij aantalLeds - 2, zodat de laatste LED niet dubbel knippert
  for (int i = aantalLeds - 2; i > 0; i--) {
    digitalWrite(pinArray[i], HIGH);
    delay(150);
    digitalWrite(pinArray[i], LOW);
  }
}