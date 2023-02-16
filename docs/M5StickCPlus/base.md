# Modifications apportées au wizard

    Description du fichier de configuration

```
substitutions:
  devicename: bureau
```

Cela permet de subtituer toutes les occurences de $devicename par bureau, cela facilitera 
le travail de maintenance

```
esphome:
  name: $devicename
  platformio_options:
    upload_speed: 115200
```

J'utilise la substitution pour le 'name' de 'esphome' et je force la vitesse de téléversement ( upload_speed )

```
esp32:
  board: m5stick-c
  framework:
    type: arduino
```
Description de carte utilisée

```
logger:
```

Utilisation d'un logger ( qui est très bavard et c'est tant mieux )

```
ota:
  password: ""
```

Définition du mot de passe pour le téléversement du firmware "Over The Air"

```
wifi:
  ssid: "wifi_ssid"
  password: "wifi_password"

  ap:
    ssid: "StickAP"
    password: "12345678"

```

Identifiants Wifi, si l'ESP32 ne peut pas se connecter au réseau spécifié il crée un réseau WiFi ( ici StickAP ) 
qui permet de changer les identifiants du Wifi

```
web_server:
  port: 80
```

Création d'un serveur WEB

```
mqtt:
  broker: 192.168.1.210
  username: jeedom
  password: jeedomPassword
  client_id: $devicename
```

Identifiants MQTT et ici j'utilise encore la substitution. Si je veux créer un nouvel équipement dans la cuisine, je change en début de fichier 
'devicename: bureau' par 'devicename: cuisine' et le tour est joué.
