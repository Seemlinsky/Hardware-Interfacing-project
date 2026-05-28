void setup() {
  // LED 1 zit op pin 12
  pinMode(12, OUTPUT);

  // LED 2 zit op pin 11
  pinMode(11, OUTPUT);
}

void loop() {
  // Eerst zet ik LED 1 aan en LED 2 uit
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);

  // 1 seconde wachten
  delay(1000);

  // Daarna zet ik LED 1 uit en LED 2 aan
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);

  // Weer 1 seconde wachten
  delay(1000);
}