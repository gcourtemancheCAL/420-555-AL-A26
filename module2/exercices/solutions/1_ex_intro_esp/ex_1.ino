namespace ex_1 {

Pin pinRed = Pin::D1,
    pinYellow = Pin::D6,
    pinGreen = Pin::D5;

void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinYellow, OUTPUT);
}

void loop() {
  // État 1: feu rouge
  digitalWrite(pinYellow, LOW);
  digitalWrite(pinRed, HIGH);
  delay(10000);

  // État 2: feu rouge + jaune
  digitalWrite(pinYellow, HIGH);
  delay(2000);

  // État 3: feu vert
  digitalWrite(pinRed, LOW);
  digitalWrite(pinYellow, LOW);
  digitalWrite(pinGreen, HIGH);
  delay(14000);

  // État 4: feu vert clignotant
  for (int i = 0; i < 10; i++) {
    digitalWrite(pinGreen, LOW);
    delay(500);
    digitalWrite(pinGreen, HIGH);
    delay(500);
  }

  // État 5: feu jaune
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinYellow, HIGH);
  delay(3000);
}

}