
### Exercice 1.3

```arduino

#include <array>

// Valeurs choisies a titre representatif seulement
constexpr int LED1 = 1;
constexpr int LED2 = 2;
constexpr int LED3 = 3;

class LedClignote {
private:
	int _pin;
	int _on;
	int _off;
	int _ts {0};

public:
	LedClignote(int pin, int on, int off, int startState = HIGH) 
		: _pin {pin}
		, _on {on}
		, _off {off}
	{
		pinMode(_pin, OUTPUT);
		digitalWrite(_pin, startState);
	}


	void tick(int dt) {
		_ts = (_ts + dt) % (_on + _off);
	
		if( _ts < _on ) digitalWrite(_pin, HIGH);
		else digitalWrite(_pin, LOW);
	}
};
  
std::array<LedClignote, 3> leds = {
	LedClignote{LED1, 500, 500},
	LedClignote{LED2, 300, 850},
	LedClignote{LED3, 700, 1000}
};

void setup() {

}

int dt() {
	static unsigned long lastTick = millis();

	unsigned long now = millis();
	int delta = (int)(now - lastTick);
	lastTick = now;	
	
	return delta
}

void loop() {
	int delta = dt();
	
	for( size_t i = 0; i < leds.size(); i++) {
		leds[i].tick(delta);
	}
	
	delay(50);
}

```

### Exercice 1.4

```arduino

#include <array>

// Valeurs choisies a titre representatif seulement
constexpr int LED1 = 1;
constexpr int LED2 = 2;
constexpr int LED3 = 3;

struct LedClignote {
private:
	int _pin;
	int _on;
	int _off;
	const char* _name;
	

	LedClignote(int pin, int on, int off, const char* name) 
		: _pin {pin}
		, _on {on}
		, _off {off}
		, _name {name}
	{
		pinMode(_pin, OUTPUT);
	}
};
  
std::array<LedClignote, 3> leds = {
	LedClignote{LED1, 500, 500, "t1"},
	LedClignote{LED2, 300, 850, "t2"},
	LedClignote{LED3, 700, 1000, "t3"}
};

void task_clignote(void* userdata) {
	LedClignote* led = (LedClignote*)userdata;
	
	for(;;) {
		digitalWrite(led->_pin, HIGH);
		delay(led->_on);
		digitalWrite(led->_pin, LOW);
		delay(led->_off);
	}
}

void setup() {
	for( size_t i = 0; i < leds.size(); i++) {
		xTaskCreate( 
			task_clignote,
			leds[i]->_name,
			1024,
			&leds[i],
			tskIDLE_PRIORITY + 1,
			nullptr
		);
	}
}

void loop() {

}

```