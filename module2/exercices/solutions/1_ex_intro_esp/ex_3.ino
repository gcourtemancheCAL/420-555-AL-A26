namespace ex_3 {

const Pin pinBuzzer = Pin::D1;

void setup() {
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  tone(pinBuzzer, 2000, 500); // Fréquence de 2kHz pendant 0.5s
	delay(500 + 1000); // 0.5s de son (ci-dessus) + 1s de silence
}

}