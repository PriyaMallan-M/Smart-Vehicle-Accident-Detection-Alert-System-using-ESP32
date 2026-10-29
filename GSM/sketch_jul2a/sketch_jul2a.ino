#include <SoftwareSerial.h>

SoftwareSerial gsm(2,3);   

void setup()
{
  Serial.begin(9600);
  gsm.begin(9600);

  delay(5000);

  Serial.println("Initializing GSM...");

  gsm.println("AT");
  delay(1000);

  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.print("AT+CMGS=\"+918807271185\"\r");
  delay(1000);

  gsm.print("Hello! GSM Module is Working.");

  delay(1000);

  gsm.write(26);   \

  Serial.println("SMS Command Sent");
}

void loop()
{
  while (gsm.available())
  {
    Serial.write(gsm.read());
  }
}