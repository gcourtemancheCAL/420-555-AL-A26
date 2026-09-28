namespace ex_2 {

const Pin pinRed = Pin::D1;

// Fonction auxiliaire pour "clipper" une valeur sur 8 bits (1 byte)
uint8_t clip8(int value) {
  value = max(value, 0);
  value = min(value, 255);
  return value;
}

void setup() {
  pinMode(pinRed, OUTPUT);
  analogWriteRange(255);
}

void loop() {
  int intensity = -50;

  // Intensité croissante
  while (intensity < 300) {
    analogWrite(pinRed, clip8(intensity));
    delay(50);
    intensity += 10;
  }

  // Intensité décroissante
  while (intensity > -50) {
    analogWrite(pinRed, clip8(intensity));
    delay(50);
    intensity -= 10;
  }
}

}