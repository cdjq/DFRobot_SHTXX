/*!
 * @file temperatureAndHumidity.ino
 * @brief Measurement of temperature and humidity
 * @n 本系列传感器可测量温湿度数据，温度的测量范围在-40~125 ℃ ，湿度的测量范围在 0~100 %RH。
 * @n 实验现象：不同模式下打印间隔不同，正确情况下输出温湿度数据，设备有错误的情况下，会提示错误信息
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version  V1.0
 * @date  2021-03-19
 * @get from https://www.dfrobot.com
 * @url  https://github.com/DFRobot/DFRobot_SHTXX
 */

#include"DFRobot_SHTXX.h"

//#define SHTC3
#ifdef SHTC3
DFRobot_SHTC3 SHTXX;
#endif

#define SHT40
#ifdef SHT40
/** 对于SHT40传感器这里支持两种型号，第一种是SHT40_AD1B ,第二种是SHT40_BD1B，这两种型号对应不同的IIC设备地址，这里对它们进行了封装，用户可传入如下两种参数
 *   型号为SHT40_AD1B的传感器使用:    SHT40_AD1B_IIC_ADDR
 *   型号为SHT40_AD1B的传感器使用:    SHT40_BD1B_IIC_ADDR
 */
DFRobot_SHT40 SHTXX(SHT40_AD1B_IIC_ADDR); 
#endif

uint32_t id = 0;
float temperature , humidity;

void setup() {
  Serial.begin(9600);
  SHTXX.begin();

#ifdef SHTC3
  SHTXX.wakeup();/*SHTC3传感器默认配置为睡眠状态，使用前请对它进行唤醒操作。 使SHTC3 进行睡眠请调用这个方法SHTXX.sleep();在SHTC3传感器进入睡眠状态后，将在被唤醒之前不工作*/
#endif

  while((id = SHTXX.getDeviceID()) == 0){
    Serial.println("ID retrieval error, please check whether the device is connected correctly!!!");
    delay(1000);
  }

  delay(1000);

  Serial.print("id :0x"); Serial.println(id ,HEX);
  /**
   * 
   *    mode 用来配置传感器的工作模式，不同的传感器有不同的工作模式
   *          SHTC3：
   *                  eEnClkStretch                              Clock Stretching Enabled 
   *                  eDisClkStretch                             Clock Stretching Disabled 
   *                  eEnClkStretchLowP                          Clock Stretching Enabled & Low Power
   *                  eDisClkStretchLowP                         Clock Stretching Disabled & Low Power
   *          SHT40:
   *                  eHighPrecision                             measure T & RH with high precision (high repeatability) 
   *                  eMediumPrecision                           measure T & RH with medium precision (medium repeatability)
   *                  eLowPrecision                              measure T & RH with lowest precision (low repeatability) 
   *                  eHeaterHighPLongT                          activate highest heater power & high precis. meas. (typ. 200mW @ 3.3V) for 1s 
   *                  eHeaterHighPShortT                         activate highest heater power & high precis. meas. (typ. 200mW @ 3.3V) for 0.1s
   *                  eHeaterMediumPLongT                        activate medium heater power  & high precis. meas. (typ. 110mW @ 3.3V) for 1s 
   *                  eHeaterMediumPShortT                       activate medium heater power  & high precis. meas. (typ. 110mW @ 3.3V) for 0.1s 
   *                  eHeaterLowPLongT                           activate lowest heater power  & high precis. meas. (typ. 20mW @ 3.3V) for 1s 
   *                  eHeaterLowPShortT                          activate lowest heater power  & high precis. meas. (typ. 20mW @ 3.3V) for 0.1s 
   */
  SHTXX.setMode(/*mode = */SHTXX.eHighPrecision);

}

void loop() {
  temperature = SHTXX.getTemperature();

  humidity = SHTXX.getHumidity();

  //SHTXX.getTemHum(temperature,humidity);

  Serial.print("Temperature :"); Serial.print(temperature); Serial.println(" C");

  Serial.print("Humidity :"); Serial.print(humidity); Serial.println(" %RH");

  delay(1000);

  Serial.println("----------------------------------------");
}
