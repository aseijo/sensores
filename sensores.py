#!/usr/bin/python

import serial
arduino = serial.Serial('/dev/ttyACM0', baudrate=9600, timeout=1.0)

while True:
    
	line = arduino.readline()
    
	if len(line) > 5:
		data = line.split(':')
		key = data[0]
		value = data[1].strip('\r\n')
	
		if key == "Luz":
			print 'Insertar '+ value +' en luz'
		if key == "DHTTemp":
			print 'Insertar '+ value +' en temperatura'
		if key == "DHTHum":
			print 'Insertar '+ value +' en humedad'
	
