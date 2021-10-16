// This utility is designed to write UTC to our Inkplate RTC
// You will have to take in to account, in your other code, handling timezones, DST / summer time, etc.

// NOTE: This project depends upon these libraries:
// NTPClient
// Inkplate-Arduino-library
// Time by Michael Margolis


/***** Configuration Items *****/
const char * wifi_ssid = "YOUR_WIFI_SSID";      // Your WiFi SSID
const char * wifi_pass = "YOUR_WIFI_PASSWORD";  // Your WiFi password
const char * ntp_server = "pool.ntp.org";    // Set to a local NTP pool server

/***** Includes *****/
#include <Inkplate.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <WiFiUdp.h>

/***** Globals *****/
Inkplate display(INKPLATE_1BIT);

/***** Code *****/
void setup() {
  /* Display setup */
  display.begin();
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.setTextColor(BLACK, WHITE);

  /* Establish connection */
  display.println("Connecting to WiFi");
  WiFi.begin(wifi_ssid, wifi_pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    display.print('.');
    display.partialUpdate();
  }
  display.println("Connected to WiFi");

  /* NTP */
  display.println("Pulling NTP");
  display.partialUpdate();
  WiFiUDP ntpUDP;
  NTPClient timeClient(ntpUDP, ntp_server);
  timeClient.begin();
  timeClient.update();
  timeClient.end();

  /* RTC */
  time_t et = timeClient.getEpochTime();
  display.rtcSetTime(hour(et), minute(et), second(et));
  display.rtcSetDate(weekday(et), day(et), month(et), year(et));
  
  display.println("Completed NTP query and RTC set");
}

void loop() {
    display.print(display.rtcGetHour());
    display.print(":");
    display.print(display.rtcGetMinute());
    display.print(":");
    display.print(display.rtcGetSecond());
    display.print(" -- ");
    display.print(display.rtcGetDay());
    display.print("/");
    display.print(display.rtcGetMonth());
    display.print("/");
    display.print(display.rtcGetYear());
    display.println("");
    display.partialUpdate();
    delay(15000);
}
