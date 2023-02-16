# Modifications apportées au wizard

    Quelques Modifications mineures ont été apportées

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
mqtt:
  broker: 192.168.1.210
  username: jeedom
  password: jeedomPassword
  client_id: $devicename
```

J'utilise encore la substitution. Si je veux créer un nouvel équipement dans la cuisine, je change en début de fichier 
'devicename: bureau' par 'devicename: cuisine' et le tour est joué.



