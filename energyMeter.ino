double kilos, price1c, price2c, pricetc, lastkillos;
double price1h, price2h, price3h, price4h, price5h, price6h, price7h, priceth;
double pricethn, price1hn, price2hn, price3hn;
double pricethns, price1hns, price2hns, price3hns;
double pricetcn, price1cn, price2cn;
double pulse;   // The number of pulses coming out of the electric meter LED
int flag, flag1, pushed;
char typePushed;
long counter = 0; // A counter used to multiply the number of pulses by the value of kwh (1/3200)
int cc, pb1, i;  // Clear-counter and push-button are used to reset the meter
int counterCurrent, cCurrent;
long restcounter;
double amp;
double kwh;
double v = 230.0;
#include <EEPROM.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 5, 9, 6, 3, 4);
//LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 10000;

void setup() {
  // Serial.begin(9600);
  pinMode (A3, INPUT);
  lcd.begin(16, 2);                          // initialize the lcd
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print("      v1.3");
  delay(1000);
  lcd.clear();  // Print a message to the LCD.
  lcd.print("Smart Space CO.");
  lcd.setCursor(0, 1);
  lcd.print("TEL : 0798902972");
  delay(2000);
  lcd.clear();  // Print a message to the LCD.
  EEPROM.get(0, counter);
  EEPROM.get(10, i);
    startMillis = millis();  //initial start time

} // end void setup

void loop() {
  pulse = analogRead(A3);
  pb1 = digitalRead(2);
  restcounter = restcounter + 1;
  cCurrent = cCurrent + 1;
  if (pulse > 300 && flag == 0) {
    counter = counter + 1;
    counterCurrent = counterCurrent + 1;
    flag = 1;
  } if (pulse < 250) {
    flag = 0;
  } // end pulse

currentMillis = millis();
  if (currentMillis - startMillis >= period){
    lcd.begin(16, 2);

    startMillis = currentMillis;  
  }

  if (cCurrent == 924)  //test whether the period has elapsed
  {
    kwh = (counterCurrent * 0.000625) * 1000;
    amp = (kwh / (v * 0.003055556 * 0.889));

  } else if (cCurrent > 925) {
    counterCurrent = 0;
    cCurrent = 0;
  }

  kilos = (counter * 0.000625);
  Serial.println(pulse);

  EEPROM.put(0, counter);



  lcd.setCursor(0, 1);
  lcd.print(kilos);
  lcd.print("Kwh");

  lcd.setCursor(0, 0);
  lcd.print(amp);
  lcd.print("Amp");

  if (pb1 == 1) {
    cc = cc + 1;
    if (cc >= 500) {
      kilos = 0;
      counter=0;
      price1c = 0;
      price2c = 0;
      pricetc = 0;
      price1h = 0;
      price2h = 0;
      price3h = 0;
      price4h = 0;
      price5h = 0;
      price6h = 0;
      price7h = 0;
      priceth = 0;
      pricethn = 0;
      price1hn = 0;
      price2hn = 0;
      price3hn = 0;
      pricethns = 0;
      price1hns = 0;
      price2hns = 0;
      price3hns = 0;
      pricetcn = 0;
      price1cn = 0;
      price2cn = 0;
      lcd.clear();
      lcd.print("   Reset Data");
      delay(1000);
      lcd.clear();
      EEPROM.put(0, 0.00);
    }
  }
  else {
    cc = 0;
  } // end reset pushButton

  if (pb1 == 1) {
    i = i + 1;
    delay(500);
  }

  switch (i) {
    case 0:///////////////////////////////////////////////////////// Home New
      lcd.setCursor(7, 0);
      lcd.print(" Type:H-N");
      if ( kilos <= 300.0) {
        price1hn = kilos * (0.05);
      }
      if ( kilos > 300.0 && kilos <= 600.0) {

        price2hn = (kilos - 300) * (0.10);
        if (price1hn == 0) {
          price1hn = 15;
        }
      }
      if ( kilos > 600) {

        price3hn = (kilos - 600) * (0.20);
        if (price1hn == 0 && price2hn == 0) {
          price1hn = 15;
          price1hn = 30;
        }
      }
      pricethn = price1hn + price2hn + price3hn ;
      lcd.setCursor(10, 1);
      lcd.print(pricethn);
      lcd.print("JD");
      break;//////////////////////////////////////////////////////////////// End Home New

    case 1:///////////////////////////////////////////////////////// Home new Support
      lcd.setCursor(7, 0);
      lcd.print("Type:H-NS");
      if ( kilos <= 300.0) {
        price1hns = kilos * (0.05);
      }
      if ( kilos > 300.0 && kilos <= 600.0) {

        price2hns = (kilos - 300) * (0.10);
        if (price1hns == 0) {
          price1hns = 15;
        }
      }
      if ( kilos > 600) {

        price3hns = (kilos - 600) * (0.20);
        if (price1hns == 0 && price2hns == 0) {
          price1hns = 15;
          price1hns = 30;
        }
      }
      pricethns = price1hns + price2hns + price3hns ;
      if (kilos > 50 && kilos <= 200) {
        pricethns = price1hns - 2.5;
      }
      if (kilos > 200 && kilos <= 600) {
        pricethns = (price1hns + price2hns) - 2;
      }
      lcd.setCursor(10, 1);
      lcd.print(pricethns);
      lcd.print("JD");
      break;/////////////////////////////////////////////////////////////// End Home new Support

    case 2:///////////////////////////////////////////////////////// Commerical New
      lcd.setCursor(7, 0);
      lcd.print(" Type:C-N");
      //first layer
      if ( kilos <= 2000.0) {
        price1cn = kilos * (0.12);
      }

      //second  l ayer

      if (kilos > 2000.0) {
        price2cn = (kilos - 2000) * 0.152;
        if (price1cn == 0) {
          price1cn = 240;
        }
      }
      pricetcn = price1cn + price2cn;
      lcd.setCursor(10, 1);
      lcd.print(pricetcn);
      lcd.print("JD");
      break;//////////////////////////////////////////////////////////////// End Commerical New

    default:
      i = 0;
      break;
  }
  EEPROM.put(10, i);
  

} // end void loop
