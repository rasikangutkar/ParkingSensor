# ParkingSensor
Cisbo parking sensor connected via Arduino Due.

This post describes how to hack into a cisbo parking sensor and connect it to an Arduino Due. The main focus of this post is on understanding the protocol rather than the code... I had come across various links hacking Cisbo parking sensor kits but the protocol was different so we had to figure it out before writing the code... Hopefully through this post and the references you will have sufficient background on how to crack the protocol.

These are some similar sites for hacking cisbo parking sensors...
http://www.underwaterrov.net/hacking-reverse-parking-sensors-with-an-arduino

http://ishankarve.blogspot.co.uk/2011/06/decoding-ultrasonic-parking-sensor.html

http://www.mp3car.com/forum/mp3car-technical-hardware/hardware-development/125211-custom-usb-parking-sensor-interface-formally-pdc-usb/page24



#Stuff used:
- Cisbo parking sensor kit

- Arduino Due

- Saleae Logic Analyzer

- Bread Board

- Jumper wires

#Set up

#Cracking the protocol

As mentioned before the focus of this post is on cracking the protocol and giving you an idea on what to expect when hacking to your own parking sensor...

- Previous protocol: 

To my understanding the protocol used is different for different cisbo models. The referenced cisbo models outputted the distance of each sensor on the line.

-Overview of the protocol: 

1. There are two regions made up of two sensors each : A & B make up Region 1 while C & D sensors make up Region 2.

2. The shortest distance of both the regions  from 1-6.9 ft is reported.

3. Each region (1ft - 6.9 ft) is broken down into 8 zones. 

Zone1 - 1-1.6ft

Zone2 - 1.7-2.3ft

Zone3 - 2.4-2.6ft

Zone4 - 2.7-32ft

Zone5 - 3.3-3.9ft

Zone6 - 4-4.6ft

Zone7 - 4.7-6.6ft

Zone8 - 6.7-6.9ft

Zone0/9 - disconnected sensors/ greater than 6.9 ft

4. Each region outputs the shortest zoned distance within it. 
i.e. to say if Region 1 is considered viz. A and B sensors. If A were to sense 4.5 ft (Zone 6) and B were to sense 1.8ft (Zone2) .. Region 1 will report Zone 2.

-Example Scenario
Sensor A detects 2.5ft

Sensor B detects 4.5ft

Sensor C detects 1.4ft

Sensor D detects 6.5ft

Data outputted: 

(Region 1: Zone 2) (Region 2: Zone 1) (Shortest Distance Integer Part: 1) (Shortest Distance Decimal Part: 4)






#Code
