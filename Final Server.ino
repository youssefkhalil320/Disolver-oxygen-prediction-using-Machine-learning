#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Replace with your network credentials
const char* ssid = "realme 8";
const char* password = "saly@naby100";

ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
const int oneWireBus = 4;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

String page = "";
double data; 
float temperatureC = 0;
float amount = 0;
void setup(void){

  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", [](){
    page = "<h1>Sensor to Node MCU Web Server</h1><h2>Tempreture:</h2> <h4>"+String(temperatureC)+"</h4> <h2>Predicted DO:</h2> <h4>"+String(amount)+"</h4>";
    server.send(200, "text/html", page);
  });
  
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  sensors.requestTemperatures(); 
  temperatureC = sensors.getTempCByIndex(0);
  amount = (5.165218500638419)+(-0.01445154*7.88)+(-3.42376732*0.539226)+(0.07387896*116)+(temperatureC*-0.15761718)+(0.303*4.95695377);
  Serial.print(temperatureC);
  Serial.println("ºC");
  delay(5000);
  server.handleClient();
}