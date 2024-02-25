# M5CoreS3BlueBox
Blue Box tone generator for the M5Stack CoreS3

![CoreS3 Blue Box picture](https://raw.githubusercontent.com/r3dfish/M5CoreS3BlueBox/main/images/CoreS3_Blue_Box.jpeg)

## Installing
In the Arduino IDE:
File -> Preferences -> Settings
In Additional Development Board Management URLs, add the following:

https://static-cdn.m5stack.com/resource/arduino/package_m5stack_index.json

Tools -> Boards -> Boards Manager

Install M5Stack

Sketch -> Include Libraries -> Manage Libraries

Install M5CoreS3

## Blue Box

This project is a software implementation of the ProjectMF hardware Blue Box available at https://projectmf.org
It is capable of emulating historical tones for the following signalling systems, as defined by ProjectMF:

  - MF (R1) - The 2600Hz/Multi-frequencysystem that ran Ma Bell's long distance network back in the day
  - DTMF (Touch-Tone, Autovon) - Used on almost every land line phone. A-B-C-D keys used to set call priority on the old Autovon military phone system
  - CCITT #5 (C5, SS5) - Same MF tones as R1 (with a few additional tone pairs for special routing), but uses a different tone sequence for international trunk clear/seize
  - CCITT #4 (C4, SS4) - Unusual 4-bits/digit tone encoding. Used in the UK and other European countries
  - 2600 Dial Pulse - Same method used by Joybubbles (Joe Engressia), Captain Crunch (John Draper), and Bill from New York (Bill Acker) to whistle free calls
  - Pay Phone Modes - Simulates both US and Canadian nickel/dime/quarter payphone coin drop tones (Red Box). Also simulates US pay phone remote operator control tones (Green Box) and 2600Hz prefix control flash
  - R2 (MFC) - Unique forward multi-frequency tone pairs, 2280Hz clear/seize tone, as used in the UK. Replaced the older AC1/AC9 UK dial pulse systems
  - AC1- Old UK tone dial pulse trunk signalling, as used by very early UK telephone "enthusiasts"
  - AC9 - Newer UK dial pulse trunk signalling, as used by early UK telephone "enthusiasts"
  - MTS (Mobile Telephone Service) - Pre-cellular, pre-IMTS mobile phone service tone signalling and dialing
  - IMTS ANI (Improved Mobile Telephone Service ANI ) - Newer pre-cellular mobile authentication spoofing
  - IMTS Digit Dialing - Improved Mobile Telephone Service (pre-cellular) digit dialing

A breakdown of all of the tones that are generated can be found in the ProjectMF documentation here:
https://github.com/donfroula/Arduino-Multimode-Blue-Box-/blob/master/blue_box_manual_v36_PWM_LCD.pdf


## CoreS3
The M5Stack CoreS3 is an ESP32-S3 based IoT development kit that is packed full of sensors and interactive components.  It is battery powered and features touch screen navigation making it an ideally small and portable device.  More information about the device can be found at the manufacturers website here:

https://shop.m5stack.com/products/m5stack-cores3-esp32s3-lotdevelopment-kit
