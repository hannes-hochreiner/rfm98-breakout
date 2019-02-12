# Control program for the Raspberry Pi
This is a small control program for the Hope RF RFM98 module.
It is built to run on the Raspberry Pi using WiringPi.

# Setup
## Install WiringPi
```
sudo apt install wiringpi
```

## Activate SPI
The SPI interface can be activated using the Raspberry Pi configuration tool.
The option can be found in the "interfacing options" sub-menu.
```
sudo raspi-config
```

# Wiring
  * BMC 8: ~CS
  * BCM 9: MISO
  * BCM 10: MOSI
  * BCM 11: CLK
  * BCM 22: RST
  * BCM 23: DIO0
  * BCM 27: DIO1
