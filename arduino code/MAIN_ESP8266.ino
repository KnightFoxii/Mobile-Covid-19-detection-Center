//Include the needed library, we will use softer serial communication with the ESP8266
#include <SoftwareSerial.h>
#include <avr/power.h>

//LCD config
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  //sometimes the LCD adress is not 0x3f. Change to 0x27 if it dosn't work.

#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
 
#define REPORTING_PERIOD_MS     1000
 
PulseOximeter pox;
uint32_t tsLastReport = 0;
 
void onBeatDetected()
{
    Serial.println("Beat!");
}

int ledPin=13;
int sensorPin=7;
boolean val =0;
  
int val;
int tempPin = 1;

//Define the used
#define ESP8266_RX 10  //Connect the TX pin from the ESP to this RX pin of the Arduino
#define ESP8266_TX 11  //Connect the TX pin from the Arduino to the RX pin of ESP

int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int Potentiometer_1 = A0;
int Potentiometer_2 = A1;
int Potentiometer_3 = A2;
int Potentiometer_4 = A3;
int switch1 = 7;
int switch2 = 8;
int switch3 = 9;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////Variables you must change according to your values/////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Add your data: SSID + KEY + host + location + id + password
//////////////////////////////////////////////
const char SSID_ESP[] = "iLinkHackathon";         //Give EXACT name of your WIFI
const char SSID_KEY[] = "Welcome1234@$$";             //Add the password of that WIFI connection
const char* host = "diabolic-chamber.000webhostapp.com";  //Add the host without "www" Example: electronoobs.com
String NOOBIX_id = "id14067095_esp8266";                     //This is the ID you have on your database, I've used 99999 becuase there is a maximum of 5 characters
String NOOBIX_password = "%d>S/b24ndK{+@dX";               //Add the password from the database, also maximum 5 characters and only numerical values
String location_url = "/TX.php?id=";            //location of your PHP file on the server. In this case the TX.php is directly on the first folder of the server
                                                //If you have the files in a different folder, add thas as well, Example: "/ESP/TX.php?id="     Where the folder is ESP 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//Used variables in the code
String url = "";
String URL_withPacket = "";    
unsigned long multiplier[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
//MODES for the ESP
const char CWMODE = '1';//CWMODE 1=STATION, 2=APMODE, 3=BOTH
const char CIPMUX = '1';//CWMODE 0=Single Connection, 1=Multiple Connections


//Define the used functions later in the code, thanks to Kevin Darrah, YT channel:  https://www.youtube.com/user/kdarrah1234
boolean setup_ESP();
boolean read_until_ESP(const char keyword1[], int key_size, int timeout_val, byte mode);
void timeout_start();
boolean timeout_check(int timeout_ms);
void serial_dump_ESP();
boolean connect_ESP();
void connect_webhost();
unsigned long timeout_start_val;
char scratch_data_from_ESP[20];//first byte is the length of bytes
char payload[200];
byte payload_size=0, counter=0;
char ip_address[16];


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Variable to SEND to the DATABASE
bool sent_bool_1 = 0;
bool sent_bool_2 = 0;
bool sent_bool_3 = 0;
int  sent_nr_1 = 0;
int  sent_nr_2 = 0;
int  sent_nr_3 = 0;
int  sent_nr_4 = 0;
int  sent_nr_5 = 0;

//Variable RECEIVED from the DATABASE
bool received_bool_1 = 0;
bool received_bool_2 = 0;
bool received_bool_3 = 0;
bool received_bool_4 = 0;
bool received_bool_5 = 0;
int  received_nr_1 = 0;
int  received_nr_2 = 0;
int  received_nr_3 = 0;
int  received_nr_4 = 0;
int  received_nr_5 = 0;
String received_text = "";


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////



//Store received chars in this variables
char t1_from_ESP[5];  //For time from web
char d1_from_ESP[2];  //For received_bool_2
char d2_from_ESP[2];  //For received_bool_2
char d3_from_ESP[2];  //For received_bool_3
char d4_from_ESP[2];  //For received_bool_4
char d5_from_ESP[2];  //For received_bool_5
char d9_from_ESP[6];  //For received_nr_1
char d10_from_ESP[6]; //For received_nr_2
char d11_from_ESP[6]; //For received_nr_3
char d12_from_ESP[6]; //For received_nr_4
char d13_from_ESP[6]; //For received_nr_5
char d14_from_ESP[300]; //For received_text 


//DEFINE KEYWORDS HERE
const char keyword_OK[] = "OK";
const char keyword_Ready[] = "Ready";
const char keyword_no_change[] = "no change";
const char keyword_blank[] = "#&";
const char keyword_ip[] = "192.";
const char keyword_rn[] = "\r\n";
const char keyword_quote[] = "\"";
const char keyword_carrot[] = ">";
const char keyword_sendok[] = "SEND OK";
const char keyword_linkdisc[] = "Unlink";

const char keyword_t1[] = "t1";
const char keyword_b1[] = "b1";
const char keyword_b2[] = "b2";
const char keyword_b3[] = "b3";
const char keyword_b4[] = "b4";
const char keyword_b5[] = "b5";
const char keyword_n1[] = "n1";
const char keyword_n2[] = "n2";
const char keyword_n3[] = "n3";
const char keyword_n4[] = "n4";
const char keyword_n5[] = "n5";
const char keyword_n6[] = "n6";
const char keyword_doublehash[] = "##";


SoftwareSerial ESP8266(ESP8266_RX, ESP8266_TX);// rx tx



void setup(){//        SETUP     START

  lcd.init();                 //Init the LCD
  lcd.backlight();            //Activate backlight   

  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);

  
  //Pin Modes for ESP TX/RX
  pinMode(ESP8266_RX, INPUT);
  pinMode(ESP8266_TX, OUTPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  pinMode(Potentiometer_1, INPUT);
  pinMode(Potentiometer_2, INPUT);
  pinMode(Potentiometer_3, INPUT);
  pinMode(Potentiometer_4, INPUT);

  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
    
  
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);

  if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
     pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
 
    // Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);
  

  
  ESP8266.begin(9600);//default baudrate for ESP
  ESP8266.listen();//not needed unless using other software serial instances
  Serial.begin(9600); //for status and debug
  
  delay(2000);//delay before kicking things off
  setup_ESP();//go setup the ESP 
 
}




void loop(){

  // Make sure to call update as fast as possible
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");
 
        tsLastReport = millis();
    }

    val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);
/* uncomment this to get temperature in farenhite
Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();
*/

  val =digitalRead(sensorPin);
  Serial.println (val);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val==HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  
  sent_nr_1 = analogRead(Potentiometer_1);
  sent_nr_1 = analogRead(Potentiometer_2);
  sent_nr_1 = analogRead(Potentiometer_3);
  sent_nr_1 = analogRead(Potentiometer_4);
  
  sent_bool_1 = digitalRead(switch1);
  sent_bool_2 = digitalRead(switch2);
  sent_bool_3 = digitalRead(switch3);
  
  send_to_server_1(); 
  digitalWrite(LED1,received_bool_1);
  digitalWrite(LED2,received_bool_2); 
  digitalWrite(LED3,received_bool_3); 
  digitalWrite(LED4,received_bool_4); 
  digitalWrite(LED5,received_bool_5);  

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("N1: "); lcd.print(received_nr_1); lcd.print("  N2: "); lcd.print(received_nr_2);
  lcd.setCursor(0,1);
  lcd.print("N3: "); lcd.print(received_nr_3); lcd.print("  N4: "); lcd.print(received_nr_4);    
  delay(1000);//5 seconds between tries  


  /*
  send_to_server_2();
  digitalWrite(LED1,received_bool_1);
  digitalWrite(LED2,received_bool_2); 
  digitalWrite(LED3,received_bool_3); 
  digitalWrite(LED4,received_bool_4); 
  digitalWrite(LED5,received_bool_5);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("N1: "); lcd.print(received_nr_1); lcd.print("  N2: "); lcd.print(received_nr_2);
  lcd.setCursor(0,1);
  lcd.print("N3: "); lcd.print(received_nr_3); lcd.print("  N4: "); lcd.print(received_nr_4);  
  delay(1000);
  send_to_server_3();
  digitalWrite(LED1,received_bool_1);
  digitalWrite(LED2,received_bool_2); 
  digitalWrite(LED3,received_bool_3); 
  digitalWrite(LED4,received_bool_4); 
  digitalWrite(LED5,received_bool_5);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("N1: "); lcd.print(received_nr_1); lcd.print("  N2: "); lcd.print(received_nr_2);
  lcd.setCursor(0,1);
  lcd.print("N3: "); lcd.print(received_nr_3); lcd.print("  N4: "); lcd.print(received_nr_4);  
  delay(1000);
  send_to_server_4();
  digitalWrite(LED1,received_bool_1);
  digitalWrite(LED2,received_bool_2); 
  digitalWrite(LED3,received_bool_3); 
  digitalWrite(LED4,received_bool_4); 
  digitalWrite(LED5,received_bool_5);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("N1: "); lcd.print(received_nr_1); lcd.print("  N2: "); lcd.print(received_nr_2);
  lcd.setCursor(0,1);
  lcd.print("N3: "); lcd.print(received_nr_3); lcd.print("  N4: "); lcd.print(received_nr_4);   
  delay(1000);
  */

  
  send_to_server_5();
  digitalWrite(LED1,received_bool_1);
  digitalWrite(LED2,received_bool_2); 
  digitalWrite(LED3,received_bool_3); 
  digitalWrite(LED4,received_bool_4); 
  digitalWrite(LED5,received_bool_5);
  

  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(received_text);
  
  delay(1000);

}//End of the main loop
