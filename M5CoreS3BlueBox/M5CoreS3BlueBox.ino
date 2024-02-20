/**
 * @file M5CoreS3BlueBox.ino
 * @author r3dfish
 * @brief Blue Box Tone Generator
 * @version 0.1
 * @date 2024-02-10
 *
 *
 * @Hardwares: M5CoreS3
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 * M5CoreS3: https://github.com/m5stack/M5CoreS3
 */

#include <M5CoreS3.h>
#include "audio_file.h"

//----------------------------------------------------------------


// a list of all the available modes
static const String menu[] = {
  "MF", "DTMF", "C5", "SS4", "2600", "Pay Phone", "R2", "AC1", "AC9", "ANI", "IMTS", "MTS",
};

// a value to hold the selected mode
int menu_index = 0;

// a value to switch context between the help menu and the main menu
bool isHelpMenu = false;





// BUTTON HANDLERS





static void btn_1() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 700;
      tone_hz_2 = 900;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 697;
      tone_hz_2 = 1209;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 700;
      tone_hz_2 = 900;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz,35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 1700;
      tone_hz_2 = 2200;
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1380;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      CoreS3.Speaker.tone(tone_hz, 34, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
      CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
      CoreS3.delay(66);
      CoreS3.Speaker.tone(tone_hz, 34, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
    }
}

static void btn_2() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 700;
      tone_hz_2 = 1100;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 697;
      tone_hz_2 = 1336;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 700;
      tone_hz_2 = 1100;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 1700;
      tone_hz_2 = 2200;
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
      CoreS3.delay(66);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1380;
      tone_hz_2 = 1620;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 2; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
     }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 2; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_3() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 900;
      tone_hz_2 = 1100;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 697;
      tone_hz_2 = 1477;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 900;
      tone_hz_2 = 1100;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      // this is not built to spec, the delay should be 33ms
      tone_hz = 1700;
      tone_hz_2 = 2200;
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 33, 2, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 33, 2, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 33, 2, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 33, 2, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 33, 2, false);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1500;
      tone_hz_2 = 1620;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);    
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 3; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 3; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_4() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 700;
      tone_hz_2 = 1300;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 770;
      tone_hz_2 = 1209;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 700;
      tone_hz_2 = 1300;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 700;
      tone_hz_2 = 1100;
      CoreS3.Speaker.tone(tone_hz, 700, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 700, 2, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1380;
      tone_hz_2 = 1740;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);    
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false); 
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 4; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 4; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_5() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 900;
      tone_hz_2 = 1300;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 770;
      tone_hz_2 = 1336;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 900;
      tone_hz_2 = 1300;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 700, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 700, 2, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1500;
      tone_hz_2 = 1740;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 5; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 5; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_6() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 1100;
      tone_hz_2 = 1300;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 770;
      tone_hz_2 = 1477;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 1100;
      tone_hz_2 = 1300;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 700;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 700, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 700, 2, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1620;
      tone_hz_2 = 1740;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 6; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 6; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_7() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 700;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 852;
      tone_hz_2 = 1209;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 700;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 900;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 700, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 700, 2, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1380;
      tone_hz_2 = 1860;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 7; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 7; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_8() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 900;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 852;
      tone_hz_2 = 1336;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 900;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 1300;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 700, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 700, 2, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1500;
      tone_hz_2 = 1860;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 8; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 8; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_9() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 1100;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 852;
      tone_hz_2 = 1477;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 1100;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 1500;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 700, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 700, 2, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1620;
      tone_hz_2 = 1860;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 9; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 9; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_0() {
    static int tone_hz;
    static int tone_hz_2;
    static int tone_hz_3;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 1300;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 941;
      tone_hz_2 = 1336;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 1300;
      tone_hz_2 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 2, true);  
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
      CoreS3.delay(80);
      CoreS3.Speaker.tone(tone_hz, 40, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 2200;
      CoreS3.Speaker.tone(tone_hz, 60, 1, false);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1740;
      tone_hz_2 = 1860;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 66, 1, true);
    } else if (menu_index == 8) {
      // AC9 mode tones
      // not built to spec, delay should be 34ms
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
      CoreS3.delay(105);
      CoreS3.Speaker.tone(tone_hz, 66, 1, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1633;
      tone_hz_2 = 2150;
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz, 25, 1, false);
      CoreS3.delay(25);
      CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.delay(250);
      for (int x=0; x < 10; x++) {
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 66, 2, true);
        CoreS3.delay(66);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      tone_hz_3 = 1500;
      CoreS3.Speaker.tone(tone_hz, 250, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, true);
      CoreS3.delay(250);
      for (int x=0; x < 10; x++) {
        CoreS3.Speaker.tone(tone_hz_2, 66, 1, true);
        CoreS3.Speaker.tone(tone_hz_3, 66, 2, true);
        CoreS3.delay(66);
        CoreS3.Speaker.tone(tone_hz, 34, 1, true);
        CoreS3.Speaker.tone(tone_hz_2, 34, 2, true);
        CoreS3.delay(34);
      }
    }
}

static void btn_star() {
    static int tone_hz;
    static int tone_hz_2;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 941;
      tone_hz_2 = 1209;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 150, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 150, 2, false);
      CoreS3.delay(150);
      CoreS3.Speaker.tone(tone_hz_2, 100, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 2200;
      CoreS3.Speaker.tone(tone_hz, 60, 1, false);
      CoreS3.delay(60);
      CoreS3.Speaker.tone(tone_hz, 60, 1, false);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1620;
      tone_hz_2 = 1980;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      tone_hz = 750;
      CoreS3.Speaker.tone(tone_hz, 100, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 95, 1, false);
    }
}

static void btn_pound() {
    static int tone_hz;
    static int tone_hz_2;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 1500;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 941;
      tone_hz_2 = 1477;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 1500;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // this is not built to spec, the delays should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 2, true);  
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      // these delays are not to spec, they should be 33ms
      tone_hz = 2200;
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 33, 1, false);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1860;
      tone_hz_2 = 1920;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    }
}

static void btn_a() {
    static int tone_hz;
    static int tone_hz_2;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 900;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 697;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 900;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 2, true);  
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1500;
      tone_hz_2 = 1980;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    }
}

static void btn_b() {
    static int tone_hz;
    static int tone_hz_2;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 1300;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 770;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 1300;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 150, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 150, 2, true);
      CoreS3.delay(100);
      CoreS3.Speaker.tone(tone_hz, 100, 1, true);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1740;
      tone_hz_2 = 1980;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    }
}

static void btn_c() {
    static int tone_hz;
    static int tone_hz_2;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 700;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 852;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 700;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
    } else if (menu_index == 3) {
      // SS4 mode tones
      // these are not built to spec, the delay should be 35ms
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 1, true);
      CoreS3.delay(70);
      CoreS3.Speaker.tone(tone_hz_2, 35, 2, true);  
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 1380;
      tone_hz_2 = 1980;
      CoreS3.Speaker.tone(tone_hz, 75, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 75, 2, false);
    } else if (menu_index == 9) {
      // ANI mode tones
      tone_hz = 1336;
      tone_hz_2 = 2150;
      for (int i=0; i<15; i++) { //15-50ms bursts (20pps) = 750ms
        CoreS3.Speaker.tone(tone_hz, 25, 1, true);
        CoreS3.delay(25);
        CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
        CoreS3.delay(25);
      }
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 1336;
      tone_hz_2 = 2150;
      for (int i=0; i<15; i++) { //15-50ms bursts (20pps) = 750ms
        CoreS3.Speaker.tone(tone_hz, 25, 1, true);
        CoreS3.delay(25);
        CoreS3.Speaker.tone(tone_hz_2, 25, 1, true);
        CoreS3.delay(25);
      }
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1300;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 1000, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 1000, 2, true);
    }
}

static void btn_d() {
    static int tone_hz;
    static int tone_hz_2;
    if (menu_index == 0) {
      // MF mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 1250, 1, false);
    } else if (menu_index == 1) {
      // DTMF mode tones
      tone_hz = 941;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);    
    } else if (menu_index == 2) {
      // C5 mode tones
      tone_hz = 2400;
      tone_hz_2 = 2600;
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 250, 2, false);  
      CoreS3.delay(250);
      CoreS3.Speaker.tone(tone_hz, 250, 1, false);
    } else if (menu_index == 3) {
      // SS4 mode tones
      tone_hz = 2400;
      tone_hz_2 = 2040;
      CoreS3.Speaker.tone(tone_hz, 150, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 150, 2, false);
      CoreS3.Speaker.tone(tone_hz_2, 350, 3, false);
    } else if (menu_index == 4) {
      // 2600 Dial Pulse mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 1500, 1, false);
    } else if (menu_index == 5) {
      // Pay Phone mode tones
      tone_hz = 2600;
      CoreS3.Speaker.tone(tone_hz, 425, 1, false);
    } else if (menu_index == 6) {
      // R2 mode tones
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 1250, 1, false);
      CoreS3.delay(2250);
      CoreS3.Speaker.tone(tone_hz, 100, 1, false);
    } else if (menu_index == 7) {
      // AC1 mode tones
      tone_hz = 750;
      tone_hz_2 = 600;
      CoreS3.Speaker.tone(tone_hz, 2000, 1, false);
      CoreS3.Speaker.tone(tone_hz_2, 800, 1, false);
    } else if (menu_index == 8) {
      // AC9 mode tones
      tone_hz = 2280;
      CoreS3.Speaker.tone(tone_hz, 1000, 1, false);
    } else if (menu_index == 9) {
      // AC1 mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 350, 1, false);
      CoreS3.delay(350);
      CoreS3.Speaker.tone(tone_hz_2, 50, 1, false);
      CoreS3.delay(50);
      CoreS3.Speaker.tone(tone_hz, 2000, 1, false);
    } else if (menu_index == 10) {
      // IMTS mode tones
      tone_hz = 2150;
      tone_hz_2 = 1633;
      CoreS3.Speaker.tone(tone_hz, 350, 1, false);
      CoreS3.delay(350);
      CoreS3.Speaker.tone(tone_hz_2, 50, 1, false);
      CoreS3.delay(50);
      CoreS3.Speaker.tone(tone_hz, 2000, 1, false);
    } else if (menu_index == 11) {
      // MTS mode tones
      tone_hz = 1100;
      tone_hz_2 = 1700;
      CoreS3.Speaker.tone(tone_hz, 1000, 1, true);
      CoreS3.Speaker.tone(tone_hz_2, 1000, 2, true);
    }
}

static void btn_vol_up() {
    int new_volume = CoreS3.Speaker.getVolume() + 25;
    // dont let the volume go above 250/255
    if (new_volume > 250) {
        new_volume = 250;
    }
    CoreS3.Speaker.setVolume(new_volume);
    drawMenu();
}

static void btn_vol_dn() {
    int new_volume = CoreS3.Speaker.getVolume() - 25;
    if (new_volume < 25) {
        new_volume = 25;
    }
    CoreS3.Speaker.setVolume(new_volume);
    drawMenu();
}

static void btn_mode() {
    if (menu_index < 11) {
      menu_index = ++menu_index;
    } else {
      menu_index = 0;
    }
    drawMenu();
}

static void btn_help() {
    // set this to true so the next screen touch returns to main menu
    isHelpMenu = true;
    // draw the help screen
    drawHelp();
}





// DRAW THE MENU INTERFACE





void drawMenu() {
    CoreS3.Display.fillScreen(TFT_BLACK);
    CoreS3.Display.setTextColor(WHITE);

    //1
    CoreS3.Display.drawRoundRect(5, 5, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(7, 7, 46, 46, BLUE);
    CoreS3.Display.drawString("1", 25, 22);

    //2
    CoreS3.Display.drawRoundRect(65, 5, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(67, 7, 46, 46, BLUE);
    CoreS3.Display.drawString("2", 85, 22);

    //3
    CoreS3.Display.drawRoundRect(125, 5, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(127, 7, 46, 46, BLUE);
    CoreS3.Display.drawString("3", 145, 22);
    
    //A
    CoreS3.Display.drawRoundRect(185, 5, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(187, 7, 46, 46, RED);
    CoreS3.Display.drawString("A", 205, 22);
    
    //4
    CoreS3.Display.drawRoundRect(5, 65, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(7, 67, 46, 46, BLUE);
    CoreS3.Display.drawString("4", 25, 84);

    //5
    CoreS3.Display.drawRoundRect(65, 65, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(67, 67, 46, 46, BLUE);
    CoreS3.Display.drawString("5", 85, 84);

    //6
    CoreS3.Display.drawRoundRect(125, 65, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(127, 67, 46, 46, BLUE);
    CoreS3.Display.drawString("6", 145, 84);
    
    //B
    CoreS3.Display.drawRoundRect(185, 65, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(187, 67, 46, 46, RED);
    CoreS3.Display.drawString("B", 205, 84);

    //7
    CoreS3.Display.drawRoundRect(5, 125, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(7, 127, 46, 46, BLUE);
    CoreS3.Display.drawString("7", 25, 145);

    //8
    CoreS3.Display.drawRoundRect(65, 125, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(67, 127, 46, 46, BLUE);
    CoreS3.Display.drawString("8", 85, 145);

    //9
    CoreS3.Display.drawRoundRect(125, 125, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(127, 127, 46, 46, BLUE);
    CoreS3.Display.drawString("9", 145, 145);
    
    //C
    CoreS3.Display.drawRoundRect(185, 125, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(187, 127, 46, 46, RED);
    CoreS3.Display.drawString("C", 205, 145);

    //*
    CoreS3.Display.drawRoundRect(5, 185, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(7, 187, 46, 46, RED);
    CoreS3.Display.drawString("*", 25, 205);

    //0
    CoreS3.Display.drawRoundRect(65, 185, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(67, 187, 46, 46, BLUE);
    CoreS3.Display.drawString("0", 85, 205);

    //#
    CoreS3.Display.drawRoundRect(125, 185, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(127, 187, 46, 46, RED);
    CoreS3.Display.drawString("#", 145, 205);
    
    //D
    CoreS3.Display.drawRoundRect(185, 185, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(187, 187, 46, 46, RED);
    CoreS3.Display.drawString("D", 205, 205);

    // volume
    CoreS3.Display.drawRoundRect(255, 5, 50, 30, 3, GREEN);
    CoreS3.Display.fillRect(257, 7, 46, 26, GREEN);
    CoreS3.Display.drawString("UP", 268, 12);
    CoreS3.Display.drawString("VOL:", 258, 40);
    int vol = (CoreS3.Speaker.getVolume() / 25) * 10;
    CoreS3.Display.drawString(String(vol) + "%", 258, 60);
    CoreS3.Display.drawRoundRect(255, 83, 50, 30, 3, GREEN);
    CoreS3.Display.fillRect(257, 85, 46, 26, GREEN);
    CoreS3.Display.drawString("DN", 265, 90);

    // help button
    CoreS3.Display.fillCircle(278, 140, 15, NAVY);
    CoreS3.Display.drawString("?", 274, 133);

    // mode
    CoreS3.Display.drawString("Mode:", 250, 165);
    CoreS3.Display.drawRoundRect(255, 185, 50, 50, 3, WHITE);
    CoreS3.Display.fillRect(257, 187, 46, 46, WHITE);
    CoreS3.Display.setTextColor(BLACK);
    if (menu_index == 0) {
      CoreS3.Display.drawString("MF", 265, 202);
    } else if (menu_index == 1) {
      CoreS3.Display.setFont(&fonts::DejaVu12);
      CoreS3.Display.drawString("DTMF", 262, 205);
      CoreS3.Display.setFont(&fonts::DejaVu18);
    } else if (menu_index == 2) {
      CoreS3.Display.drawString("C5", 268, 202);
    } else if (menu_index == 3) {
      CoreS3.Display.drawString("SS4", 262, 202);
    } else if (menu_index == 4) {
      CoreS3.Display.drawString("2600", 257, 202);
    } else if (menu_index == 5) {
      CoreS3.Display.setFont(&fonts::DejaVu12);
      CoreS3.Display.drawString("Pay", 269, 195);
      CoreS3.Display.drawString("Phone", 258, 215);
      CoreS3.Display.setFont(&fonts::DejaVu18);
    } else if (menu_index == 6) {
      CoreS3.Display.drawString("R2", 267, 203);
    } else if (menu_index == 7) {
      CoreS3.Display.drawString("AC1", 261, 202);
    } else if (menu_index == 8) {
      CoreS3.Display.drawString("AC9", 261, 202);
    } else if (menu_index == 9) {
      CoreS3.Display.drawString("ANI", 263, 202);
    } else if (menu_index == 10) {
      CoreS3.Display.drawString("IMTS", 256, 202);
    } else if (menu_index == 11) {
      CoreS3.Display.drawString("MTS", 260, 202);
    }
}





// DRAW THE HELP DIALOG




void drawHelp() {
    CoreS3.Display.fillScreen(TFT_BLACK);
    CoreS3.Display.setTextColor(WHITE);
    if (menu_index == 0) {
      // Draw the MF help menu
      CoreS3.Display.drawString("1 -  700hz + 900hz", 5, 0);
      CoreS3.Display.drawString("2 -  700hz + 1100hz", 5, 15);
      CoreS3.Display.drawString("3 -  900hz + 1100hz", 5, 30);
      CoreS3.Display.drawString("4 -  700hz + 1300hz", 5, 45);
      CoreS3.Display.drawString("5 -  900hz + 1300hz", 5, 60);
      CoreS3.Display.drawString("6 - 1100hz + 1300hz", 5, 75);
      CoreS3.Display.drawString("7 -  700hz + 1500hz", 5, 90);
      CoreS3.Display.drawString("8 -  900hz + 1500hz", 5, 105);
      CoreS3.Display.drawString("9 - 1100hz + 1500hz", 5, 120);
      CoreS3.Display.drawString("0 - 1300hz + 1500hz", 5, 135);
      CoreS3.Display.drawString("* - KP - Key Pulse", 5, 150);
      CoreS3.Display.drawString("# - ST - Start", 5, 165);
      CoreS3.Display.drawString("A - STP", 5, 180);
      CoreS3.Display.drawString("B - ST2P", 5, 195);
      CoreS3.Display.drawString("C - ST3P", 5, 210);
      CoreS3.Display.drawString("D - Supervision", 5, 225);
    } else if (menu_index == 1) {
      // Draw the DTMF help menu
      CoreS3.Display.drawString("1 -  697hz + 1209hz", 5, 0);
      CoreS3.Display.drawString("2 -  697hz + 1336hz", 5, 15);
      CoreS3.Display.drawString("3 -  697hz + 1477hz", 5, 30);
      CoreS3.Display.drawString("4 -  770hz + 1209hz", 5, 45);
      CoreS3.Display.drawString("5 -  770hz + 1336hz", 5, 60);
      CoreS3.Display.drawString("6 -  770hz + 1477hz", 5, 75);
      CoreS3.Display.drawString("7 -  852hz + 1209hz", 5, 90);
      CoreS3.Display.drawString("8 -  852hz + 1336hz", 5, 105);
      CoreS3.Display.drawString("9 -  852hz + 1477hz", 5, 120);
      CoreS3.Display.drawString("0 -  941hz + 1336hz", 5, 135);
      CoreS3.Display.drawString("* -  941hz + 1209hz", 5, 150);
      CoreS3.Display.drawString("# -  941hz + 1477hz", 5, 165);
      CoreS3.Display.drawString("A -  697hz + 1633hz", 5, 180);
      CoreS3.Display.drawString("B -  770hz + 1633hz", 5, 195);
      CoreS3.Display.drawString("C -  852hz + 1633hz", 5, 210);
      CoreS3.Display.drawString("D -  941hz + 1633hz", 5, 225);
    }else if (menu_index == 2) {
      // Draw the C5 help menu
      CoreS3.Display.drawString("1 -  700hz + 900hz", 5, 0);
      CoreS3.Display.drawString("2 -  700hz + 1100hz", 5, 15);
      CoreS3.Display.drawString("3 -  900hz + 1100hz", 5, 30);
      CoreS3.Display.drawString("4 -  700hz + 1300hz", 5, 45);
      CoreS3.Display.drawString("5 -  900hz + 1300hz", 5, 60);
      CoreS3.Display.drawString("6 - 1100hz + 1300hz", 5, 75);
      CoreS3.Display.drawString("7 -  700hz + 1500hz", 5, 90);
      CoreS3.Display.drawString("8 -  900hz + 1500hz", 5, 105);
      CoreS3.Display.drawString("9 - 1100hz + 1500hz", 5, 120);
      CoreS3.Display.drawString("0 - 1300hz + 1500hz", 5, 135);
      CoreS3.Display.drawString("* - KP1 - Key Pulse 1", 5, 150);
      CoreS3.Display.drawString("# - ST - Start", 5, 165);
      CoreS3.Display.drawString("A - Code 12 (STP)", 5, 180);
      CoreS3.Display.drawString("B - KP2 - Key Pulse 2", 5, 195);
      CoreS3.Display.drawString("C - Code 11 (ST3P)", 5, 210);
      CoreS3.Display.drawString("D - Clear Forward Seizure", 5, 225);
    }else if (menu_index == 3) {
      // Draw the SS4 help menu
      CoreS3.Display.drawString("1 -  2400(0) + 2040(1) 0001", 5, 0);
      CoreS3.Display.drawString("2 -  2400(0) + 2040(1) 0010", 5, 15);
      CoreS3.Display.drawString("3 -  2400(0) + 2040(1) 0011", 5, 30);
      CoreS3.Display.drawString("4 -  2400(0) + 2040(1) 0100", 5, 45);
      CoreS3.Display.drawString("5 -  2400(0) + 2040(1) 0101", 5, 60);
      CoreS3.Display.drawString("6 -  2400(0) + 2040(1) 0110", 5, 75);
      CoreS3.Display.drawString("7 -  2400(0) + 2040(1) 0111", 5, 90);
      CoreS3.Display.drawString("8 -  2400(0) + 2040(1) 1000", 5, 105);
      CoreS3.Display.drawString("9 -  2400(0) + 2040(1) 1001", 5, 120);
      CoreS3.Display.drawString("0 -  2400(0) + 2040(1) 1010", 5, 135);
      CoreS3.Display.drawString("* -  Terminal Seizure", 5, 150);
      CoreS3.Display.drawString("# -  End of Pulsing", 5, 165);
      CoreS3.Display.drawString("A -  Code 12", 5, 180);
      CoreS3.Display.drawString("B -  Transit Seizure", 5, 195);
      CoreS3.Display.drawString("C -  Code 11", 5, 210);
      CoreS3.Display.drawString("D -  Clear Forward", 5, 225);
    } else if (menu_index == 4) {
      // Draw the 2600 help menu
      CoreS3.Display.drawString("1 -  Addressing Digit 1", 5, 0);
      CoreS3.Display.drawString("2 -  Addressing Digit 2", 5, 15);
      CoreS3.Display.drawString("3 -  Addressing Digit 3", 5, 30);
      CoreS3.Display.drawString("4 -  Addressing Digit 4", 5, 45);
      CoreS3.Display.drawString("5 -  Addressing Digit 5", 5, 60);
      CoreS3.Display.drawString("6 -  Addressing Digit 6", 5, 75);
      CoreS3.Display.drawString("7 -  Addressing Digit 7", 5, 90);
      CoreS3.Display.drawString("8 -  Addressing Digit 8", 5, 105);
      CoreS3.Display.drawString("9 -  Addressing Digit 9", 5, 120);
      CoreS3.Display.drawString("0 -  Addressing Digit 0", 5, 135);
      CoreS3.Display.drawString("D -  Supervision", 5, 150);
    } else if (menu_index == 5) {
      // Draw the Pay Phone help menu
      CoreS3.Display.drawString("1 -  US Nickel", 5, 0);
      CoreS3.Display.drawString("2 -  US Dime", 5, 15);
      CoreS3.Display.drawString("3 -  US Quarter", 5, 30);
      CoreS3.Display.drawString("4 -  Coin Collect", 5, 45);
      CoreS3.Display.drawString("5 -  Coin Return", 5, 60);
      CoreS3.Display.drawString("6 -  Ringback", 5, 75);
      CoreS3.Display.drawString("7 -  Operator Attached", 5, 90);
      CoreS3.Display.drawString("8 -  Operator Released", 5, 105);
      CoreS3.Display.drawString("9 -  Coin Collect", 5, 120);
      CoreS3.Display.drawString("0 -  Canadian Nickel", 5, 135);
      CoreS3.Display.drawString("* -  Canadian Dime", 5, 150);
      CoreS3.Display.drawString("# -  Canadian Quarter", 5, 165);
      CoreS3.Display.drawString("D -  Long 2600hz flash", 5, 180);
    } else if (menu_index == 6) {
      // Draw the R2 help menu
      CoreS3.Display.drawString("1 -  Addressing Digit 1", 5, 0);
      CoreS3.Display.drawString("2 -  Addressing Digit 2", 5, 15);
      CoreS3.Display.drawString("3 -  Addressing Digit 3", 5, 30);
      CoreS3.Display.drawString("4 -  Addressing Digit 4", 5, 45);
      CoreS3.Display.drawString("5 -  Addressing Digit 5", 5, 60);
      CoreS3.Display.drawString("6 -  Addressing Digit 6", 5, 75);
      CoreS3.Display.drawString("7 -  Addressing Digit 7", 5, 90);
      CoreS3.Display.drawString("8 -  Addressing Digit 8", 5, 105);
      CoreS3.Display.drawString("9 -  Addressing Digit 9", 5, 120);
      CoreS3.Display.drawString("0 -  Addressing Digit 0", 5, 135);
      CoreS3.Display.drawString("* -  Cable route/test call", 5, 150);
      CoreS3.Display.drawString("# -  End of Pulsing", 5, 165);
      CoreS3.Display.drawString("A -  Code 12", 5, 180);
      CoreS3.Display.drawString("B -  Satellite route", 5, 195);
      CoreS3.Display.drawString("C -  Code 11", 5, 210);
      CoreS3.Display.drawString("D -  Clear Forward Seize", 5, 225);
    } else if (menu_index == 7) {
      // Draw the AC1 help menu
      CoreS3.Display.drawString("1 -  Addressing Digit 1", 5, 0);
      CoreS3.Display.drawString("2 -  Addressing Digit 2", 5, 15);
      CoreS3.Display.drawString("3 -  Addressing Digit 3", 5, 30);
      CoreS3.Display.drawString("4 -  Addressing Digit 4", 5, 45);
      CoreS3.Display.drawString("5 -  Addressing Digit 5", 5, 60);
      CoreS3.Display.drawString("6 -  Addressing Digit 6", 5, 75);
      CoreS3.Display.drawString("7 -  Addressing Digit 7", 5, 90);
      CoreS3.Display.drawString("8 -  Addressing Digit 8", 5, 105);
      CoreS3.Display.drawString("9 -  Addressing Digit 9", 5, 120);
      CoreS3.Display.drawString("0 -  Addressing Digit 0", 5, 135);
      CoreS3.Display.drawString("* -  Seize", 5, 150);
      CoreS3.Display.drawString("D -  Clear Forward", 5, 165);
    } else if (menu_index == 8) {
      // Draw the AC9 help menu
      CoreS3.Display.drawString("1 -  Addressing Digit 1", 5, 0);
      CoreS3.Display.drawString("2 -  Addressing Digit 2", 5, 15);
      CoreS3.Display.drawString("3 -  Addressing Digit 3", 5, 30);
      CoreS3.Display.drawString("4 -  Addressing Digit 4", 5, 45);
      CoreS3.Display.drawString("5 -  Addressing Digit 5", 5, 60);
      CoreS3.Display.drawString("6 -  Addressing Digit 6", 5, 75);
      CoreS3.Display.drawString("7 -  Addressing Digit 7", 5, 90);
      CoreS3.Display.drawString("8 -  Addressing Digit 8", 5, 105);
      CoreS3.Display.drawString("9 -  Addressing Digit 9", 5, 120);
      CoreS3.Display.drawString("0 -  Addressing Digit 0", 5, 135);
      CoreS3.Display.drawString("* -  Seize", 5, 150);
      CoreS3.Display.drawString("D -  Clear Forward", 5, 165);
    } else if (menu_index == 9) {
      // Draw the ANI help menu
      CoreS3.Display.drawString("1 -  Addressing Digit 1", 5, 0);
      CoreS3.Display.drawString("2 -  Addressing Digit 2", 5, 15);
      CoreS3.Display.drawString("3 -  Addressing Digit 3", 5, 30);
      CoreS3.Display.drawString("4 -  Addressing Digit 4", 5, 45);
      CoreS3.Display.drawString("5 -  Addressing Digit 5", 5, 60);
      CoreS3.Display.drawString("6 -  Addressing Digit 6", 5, 75);
      CoreS3.Display.drawString("7 -  Addressing Digit 7", 5, 90);
      CoreS3.Display.drawString("8 -  Addressing Digit 8", 5, 105);
      CoreS3.Display.drawString("9 -  Addressing Digit 9", 5, 120);
      CoreS3.Display.drawString("0 -  Addressing Digit 0", 5, 135);
      CoreS3.Display.drawString("C -  Hangup", 5, 150);
      CoreS3.Display.drawString("D -  Seize", 5, 165);
    } else if (menu_index == 10) {
      // Draw the IMTS help menu
      CoreS3.Display.drawString("1 -  Addressing Digit 1", 5, 0);
      CoreS3.Display.drawString("2 -  Addressing Digit 2", 5, 15);
      CoreS3.Display.drawString("3 -  Addressing Digit 3", 5, 30);
      CoreS3.Display.drawString("4 -  Addressing Digit 4", 5, 45);
      CoreS3.Display.drawString("5 -  Addressing Digit 5", 5, 60);
      CoreS3.Display.drawString("6 -  Addressing Digit 6", 5, 75);
      CoreS3.Display.drawString("7 -  Addressing Digit 7", 5, 90);
      CoreS3.Display.drawString("8 -  Addressing Digit 8", 5, 105);
      CoreS3.Display.drawString("9 -  Addressing Digit 9", 5, 120);
      CoreS3.Display.drawString("0 -  Addressing Digit 0", 5, 135);
      CoreS3.Display.drawString("C -  Hangup", 5, 150);
      CoreS3.Display.drawString("D -  Seize", 5, 165);
    } else if (menu_index == 11) {
      // Draw the MTS help menu
      CoreS3.Display.drawString("1 -  Addressing Digit 1", 5, 0);
      CoreS3.Display.drawString("2 -  Addressing Digit 2", 5, 15);
      CoreS3.Display.drawString("3 -  Addressing Digit 3", 5, 30);
      CoreS3.Display.drawString("4 -  Addressing Digit 4", 5, 45);
      CoreS3.Display.drawString("5 -  Addressing Digit 5", 5, 60);
      CoreS3.Display.drawString("6 -  Addressing Digit 6", 5, 75);
      CoreS3.Display.drawString("7 -  Addressing Digit 7", 5, 90);
      CoreS3.Display.drawString("8 -  Addressing Digit 8", 5, 105);
      CoreS3.Display.drawString("9 -  Addressing Digit 9", 5, 120);
      CoreS3.Display.drawString("0 -  Addressing Digit 0", 5, 135);
      CoreS3.Display.drawString("C -  Disconnect", 5, 150);
      CoreS3.Display.drawString("D -  Connect", 5, 165);
    }
}




// DO ALL THE SETUP




void setup(void) {
    auto cfg = M5.config();
    CoreS3.begin(cfg);
    {
        auto spk_cfg = CoreS3.Speaker.config();
        if (spk_cfg.use_dac || spk_cfg.buzzer) {
            /// Increasing the sample_rate will improve the sound quality
            /// instead of increasing the CPU load.
            spk_cfg.sample_rate =
                192000;  // default:64000 (64kHz)  e.g. 48000 , 50000 , 80000 ,
                         // 96000 , 100000 , 128000 , 144000 , 192000 , 200000
        }
        CoreS3.Speaker.config(spk_cfg);
    }
    CoreS3.Speaker.begin();
    if (!CoreS3.Speaker.isEnabled()) {
        CoreS3.Display.print("Speaker not found...");
        for (;;) {
            CoreS3.delay(1);
        }
    }

    /// The setVolume function can be set the master volume in the range of
    /// 0-255. (default : 64)
    CoreS3.Speaker.setVolume(125);

    /// The setAllChannelVolume function can be set the all virtual channel
    /// volume in the range of 0-255. (default : 255)
    CoreS3.Speaker.setAllChannelVolume(255);

    /// The setChannelVolume function can be set the specified virtual channel
    /// volume in the range of 0-255. (default : 255)
    CoreS3.Speaker.setChannelVolume(0, 255);

    // rotate 270 to put the camera on the top
    CoreS3.Display.setRotation(3);
    CoreS3.Display.setFont(&fonts::DejaVu18);
    CoreS3.Display.setEpdMode(epd_mode_t::epd_fastest);
    CoreS3.Display.fillScreen(TFT_BLACK);
    CoreS3.Display.setTextColor(WHITE);

    // start with the initial menu painted on the screen
    drawMenu();
}





// THE FAMOUS ARDUINO LOOP
// NOT TO BE CONFUSED WITH THE WORDPRESS LOOP





void loop(void) {

    CoreS3.update();

    auto touch_count = CoreS3.Touch.getCount();
    for (size_t i = 0; i < touch_count; i++) {
        auto detail = CoreS3.Touch.getDetail(i);
        // we only want to take action on the single event where the finger is lifted from the display
        if (detail.state == m5::touch_state_t::touch_end) {
          // check if we are in the help menu, if so return to main menu
          if (isHelpMenu == true) {
            // touch event in the help menu, return to the main menu
            isHelpMenu = false;
            drawMenu();
          } else if ((size_t)detail.x < 56) {
            // in the first column
            if ((size_t)detail.y < 56) {
              btn_1();
            } else if ((size_t)detail.y < 105) {
              btn_4();
            } else if ((size_t)detail.y < 180) {
              btn_7();
            } else if ((size_t)detail.y < 240) {
              btn_star();
            }
          } else if ((size_t)detail.x < 105) {
            // in the second column
            if ((size_t)detail.y < 56) {
              btn_2();
            } else if ((size_t)detail.y < 105) {
              btn_5();
            } else if ((size_t)detail.y < 180) {
              btn_8();
            } else if ((size_t)detail.y < 240) {
              btn_0();
            }
          } else if ((size_t)detail.x < 180) {
            // in the third column
            if ((size_t)detail.y < 56) {
              btn_3();
            } else if ((size_t)detail.y < 105) {
              btn_6();
            } else if ((size_t)detail.y < 180) {
              btn_9();
            } else if ((size_t)detail.y < 240) {
              btn_pound();
            }
          } else if ((size_t)detail.x < 240) {
            // in the fourth column
            if ((size_t)detail.y < 56) {
              btn_a();
            } else if ((size_t)detail.y < 105) {
              btn_b();
            } else if ((size_t)detail.y < 180) {
              btn_c();
            } else if ((size_t)detail.y < 240) {
              btn_d();
            }
          } else {
            // in the fifth column
            if ((size_t)detail.y > 4 && (size_t)detail.y < 36) {
              btn_vol_up();
            } else if ((size_t)detail.y > 84 && (size_t)detail.y < 112) {
              btn_vol_dn();
            } else if ((size_t)detail.y > 133 && (size_t)detail.y < 145) {
              btn_help();
            } else if ((size_t)detail.y > 186 && (size_t)detail.y < 232) {
              btn_mode();
            }
          }
        }
    }
}
