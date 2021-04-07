/*!
 * @file temperatureAndHumidity.ino
 * @brief Measurement of temperature and humidity
 * @n 本传感器可测量温湿度数据,温度的测量范围在-40~125 ℃ ,湿度的测量范围在 0~100 %RH。
 * @n 本传感器提供高、中、低,三种测量精度,还提供了高、中、低,三种加热功率对片上加热器进行加热。
 * @n 使用加热器的主要情景：
 * @n 1、Removal of condensed / spray water on the sensor surface. Although condensed water is not a reliability / quality problem to the sensor, it will however make the sensor nonresponsive to RH changes in the air as long as there is liquid water on the surface.
 * @n 2、Creep-free operation in high humid environments. Periodic heating pulses allow for creepSTXfree high-humidity measurements for extended times.
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version  V1.0
 * @date  2021-03-19
 * @get from https://www.dfrobot.com
 * @url  https://github.com/DFRobot/DFRobot_SHTXX
 */
#include"DFRobot_SHT40.h"

/** 
 *  对于SHT40传感器这里支持两种型号,第一种是SHT40_AD1B, 第二种是SHT40_BD1B,这两种型号对应不同的IIC设备地址,这里对它们进行了封装,用户可传入如下两种参数
 *  型号为SHT40_AD1B的传感器使用:    SHT40_AD1B_IIC_ADDR
 *  型号为SHT40_AD1B的传感器使用:    SHT40_BD1B_IIC_ADDR
 */
DFRobot_SHT40 SHT40(SHT40_AD1B_IIC_ADDR); 


uint32_t id = 0;
float temperature, humidity;

void setup() {

  Serial.begin(9600);
  SHT40.begin();

  while((id = SHT40.getDeviceID()) == 0){
    Serial.println("ID retrieval error, please check whether the device is connected correctly!!!");
    delay(1000);
  }

  delay(1000);
  Serial.print("id :0x"); Serial.println(id, HEX);
  /**
   *    mode 用来配置传感器的工作模式
   *          SHT40:
   *                  PRECISION_HIGH_HEATER_OFF                       measure T & RH with high precision (high repeatability) 
   *                  PRECISION_MID_HEATER_OFF                        measure T & RH with medium precision (medium repeatability)
   *                  PRECISION_LOW_HEATER_OFF                        measure T & RH with lowest precision (low repeatability) 
   *                  PRECISION_HIGH_HEATER_1S                        activate highest heater power & high precis. meas. for 1s 
   *                  PRECISION_HIGH_HEATER_100MS                     activate highest heater power & high precis. meas. for 0.1s
   *                  PRECISION_MID_HEATER_1S                         activate medium heater power  & high precis. meas. for 1s 
   *                  PRECISION_MID_HEATER_100MS                      activate medium heater power  & high precis. meas. for 0.1s 
   *                  PRECISION_LOW_HEATER_1S                         activate lowest heater power  & high precis. meas. for 1s 
   *                  PRECISION_LOW_HEATER_100MS                      activate lowest heater power  & high precis. meas. for 0.1s 
   */
  SHT40.setMode(/*mode = */PRECISION_HIGH_HEATER_OFF);

}

void loop() {
  temperature = SHT40.getTemperature();

  humidity = SHT40.getHumidity();

  //SHTXX.getTemHum(temperature,humidity);

  Serial.print("Temperature :"); Serial.print(temperature); Serial.println(" C");

  Serial.print("Humidity :"); Serial.print(humidity); Serial.println(" %RH");

  delay(1000);

  Serial.println("----------------------------------------");
}
