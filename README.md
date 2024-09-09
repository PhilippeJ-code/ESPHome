# Utilisation de ESPHome

ESPHome est un système qui permet de controler vos ESP8266/ESP32 sur base d'un simple fichier de configuration,
il est à la base prévu pour communiquer avec Home Assistant mais il communique également par MQTT ce qui permettra
de l'utiliser avec Jeedom et notamment en passant par jMQTT.

Un petit tour ici https://esphome.io/index.html pour se rendre compte des possiblités offertes par ce produit.

Pour l'utiliser il faut d'abord l'installer en suivant la procédure décrite ici https://esphome.io/guides/installing_esphome.html

# ESPHome et Jeedom

Dans mon cas ça se passe sous Windows mais ça fonctionne également sous MAC ou Linux.
Et pour la démonstration je travaillerai avec un ESP32 monté sur l'AZTouch de AZDelivery 
et avec un module M5StickCPlus avec un module environnemental qui donne température, 
humidité et pression.

## 1. Utilisation du wizard

Tout se passe en ligne de commande, on lance donc l'invite de commandes en mode administrateur et on se place
dans le répertoire qui contiendra le seul fichier nécessaire à ESPHome, un fichier de configuration yaml

On trouve une description complète de la ligne de commande ici https://esphome.io/guides/cli.html

Je vais donc lancer la commande  `esphome wizard hello.yaml`, quelques questions plus loin et 
le fichier hello.yaml sera créé, il ne restera plus qu'à le compiler et à l'envoyer sur l'ESP32.

Le wizard nous demande d'abord le nom du module, le module sera installé sur mon bureau je le nomme donc `bureau`, 
la plateforme pour moi `ESP32`, la carte pour moi `az-delivery-devkit-v4`, le SSID de mon réseau WiFi `wifi_ssid`,
le mot de passe `ssid_password` et pour le mot de passe ota je ne mets rien.

Voici le code généré dans le fichier hello.yaml

```
esphome:
  name: bureau

esp32:
  board: az-delivery-devkit-v4
  framework:
    type: arduino

# Enable logging
logger:

# Enable Home Assistant API
api:
  password: ""

ota:
  password: ""

wifi:
  ssid: "wifi_ssid"
  password: "wifi_password"

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Bureau Fallback Hotspot"
    password: "dBIEO8pQUXXa"

captive_portal:
```

Je supprime les 3 lignes concernant Home Assistant, la possibilité d'accéder à l'ESP32 par le WEB et l'accès à MQTT 
pour en arriver à ceci https://github.com/PhilippeJ-code/ESPHome/blob/master/src/hello.yaml. Il faudra changer les 
identifiants WiFi et MQTT pour que ça fonctionne sur votre configuration.

## 2. Compilation

Je lance la commande `esphome run hello.yaml` qui sur base du fichier configuration va générer les fichiers nécessaires, 
les compiler et téléverser le firmware sur l'ESP32 sur le port USB que vous devrez spécifier.

## 3. Et ça donne

Un petit tour sur le WEB à l'adresse attribuée à l'ESP32

![web](/docs/images/web.png "web")

Et un petit tour sur Jeedom pour créer un équipement Bureau sur jMQTT avec un topic bureau/#

![jmqtt](/docs/images/jmqtt.png "jmqtt")

Les commandes créées automatiquement par ESPHome apparaissent tout aussi automatiquement

![cmds](/docs/images/cmds.png "cmds")

La suite dans le répertoire docs en commençant par le répertoire M5StickCPlus





