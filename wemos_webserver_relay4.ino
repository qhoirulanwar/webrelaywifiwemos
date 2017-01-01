#include <ESP8266WiFi.h>
 
const char* ssid = "Nama Wifi yang tersedia";
const char* password = "Masukan Wifi password";

int ledPin1 = D1;
int ledPin2 = D2;
int ledPin3 = D3;
int ledPin4 = D4;
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
 
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
//  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  if (request.indexOf("/LED1=ON") != -1) {
    digitalWrite(ledPin1, HIGH);
  } 
  if (request.indexOf("/LED1=OFF") != -1){
    digitalWrite(ledPin1, LOW);
  }
  if (request.indexOf("/LED2=ON") != -1) {
    digitalWrite(ledPin2, HIGH);
  } 
  if (request.indexOf("/LED2=OFF") != -1){
    digitalWrite(ledPin2, LOW);
  }
  if (request.indexOf("/LED3=ON") != -1) {
    digitalWrite(ledPin3, HIGH);
  } 
  if (request.indexOf("/LED3=OFF") != -1){
    digitalWrite(ledPin3, LOW);
  }
  if (request.indexOf("/LED4=ON") != -1) {
    digitalWrite(ledPin4, HIGH);
  } 
  if (request.indexOf("/LED4=OFF") != -1){
    digitalWrite(ledPin4, LOW);
  }
  if (request.indexOf("/LED=ONALL") != -1) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
  } 
  if (request.indexOf("/LED=OFFALL") != -1){
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }


  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
//  dapatkanStatusButton(client);
 
  client.print("Lampu 1 Sedang ");
    if (digitalRead(D1)) {
        client.println("Menyala<br>");
    }
    else {
        client.println(" Mati<br>");
    }
      client.print("Lampu 2 Sedang ");
    if (digitalRead(D2)) {
        client.println("Menyala<br>");
    }
    else {
        client.println(" Mati<br>");
    }
      client.print("Lampu 3 Sedang ");
    if (digitalRead(D3)) {
        client.println("Menyala<br>");
    }
    else {
        client.println(" Mati<br>");
    }
      client.print("Lampu 4 Sedang ");
    if (digitalRead(D4)) {
        client.println("Menyala<br>");
    }
    else {
        client.println(" Mati<br>");
    }
client.println("<br>");
  client.println("Klik Untuk <a href=\"/LED1=ON\">Menyalakan</a> Lampu pin 1 ON<br>");
  client.println("Klik Untuk <a href=\"/LED1=OFF\">Matikan</a> Lampu pin 1 OFF<br>");
client.println("<br>");
  client.println("Klik Untuk <a href=\"/LED2=ON\">Menyalakan</a> Lampu pin 2 ON<br>");
  client.println("Klik Untuk <a href=\"/LED2=OFF\">Matikan</a> Lampu pin 2 OFF<br>");
client.println("<br>");
  client.println("Klik Untuk <a href=\"/LED3=ON\">Menyalakan</a> Lampu pin 3 ON<br>");
  client.println("Klik Untuk <a href=\"/LED3=OFF\">Matikan</a> Lampu pin 3 OFF<br>");
client.println("<br>");
  client.println("Klik Untuk <a href=\"/LED4=ON\">Menyalakan</a> Lampu pin 4 ON<br>");
  client.println("Klik Untuk <a href=\"/LED4=OFF\">Matikan</a> Lampu pin 4 OFF<br>");
client.println("<br>");
  client.println("Klik Untuk <a href=\"/LED=ONALL\">Menyalakan</a> Semua Lampu<br>");
  client.println("Klik Untuk <a href=\"/LED=OFFALL\">Matikan</a> Semua Lampu<br>");
  client.println("</html>");
 
//  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
