namespace ex_3b { // Version avec interrupts

const Pin
  pinRed = Pin::D5,
  pinYellow = Pin::D6,
  pinGreen = Pin::D7,
  pinBlue = Pin::D0, // Branchée en logique inverse
  pinButton = Pin::D1;

void IRAM_ATTR buttonHandler(){
	digitalWrite(pinBlue, LOW);
}

void blink(Pin pin, unsigned long duration) {
  while (duration > 0) {
    digitalWrite(pin, !digitalRead(pin));
    delay(min(500ul, duration));
    duration -= min(500ul, duration);
  }
}
                       
void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinButton, INPUT);

  digitalWrite(pinBlue, HIGH); // La lumière est éteinte par défaut (loqique inverse)
  attachInterrupt(digitalPinToInterrupt(pinButton), buttonHandler, RISING);
}

void loop() {
  // État 1: feu rouge
  digitalWrite(pinYellow, LOW);
  digitalWrite(pinRed, HIGH);

  if (digitalRead(pinBlue) == LOW) {
    blink(pinBlue, 5000);
    digitalWrite(pinBlue, HIGH);
    delay(5000);
  }
  else {
    delay(10000);
  }

  // État 3: feu vert
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  delay(5000);

  // État 5: feu jaune
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinYellow, HIGH);
  delay(3000);
}

}