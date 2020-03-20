#include <ESP8266WebServer.h>//ketab khane web server
#include <ESP8266WiFi.h>
#define ledpin 5
ESP8266WebServer server(80);

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
WiFi.mode(WIFI_AP_STA);
WiFi.softAP("mohammadES","123456789");
WiFi.begin("AndroidShare_9141","941a5577c57b");
while(WiFi.status() != WL_CONNECTED){
  delay(5000);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected to Domaino");
Serial.println("Ip Address: ");
Serial.println(WiFi.localIP());
server.on("/",helloserver);
server.on("/off",ledoff);
server.on("/on",ledon);
server.onNotFound(notfound);
server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
delay(50);
}
void ledon(void){
  digitalWrite(ledpin,HIGH);
  server.send(200,"text/html","Ok Led is On");
}
void ledoff(void){
   digitalWrite(ledpin,LOW);
  server.send(200,"text/html","Ok Led is OFF");
}
void notfound(void){
   
  server.send(404,"text/html","Error");
}
void helloserver(void){
  
  server.send(200,"text/html","hello i am ESP8266 nod");
}
