int pinArray[] = {12, 11, 10, 9, 8, 7, 6, 5};
int aantalLeds = 8;

void setup() {
  for (int count = 0; count < aantalLeds; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  // LED's heen laten lopen
  for (int count = 0; count < aantalLeds; count++) {
    digitalWrite(pinArray[count], HIGH);
    delay(150);
    digitalWrite(pinArray[count], LOW);
  }

  // LED's terug laten lopen
  for (int count = aantalLeds - 2; count > 0; count--) {
    digitalWrite(pinArray[count], HIGH);
    delay(150);
    digitalWrite(pinArray[count], LOW);
  }
}