# DFRobot_SHT

## DFRobot_SHTC3

The SHTC3 is a digital humidity and temperature sensor designed especially for high-volume consumer electronics applications.

The sensor covers a humidity measurement range of 0 to 100 %RH and a temperature measurement range of - 40 °C to 125 °C with a typical accuracy of ±2 %RH and ±0.2°C.

![](D:\Arduino\libraries\DFRobot_SHTXX\resources\images\SEN0414svg1.png)

## DFRobot_SHT40

该传感器的工作范围为0至100 % RH,温度范围为40°C至125°C,精度为±1.8% RH和±0.2°C.SHT40的供电电压范围从1.08 V到3.6 V,平均电流400 nA,非常适合移动和电池驱动的应用。

![](D:\Arduino\libraries\DFRobot_SHTXX\resources\images\SEN0428svg1 - .png)

## 产品链接（https://www.dfrobot.com/）
    SKU：SEN0414
    SKU：SEN0428

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)
<snippet>
<content>

## Summary
Measurement of temperature and humidity

## Installation

To use this library, download the library file first, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods—DFRobot_SHT

```C++
  /**
   * @brief  对主控板的IIC进行了初始化
   */
  void begin();

  /**
   * @brief  获取温度数据
   * @return 温度值,单位：摄氏度
   */
  float getTemperature();

  /**
   * @brief  获取湿度数据
   * @return 湿度值,单位：%RH
   */
  float getHumidity();

  /**
   * @brief  获取温湿度数据
   * @param   tem  存放温度数据的引用
   * @param   hum  存放湿度数据的引用
   */
  void  getTemHum(float &tem, float &hum);

  /**
   * @brief  设置传感器工作模式
   * @param  mode  传感器的工作模式
   * @n            SHTC3：
   * @n                    PRECISION_HIGH_CLKSTRETCH_ON                              Clock Stretching Enabled 
   * @n                    PRECISION_HIGH_CLKSTRETCH_OFF                             Clock Stretching Disabled 
   * @n                    PRECISION_LOW_CLKSTRETCH_ON                               Clock Stretching Enabled & Low Power
   * @n                    PRECISION_LOW_CLKSTRETCH_OFF                              Clock Stretching Disabled & Low Power
   * @n            SHT40:
   * @n                    PRECISION_HIGH_HEATER_OFF                                 measure T & RH with high precision (high repeatability) 
   * @n                    PRECISION_MID_HEATER_OFF                                  measure T & RH with medium precision (medium repeatability)
   * @n                    PRECISION_LOW_HEATER_OFF                                  measure T & RH with lowest precision (low repeatability) 
   * @n                    PRECISION_HIGH_HEATER_1S                                  activate highest heater power & high precis. meas. (typ. 200mW @ 3.3V) for 1s 
   * @n                    PRECISION_HIGH_HEATER_100MS                               activate highest heater power & high precis. meas. (typ. 200mW @ 3.3V) for 0.1s
   * @n                    PRECISION_MID_HEATER_1S                                   activate medium heater power  & high precis. meas. (typ. 110mW @ 3.3V) for 1s 
   * @n                    PRECISION_MID_HEATER_100MS                                activate medium heater power  & high precis. meas. (typ. 110mW @ 3.3V) for 0.1s 
   * @n                    PRECISION_LOW_HEATER_1S                                   activate lowest heater power  & high precis. meas. (typ. 20mW @ 3.3V) for 1s 
   * @n                    PRECISION_LOW_HEATER_100MS                                activate lowest heater power  & high precis. meas. (typ. 20mW @ 3.3V) for 0.1s 
   */
   void setMode(uint16_t mode) ;

  /**
   * @brief  获取传感器的唯一标识符
   * @return 获取成功返回传感器的唯一标识符,失败返回0
   */
   uint32_t getDeviceID();

  /**
   * @brief  software reset
   */
   void softwareReset() ;

  /**
   * @brief  Obtain raw data of temperature and humidity
   * @param  temp Pointer to the address of the original value of the temperature
   * @param  hun   Pointer to the address of the original value of the humidity
   * @return Is the data obtained correct? return true  The data is correct ; return false  The data  is incorrect
   */
   bool getTandRHRawData(uint16_t *temp, uint16_t *hum);
```

## Methods—DFRobot_SHTC3

```C++
  /**
   * @brief  初始化Wire,并且对传感器进行软件复位,然后使传感器进入睡眠状态,需要使用时,在对其进行唤醒。
   */
  void begin();

  /**
   * @brief  当传感器处于睡眠模式时,在进行任何进一步的通信之前,需要唤醒
   */
  void wakeup();
  
  /**
   * @brief  设置传感器为睡眠模式,设置后,在未唤醒前无法进行数据采集
   */
  void sleep();
```

## Methods—DFRobot_SHT40

```C++
  /**
   * @brief  初始化Wire,并且对传感器进行软件复位
   */
  void begin();
```



## Compatibility

### DFRobot_SHTC3

| MCU                | Work Well | Work Wrong | Untested | Remarks |
| ------------------ | :-------: | :--------: | :------: | ------- |
| Arduino uno        |     √     |            |          |         |
| FireBeetle esp32   |     √     |            |          |         |
| FireBeetle esp8266 |     √     |            |          |         |
| FireBeetle m0      |     √     |            |          |         |
| Leonardo           |     √     |            |          |         |
| Microbit           |     √     |            |          |         |
| Arduino MEGA2560   |     √     |            |          |         |

### DFRobot_SHT40

| MCU                | Work Well | Work Wrong | Untested | Remarks |
| ------------------ | :-------: | :--------: | :------: | ------- |
| Arduino uno        |     √     |            |          |         |
| FireBeetle esp32   |     √     |            |          |         |
| FireBeetle esp8266 |     √     |            |          |         |
| FireBeetle m0      |     √     |            |          |         |
| Leonardo           |     √     |            |          |         |
| Microbit           |     √     |            |          |         |
| Arduino MEGA2560   |     √     |            |          |         |

## History

- data 2021-03-19
- version V1.0


## Credits

Written by [yangfeng]<feng.yang@dfrobot.com>,2021,(Welcome to our [website](https://www.dfrobot.com/))
