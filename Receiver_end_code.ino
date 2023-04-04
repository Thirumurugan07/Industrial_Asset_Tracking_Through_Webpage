// Here ESP32 Node MCU is used since it has in-built Wifi Module
#include <WiFi.h>
#include "ThingSpeak.h"
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch(); // initialize RCSwitch library
int rx_pin = 17; 
const int BUZZ_PIN = 5; // Buzzer is connected to GPIO PIN 5
const char *ssid =  "YOUR_WIFI_SSID";     
const char *pass =  "YOUR_WIFI_PASSWORd";
const char* server = "api.thingspeak.com";
WiFiClient client;
unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "Write_AP_Key_of_your_specific_field";
unsigned long lastTime = 0;
unsigned long timerDelay = 30000; // Delay for 30secs


void setup() {
  Serial.begin(9600);  //Initialize serial
  mySwitch.enableReceive(rx_pin); // Set the interrupt number for the receiver
  pinMode(BUZZ_PIN
, OUTPUT);
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, pass); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }
    if (mySwitch.available()) {
    int value = mySwitch.getReceivedValue(); // Get the value of received signal
    if (value == 12345 ) {
     digitalWrite(BUZZ_PIN, HIGH);
     Serial.println("Connected");
     delay(1000);      
     mySwitch.resetAvailable();
    
  }
  else {
    
       digitalWrite(BUZZ_PIN, LOW);
        Serial.println("Not Connected");
        mySwitch.resetAvailable();
   }
    
    }
    else {
             digitalWrite(BUZZ_PIN, LOW);
              Serial.println("No Connections");  
    }

    // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
    // pieces of information in a channel.  Here, we write to field 1.
    int x = ThingSpeak.writeField(myChannelNumber, 1, BUZZ_PIN, myWriteAPIKey);

    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }
}
