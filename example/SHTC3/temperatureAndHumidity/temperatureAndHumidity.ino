/*!
 * @file temperatureAndHumidity.ino
 * @brief Measurement of temperature and humidity
 * @n 本传感器可测量温湿度数据,温度的测量范围在-40~125 ℃ ,湿度的测量范围在 0~100 %RH。
 * @n 本传感器可通过四种模式测量数据,分别是 开启时钟延展、不开启时钟延展、低功耗模式加时钟延展、低功耗模式不加时钟延展。
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version  V1.0
 * @date  2021-03-19
 * @get from https://www.dfrobot.com
 * @url  https://github.com/DFRobot/DFRobot_SHTXX
 */

#include"DFRobot_SHTC3.h"

DFRobot_SHTC3 SHTC3;

uint32_t id = 0;
float temperature,  humidity;

void setup() {
  Serial.begin(9600);
  SHTC3.begin();
  SHTC3.wakeup();/*SHTC3传感器默认配置为睡眠状态,使用前请对它进行唤醒操作。 使SHTC3 进行睡眠请调用这个方法SHTC3.sleep();在SHTC3传感器进入睡眠状态后,将在被唤醒之前不工作*/

  while((id = SHTC3.getDeviceID()) == 0){
    Serial.println("ID retrieval error, please check whether the device is connected correctly!!!");
    delay(1000);
  }

  delay(1000);
  Serial.print("id :0x"); Serial.println(id, HEX);
  
  /**
   * 
   *    mode 用来配置传感器的工作模式,不同的传感器有不同的工作模式
   *          SHTC3：
   *                  eEnClkStretch                              Clock Stretching Enabled 
   *                  eDisClkStretch                             Clock Stretching Disabled 
   *                  eEnClkStretchLowP                          Clock Stretching Enabled & Low Power
   *                  eDisClkStretchLowP                         Clock Stretching Disabled & Low Power
   */
  SHTC3.setMode(/*mode = */SHTC3.eEnClkStretch);

}

void loop() {
  temperature = SHTC3.getTemperature();

  humidity = SHTC3.getHumidity();

  //SHTC3.getTemHum(temperature, humidity);

  Serial.print("Temperature :"); Serial.print(temperature); Serial.println(" C");

  Serial.print("Humidity :"); Serial.print(humidity); Serial.println(" %RH");

  delay(1000);

  Serial.println("----------------------------------------");
}
