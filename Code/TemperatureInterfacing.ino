#include <LiquidCrystal_I2C.h>

#include <DHT.h>
#include <DHT_U.h>

#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int DHTPIN=2;
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

int h,t;

void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Serial.println("Temperature and humidity Sensor");
  dht.begin();
}

void loop(){
  h=dht.readHumidity();
  t=dht.readTemperature();

  Serial.print("Humidity:");
  Serial.print(h);
  Serial.print("%,Temp:");
  Serial.print(t);
  Serial.println(" Celsius");

for(int i=0;i<16;i++){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sensing......");
  lcd.setCursor(i,1);
  lcd.print("*");
  delay(750);
}
delay(300);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Temperature:");
lcd.print(t);
lcd.print("C");


lcd.setCursor(0,1);
lcd.print("Humidity::");
lcd.print(h);
lcd.print("%");

delay(5000);
lcd.clear();

lcd.setCursor(1,0);
lcd.print("Observation:");
lcd.setCursor(0,1);
if(t>20){
  lcd.print("Hot Weather");
}
else{
  lcd.print("Cold Weather");
}
delay(3000);
lcd.clear();

}
 
