# Robocup Junior 2022
## Rescue Line

|Index|
----------
|[Material](#material)|
|[Detalhes Técnicos](#detalhes-técnicos)|


# Material
Main Board:
* Uno/STM32/ESP32

Slave:
* STM32/ESP32

Communication:
* Not allowed

Sensores:
* [4 x RGB Sensor](https://www.botnroll.com/pt/luz-imagem/423-sensor-de-cor-tcs3200.html)
    * Para deteção dos quadrados para virar
* [1 x IR Sensor](https://www.botnroll.com/pt/infravermelhos/47-seguidor-de-linha-qtr-8a-.html)
    * Para seguidor de Linha
* Ultrasound or TOF sensor

# Detalhes Técnicos
## Robó
Haverá duas placas:
* Master
    * Uno/STM32/ESP32
* Slave
    * Serve para ler o Seguidor de Linha
    * STM32/ESP32
        * Nota sobre o ESP32: [ESP32 não lê valores analógicos de forma linear](https://www.esp32.com/viewtopic.php?t=2881)
    * Nota: Nano ou Uno não dão devido à fala de pinos Analógicos ou ADC
    
----------
## Chão
A linha preta tem entre 1 a 2 cm  
Os marcadores verdes de virar são 25x25 mm

