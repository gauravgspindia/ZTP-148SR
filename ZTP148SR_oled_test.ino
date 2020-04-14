//This code is designed and implemented by Dr. Gourav Verma, ECE Dept. Graphic Era University.
//The code is designed to interface the ZTP-148SR IR thermal sensor. The output of thermal sensor should join to Analog pin A0
//Rest of the wire connection are as follows:

//A0- Output of Opamp of sensor
// A5-SCL
// A4-SDA

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

int X[10],B[10],i,j,sum=0,sum1=0,avg,avg1,avg2;

void intro(void);
void dispTemp(float);
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
 
}

void loop() {

  intro();

  int sensorValue ;
  for(i=0;i<=9;i++)
  {
    sensorValue = analogRead(A0);
  X[i]=sensorValue;
  sum=sum+X[i];
  }

avg= sum/10;
avg1=avg; 
  Serial.println();
//  Serial.println(sensorValue);
  
  // print out the value you read:
  Serial.println(avg);
  delay(1000);        // delay in between reads for stability

for(i=0;i<=9;i++)
  {
    sensorValue = analogRead(A0);
  X[i]=sensorValue;
  sum=sum+X[i];
  }

avg= sum/10;
avg2=avg;
  
  
  if(avg1==avg2)
  intro();
  else
  {
// calculate temperature
   if(avg==2)// change value here and call the function
     dispTemp(30.5);
      if(avg==2)// change value here and call the function
     dispTemp(30.5);
      if(avg==2)// change value here and call the function
     dispTemp(30.5);
      if(avg==2)// change value here and call the function
     dispTemp(30.5);
  }
  
}
void dispTemp(float x)
{
  display.clearDisplay();
  display.setTextSize(1);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,20);                
  display.println("Target"); 
  
  display.setTextSize(2);
  display.setCursor(50,17);
  display.println(x);  
  display.setCursor(110,17);
  display.println("F");
  
  display.display();
  
  delay(10000);

  
}

void intro(void)
{
    display.clearDisplay();
  delay(1000);
  display.drawRect(0, 0, 127, 63, WHITE);
  display.setTextSize(2.8);
  display.setTextColor(WHITE);
  display.setCursor(25, 10);
  // Display static text
  display.println(F("THERMAL"));
  display.setCursor(25, 35);
  display.println(F("SCANNER"));
  display.display(); 
  delay(2000);
  display.clearDisplay();
  
  display.drawRect(0, 0, 127, 63, WHITE);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 6);
  // Display static text
  display.println(F("An Effort"));
  display.setCursor(54, 25);
  display.println(F("of"));
//    display.setCursor(82, 6);
//  display.println(F("GEU"));
  
  display.setCursor(10, 42);
  // Display static text
  display.println(F("OLF"));
  display.setCursor(61, 42);
  display.println(F("&"));
    display.setCursor(82, 42);
  display.println(F("GEU"));
  display.display(); 
  delay(2000);  
}
