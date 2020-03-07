/**
 * 
 * @author Bousselmi Bessem 
 * Sources for this can be found at:
 * https://github.com/bassouma21001/iot_workshop
 * 
 */
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define RELAY 5
#define PORT 80
IPAddress staticIP(10, 10, 10, 10);
IPAddress gateway(10, 10, 10, 1);
IPAddress subnet(255, 0, 0, 0);

ESP8266WebServer server(PORT);

void setup(){
    pinMode(RELAY, OUTPUT);
    WiFi.softAP("ESP IOT", "12345678");
    WiFi.softAPConfig(staticIP, gateway, subnet);
    
    server.on("/", HTTP_GET, handleRoot);
    server.on("/control", HTTP_GET, handleControl);
    server.onNotFound(handleNotFound);
    server.begin();
        
}

void loop(){
  server.handleClient();
}

void handleControl(){
    if (server.arg("q") == "OK") {
    digitalWrite(RELAY, !digitalRead(RELAY));
    String state;
    digitalRead(RELAY) == HIGH ? state = "ON" : state = "OFF";
    server.send(200, "text/plain", state);
  }
}

void handleRoot(){
  server.send(200, "text/html", "<h1> Welcome to Iot Workshop <3 </h1>");
}

void handleNotFound() {
  server.send(404, "text/plain", "404: Not found");
}
