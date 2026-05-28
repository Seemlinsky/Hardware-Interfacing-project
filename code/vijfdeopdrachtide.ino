#include <Servo.h>

Servo mijnServo;

const int servoPin = 9;
const int knop1Pin = 2;
const int knop2Pin = 3;

void setup() {
  // Servo koppelen aan pin 9
  mijnServo.attach(servoPin);

  // Knoppen instellen als input
  pinMode(knop1Pin, INPUT);
  pinMode(knop2Pin, INPUT);

  // Servo begint op 0 graden
  mijnServo.write(0);
}

void loop() {
  // Knoppen uitlezen
  int knop1Status = digitalRead(knop1Pin);
  int knop2Status = digitalRead(knop2Pin);

  // Beide knoppen tegelijk ingedrukt
  if (knop1Status == HIGH && knop2Status == HIGH) {
    beweegServo(0, 120, 1000);
    delay(2000); // even blijven staan
    beweegServo(120, 0, 1000);
  }

  // Alleen knop 1 ingedrukt: langzamer bewegen
  else if (knop1Status == HIGH) {
    beweegServo(0, 120, 1000);
    beweegServo(120, 0, 1000);
  }

  // Alleen knop 2 ingedrukt: sneller bewegen
  else if (knop2Status == HIGH) {
    beweegServo(0, 120, 500);
    beweegServo(120, 0, 500);
  }
}

void beweegServo(int startHoek, int eindHoek, int totaleTijd) {
  int stappen = abs(eindHoek - startHoek);

  // Tijd per stap berekenen, zodat de beweging ongeveer klopt
  int wachttijd = totaleTijd / stappen;

  // Servo beweegt omhoog
  if (startHoek < eindHoek) {
    for (int hoek = startHoek; hoek <= eindHoek; hoek++) {
      mijnServo.write(hoek);
      delay(wachttijd);
    }
  }

  // Servo beweegt terug omlaag
  else {
    for (int hoek = startHoek; hoek >= eindHoek; hoek--) {
      mijnServo.write(hoek);
      delay(wachttijd);
    }
  }
}