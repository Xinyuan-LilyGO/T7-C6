/*
 * @Description: ESP Sleep
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-08-18 15:26:31
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-01-30 14:37:48
 * @License: GPL 3.0
 */
#include <Arduino.h>
#include "pin_config.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("Ciallo");

    pinMode(9, INPUT_PULLUP);
}

void loop()
{
    if (digitalRead(9) == 0)
    {
        Serial.println("Deep sleep on");
        delay(1000);
        esp_deep_sleep_start();
    }
}
