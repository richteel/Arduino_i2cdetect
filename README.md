# Arduino_i2cdetect
I2C Detect for Arduino allowing use on I2C0 or I2C1 for devices with multiple I2C Buses.

The sample I2C code included in several examples assumes that a device has only one I2C bus. On the Raspberry Pi Pico, there are two I2C buses, so the typical examples do not work. This project was created to support multiple buses and to replicate the i2cdetect command available on the Raspberry Pi devices running Linux.

![Arduino IDE showing code and output](/images/SampleOutputArduinoIDE.png)

Below is a wiring diagram showing a Raspberry Pi Pico connected to a BNO085 breakout board. The diagram shows the I2C1 bus being connected. The Arduino IDE image above shows code and output for the setup shown in the wiring diagram.

The only requirement to switch buses is to edit the three define lines to indicate which pins are being used and I2C bus. This code has only been tested for multiple buses on the Raspberry Pi Pico. Other devices, may require different assignments or begin statements.

![Wiring diagram for Raspberry Pi Pico and GY-BNO085 AR VR IMU High Accuracy Nine-Axis 9DOF](/images/BNO085_c.png)