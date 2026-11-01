# Irradiación de Memoria - Física Electrónica - UTN.FRBA   
## Integrantes   
* Stutz     Enrique   
* Yopolo    Iván   

---

## Objetivos   
Escribir en una memoria (EEPROM, Flash, etc) y leerla constantemente para detectar si hubo cambios por radiación.   

---

## Experimento
### Materiales
Consta de los siguientes elementos:   

* 1x LPC845.   
* 1x Clon.   

### Software
Se separa en 2 partes sencillas:   

1. Un programa en un LPC845 que escribe inicialmente en memoria (menos de unos cuantos kB) para luego leer y transmitir a la PC constantemente si hubo cambios.   
2. Un programa en un módulo "Clon" para recibir dichos datos y registrarlos en un archivo. Luego, los transmite a un servidor del LIFEDE.   
