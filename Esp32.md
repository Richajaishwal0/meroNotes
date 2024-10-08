## We will discuss about the esp32 with cam module in detail with its various applications.
# Here are some useful packages that are used for esp32
```bash
#include "WiFi.h"
```
### Description
This library provides the function to connect the networks, and manage Wi-Fi settings.<hr>
### Some common functions used are:
- WiFi.begin(ssid, password): Connects the ESP32 to a Wi-Fi network.
- WiFi.scanNetworks(): Scans for available Wi-Fi networks.
- WiFi.status(): Returns the connection status (e.g., WL_CONNECTED).
- WiFi.localIP(): Returns the local IP address of the ESP32.
# Notes
Encryption types:
It refers to the method used by the Wi-Fi network to          protect data sent between devices.
Common types are:
  1. WIFI_AUTH_OPEN: No encryption (an open network).
  2. WIFI_AUTH_WEP: WEP encryption (outdated and insecure).
  3. WIFI_AUTH_WPA_PSK: WPA encryption with pre-shared key.
  4. WIFI_AUTH_WPA2_PSK: WPA2 encryption with pre-shared key (commonly 
    used).
  5. WIFI_AUTH_WPA_WPA2_PSK: Mixed WPA/WPA2 mode.
```bash
#include "BluetoothSerial.h"
```
###  Description
It helps in classic bluetooth communication.
### Some common functions used are:
- BluetoothSerial.begin(name): Starts Bluetooth with the specified name.
- BluetoothSerial.available(): Checks if data is available to read.
- BluetoothSerial.read(): Reads data from the Bluetooth connection.
- BluetoothSerial.write(data): Sends data over Bluetooth.
```bash
#include "ESP32Servo.h"
```
### Description
It controls servo motors with PWM signals.
### Some common functions used are:
- servo.attach(pin): Attaches a servo motor to a specified pin.
- servo.write(angle): Sets the servo to a specific angle (0–180 degrees).
- servo.detach(): Detaches the servo to stop the control signal.

```bash
#include "HTTPClient.h"
```
### Some common functions used are:
- http.begin(url): Starts an HTTP request to a specified URL.
- http.GET(): Sends an HTTP GET request.
- http.POST(data): Sends an HTTP POST request with data.
- http.end(): Ends the HTTP request.
### Description
It sends HTTP requests (GET, POST) to web servers.

```bash
#include "WebServer.h"
```
### Description
It runs a web server on ESP32 to serve web pages.
Some common fucntions used are:
### Some common functions used are:
- server.on(path, handler): Handles a request for a specific URL path.
- server.begin(): Starts the web server.
- server.handleClient(): Handles incoming client requests.
``` bash
#include "ESPAsyncWebServer.h"
```
### Description
It runs asynchronous web servers for handling multiple connections.
### Some common functions used are:
- server.on(path, HTTP_GET, handler): Handles asynchronous HTTP GET requests.
- server.serveStatic(path, fs, directory): Serves static files from a filesystem.
- server.begin(): Starts the asynchronous web server.
  
```bash
#include "Wire.h"
```
### Description
I2C communication for interfacing sensors and peripherals.
### Some common functions used are:
- Wire.begin(): Initializes I2C communication.
- Wire.requestFrom(address, quantity): Requests data from a device.
- Wire.write(data): Sends data to the I2C device.
- Wire.read(): Reads data received from the I2C device.
```bash
#include "SPI.h"
```
### Description
SPI communication for fast data exchange with peripherals.
### Some common functions used are:
- SPI.begin(): Initializes the SPI bus.
- SPI.transfer(data): Transfers data to SPI devices.
- SPI.end(): Terminates the SPI bus.
```bash
#include "Adafruit_Sensor.h"
```
### Description 
Sensor library for interfacing with various Adafruit sensors.
### Some common functions used are:
- sensor.read(): Reads sensor data.
- sensor.begin(): Initializes the sensor.
## Pin configurations
![image](https://github.com/user-attachments/assets/d7ebad26-6bdf-4cb2-959c-d532fa0401e2)

### References for pin configurations of esp32-cam  [link](https://lastminuteengineers.com/esp32-cam-pinout-reference)
### References to program esp32-cam [link](https://randomnerdtutorials.com/getting-started-with-esp32/#esp32-programming-environments)
## Code for esp32 wifi simulation  using LCD
```bash
// Learn about the ESP32 WiFi simulation in
// https://docs.wokwi.com/guides/esp32-wifi

#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //library for LCD

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

#define NTP_SERVER     "pool.ntp.org" //This is the address of the NTP server from which the device will request the current time. The "pool" is a set of publicly available NTP servers.
#define UTC_OFFSET     0
#define UTC_OFFSET_DST 0

void spinner() {
  static int8_t counter = 0;
  const char* glyphs = "\xa1\xa5\xdb";
  LCD.setCursor(15, 1);
  LCD.print(glyphs[counter++]);
  if (counter == strlen(glyphs)) {
    counter = 0;
  }
}

void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    LCD.setCursor(0, 1);
    LCD.println("Connection Err");
    return;
  }

  LCD.setCursor(8, 0);
  LCD.println(&timeinfo, "%H:%M:%S");

  LCD.setCursor(0, 1);
  LCD.println(&timeinfo, "%d/%m/%Y   %Z");
}

void setup() {
  Serial.begin(115200);

  LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("Connecting to ");
  LCD.setCursor(0, 1);
  LCD.print("WiFi ");

  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    spinner();
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.println("Online");
  LCD.setCursor(0, 1);
  LCD.println("Updating time...");

  configTime(UTC_OFFSET, UTC_OFFSET_DST, NTP_SERVER);
}

void loop() {
  printLocalTime();
  delay(250);
}

```
