/**
 * 
 * @author Bousselmi Bessem 
 * Sources for this can be found at:
 * https://github.com/bassouma21001/iot_workshop
 * 
 */
 
#include <dht.h>

dht DHT;

#define DHT11_PIN 5

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}
