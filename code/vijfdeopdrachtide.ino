#include <Servo.h>

// Hier maak ik de servo aan
Servo mijnServo;

// Hier zet ik welke pinnen ik gebruik
const int servoPin = 9;
const int knop1Pin = 2;
const int knop2Pin = 3;

void setup() {
  // Servo zit op pin 9
  mijnServo.attach(servoPin);

  // Ik gebruik normale INPUT omdat ik zelf 10k weerstanden gebruik
  pinMode(knop1Pin, INPUT);
  pinMode(knop2Pin, INPUT);

  // Servo begint op 0 graden
  mijnServo.write(0);
  delay(500);
}

void loop() {
  // Bij pull-down weerstand is HIGH = knop ingedrukt
  bool knop1 = digitalRead(knop1Pin) == HIGH;
  bool knop2 = digitalRead(knop2Pin) == HIGH;

  // Als ik een knop indruk, wacht Arduino even
  // Dan kan hij beter zien of ik 1 knop of 2 knoppen indruk
  if (knop1 || knop2) {
    delay(300);

    knop1 = digitalRead(knop1Pin) == HIGH;
    knop2 = digitalRead(knop2Pin) == HIGH;

    // Beide knoppen tegelijk
    if (knop1 && knop2) {
      beweegServo(0, 120, 1000);
      delay(2000);
      beweegServo(120, 0, 1000);
    }

    // Alleen knop 1
    else if (knop1) {
      beweegServo(0, 120, 1000);
      beweegServo(120, 0, 1000);
    }

    // Alleen knop 2
    else if (knop2) {
      beweegServo(0, 120, 500);
      beweegServo(120, 0, 500);
    }

    // Wachten tot ik alle knoppen loslaat
    wachtTotKnoppenLos();

    // Servo blijft op 0 graden
    mijnServo.write(0);
  }
}

// Deze functie laat de servo bewegen
void beweegServo(int startHoek, int eindHoek, int totaleTijd) {
  int stappen = abs(eindHoek - startHoek);

  if (stappen == 0) {
    return;
  }

  int wachttijd = totaleTijd / stappen;

  if (startHoek < eindHoek) {
    for (int hoek = startHoek; hoek <= eindHoek; hoek++) {
      mijnServo.write(hoek);
      delay(wachttijd);
    }
  } else {
    for (int hoek = startHoek; hoek >= eindHoek; hoek--) {
      mijnServo.write(hoek);
      delay(wachttijd);
    }
  }
}

// Wachten tot beide knoppen los zijn
void wachtTotKnoppenLos() {
  while (digitalRead(knop1Pin) == HIGH || digitalRead(knop2Pin) == HIGH) {
    delay(10);
  }
}