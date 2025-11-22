
# Digital Clock with Temperature & Humidity Display  
###  DSD Project

This project implements a **Digital Clock** using an **Arduino Uno**, **DS3231 Real-Time Clock**, **TM1637 4-digit 7-segment display**, and a **DHT11 temperature & humidity sensor**.  
A push button allows the user to toggle between:

- ⏰ **Time (HH:MM)**  
- 🌡️ **Temperature (°C)**  
- 💧 **Humidity (%)**

The TM1637 display is used for its simple interface and minimal wiring, while the DS3231 ensures highly accurate timekeeping. The DHT11 sensor adds environmental monitoring to enhance the functionality of the project.

---

## 🔧 Features
- Real-time clock with precise DS3231 RTC
- Temperature and humidity display using DHT11
- TM1637 display with brightness control
- Push button toggling between different display modes
- Non-blocking code using `millis()` for smooth operation
- Easy to build, ideal for students and hobbyists

---

## 🧰 Components Used
- Arduino UNO  
- TM1637 4-Digit Display  
- DS3231 RTC Module  
- DHT11 Temperature & Humidity Sensor  
- Push Button + 10kΩ resistor  
- Jumper Wires  
- USB Cable / Power Supply  

---

## 🔌 Circuit Connections
### **TM1637**
| TM1637 Pin | Arduino Pin |
|------------|-------------|
| VCC        | 5V          |
| GND        | GND         |
| DIO        | D7          |
| CLK        | D6          |

### **DS3231 RTC**
| DS3231 Pin | Arduino Pin |
|------------|-------------|
| VCC        | 5V          |
| GND        | GND         |
| SDA        | A4          |
| SCL        | A5          |

### **DHT11 Module**
| DHT11 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| GND       | GND         |
| DATA      | D2          |

### **Push Button**
- One leg → D3  
- Other leg → GND  
- 10k resistor → D3 to 5V (pull-up)

---

## ▶️ **How It Works**
1. The Arduino reads time from the DS3231.
2. It reads temperature and humidity from the DHT11.
3. The display shows **time**, **temperature**, or **humidity** based on the push button.
4. The output updates every second without freezing the processor.

---

## 🧪 Future Improvements
- Add alarm functionality  
- Auto-brightness using LDR  
- Bluetooth or WiFi updates  
- Weather forecast using online APIs  

---
