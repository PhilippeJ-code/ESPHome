# Modifications apportées au wizard

Description du fichier de configuration

Cela permet de subtituer toutes les occurences de $devicename par bureau, cela facilitera 
le travail de maintenance

```
substitutions:
  devicename: bureau
```

J'utilise la substitution pour le 'name' de 'esphome' et je force la vitesse de téléversement ( upload_speed )

```
esphome:
  name: $devicename
  platformio_options:
    upload_speed: 115200
```

Description de la carte utilisée

```
esp32:
  board: m5stick-c
  framework:
    type: arduino
```

Utilisation d'un logger ( qui est très bavard et c'est tant mieux )

```
logger:
```

Définition du mot de passe pour le téléversement du firmware "Over The Air"

```
ota:
  password: ""
```

Identifiants Wifi, si l'ESP32 ne peut pas se connecter au réseau spécifié il crée un réseau WiFi ( ici StickAP ) 
qui permet de changer les identifiants du Wifi en se connectant avec un smartphone par exemple et en accédant
à l'adresse 192.168.1.4

```
wifi:
  ssid: "wifi_ssid"
  password: "wifi_password"

  ap:
    ssid: "StickAP"
    password: "12345678"

```

Création d'un serveur WEB

```
web_server:
  port: 80
```

Identifiants MQTT et ici j'utilise encore la substitution. Si je veux créer un nouvel équipement dans la cuisine, je change en début de fichier 
'devicename: bureau' par 'devicename: cuisine' et le tour est joué.


```
mqtt:
  broker: 192.168.1.210
  username: jeedom
  password: jeedomPassword
  client_id: $devicename
```
