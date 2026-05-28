#include <Servo.h>

Servo mijnServo;

const int servoPin = 9;
const int xPin = A0;      // VRx van joystick
const int knopPin = 2;    // SW van joystick

int joystickWaarde = 0;
int servoHoek = 0;
int knopStatus = HIGH;

void setup() {
  mijnServo.attach(servoPin);

  // Joystick-knop gebruikt meestal interne pull-up
  pinMode(knopPin, INPUT_PULLUP);

  mijnServo.write(0);
}

void loop() {
  knopStatus = digitalRead(knopPin);

  // Als joystick wordt ingedrukt
  if (knopStatus == LOW) {
    beweegServo(0, 120, 1000);
    beweegServo(120, 0, 1000);
  } 
  else {
    // Links/rechts beweging van joystick uitlezen
    joystickWaarde = analogRead(xPin);

    // Waarde 0-1023 omzetten naar 0-180 graden
    servoHoek = map(joystickWaarde, 0, 1023, 0, 180);

    mijnServo.write(servoHoek);

    delay(15);
  }
}

void beweegServo(int startHoek, int eindHoek, int totaleTijd) {
  int stappen = abs(eindHoek - startHoek);
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