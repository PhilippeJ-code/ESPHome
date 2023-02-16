# Utilisation de ESPHome

ESPHome est un système qui permet de controler vos ESP8266/ESP32 sur base d'un simple fichier de configuration,
il est à la base prévu pour communiquer avec Home Assistant mais il communique également par MQTT ce qui permettra
de l'utiliser avec Jeedom et notamment en passant par jMQTT.

Un petit tour ici https://esphome.io/index.html pour se rendre compte des possiblités offertes par ce produit.

Pour l'utiliser il faut d'abord l'installer en suivant la procédure décrite ici https://esphome.io/guides/installing_esphome.html

# ESPHome et Jeedom

    Dans mon cas ça se passe sous Windows mais ça fonctionne également sous MAC ou Linux.
    Et pour la démonstration je travaillerai avec un ESP32 monté sur l'AZTouch de AZDelivery 
        et avec un module M5StickCPlus avec un module environnemental qui donne température, humidité et pression.

## 1. Utilisation du wizard

    Tout se passe en ligne de commande, on lance donc l'invite de commandes en mode administrateur et on se place
    dans le répertoire qui contiendra le seul fichier nécessaire à ESPHome, un fichier de configuration yaml

    On trouve une description complète de la ligne de commande ici https://esphome.io/guides/cli.html

    Je vais donc lancer la commande  `esphome wizard hello.yaml`, quelques questions plus loin et 
    le fichier hello.yaml sera créé, il ne restera plus qu'à le compiler et à l'envoyer sur l'ESP32.

