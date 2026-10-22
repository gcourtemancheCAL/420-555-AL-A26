# GPIOZero

La librairie GPIOZero fournit une quantité de classe facilitant l'utilisation des GPIO du Pi selon ce que vous voulez faire.

**Documentation :** 
- [Classes d'Input](https://gpiozero.readthedocs.io/en/stable/api_input.html)
- [Classes d'output](https://gpiozero.readthedocs.io/en/stable/api_output.html)
- [Identification des broches](https://gpiozero.readthedocs.io/en/stable/recipes.html#pin-numbering)

## Note important :

Avant  d'utiliser une classe, lisez sa documentation. Le Pi et la librairie GPIOZero vont gérer beaucoup de choses pour vous. Il est important de savoir quels éléments y sont gérés afin de bien concevoir votre circuit. 

Par exemple, la classe Button va : 
- Activer une résistance Pull up ou pull down automatiquement selon les paramètres que vous lui passé
- Un paramètre au constructeur détermine le délai de debouncing

## Exemples : 

### Exemple 1 : Un bouton alterne l'état d'une DEL

```python
from gpiozero import Button
from gpiozero import LED

button = Button(4, True, False, 0.02)
led = LED(17)

while True:
	button.wait_for_press()
	led.toggle()
	
```


### Exemple 2 : Un bouton qui permet de déterminer si des lumières clignotent ou pas

```python
from gpiozero import Button
from gpiozero import LED
from time import sleep
from threading import Thread

running = False
thread = None

button = Button(4, True, False, 0.02)

led = LED(17)
led.off()

def clignote_task():
	while running:
		led.toggle()
		time.sleep(1)
		
	led.off()

def start_thread():
	global thread
	global running
	
	running = True
	thread = Thread(target=clignote_task)
	
def stop_thread():
	global thread
	global running
	
	running = False
	thread.join()
	thread = None

while True:
	button.wait_for_press()
	start_thread()
	button.wait_for_press()
	stop_thread()
	
```

### Exemple 3 : Un compteur binaire à 3 bits

```python
from gpiozero import Button
from gpiozero import LED

val = 0
bits = [LED(17), LED(18), LED(19)]
button_plus = Button(4, True, False, 0.02)
button_minus = Button(5, True, False, 0.02)

def on_plus():
	global val

	val = (val + 1) % 8
	update_bits(val)
	
def on_minus():
	global val

	if val == 0:
		val = 8
	val--
	update_bits(val)
	
def update_bits(val):
	for i in range(len(bits)):
		bits[i].value = ( (val >> i) & 0x01)

update_bits(val)
button_plus.when_pressed = on_plus
button_minus.when_pressed = on_minus

# Bloque l'exécution du script empêchant ainsi le programme de se terminer.
# L'action dans notre script se produit via callbacks(when_pressed)	
pause()
```
