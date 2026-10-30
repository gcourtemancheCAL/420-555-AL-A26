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

### Option 1 - Comme un ordinateur

On peut utiliser le Pi comme un ordinateur régulier. Il suffit alors de le brancher à un écran, un clavier et une souris et puis voila.

### Option 2 - SSH

La vaste majorité des activités qu'on va faire sur notre Pi peuvent être faites en ligne de commande. Ipso facto : on peut tout faire via ssh.

Visual studio code supporte d'ailleurs un plugin pour le développement remote via ssh : https://code.visualstudio.com/docs/remote/ssh

### Option 3 - VNC

`apt-get install realvnc-vnc-server realvnc-vnc-viewer `

https://www.realvnc.com/en/connect/download/viewer/windows/

## Connection par Wifi

Au Cégep il n'est pas possible de brancher votre RPI au Wifi et ensuite accéder à votre appareil par son adresse IP car les appareils sur le Wifi invité ne peuvent pas se voir

>[!important] NOTE POUR MOI ET PAS LES ETUDIANTS : TODO : Je dois setup le AP sans fil. Il va me falloir 4.176 et 4.151... 

>[!important] Ici cette approche fonctionnera à votre domicile, mais n'est pas possible sur le WIFI `invité`

### Utilisation du Wifi comme HotSpot

Il est possible de configurer votre RPI pour offrir un Wifi et ainsi vous pouvez vous connecter sur ce Wifi à partir de votre ordinateur et ainsi interagir avec votre PI

`sudo nmcli device wifi hotspot ssid pi_MATRICULE password VOTREPASSWORD`

>[!warning] Ajouter `connection.autoconnect true` pour que cette configuration soit persistée

>[!danger] Ici votre PI n'aura pas accès à l'internet, vous pourrez utiliser le port physique pour lui permettre d'accéder l'internet

