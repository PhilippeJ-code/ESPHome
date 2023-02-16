# ESPHome et Jeedom

    Dans mon cas ça se passe sous Windows mais ça fonctionne également sous MAC ou Linux.
    Et pour la démonstration je travaillerai avec un ESP32 monté sur l'AZTouch de AZDelivery 
        et avec un module M5StickCPlus avec un module environnemental qui donne température, humidité et pression.

## 1. Utilisation du wizard

    Tout se passe en ligne de commande, on lance donc l'invite de commandes en mode administrateur et on se place
    dans le répertoire qui contiendra le seul fichier nécessaire à ESPHome, un fichier de configuration yaml

    On trouve une description complète de la ligne de commande ici https://esphome.io/guides/cli.html

    Je vais donc lancer la commande <pre><code>eshome wizard hello.yaml</code></pre>, quelques questions plus loin et 
    le fichier hello.yaml sera créé, il ne restera plus qu'à le compiler et à l'envoyer sur l'ESP32.

    
    

