#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pins for LCD

byte Degree[8] =
{
0b01110,
0b01010,
0b01010,
0b01110,
0b00000,
0b00000,
0b00000,
0b00000
}; // Custom symbol for degrees

void setup()
{
    dht.begin();
    lcd.begin(16, 2); // (columns, rows)
    lcd.createChar(0, Degree);
}

void loop()
{
    float humidity = dht.readHumidity();
    float temp = dht.readTemperature();

    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.setCursor(6, 1);
    lcd.write(byte(0)); // Prints the degree symbol
    lcd.setCursor(7, 1);
    lcd.print("C");

    delay(5000); // Delay 5 seconds before displaying humidity reading
    lcd.clear();

    lcd.print("Humidity:");
    lcd.setCursor(0, 1);
    lcd.print(humidity);
    lcd.setCursor(6, 1);
    lcd.print("%");

    delay(5000); // Delay 5 seconds before displaying temperature reading again
    lcd.clear();
}