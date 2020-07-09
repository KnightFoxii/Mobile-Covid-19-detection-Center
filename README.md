# Mobile Covid Monitoring

This System is developed wiht the help of arduino and 000webhostapp.com 


000webhostapp.com is used as its a free tool for hosting websites along with sql databases. 

The following hardware is required:-
1. Arduino Nano - ATMEGA328p (v- old bootloader)
2. ESP8266 Wifi Module - to send data to website
3. Temperature Sensor - LM35 / DS18B20 ( First is commonly available & other is waterproof one )
4. SPO2 Sensor - MAX30100/2 ( Need to short out some connections. Guide is available at - https://how2electronics.com/interfacing-max30100-pulse-oximeter-sensor-arduino/ Follow 2nd Method )
5. Sound Sensor - LM393
6. Resistors - 1k, 2.2k, 10k ( one of each kind )
All the above sensors should be connected according to the circuit diagram given in the repository.

#Steps:-
1. Create an account at 000webhostapp.com
2. Host website using code given in repository.
3. Also create a database.
4. Make changes in arduino code. ( Change wifi ssid + wifi pass + hostname + database id + database pass )
5. Save changes in arduino code.
6. Upload the code to the arduino ( MAIN_ESP8266.ino )

On doing the above steps you should now see the parameters of a patient ( touching the sensors ) from anywhere in the world.
The website will auto-refresh so you will get real time values of the patient.
