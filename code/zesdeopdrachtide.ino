#include <Servo.h>

Servo mijnServo;

const int servoPin = 9;
const int xPin = A0;      // VRx van joystick
const int knopPin = 2;    // SW van joystick

int joystickWaarde = 0;
int servoHoek = 0;
int knopStatus = HIGH;

void setup() {
  // Servo koppelen aan pin 9
  mijnServo.attach(servoPin);

  // Ik gebruik de interne pull-up voor de joystickknop
  pinMode(knopPin, INPUT_PULLUP);

  // Servo begint op 0 graden
  mijnServo.write(0);
}

void loop() {
  // Joystickknop uitlezen
  knopStatus = digitalRead(knopPin);

  // Als ik de joystick indruk, doet de servo een vaste beweging
  if (knopStatus == LOW) {
    beweegServo(0, 120, 1000);
    beweegServo(120, 0, 1000);
  }

  else {
    // Links/rechts beweging van de joystick uitlezen
    joystickWaarde = analogRead(xPin);

    // Joystickwaarde omzetten naar een servohoek
    servoHoek = map(joystickWaarde, 0, 1023, 0, 180);

    // Servo naar de berekende hoek sturen
    mijnServo.write(servoHoek);

    delay(15);
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