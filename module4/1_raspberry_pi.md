# Raspberry Pi

## Broches

<img src="img/Pasted image 20261007100900.png" width="400" />

## Connexions

<img src="img/Pasted image 20261007100931.png" width="600" />

<img src="img/Pasted image 20261007120752.png" width="600" />

## Installation du Pi

### Insertion de la carte microSD dans le pi

<img src="img/Pasted image 20261028110833.png" width="600" />

### Adapteur MicroSD : 

<img src="img/Pasted image 20261028110400.png" width="600" />

### Flasher l'image sur la carte microSD

Raspeberry pi imager : https://www.raspberrypi.com/software/

<img src="img/Capture d’écran 2026-10-13 122031.png" width="600" />

<img src="img/Capture d’écran 2026-10-13 122110.png" width="600" />

<img src="img/Capture d’écran 2026-10-13 122134.png" width="600" />

<img src="img/Capture d’écran 2026-10-13 122310.png" width="600" />

<img src="img/Capture d’écran 2026-10-13 122405.png" width="600" />

## Travailler sur le Pi

### Retrouver le Pi sur le réseau

Il va normalement être possible de se connecter au Pi directement via son adresse IP. Pour ce faire, vous allez normalement devoir connecter le Pi à un écran le temps d'identifier son adresse IP.

Ça peut être problématique. Je vous recommanderais donc de vous y connecter via son nom d'hôte. Pour s'assurer que cette option soit fonctionnelle sur le maximum de réseaux possibles, il va falloir désactiver le mode IPv6 dans la configuration du service mDNS de votre pi.

```bash
	# Sur le pi
	# Modifiez le fichier /etc/avahi/avahi-daeomon.conf
	vim /etc/avahi/avahi-daeomon.conf
	
	# Désactiver IPv6
	use-ipv6=no
	publish-aaaa-on-ipv4=no
	
	# On sauvegarde et quitte vim
	<esc><esc>:wq
	
	# On redémarre le service avahi
	sudo systemctl restart avahi-daemon
```

### Option 1 - Comme un ordinateur

On peut utiliser le Pi comme un ordinateur régulier. Il suffit alors de le brancher à un écran, un clavier et une souris et puis voila.

### Option 2 - SSH

La vaste majorité des activités qu'on va faire sur notre Pi peuvent être faites en ligne de commande. Ipso facto : on peut tout faire via ssh.

Visual studio code supporte d'ailleurs un plugin pour le développement remote via ssh : https://code.visualstudio.com/docs/remote/ssh

### Option 3 - VNC

`apt-get install realvnc-vnc-server realvnc-vnc-viewer `

https://www.realvnc.com/en/connect/download/viewer/windows/

## Connexion par Wifi

Utilisez le wifi du labo. Pas invité. Comme ça vos système vont être en mesure de se voir.
### Utilisation du Pi comme HotSpot

Il est possible de configurer votre RPI pour offrir un Wifi et ainsi vous pouvez vous connecter sur ce Wifi à partir de votre ordinateur et ainsi interagir avec votre PI

`sudo nmcli device wifi hotspot ssid pi_MATRICULE password VOTREPASSWORD`

>[!warning] Ajouter `connection.autoconnect true` pour que cette configuration soit persistée

>[!danger] Ici votre PI n'aura pas accès à l'internet, vous pourrez utiliser le port physique pour lui permettre d'accéder l'internet

