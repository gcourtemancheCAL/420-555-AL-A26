# Bluetooth et BLE

## Introduction rapide à BLE (traduit de [ArduinoBLE](https://docs.arduino.cc/libraries/arduinoble/#BLECharacteristic%20Class))

Bluetooth® 4.0 comprend à la fois le Bluetooth® traditionnel, désormais appelé « Bluetooth® Classic », et le Bluetooth® Low Energy (Bluetooth® à basse consommation). Ce dernier est optimisé pour une faible consommation d’énergie à de faibles débits de données et a été conçu pour fonctionner avec de simples piles boutons au lithium.

Contrairement aux communications Bluetooth® standard, essentiellement basées sur une connexion série asynchrone (UART), un émetteur-récepteur Bluetooth® LE fonctionne comme un babillard communautaire. Les ordinateurs qui s’y connectent sont comme les membres d’une communauté qui consultent le babillard. Chaque émetteur-récepteur joue soit le rôle du babillard, soit celui du lecteur. S’il joue le rôle du babillard — appelé _périphérique_ dans la terminologie Bluetooth® LE —, il publie des données que tous les émetteurs-récepteurs de la communauté peuvent lire. S’il joue le rôle du lecteur — appelé _appareil central_ —, il consulte les babillards (les périphériques) qui contiennent des informations qui l’intéressent. Vous pouvez également considérer les périphériques comme les serveurs d’un échange client-serveur, puisqu’ils contiennent les informations demandées par les lecteurs. De la même façon, les appareils centraux sont les clients du monde Bluetooth® LE, puisqu’ils lisent les informations offertes par les périphériques.

<img src="img/Pasted image 20261022121408.png" width="600" />

Imaginez un périphérique Bluetooth® LE comme un babillard et les appareils centraux comme les personnes qui le consultent. Les appareils centraux consultent les services, récupèrent les données, puis passent à autre chose. Chaque échange est rapide, de l’ordre de quelques millisecondes, ce qui permet à plusieurs appareils centraux de récupérer des données auprès d’un même périphérique.

Les informations présentées par un périphérique sont structurées en **services**, chacun étant subdivisé en **caractéristiques**. Vous pouvez comparer les services aux annonces affichées sur un babillard et les caractéristiques aux différents paragraphes de ces annonces. Si vous êtes un périphérique, vous mettez simplement à jour chaque caractéristique d’un service lorsque cela est nécessaire, sans vous préoccuper de savoir si les appareils centraux la lisent ou non. Si vous êtes un appareil central, vous vous connectez au périphérique, puis vous lisez les caractéristiques qui vous intéressent. Lorsqu’une caractéristique est accessible en lecture et en écriture, le périphérique et l’appareil central peuvent tous deux la modifier.

## Intrégrer BLE dans nos projets

Le ESP32 supporte une stack Bluetooth BLE. Nous allons nous en servir comme _périphérique BLE_. 

Ce périphérique va devoir intéragir avec d'autres appareils : 
- Avec votre cellulaire 
- Avec le pi
- Avec votre laptop

Bien que l'objectif final est d'écrire une application sur votre Pi qui communique en bluetooth, il existe des clients génériques vous permettant de tester pendant le développement via votre celullaire ou bien même votre ordinateur portable.
- J'utilise [GATTBrowser for android](https://www.renesas.com/en/document/apn/gattbrowser-android-smartphone-application-instruction-manual-rev102)
- Ils ont aussi une version Windows (disponible sur Léa)

### Exemple 1

Référence : https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ble.html

```arduino
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

BLECharacteristic *pLedStateChar;
void setup() {
	Serial.begin(19200);
	pinMode(23, OUTPUT);

	// 1. Initialization du module BLE. 
	//     Le nom du device va être "MyESP32" : c'est le nom qu'on va voir
	//     lorsqu'on essaie de s'y connecter.
	BLEDevice::init("MyESP32");
	
	// 2. On crée le serveur BLE.
	//    Le pointeur est local a la fonction. 
	//    Cependant, l'allocation est dynamique donc le serveur va exister
	//    même si on perd le pointeur.
	BLEServer *pServer = BLEDevice::createServer();
	
	// 3. On crée le service.
	//    Un service est un groupe d'attributs pouvant être lus et modifiés.
	//    Certains services prédéfinies existent fournissant un 
	//    contrat commun à différentes classes d'appareils (par exemple : pacemaker).
	//    Ces services connus permettent l'interopérabilité des appareils.
	//    Dans notre cas à nous, nous allons créer des services entièrement custom 
	//    donc nous devons utiliser un UUID nous étant spécifique.
	BLEService *pService = pServer->createService("df0a1236-f7ce-4f49-8ca1-3677b84b58c0");
	
	// 4. Crée la caractéristique.
	//    Une caractéristique c'est l'attribut sur lequel on va travailler : 
	//    on va pouvoir y lire et écrire des valeurs
	//
	//    Ici, on garde le pointeur dans une variable globale. On va ainsi 
	//    pouvoir se référer à la caractéristique plus tard dans notre programme.
	pLedStateChar = pService->createCharacteristic(
		"563a715c-d3c5-4817-9e6d-ee6aec89e222",
		BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
	pLedStateChar->setValue(0);
	
	// 5. Le service est prêt : on le démarre
	pService->start();
	
	// 6. Débute le processus d'advertising : le device va maintenant être visible
	//    par les clients bluetooth.
	BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
	pAdvertising->addServiceUUID("df0a1236-f7ce-4f49-8ca1-3677b84b58c0");
	pAdvertising->setScanResponse(true);
	pAdvertising->start(); // Essential line!
	
	  
	Serial.println("advertising");
}

void loop() {
	if( pLedStateChar->getLength() >= 1 ){
		uint8_t *data = pLedStateChar->getData();
		digitalWrite(23, *data);
	}

	delay(500);
}
```

Je peux maintenant utiliser GATTBrowser pour modifier mon attribut : 

TODO IMAGE

Je pourrais aussi utiliser mon Pi pour m'y connecter et le modifier. 

L'exemple de code suivant utilise la librairie `bleak` pour la connectivitée BLE.

Documentation : https://bleak.readthedocs.io/en/latest/api/index.html

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install bleak
```

Le code : 

```python
import asyncio
import time

from bleak import BleakClient, BleakScanner
from bleak.exc import BleakError

DEVICE_NAME = "MyESP32"
SERVICE_UUID = "df0a1236-f7ce-4f49-8ca1-3677b84b58c0"
LED_UUID = "563a715c-d3c5-4817-9e6d-ee6aec89e222"

# Bleak utilise des appels asynchrone. La chaine d'appel doit donc 
# etre async.
async def main():
    print(f"Scanning for {DEVICE_NAME}...")

    device = await BleakScanner.find_device_by_filter(
        lambda device, advertisement: (
            # On filtre ici sur le nom et le uuid de service publié
            #   -> Un device peut publier plusieurs services
            #   -> Plusieurs devices peuvent avoir le même nom
            advertisement.local_name == DEVICE_NAME
            and SERVICE_UUID in advertisement.service_uuids
        ),
        timeout=15.0,
    )

    if device is None:
        print("Device not found. Check that the ESP32 is advertising.")
        return

    print(f"Found {device.name} [{device.address}]")

    async with BleakClient(device) as client:
        print("Connected.")

        while True:
            data = await client.read_gatt_char(LED_UUID)
            if data is not None:
                await client.write_gatt_char(
                    LED_UUID,
                    bytes([ (data[0] ^ 0x01) & 0x01 ]),
                    response=True,
                )
            time.sleep(1)
       
if __name__ == "__main__":
    try:
        asyncio.run(main())
    except (KeyboardInterrupt, EOFError):
        print("\nExiting.")
    except (BleakError, OSError, asyncio.TimeoutError) as error:
        print(f"Bluetooth error: {error}")
        
```

### Server Callbacks

Documentation du serveur : https://github.com/espressif/arduino-esp32/blob/master/libraries/BLE/src/BLEServer.h

```arduino
// Classe de callback pour le serveur qui redemarre le advertising
// lorsque la connexion avec un appareil est interrompue.
class ServerCallbacks : public BLEServerCallbacks {
public:
	ServerCallbacks(){}
	virtual ~ServerCallbacks(){}
	virtual void onConnect(BLEServer *pServer){
		// On ne fait rien ici.
	}
	virtual void onDisconnect(BLEServer *pServer){
		pServer->getAdvertising()->start();
	}
};

// Instance globale 
ServerCallbacks g_ServerCallbacks {};

// On enregistre ensuite notre instance afin de gerer les callbacks provenant du serveur.
void setup() {
	// ...
	
	// 2. Create the server
	BLEServer *pServer = BLEDevice::createServer();
	
	// On enregistre le callback
	pServer->setCallbacks(&g_ServerCallbacks);
	
	// ...
}

```


### Characteristics Callbacks

Documentation de characteristics : https://github.com/espressif/arduino-esp32/blob/master/libraries/BLE/src/BLECharacteristic.h

Le principe est le même.  Les pincipaux callbacks sont les suivants : 

```arduino
  virtual void onRead(BLECharacteristic *pCharacteristic);
  virtual void onWrite(BLECharacteristic *pCharacteristic);
  virtual void onNotify(BLECharacteristic *pCharacteristic);
  virtual void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);
```

```arduino
class LEDStatusCallbacks : public BLECharacteristicCallbacks {
private:
	int _pin{0};

public:
	LEDStatusCallbacks(int pin) :_pin {pin} {}
	virtual ~LEDStatusCallbacks(){}
	virtual void onWrite(BLECharacteristic *pCharacteristic) {
		if( pCharacteristic->getLength() >= 1 ){
			uint8_t *data = pCharacteristic->getData();
			digitalWrite(_pin, *data);
		}
	}
};

LEDStatusCallbacks g_ledCallbacks{23};

void setup() {
	// ...
	
	// 4. Create your characteristics...

	pLedStateChar = pService->createCharacteristic(
		"563a715c-d3c5-4817-9e6d-ee6aec89e222",
		BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
	pLedStateChar->setValue(0);
	
	// On enregistre le callback
	pLedStateChar->setCallbacks(&g_ledCallbacks); 
	
	// ...
}
```

