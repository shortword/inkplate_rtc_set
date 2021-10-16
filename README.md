# inkplate_rtc_set
Inkplate (Arduino) Utility to set the RTC from NTP

## Description

This is a simple Arduino sketch to set the RTC on your inkplate. To get it working, you need to:
1. Replace wifi_ssid and wifi_pass near the top of the sketch
1. Install the libraries mentions at the top of the sketch
1. (As of this writing) You MAY need to enable RTC support in the Inkplate library

The Inkplate Arduino library doesn't currently support the RTC on the Inkplate 10 board.
Fear not, though, you can find a fork of the library with this integrated at: https://github.com/shortword/Inkplate-Arduino-library
I will be submitting a pull request to the upstream project as well.

Build. Flash. Run. Enjoy.