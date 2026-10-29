#include <WiFi.h>
#include <ThingESP.h>

ThingESP32 thing("Priya55", "Priya23", "IoTproject5");

int LED = 2;
int Motor = 4;
//int Buzzer = D4;


unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(Motor, OUTPUT);
  //pinMode(Buzzer, OUTPUT);
  thing.SetWiFi("vivo Y22s", "12345678");
  thing.initDevice();
}


String HandleResponse(String query)
{
  if (query == "led on") {
    digitalWrite(LED, 1);
    return "Done: LED Turned ON";
  }

  else if (query == "led off") {
    digitalWrite(LED, 0);
    return "Done: LED Turned OFF";
  }
  

  else if (query == "led status"){ 
    return digitalRead(LED) ? "LED is OFF" : "LED is ON";
  // return "Your query was invalid..";
  }

   else if (query == "motor on") {
    digitalWrite(Motor, 1);
    return "Done: motor Turned ON";
  }

  else if (query == "motor off") {
    digitalWrite(Motor, 0);
    return "Done: motor Turned OFF";
  }
  

  else if (query == "motor status"){ 
    return digitalRead(Motor) ? "motor is OFF" : "motor is ON";
   //return "Your query was invalid..";
  }
  else
  {
    return "Your query was invalid..";
  }

}


void loop()
{
  thing.Handle();

}