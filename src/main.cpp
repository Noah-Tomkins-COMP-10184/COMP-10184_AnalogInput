/**
 * I, Noah Tomkins, 0000790079 certify that this material is my original work.
 * No other person's work has been used without due acknowledgement.
 */

#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

String getTempString(double temp) {
    if (temp < 10)
        return "Cold!";
    if (temp < 15)
        return "Cool";
    if (temp < 25)
        return "Perfect";
    if (temp < 30)
        return "Warm";
    if (temp < 35)
        return "Hot";
    else
        return "Too Hot!";
}

void loop() {
  
    int iVal = analogRead(A0);
    double temp = ((double)(map(iVal, 0, 1024, 0, 5000)) / 100);

    Serial.println(
        "Digitized Value of " + String(iVal) + 
        " is equivalent to a temperature of " + String(temp) + 
        "°C, which is " + getTempString(temp)
    );
    
    delay(2000);
}

