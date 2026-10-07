namespace ex_1 {

const Pin
  pinRed = Pin::D5,
  pinButton = Pin::D1;

void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinButton, INPUT);
}

void loop() {
  int state = digitalRead(pinButton);
  digitalWrite(pinRed, state);
}

}