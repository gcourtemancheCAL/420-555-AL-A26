namespace ex_3a { // Version sans interrupts

const Pin
  pinRed = Pin::D5,
  pinYellow = Pin::D6,
  pinGreen = Pin::D7,
  pinBlue = Pin::D0, // Branchée en logique inverse
  pinButton = Pin::D1;

unsigned long await(Pin pin, unsigned long timeout, int state = HIGH) {
  unsigned long start = millis();
  while (millis() - start < timeout) {
    if (digitalRead(pin) == state)
      return millis() - start;
    delay(1); // Pour empêcher le WDT de reset le controlleur après 2s
  }
  return timeout;
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
}

void loop() {
  unsigned long elapsed, duration;

  // État 1: feu rouge
  digitalWrite(pinYellow, LOW);
  digitalWrite(pinRed, HIGH);

  duration = 5000;
  if (digitalRead(pinBlue) == LOW) {
    blink(pinBlue, duration);
    digitalWrite(pinBlue, HIGH);
    elapsed = duration;
  }
  else {
    elapsed = await(pinButton, duration);
  }
  
  elapsed += await(pinButton, duration);
  if (elapsed < 2*duration) {
    digitalWrite(pinBlue, LOW);
    delay(2*duration - elapsed);
  }

  // État 3: feu vert
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  duration = 5000;
  elapsed = await(pinButton, duration);
  if (elapsed < duration) {
    digitalWrite(pinBlue, LOW);
    delay(duration - elapsed);
  }

  // État 5: feu jaune
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinYellow, HIGH);
  duration = 3000;
  elapsed = await(pinButton, duration);
  if (elapsed < duration) {
    digitalWrite(pinBlue, LOW);
    delay(duration - elapsed);
  }
}

}