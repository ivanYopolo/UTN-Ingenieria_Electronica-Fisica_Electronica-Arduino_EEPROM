# Irradiación de Memoria EEPROM - Física Electrónica - UTN.FRBA   
## Integrantes   
* Stutz     Enrique   
* Yopolo    Iván   

---

## Objetivos   
Escribir en una memoria EEPORM y leerla constantemente para detectar si hubo cambios por radiación.   

---

## Experimento
### Materiales
Consta de los siguientes elementos:   

* 1x Arduino Nano.   
* 1x Computadora (PC).   

### Software
Se separa en 2 partes sencillas:   

1. Un programa en un Arduino Nano que escribe inicialmente en EEPROM (menos de unos cuantos kB) para luego leer y transmitir a la PC constantemente si hubo cambios.   
2. Un programa en una computadora (PC) para recibir dichos datos y registrarlos en un archivo.   
