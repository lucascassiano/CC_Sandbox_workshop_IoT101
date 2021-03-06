#include <WiFi.h>
#include <MQTTClient.h>

const char ssid[] = "MIT";
const char pass[] = "";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

String topic = "sandbox";
String server = "replace.media.mit.edu";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  client.begin(server, net);
  client.onMessage(messageReceived);

  connect();
}

void connect() {
  Serial.print("checking wifi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");

  while (!client.connect("arduino", "try", "try")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("connected!");

  client.subscribe("collective");

}

void loop() {
  client.loop();
  
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  client.publish("/hello", "world");
  
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
}
