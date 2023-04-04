# Industrial_Asset_Tracking_using_IoT
This project makes use of rf technology along with IOT to achieve this system track location of objects, goods, personnel within a building or any facility. The system has the capability to pinpoint the location of any entity to exact room it is currently located in. 

RF modules are used for transmitting and receiving data because of its high volume of application than IR. RF signals travel between transmitter and receiver despite any obstruction. It operates at a specific frequency of 433MHz. when the frequency range between transmitter module and receiver module increases above 433MHz (i.e. when
transmitter moves far away from receiver), the receiver is alerted with a buzzer sound and an alert message.

ThingSpeak is an open-source IOT platform and API to store and retrieve data. ThingSpeak enables developers to store the data and information like sensor values, location of an asset with periodic status updates. In the proposed system, a channel has been created named “IOT Asset Tracking System” which provides information about the asset condition through frequency range and also locates the asset on map.

The transmitter kit is placed with the asset to be tracked. The central nano micro controller is connected with RF transmitter.The RF transmitter modules at transmitter phasecommunicate with the RF receiver module at receiver phase continuously by transmitting radio signals. The maximum threshold frequency range is 433MHz. When the transmitter moves away from the receiver, the signal strength between them decreases and buzzer is turned on on the receiver side as an alert message.

The receiver kit is with the person monitoring the asset. The central nano micro controller(ESP32) is connected with  RF receiver module and buzzer.
