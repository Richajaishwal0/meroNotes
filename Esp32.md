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
