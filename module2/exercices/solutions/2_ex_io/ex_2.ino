namespace ex_2 {

const Pin
  pinRed1 = Pin::D5,
  pinRed2 = Pin::D6,
  pinRed3 = Pin::D7,
  pinButton = Pin::D1;

int oldState = LOW;
int compteur = 0;

void setup() {
  pinMode(pinRed1, OUTPUT);
  pinMode(pinRed2, OUTPUT);
  pinMode(pinRed3, OUTPUT);
  pinMode(pinButton, INPUT);
}

void loop() {
  int newState = digitalRead(pinButton);
  if (newState != oldState && newState == HIGH) { // On détecte quand l'état change vers "HIGH"
    Serial.print("Compteur = ");
    Serial.println(++compteur, DEC);
  }
  oldState = newState;

  switch (compteur) {
    case 3: digitalWrite(pinRed3, HIGH);
    case 2: digitalWrite(pinRed2, HIGH);
    case 1: digitalWrite(pinRed1, HIGH);
    break;

    default: compteur = 0;
    case 0:
      digitalWrite(pinRed1, LOW);
      digitalWrite(pinRed2, LOW);
      digitalWrite(pinRed3, LOW);
  }
}

}