#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "AdventureLearning_5G";
const char* password = "Adv@cbe123";

String writeAPI = "H19EWXFYTI6M0D7E";

HardwareSerial mySerial(2);

void setup()
{
  Serial.begin(115200);

  mySerial.begin(9600, SERIAL_8N1, 16, 17);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
}

void loop()
{
  if (mySerial.available())
  {
    String data = mySerial.readStringUntil('\n');

    int commaIndex = data.indexOf(',');

    if (commaIndex > 0)
    {
      int rain = data.substring(0, commaIndex).toInt();
      int turbidity = data.substring(commaIndex + 1).toInt();

      Serial.print("Rain: ");
      Serial.print(rain);
      Serial.print("  Turbidity: ");
      Serial.println(turbidity);

      if (WiFi.status() == WL_CONNECTED)
      {
        HTTPClient http;

        String url =
          "http://api.thingspeak.com/update?api_key=" +
          writeAPI +
          "&field1=" + String(rain) +
          "&field2=" + String(turbidity);

        http.begin(url);
        http.GET();
        http.end();
      }
    }
  }

  delay(2000); // ThingSpeak minimum interval
}