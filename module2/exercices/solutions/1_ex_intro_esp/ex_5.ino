namespace ex_5 {

Pin pinRed = Pin::D1,
    pinGreen = Pin::D5,
    pinBlue = Pin::D6;

void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
}

void loop() {
  // État 0: éteint (en logique inverse)
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinBlue, HIGH);
  delay(1000);

  // État 1: rouge
  digitalWrite(pinBlue, HIGH);
  digitalWrite(pinRed, LOW);
  delay(1000);

  // État 2: vert
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinGreen, LOW);
  delay(1000);

  // État 3: bleu
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinBlue, LOW);
  delay(1000);
}

}