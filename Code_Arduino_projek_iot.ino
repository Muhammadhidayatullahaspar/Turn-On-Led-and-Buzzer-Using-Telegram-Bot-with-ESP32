#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>


// Replace with your network credentials
const char* ssid = "realme 6";
const char* password = "Nryalife";

// Initialize Telegram BOT
#define BOTtoken "1650304104:AAGOqlShHWxAsV_AQlCQtmY2CBUVdSFzesw"  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "1409831210"

#ifdef ESP8266
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

const int ledPin1 = 2;
const int ledPin2 = 5;
const int ledPin3 = 4;
bool ledState1 = LOW;
bool ledState2 = LOW;
bool ledState3 = LOW;
const int Pinalarm1 = 14;
bool Alarm1 = LOW;
const int Pinalarm2 = 26;
bool Alarm2 = LOW;
// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Petunjuk di bawah ini.\n\n";
      welcome += "Lampu 1 nyala untuk menyalakan lampu 1 \n";
      welcome += "Lampu 1 mati untuk matikan lampu 1 \n";
      welcome += "Cek lampu 1 untuk mengecek kondisi lampu 1 \n";

         welcome += "Lampu 2 nyala untuk menyalakan lampu 2 \n";
      welcome += "Lampu 2 mati untuk matikan lampu 2 \n";
      welcome += "Cek lampu 2 untuk mengecek kondisi lampu 2 \n";

         welcome += "Lampu 3 nyala untuk menyalakan lampu 3 \n";
      welcome += "Lampu 3 mati untuk matikan lampu 3 \n";
      welcome += "Cek lampu 3 untuk mengecek kondisi lampu 3 \n";

          welcome += "Alarm 1 bunyi untuk membunyikan alarm 1 \n";
      welcome += "Alarm 1 mati untuk mematikan alarm 1 \n";
      welcome += "Cek alarm 1 untuk mengecek kondisi alarm \n";

        welcome += "Alarm 2 bunyi untuk membunyikan alarm 2 \n";
      welcome += "Alarm 2 mati untuk mematikan alarm 2 \n";
      welcome += "Cek alarm 2 untuk mengecek kondisi alarm \n";

        welcome += "Semua lampu nyala untuk menyalakan semua lampu \n";
      welcome += "Semua lampu mati untuk matikan semua lampu \n";
      welcome += "Semua alarm bunyi untuk membunyikan semua alarm \n";
      welcome += "Semua alarm mati untuk mematikan semua alarm \n";
       welcome += "TERIMA KASIH \n";
      bot.sendMessage(chat_id, welcome, "");
    }
//LED1
    if (text == "Lampu 1 nyala") {
      bot.sendMessage(chat_id, "Lampu 1 menyala", "");
      ledState1 = HIGH;
      digitalWrite(ledPin1, ledState1);
    }
    
    if (text == "Lampu 1 mati") {
      bot.sendMessage(chat_id, "Lampu 1 mati", "");
      ledState1 = LOW;
      digitalWrite(ledPin1, ledState1);
    }
    
    if (text == "Cek lampu 1") {
      if (digitalRead(ledPin1)){
        bot.sendMessage(chat_id, "Lampu 1 menyala", "");
      }
      else{
        bot.sendMessage(chat_id, "Lampu 1 mati", "");
      }
    }

//LED2
       if (text == "Lampu 2 nyala") {
      bot.sendMessage(chat_id, "Lampu 2 menyala", "");
      ledState2 = HIGH;
      digitalWrite(ledPin2, ledState2);
    }
    
    if (text == "Lampu 2 mati") {
      bot.sendMessage(chat_id, "Lampu 2 mati", "");
      ledState2 = LOW;
      digitalWrite(ledPin2, ledState2);
    }
    
    if (text == "Cek lampu 2") {
      if (digitalRead(ledPin2)){
        bot.sendMessage(chat_id, "Lampu 2 menyala", "");
      }
      else{
        bot.sendMessage(chat_id, "Lampu 2 mati", "");
      }
    }


//LED3
       if (text == "Lampu 3 nyala") {
      bot.sendMessage(chat_id, "Lampu 3 menyala", "");
      ledState3 = HIGH;
      digitalWrite(ledPin3, ledState3);
    }
    
    if (text == "Lampu 3 mati") {
      bot.sendMessage(chat_id, "Lampu 3 mati", "");
      ledState3 = LOW;
      digitalWrite(ledPin3, ledState3);
    }
    
    if (text == "Cek lampu 3") {
      if (digitalRead(ledPin3)){
        bot.sendMessage(chat_id, "Lampu 3 menyala", "");
      }
      else{
        bot.sendMessage(chat_id, "Lampu 3 mati", "");
      }
    }

// alarm 
 if (text == "Alarm 1 bunyi") {
      bot.sendMessage(chat_id, "Alarm 1 bunyi", "");
      Alarm1 = HIGH;
      digitalWrite(Pinalarm1, Alarm1);
    }
  if (text == "Alarm 1 mati") {
      bot.sendMessage(chat_id, "Alarm 1 mati", "");
      Alarm1 = LOW;
      digitalWrite(Pinalarm1, Alarm1);
    }
   if (text == "Cek alarm 1") {
      if (digitalRead(Pinalarm1)){
        bot.sendMessage(chat_id, "Alarm 1 bunyi", "");
      }
      else{
        bot.sendMessage(chat_id, "Alarm 1 mati", "");
      }
   }

 if (text == "Alarm 2 bunyi") {
      bot.sendMessage(chat_id, "Alarm 2 bunyi", "");
      Alarm2 = HIGH;
      digitalWrite(Pinalarm2, Alarm2);
    }
  if (text == "Alarm 2 mati") {
      bot.sendMessage(chat_id, "Alarm mati", "");
      Alarm2 = LOW;
      digitalWrite(Pinalarm2, Alarm2);
    }
    if (text == "Cek alarm 2") {
      if (digitalRead(Pinalarm2)){
        bot.sendMessage(chat_id, "Alarm 2 bunyi", "");
      }
      else{
        bot.sendMessage(chat_id, "Alarm 2 mati", "");
      }
   }
 

//Semua
           if (text == "Semua lampu nyala") {
      bot.sendMessage(chat_id, "semua lampu menyala", "");
      ledState1 = HIGH;
      ledState2 = HIGH;
      ledState3 = HIGH;
      digitalWrite(ledPin1, ledState1);
      digitalWrite(ledPin2, ledState2);
      digitalWrite(ledPin3, ledState3);
    }
    
    if (text == "Semua lampu mati") {
      bot.sendMessage(chat_id, "semua lampu mati", "");
      ledState1 = LOW;
      ledState2 = LOW;
      ledState3 = LOW;
      digitalWrite(ledPin1, ledState1);
      digitalWrite(ledPin2, ledState2);
      digitalWrite(ledPin3, ledState3);
    }

// alarm
       if (text == "Semua alarm bunyi") {
      bot.sendMessage(chat_id, "semua alarm menyala", "");
     Alarm1 = HIGH;
      digitalWrite(Pinalarm1, Alarm1);
      Alarm2 = HIGH;
      digitalWrite(Pinalarm2, Alarm2);
    }
    
    if (text == "Semua alarm mati") {
      bot.sendMessage(chat_id, "semua alarm mati", "");
   Alarm1 = LOW;
      digitalWrite(Pinalarm1, Alarm1);
   Alarm2 = LOW;
      digitalWrite(Pinalarm2, Alarm2);
    }
  }
}
  void setup() {
  Serial.begin(115200);

  #ifdef ESP8266
    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
    client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  #endif

  pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, ledState1);
    pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, ledState2);
    pinMode(ledPin3, OUTPUT);
  digitalWrite(ledPin3, ledState3);
    pinMode(Pinalarm1, OUTPUT);
  digitalWrite(Pinalarm1, Alarm1);
   pinMode(Pinalarm2, OUTPUT);
  digitalWrite(Pinalarm2, Alarm2);
  
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
