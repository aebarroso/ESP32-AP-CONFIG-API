# Repository description (GitHub “About” + README intro)

ESP32-AP-CONFIG-API is an ESP-IDF reference project that turns an ESP32 into a Wi-Fi Access Point (captive portal style) so you can configure the device from a phone or laptop.
It serves a lightweight web UI where you set Wi-Fi credentials and basic device settings, stores them persistently (NVS), then switches to STA mode and connects to the configured network. Once online, the device calls a public API (weather + moon phase) and can display/log the results (serial output by default, easy to extend to OLED/MQTT/HTTP).

## Highlights
 
- ESP-IDF Wi-Fi AP → configuration portal → STA flow

- Embedded web UI (HTML/CSS/JS served from flash: SPIFFS/LittleFS or embedded binaries)

- Settings persistence with NVS

- Simple HTTP client to fetch weather and moon phases

- Clean, modular structure meant as a reusable base for IoT products

## Use cases

- “First-boot provisioning” for IoT devices

- Field configuration without app installation

- A clean starting point for sensors/dashboards
