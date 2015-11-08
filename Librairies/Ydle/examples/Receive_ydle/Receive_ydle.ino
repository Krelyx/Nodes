/* Author : Xylerk
* Description : 
* Licence : CC-BY-SA
*/

#include <TimerOne.h>
#include "Ydle.h"
#define RX_PIN 12
#define TX_PIN 10
#define DELAY_SEND 15000
// Init de la node, 
ydle y(RX_PIN, TX_PIN);

extern bool isRead;
extern uint8_t receivednid ;

unsigned long last_send, cur_time;

void setup()
{
	Serial.begin(115200);
        Serial.println("Test");
        y.init_timer();

	cur_time = millis();
	last_send = cur_time;
}

void loop()
{
    y.receive();
    if(y.initialized()){
	cur_time = millis();
	if( cur_time - last_send >= DELAY_SEND)
        {
            last_send = cur_time;
        }
         if (y.isCmdON() &&  isRead == false)
        {
            isRead = true;
            Serial.println("Command On received!");
            Serial.print("Actuator: ");
            Serial.println(receivednid);  
        }
        if (y.isCmdOFF() &&  isRead == false)
        {
            isRead = true;
            Serial.println("Command OFF received!");
            Serial.print("Actuator: ");
            Serial.println(receivednid);  
        }
        if (y.isCmdSet() &&  isRead == false)
        {
            isRead = true;
            Serial.println("Command SET received!");
            Serial.print("Value to set: ");
            Serial.println(receivednid);  
        }
        if (y.isCmdAskData() &&  isRead == false)
        {
            isRead = true;
            Serial.println("Command AskData received!");
            Serial.println("Ok I send my data ");
        }    
    }
}


