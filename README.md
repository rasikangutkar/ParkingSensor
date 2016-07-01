# ParkingSensor
Cisbo parking sensor connected via Arduino Due.
The aim of this project was to hack into a Cisbo parking sensor kit and infer the distance zone reported by the sensors.

https://github.com/rasikangutkar/ParkingSensor/blob/master/kit.jpg

Read more about cracking the protocol and the code at https://github.com/rasikangutkar/ParkingSensor/wiki

#To run the zoning code:
  - Connect the data pin to the Arduino Due (pin 22)
  - Connect the sensors to the Cisbo parking sensor
  - Connect power supply to the parking sensor (12 V)
  - Download "parkingSensorZoning.ino"
  - Open in Arduino IDE and upload sketch to Due (https://www.arduino.cc/en/Main/Software)
  - Open the serial monitor to view the zone output
  - Change the positions of the sensors and press the reset button for the zone
