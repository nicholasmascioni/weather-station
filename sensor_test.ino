#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(9600);
    dht.begin();
}

void loop()
{
    float humidity = dht.readHumidity();
    float temp = dht.readTemperature();
    float heat_index = dht.computeHeatIndex(temp, humidity, false); 
    // Fahrenheit is the default for the heat index function so the false parameter is added

    if (isnan(humidity) || isnan(temp))
    {
        Serial.println("Failed to read from sensor!");
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%\n");
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print("°C\n");
    Serial.print("Heat Index: ");
    Serial.print(heat_index);
    Serial.print("°C\n");
}