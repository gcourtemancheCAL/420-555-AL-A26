# FreeRTOS

>[!warning] Je suis habitué à travailler directement avec l'environnement ESP-IDF et non pas avec l'environnement de l'IDE arduino. Cet environnement me donne accès direct à la totalité de l'API d'espressif ainsi que de FreeRTOS. L'environnement d'arduino est limité dans cette mesure - certains APIs sont disponibles, d'autres non. Il est possible que certains éléments abordés dans ce document ne vous soit pas directement accessible en classe.

Contrairement au 8266, les ESP32 ne sont pas bare metal. Ils roulent un OS s'appelant FreeRTOS. 

FreeRTOS est un **R**eal **T**ime **O**perating **S**ystem. Un RTOS est un système d'exploitation léger conçu pour exécuter des tâches avec un temps de réponse prévisible et garanti (i.e en temps réel). 

**Ce que FreeRTOS fournit :** 
- Un système de scheduling basé sur des `task` (similaire à des threads)
- Un système de communication et de synchronization intertâche basé sur des queues, des sémaphores et des mutexes.
- [Un système d'allocation dynamique de la mémoire](https://freertos.org/Documentation/02-Kernel/02-Kernel-features/09-Memory-management/01-Memory-management)
- Des timers

**Ce que FreeRTOS ne fournit pas :** 
- Un environnement de bureau
- Un système de fichier
- Des processus distincts et indépendants
- Mémoire virtuelle
- Un environnement graphique
- ...

## Exemple de task

```arduino

void BlinkTask(void *parameter);

void setup() {
	static int blinkDelayMs = 1000;

	xTaskCreate( 
		BlinkTask,            // La fonction implémentant la tâche
		
		"task_test",          // Un nom donné à la tâche. Peu d'impact réel. Surtout pour debug.
		
		1024,                 // Taille de la pile (stack) de la tâche. 
		                      // Sur freertos : multiplié par word size.
		                      // Sur ESP32 - override pour être taille en byte directement
		
		&blinkDelayMs,        // Pointeur qui est passé en paramètre à la tâche. Peut être n'importe quoi.
		                      // Ce genre d'argument est souvent appelé `user context`  
		
		tskIDLE_PRIORITY + 1, // Priorité de la tâche. Influence le scheduling des tâches. 
		                      // Plus la priorité est élevé : plus que la tâche est prioritaire.
		                      // Les tâches prioritaires qui ne sont pas en attentes vont _toujours_ 
		                      // être exécutée avant les tâche moins prioritaires. 
		
		nullptr               // pointeur vers TaskHandle_t. Permet de récuperer le handle de la tâche
		                      // afin de la manipuler par la suite (par exemple, pour la supprimer via vTaskDelete)
		                      // Optionnel et peut être null.
	);
}

void BlinkTask(void *parameter) {
	for (;;) { // Boucle infinie. Très important : "the task must never attempt to return or exit"
		
		// parameter est le user context passé à la création de la tâche.
		int delayMs = parameter == nullptr ? 1000 : *((int*)parameter);
		
		digitalWrite(1, HIGH);
		
		// vTaskDelay est l'équivalent FreeRTOS du delay d'arduino.
		//     En fait : delay invoque vTaskDelay si disponible.
		// Différence importante : vTaskDelay opère sur un nombre de tick.
		// Il faut donc le convertir en unité de temps (ms). 
		// On utilise donc ici la macro pdMS_TO_TICKS.
		vTaskDelay(pdMS_TO_TICKS(delayMs));
		
		digitalWrite(1, LOW);
		
		vTaskDelay(pdMS_TO_TICKS(delayMs));
	}
}



```

### API FreeRTOS
[xTaskCreate](https://www.freertos.org/Documentation/02-Kernel/04-API-references/01-Task-creation/01-xTaskCreate)

[Scheduling des tâches](https://freertos.org/Documentation/02-Kernel/02-Kernel-features/01-Tasks-and-co-routines/04-Task-scheduling)

**TLDR :** 
- Les tâches ont une priorité fixe
- FreeRTOS va toujours essayer d'exécuter une tâche de priorité plus élevé si disponible.
	- Des tâches de priorité moindre peuvent être entièrement privé de temps de processeur s'il y a toujours des tâches plus prioritaires à exécuter
	- En d'autres mots, assurez-vous de faire "dormir" vos tâches de temps en temps pour donner de la place aux autres.
- À priorité égales, les tâches sont exécutés à tour de rôle
- Les tâches se font donner un tick d'exécution à la fois.
- La durée par défaut d'un tick est de 1ms.
- [Uniquement les tâches dans l'état `READY` sont considérés pour être exécutés.](https://freertos.org/Documentation/02-Kernel/02-Kernel-features/01-Tasks-and-co-routines/02-Task-states)

## Mutex

On peut utiliser directement les mutex de la stdlib c++ sur le ESP32.

```arduino

#include <mutex>

struct AppContext {
	std::mutex mut {};
	int counter {0};
};

AppContext g_app_context {};
void exemple_mutex_task(void *parameter);

void setup() {
	Serial.begin(9600);
	xTaskCreate( exemple_mutex_task, "", 1024, &g_app_context, tskIDLE_PRIORITY + 1, nullptr );
}

void exemple_mutex_task(void *parameter) {
	AppContext *ctx = (AppContext *)parameter;
	
	for (;;) {
		Serial.println("TASK LOOP - BEGIN");
		{
			// On utilise un `lock_guard` pour gérer le cycle lock/unlock du mutex automatiquement
			// Lorsque la variable lock est créé : le mutex est locked.
			// Lors la variable lock est détruite (à la sortie du block) : le mutex est unlocked.
			std::lock_guard<std::mutex> lock {ctx->mut};
			Serial.println("TASK LOOP - MUTEX");
			ctx->counter++;
			vTaskDelay(pdMS_TO_TICKS(50));
			Serial.print("TASK LOOP - MUTEX OUT");
		}
		
		Serial.println("TASK LOOP - SLEEP");
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void loop() {
	Serial.println("ARDUINO LOOP - BEGIN");
	{
		std::lock_guard<std::mutex> lock {g_app_context.mut};

		Serial.print("ARDUINO LOOP - MUTEX. V=");
		Serial.println(g_app_context.counter, DEC);
		vTaskDelay(pdMS_TO_TICKS(50));
		Serial.print("ARDUINO LOOP - MUTEX OUT");
	}
	
	Serial.println("ARDUINO LOOP - SLEEP");
	vTaskDelay(pdMS_TO_TICKS(500));
}
```

