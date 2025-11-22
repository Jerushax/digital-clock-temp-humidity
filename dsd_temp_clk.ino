//# Digital Clock with Temperature & Humidity Display  
// **By R. Jerusha – DSD Project**
#include <Wire.h>
#include <RTClib.h>
#include <TM1637Display.h>
#include <DHT.h>

#define CLK 6
#define DIO 7
#define DHTPIN 4
#define DHTTYPE DHT11
#define BUTTON_PIN 2  // Push button

TM1637Display display(CLK, DIO);
RTC_DS3231 rtc;
DHT dht(DHTPIN, DHTTYPE);

int mode = 0;  // 0: Time, 1: Temp, 2: Humidity
bool lastButtonState = LOW;

// Custom characters
const uint8_t customC = SEG_A | SEG_F | SEG_E | SEG_D; // For 'C'
const uint8_t customH = SEG_B | SEG_C | SEG_E | SEG_F | SEG_G; // For 'H'

void setup() {
  Wire.begin();
  rtc.begin();
  dht.begin();
  display.setBrightness(7);
  pinMode(BUTTON_PIN, INPUT);

  Serial.begin(9600);
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  // Read push button
  bool currentButtonState = digitalRead(BUTTON_PIN);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    mode = (mode + 1) % 3; // Cycle: 0 → 1 → 2 → 0 ...
    delay(200);            // Debounce delay
  }
  lastButtonState = currentButtonState;

  if (mode == 0) {
    // Show Time
    DateTime now = rtc.now();
    int timeVal = now.hour() * 100 + now.minute();
    display.showNumberDecEx(timeVal, 0b11100000, true); // Colon between HH:MM
    Serial.print("Time: ");
    Serial.print(now.hour());
    Serial.print(":");
    Serial.println(now.minute());

  } else if (mode == 1) {
    // Show Temperature with 'C'
    float temp = dht.readTemperature();
    if (!isnan(temp)) {
      int t = (int)temp;
      uint8_t data[] = {
        display.encodeDigit((t / 10) % 10),
        display.encodeDigit(t % 10),
        0x00,
        customC
      };
      display.setSegments(data);
      Serial.print("Temp: ");
      Serial.print(t);
      Serial.println(" C");
    } else {
      display.showNumberDec(8888);
    }

  } else if (mode == 2) {
    // Show Humidity with 'H'
    float hum = dht.readHumidity();
    if (!isnan(hum)) {
      int h = (int)hum;
      uint8_t data[] = {
        display.encodeDigit((h / 10) % 10),
        display.encodeDigit(h % 10),
        0x00,
        customH
      };
      display.setSegments(data);
      Serial.print("Humidity: ");
      Serial.print(h);
      Serial.println(" %");
    } else {
      display.showNumberDec(8888);
    }
  }

  delay(500); // Smooth refresh
}

