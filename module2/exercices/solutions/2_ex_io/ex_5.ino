namespace ex_5 {

enum Notes {
  E4 = 330,
  G4 = 392,
  A4 = 440
};

const Pin
  pinRed = Pin::D5,
  pinYellow = Pin::D6,
  pinGreen = Pin::D7,
  pinSwitch = Pin::D1, 
  pinBuzzer = Pin::D0; // Branchée en logique inverse

volatile int freq;

void IRAM_ATTR switchHandler(){
	freq = digitalRead(pinSwitch) + 1;
}

void setup() {
  pinMode(pinRed, INPUT_PULLUP);
  pinMode(pinYellow, INPUT_PULLUP);
  pinMode(pinGreen, INPUT_PULLUP);
  pinMode(pinSwitch, INPUT);
  pinMode(pinBuzzer, OUTPUT);

  switchHandler(); // Il faut initialiser freq à son état initial
  attachInterrupt(digitalPinToInterrupt(pinSwitch), switchHandler, CHANGE);
}

void loop() {
  if (!digitalRead(pinRed))
    tone(pinBuzzer, E4 * freq);
  else if (!digitalRead(pinYellow))
    tone(pinBuzzer, G4 * freq);
  else if (!digitalRead(pinGreen))
    tone(pinBuzzer, A4 * freq);
  else
    noTone(pinBuzzer);
}

}