/*
 * @Description: 电池电压检测
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-07-14 16:16:07
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-05-27 16:00:48
 * @License: GPL 3.0
 */
#include <Arduino.h>
#include "pin_config.h"

static bool Temp = false;

void setup()
{
    Serial.begin(115200);

    // 测量电池
    pinMode(BATTERY_ADC_DATA, INPUT_PULLDOWN);
    analogReadResolution(12);
}

void loop()
{
    Serial.print("ADC Value:");
    Serial.println(analogRead(BATTERY_ADC_DATA));

    Serial.printf("ADC Voltage: %.03f V\n", ((float)analogReadMilliVolts(BATTERY_ADC_DATA)) / 1000.0);

    Serial.printf("Battery Voltage: %.03f V\n", (((float)analogReadMilliVolts(BATTERY_ADC_DATA)) / 1000.0) * 2.0);
    Serial.println();

    delay(1000);
}