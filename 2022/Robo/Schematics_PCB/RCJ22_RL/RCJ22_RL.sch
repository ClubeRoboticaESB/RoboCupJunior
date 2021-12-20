EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
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
Text Notes 12200 10950 0    50   ~ 0
Robot for RCJ22 Rescue Line 
$Comp
L STM32_Bluepill:BluePill_Part_Like U1
U 1 1 61B80D92
P 8250 2400
F 0 "U1" H 8250 3565 50  0000 C CNN
F 1 "BluePill" H 8250 3474 50  0000 C CNN
F 2 "STM32_BluePill:BluePill_1" H 8950 1400 50  0001 C CNN
F 3 "" H 8950 1400 50  0001 C CNN
	1    8250 2400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x07 J1
U 1 1 61B7ED67
P 9850 2700
F 0 "J1" H 9930 2742 50  0000 L CNN
F 1 "LineSensor" H 9930 2651 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 9850 2700 50  0001 C CNN
F 3 "~" H 9850 2700 50  0001 C CNN
	1    9850 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 3000 9050 3000
Wire Wire Line
	9650 2900 9050 2900
Wire Wire Line
	9650 2800 9050 2800
Wire Wire Line
	9650 2700 9050 2700
Wire Wire Line
	9650 2600 9050 2600
Text GLabel 9050 1700 2    50   Input ~ 0
3V3
Text GLabel 9050 1600 2    50   Input ~ 0
GND
Text GLabel 9050 1500 2    50   Input ~ 0
GND
Text GLabel 7450 3300 0    50   Input ~ 0
GND
Text GLabel 7450 3400 0    50   Input ~ 0
3V3
Text Label 9350 2700 0    50   ~ 0
IR2
Text Label 9350 2800 0    50   ~ 0
IR3
Text Label 9350 2900 0    50   ~ 0
IR4
Text Label 9350 3000 0    50   ~ 0
IR5
Text GLabel 9650 2400 0    50   Input ~ 0
3V3
Text GLabel 9650 2500 0    50   Input ~ 0
GND
Text Label 9350 2600 0    50   ~ 0
IR1
Text GLabel 1850 1250 1    50   Input ~ 0
3V3
Text GLabel 1850 2750 3    50   Input ~ 0
GND
Text GLabel 2050 1250 1    50   Input ~ 0
VIN
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 61C0E352
P 2900 1950
F 0 "J3" H 2980 1942 50  0000 L CNN
F 1 "Motor1" H 2980 1851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2900 1950 50  0001 C CNN
F 3 "~" H 2900 1950 50  0001 C CNN
	1    2900 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 1850 2700 1850
Wire Wire Line
	2350 1950 2700 1950
Wire Wire Line
	2350 2050 2700 2050
Wire Wire Line
	2350 2150 2700 2150
Text Notes 2650 800  0    118  ~ 24
Motors Drivers
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A1
U 1 1 61C24868
P 1850 1950
F 0 "A1" H 1500 2750 50  0000 C CNN
F 1 "A4988_M1" H 1500 2650 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 2125 1200 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 1950 1650 50  0001 C CNN
	1    1850 1950
	1    0    0    -1  
$EndComp
Text GLabel 2050 2750 3    50   Input ~ 0
GND
Text GLabel 4350 1250 1    50   Input ~ 0
3V3
Text GLabel 4350 2750 3    50   Input ~ 0
GND
Text GLabel 4550 1250 1    50   Input ~ 0
VIN
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 61C331E9
P 5400 1950
F 0 "J4" H 5480 1942 50  0000 L CNN
F 1 "Motor2" H 5480 1851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5400 1950 50  0001 C CNN
F 3 "~" H 5400 1950 50  0001 C CNN
	1    5400 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 1850 5200 1850
Wire Wire Line
	4850 1950 5200 1950
Wire Wire Line
	4850 2050 5200 2050
Wire Wire Line
	4850 2150 5200 2150
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A3
U 1 1 61C331F7
P 4350 1950
F 0 "A3" H 4000 2750 50  0000 C CNN
F 1 "A4988_M2" H 4000 2650 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 4625 1200 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 4450 1650 50  0001 C CNN
	1    4350 1950
	1    0    0    -1  
$EndComp
Text GLabel 4550 2750 3    50   Input ~ 0
GND
Text GLabel 1850 3250 1    50   Input ~ 0
3V3
Text GLabel 1850 4750 3    50   Input ~ 0
GND
Text GLabel 2050 3250 1    50   Input ~ 0
VIN
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 61C352F9
P 2900 3950
F 0 "J2" H 2980 3942 50  0000 L CNN
F 1 "Motor3" H 2980 3851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2900 3950 50  0001 C CNN
F 3 "~" H 2900 3950 50  0001 C CNN
	1    2900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 3850 2700 3850
Wire Wire Line
	2350 3950 2700 3950
Wire Wire Line
	2350 4150 2700 4150
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A2
U 1 1 61C35307
P 1850 3950
F 0 "A2" H 1500 4750 50  0000 C CNN
F 1 "A4988_M3" H 1500 4650 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 2125 3200 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 1950 3650 50  0001 C CNN
	1    1850 3950
	1    0    0    -1  
$EndComp
Text GLabel 2050 4750 3    50   Input ~ 0
GND
Text GLabel 4350 3250 1    50   Input ~ 0
3V3
Text GLabel 4350 4750 3    50   Input ~ 0
GND
Text GLabel 4550 3250 1    50   Input ~ 0
VIN
$Comp
L Connector_Generic:Conn_01x04 J5
U 1 1 61C36631
P 5400 3950
F 0 "J5" H 5480 3942 50  0000 L CNN
F 1 "Motor4" H 5480 3851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5400 3950 50  0001 C CNN
F 3 "~" H 5400 3950 50  0001 C CNN
	1    5400 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3850 5200 3850
Wire Wire Line
	4850 3950 5200 3950
Wire Wire Line
	4850 4050 5200 4050
Wire Wire Line
	4850 4150 5200 4150
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A4
U 1 1 61C3663F
P 4350 3950
F 0 "A4" H 4000 4750 50  0000 C CNN
F 1 "A4988_M4" H 4000 4650 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 4625 3200 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 4450 3650 50  0001 C CNN
	1    4350 3950
	1    0    0    -1  
$EndComp
Text GLabel 4550 4750 3    50   Input ~ 0
GND
Wire Wire Line
	1450 1650 1300 1650
Wire Wire Line
	1300 1650 1300 1550
Wire Wire Line
	1300 1550 1450 1550
Wire Wire Line
	3950 1650 3850 1650
Wire Wire Line
	3850 1650 3850 1550
Wire Wire Line
	3850 1550 3950 1550
Wire Wire Line
	1450 3650 1350 3650
Wire Wire Line
	1350 3650 1350 3550
Wire Wire Line
	1350 3550 1450 3550
Wire Wire Line
	3950 3650 3850 3650
Wire Wire Line
	3850 3650 3850 3550
Wire Wire Line
	3850 3550 3950 3550
Text GLabel 1450 1950 0    50   Input ~ 0
STEP1
Text GLabel 3950 1950 0    50   Input ~ 0
STEP2
Text GLabel 1450 3950 0    50   Input ~ 0
STEP3
Text GLabel 3950 3950 0    50   Input ~ 0
STEP4
Text GLabel 1450 2050 0    50   Input ~ 0
DIR1
Text GLabel 3950 2050 0    50   Input ~ 0
DIR2
Text GLabel 1450 4050 0    50   Input ~ 0
DIR3
Text GLabel 3950 4050 0    50   Input ~ 0
DIR4
Wire Notes Line
	6000 5350 550  5350
$Comp
L Device:C C1
U 1 1 61C6B6A9
P 1800 6100
F 0 "C1" H 1915 6146 50  0000 L CNN
F 1 "Cap1" H 1915 6055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Axial_L21.0mm_D8.0mm_P28.00mm_Horizontal" H 1838 5950 50  0001 C CNN
F 3 "~" H 1800 6100 50  0001 C CNN
	1    1800 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 6250 1300 6250
Text GLabel 1300 5900 0    50   Input ~ 0
BATVIN
Text GLabel 1300 6250 0    50   Input ~ 0
GND
Text Notes 2000 5750 0    118  ~ 24
Power Circuit
$Comp
L Regulator_Linear:LM317_TO-220 U2
U 1 1 61C0EDE5
P 3300 6200
F 0 "U2" H 3300 6450 50  0000 C CNN
F 1 "LM317" H 3300 6350 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3300 6450 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm317.pdf" H 3300 6200 50  0001 C CNN
	1    3300 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 6250 2400 6250
Connection ~ 1800 6250
Text GLabel 2500 6250 2    50   Input ~ 0
GND
Text GLabel 3900 5900 2    50   Input ~ 0
VIN
$Comp
L Device:R R1
U 1 1 61C1DA2A
P 3700 6350
F 0 "R1" H 3770 6396 50  0000 L CNN
F 1 "R330" H 3770 6305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3630 6350 50  0001 C CNN
F 3 "~" H 3700 6350 50  0001 C CNN
	1    3700 6350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 61C2150F
P 3700 6750
F 0 "R2" H 3770 6796 50  0000 L CNN
F 1 "R560" H 3770 6705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3630 6750 50  0001 C CNN
F 3 "~" H 3700 6750 50  0001 C CNN
	1    3700 6750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 61C29078
P 4350 6550
F 0 "C2" H 4465 6596 50  0000 L CNN
F 1 "Cap2" H 4465 6505 50  0000 L CNN
F 2 "Capacitor_THT:CP_Axial_L21.0mm_D8.0mm_P28.00mm_Horizontal" H 4388 6400 50  0001 C CNN
F 3 "~" H 4350 6550 50  0001 C CNN
	1    4350 6550
	1    0    0    -1  
$EndComp
Text GLabel 4800 6200 2    50   Input ~ 0
3V3
Text GLabel 4750 6900 2    50   Input ~ 0
GND
Wire Wire Line
	1300 5900 1800 5900
Wire Wire Line
	1800 5950 1800 5900
Connection ~ 1800 5900
Wire Wire Line
	1800 5900 3000 5900
Wire Wire Line
	3000 5900 3000 6200
Connection ~ 3000 5900
Wire Wire Line
	3000 5900 3900 5900
Text Notes 3200 6250 0    24   ~ 0
TO-220
Wire Notes Line
	6000 500  6000 7150
Wire Notes Line
	6000 7150 500  7150
Wire Wire Line
	3600 6200 3700 6200
Wire Wire Line
	3700 6500 3700 6550
Wire Wire Line
	3700 6550 3300 6550
Wire Wire Line
	3300 6550 3300 6500
Connection ~ 3700 6550
Wire Wire Line
	3700 6550 3700 6600
Wire Wire Line
	2400 6250 2400 6900
Wire Wire Line
	2400 6900 3700 6900
Connection ~ 2400 6250
Wire Wire Line
	2400 6250 2500 6250
Connection ~ 3700 6900
Connection ~ 3700 6200
Wire Wire Line
	3700 6900 4350 6900
Wire Wire Line
	3700 6200 4350 6200
Wire Wire Line
	4350 6400 4350 6200
Wire Wire Line
	4350 6700 4350 6900
Wire Wire Line
	4750 6900 4350 6900
Connection ~ 4350 6900
Wire Wire Line
	4800 6200 4350 6200
Connection ~ 4350 6200
Wire Wire Line
	2350 4050 2700 4050
$EndSCHEMATC
