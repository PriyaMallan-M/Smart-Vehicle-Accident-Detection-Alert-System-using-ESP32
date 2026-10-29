#define RAIN_PIN A0
#define TURBIDITY_PIN A1

void setup()
{
  Serial.begin(9600);
}  

void loop()
{
  int rain = analogRead(RAIN_PIN);
  int turbidity = analogRead(TURBIDITY_PIN);

  Serial.print(rain);
  Serial.print(",");
  Serial.println(turbidity);

  delay(1000);
}