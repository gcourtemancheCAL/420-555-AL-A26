// Choix de l'exercice à exécuter ==============================================
#define EXERCICE ex_5

// Code pour satisfaire Arduino ================================================
#define QUOTE(x) #x
#define STR(val) QUOTE(val)

namespace EXERCICE {
  void setup();
  void loop();
}

// Code commun à tous les exercices ============================================
enum Pin : uint8_t {
  D0 = 16, // starts pulled high, no interrupt or pwm
  D1 =  5,
  D2 =  4,
  D3 =  0, // always pulled high, fails to boot if low
  D4 =  2, // always pulled high, fails to boot if low
  D5 = 14,
  D6 = 12,
  D7 = 13,
  D8 = 15, // always pulled low, fails to boot if high
  RX =  3,
  TX =  1
};

unsigned int count = 0;
unsigned long last = 0;

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.print("\n\nExercice: ");
  Serial.println(STR(EXERCICE));
  EXERCICE::setup();
}

void loop() {
  if (millis() - last > 1000) {
    Serial.print("Ping #");
    Serial.println(++count, DEC);
    last = millis();
  }
  EXERCICE::loop();
}
