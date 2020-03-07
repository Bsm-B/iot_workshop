/**
 * 
 * @author Bousselmi Bessem 
 * Sources for this can be found at:
 * https://github.com/bassouma21001/iot_workshop
 * 
 */
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <dht.h>


#define DHT11_PIN 4
#define RELAY 5
#define PORT 80

IPAddress staticIP(10, 10, 10, 10);
IPAddress gateway(10, 10, 10, 1);
IPAddress subnet(255, 0, 0, 0);

ESP8266WebServer server(PORT);
dht DHT;

void setup(){
    Serial.begin(9600);
    pinMode(RELAY, OUTPUT);
    /*  AP
    WiFi.softAP("ESP IOT", "12345678");
    WiFi.softAPConfig(staticIP, gateway, subnet);*/
    WiFi.softAPdisconnect (true);
    WiFi.begin("Lolipop", "test0000");
    WiFi.hostname("ESPIOT");
    while (WiFi.status() != WL_CONNECTED) {  //Wait for connection

    delay(500);
    Serial.println("Waiting to connect...");

    }
    Serial.print("IP Address of network: ");
    Serial.println(WiFi.localIP());
    server.on("/", HTTP_GET, handleRoot);
    server.on("/led", HTTP_GET, Control_led);
    server.on("/dht", HTTP_GET, read_dht);
    server.onNotFound(handleNotFound);
    server.begin();
        
}

void loop(){
  server.handleClient();
}

void Control_led(){
    digitalWrite(RELAY, !digitalRead(RELAY));
    String state;
    digitalRead(RELAY) == HIGH ? state = "ON" : state = "OFF";
    server.send(200, "text/plain", state);
}

void read_dht(){
   int chk = DHT.read11(DHT11_PIN);
   String Data = "{\"DH\": {\"T\": "+ (String)DHT.temperature + ", \"H\": " + (String)DHT.humidity + "}}";
  String Data2 = "Temperature " + (String)DHT.temperature + "Humidity" + (String)DHT.humidity;
   server.send(200, "text/plain", Data);
}

void handleRoot(){
  server.send(200, "text/html", "<h1> Welcome to Iot Workshop <3 </h1>");
}

void handleNotFound() {
  server.send(404, "text/plain", "404: Not found");
}
