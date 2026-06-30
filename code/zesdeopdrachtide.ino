#include <Servo.h>

Servo mijnServo;

const int servoPin = 9;
const int xPin = A0;      // VRx van joystick
const int knopPin = 2;    // SW van joystick

int servoHoek = 90;
bool knopAlGedaan = false;

void setup() {
  mijnServo.attach(servoPin);

  // Joystickknop met interne pull-up weerstand
  pinMode(knopPin, INPUT_PULLUP);

  // Servo begint in het midden
  mijnServo.write(servoHoek);
  delay(500);
}

void loop() {
  int knopStatus = digitalRead(knopPin);

  // Als joystick wordt ingedrukt: automatische beweging 1 keer uitvoeren
  if (knopStatus == LOW && knopAlGedaan == false) {
    knopAlGedaan = true;

    // Eerst naar 0 graden
    beweegServo(servoHoek, 0, 500);

    // Daarna opdrachtbeweging: 0 naar 120 en terug naar 0
    beweegServo(0, 120, 1000);
    beweegServo(120, 0, 1000);

    servoHoek = 0;
  }

  // Als knop los is, mag de joystick weer normaal sturen
  if (knopStatus == HIGH) {
    knopAlGedaan = false;

    int joystickWaarde = analogRead(xPin);

    // Dode zone zodat de servo niet raar trilt rond het midden
    if (joystickWaarde < 450) {
      servoHoek = 0;
    } 
    else if (joystickWaarde > 570) {
      servoHoek = 180;
    } 
    else {
      servoHoek = 90;
    }

    mijnServo.write(servoHoek);
    delay(30);
  }
}

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
  } 
  else {
    for (int hoek = startHoek; hoek >= eindHoek; hoek--) {
      mijnServo.write(hoek);
      delay(wachttijd);
    }
  }
}