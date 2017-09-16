EESchema Schematic File Version 2
LIBS:rfm98-breakout-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:rfm98-breakout
LIBS:rfm98-breakout-cache
EELAYER 25 0
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
L RFM98 RFM1
U 1 1 59ABE80E
P 5800 3750
F 0 "RFM1" H 6000 3300 60  0000 C CNN
F 1 "RFM98" V 5800 3750 60  0000 C CNN
F 2 "rfm98-breakout:RFM98" H 5800 3750 60  0001 C CNN
F 3 "https://github.com/SeeedDocument/RFM95-98_LoRa_Module/blob/master/RFM95_96_97_98_DataSheet.pdf" H 5800 3750 60  0001 C CNN
F 4 "1597-1491-ND" H 5800 3750 60  0001 C CNN "Digi-Key Part Number"
	1    5800 3750
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59ABEB9C
P 7150 3850
F 0 "C1" H 7175 3950 50  0000 L CNN
F 1 "0.1µF" H 7175 3750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7188 3700 50  0001 C CNN
F 3 "" H 7150 3850 50  0001 C CNN
	1    7150 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3700 7150 3700
Wire Wire Line
	6350 4000 7150 4000
$Comp
L GND #PWR01
U 1 1 59ABEC03
P 7150 4250
F 0 "#PWR01" H 7150 4000 50  0001 C CNN
F 1 "GND" H 7150 4100 50  0000 C CNN
F 2 "" H 7150 4250 50  0001 C CNN
F 3 "" H 7150 4250 50  0001 C CNN
	1    7150 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 4000 7150 4250
$Comp
L GND #PWR02
U 1 1 59ABEC54
P 4950 4250
F 0 "#PWR02" H 4950 4000 50  0001 C CNN
F 1 "GND" H 4950 4100 50  0000 C CNN
F 2 "" H 4950 4250 50  0001 C CNN
F 3 "" H 4950 4250 50  0001 C CNN
	1    4950 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3400 4950 3400
Wire Wire Line
	4950 2850 4950 4250
Wire Wire Line
	5250 4100 4950 4100
Connection ~ 4950 4100
$Comp
L Antenna_Shield AE1
U 1 1 59ABECB8
P 8000 3900
F 0 "AE1" H 7925 4075 50  0000 R CNN
F 1 "Antenna_Shield" H 7925 4000 50  0000 R CNN
F 2 "rfm98-breakout:MOLEX-0732511150" H 8000 4000 50  0001 C CNN
F 3 "http://www.molex.com/pdm_docs/sd/732511150_sd.pdf" H 8000 4000 50  0001 C CNN
F 4 "WM5534-ND" H 8000 3900 60  0001 C CNN "Digi-Key Part Number"
	1    8000 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 4100 8000 4100
$Comp
L GND #PWR03
U 1 1 59ABED15
P 8100 4250
F 0 "#PWR03" H 8100 4000 50  0001 C CNN
F 1 "GND" H 8100 4100 50  0000 C CNN
F 2 "" H 8100 4250 50  0001 C CNN
F 3 "" H 8100 4250 50  0001 C CNN
	1    8100 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 4100 8100 4250
Wire Wire Line
	5200 2850 4950 2850
Connection ~ 4950 3400
Wire Wire Line
	5250 3500 4850 3500
Wire Wire Line
	4850 3500 4850 2250
Wire Wire Line
	4850 2250 5200 2250
Wire Wire Line
	5200 2350 4750 2350
Wire Wire Line
	4750 2350 4750 3600
Wire Wire Line
	4750 3600 5250 3600
Wire Wire Line
	5250 3700 4650 3700
Wire Wire Line
	4650 3700 4650 2450
Wire Wire Line
	4650 2450 5200 2450
Wire Wire Line
	5250 3800 4550 3800
Wire Wire Line
	4550 3800 4550 2550
Wire Wire Line
	4550 2550 5200 2550
Wire Wire Line
	5250 3900 4450 3900
Wire Wire Line
	4450 3900 4450 2650
Wire Wire Line
	4450 2650 5200 2650
Wire Wire Line
	6350 3600 6500 3600
Wire Wire Line
	6500 3600 6500 2750
Wire Wire Line
	6500 2750 6400 2750
Wire Wire Line
	6350 3500 6600 3500
Wire Wire Line
	6600 3500 6600 2650
Wire Wire Line
	6600 2650 6400 2650
Wire Wire Line
	6350 3400 6700 3400
Wire Wire Line
	6700 3400 6700 2550
Wire Wire Line
	6700 2550 6400 2550
Wire Wire Line
	6350 3900 6800 3900
Wire Wire Line
	6800 3900 6800 2450
Wire Wire Line
	6800 2450 6400 2450
Wire Wire Line
	6350 3800 6900 3800
Wire Wire Line
	6900 3800 6900 2350
Wire Wire Line
	6900 2350 6400 2350
Wire Wire Line
	5200 2750 5100 2750
Wire Wire Line
	5100 2750 5100 3250
Wire Wire Line
	5100 3250 7150 3250
Wire Wire Line
	7150 3250 7150 3700
Wire Wire Line
	5250 4000 4350 4000
Wire Wire Line
	4350 4000 4350 2050
Wire Wire Line
	4350 2050 6550 2050
Wire Wire Line
	6550 2050 6550 2250
Wire Wire Line
	6550 2250 6400 2250
$Comp
L RFM_CONNECTOR RC1
U 1 1 59BAD13F
P 5800 2550
F 0 "RC1" H 6100 2100 60  0000 C CNN
F 1 "RFM_CONNECTOR" V 5800 2550 60  0000 C CNN
F 2 "rfm98-breakout:RFM98_CON" H 5800 2550 60  0001 C CNN
F 3 "" H 5800 2550 60  0001 C CNN
	1    5800 2550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
