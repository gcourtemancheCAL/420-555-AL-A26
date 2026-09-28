namespace ex_4 {

const Pin pinBuzzer = Pin::D1;

const int sing_along_song[][2] = {
	// format: {fréquence en hz, durée en ms}
	{220, 364},
	{247, 364},
	{262, 364},
	{220, 182},
	{247, 364},
	{262, 364},
	{220, 182},
	{247, 364},
	{262, 364},
	{0, 1000} // pause
};

void setup() {
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    tone(pinBuzzer, sing_along_song[i][0], sing_along_song[i][1]);
    delay(sing_along_song[i][1]);
  }
}

}