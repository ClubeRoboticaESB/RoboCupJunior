EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32_Bluepill:YAAJ_BluePill_Part_Like U1
U 1 1 61B31F42
P 2200 2500
F 0 "U1" H 2200 3665 50  0000 C CNN
F 1 "MainBoard" H 2200 3574 50  0000 C CNN
F 2 "STM32_Bluepill:YAAJ_BluePill_1" H 2900 1500 50  0001 C CNN
F 3 "" H 2900 1500 50  0001 C CNN
	1    2200 2500
	1    0    0    -1  
$EndComp
$Comp
L STM32_Bluepill:YAAJ_BluePill_Part_Like U2
U 1 1 61B34B62
P 4250 2500
F 0 "U2" H 4250 3665 50  0000 C CNN
F 1 "LineSensorBoard" H 4250 3574 50  0000 C CNN
F 2 "STM32_Bluepill:YAAJ_BluePill_1" H 4950 1500 50  0001 C CNN
F 3 "" H 4950 1500 50  0001 C CNN
	1    4250 2500
	1    0    0    -1  
$EndComp
Text GLabel 3450 2900 0    50   Input ~ 0
SCL
Text GLabel 3450 3000 0    50   Input ~ 0
SDA
Text GLabel 1400 2900 0    50   Input ~ 0
SCL
Text GLabel 1400 3000 0    50   Input ~ 0
SDA
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 61B551AD
P 5700 2700
F 0 "J1" H 5780 2692 50  0000 L CNN
F 1 "QTR-8A" H 5780 2601 50  0000 L CNN
F 2 "Connector_JST:JST_EH_S8B-EH_1x08_P2.50mm_Horizontal" H 5700 2700 50  0001 C CNN
F 3 "~" H 5700 2700 50  0001 C CNN
	1    5700 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2400 5500 2400
Wire Wire Line
	5050 2500 5500 2500
Wire Wire Line
	5050 2600 5500 2600
Wire Wire Line
	5050 2700 5500 2700
Wire Wire Line
	5050 2800 5500 2800
Wire Wire Line
	5050 2900 5500 2900
Wire Wire Line
	5050 3000 5500 3000
Wire Wire Line
	5050 3100 5500 3100
$EndSCHEMATC
