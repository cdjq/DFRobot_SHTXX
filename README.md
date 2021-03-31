# DFRobot_SHTXX

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

## Methods—DFRobot_SHTXX

```C++
  /**
   * @brief  初始化设备
   */
  void begin();

  /**
   * @brief  获取温度数据
   * @return 温度值，单位：摄氏度
   */
  float getTemperature();

  /**
   * @brief  获取湿度数据
   * @return 湿度值，单位：%RH
   */
  float getHumidity();
  /**
   * @brief  获取湿度数据
   * @param   tem  存放温度数据的引用
   * @param   hum  存放湿度数据的引用
   */
  void  getTemHum(float &tem , float &hum);
  
  /**
   * @brief  获取传感器的唯一标识符
   * @param  id  这里作为引用传参，将会将读取到的唯一设备标识符赋值给参数"id"
   * @return 传感器的唯一标识符
   */
  virtual bool getDeviceID(uint32_t &id)=0;

  /**
   * @brief  set the operating mode of the sensor
   * @param  mode  The operating mode of the sensor
   */
  virtual void setMode(uint8_t mode) = 0;
```

## Methods—DFRobot_SHTC3

```C++
  /**
   * @brief  初始化传感器
   * @return Whether the device is on or not. return true succeed ;return false failed.
   */
  void begin();

  /**
   * @brief  set the operating mode of the sensor
   * @param  mode  The operating mode of the sensor
   *               eEnClkStretch                     Clock Stretching Enabled
   *               eDisClkStretch                    Clock Stretching Disabled
   *               eEnClkStretchLowP                 Clock Stretching Enabled & Low Power
   *               eDisClkStretchLowP                Clock Stretching Disabled & Low Power
   */
  void setMode(uint8_t mode = eEnClkStretch);

  /**
   * @brief  当传感器处于睡眠模式时，在进行任何进一步的通信之前，需要唤醒
   */
  void wakeup();
  
  /**
   * @brief  当VDD达到the power-up voltage level时，SHTC3在230µs的持续时间后进入空闲状态。 在此之后，必须使用将传感器设置为睡眠模式。
   */
  void sleep();

  /**
   * @brief  获取传感器的唯一标识符
   * @param  id  这里作为引用传参，将会将读取到的唯一设备标识符赋值给参数"id"
   * @return 传感器的唯一标识符
   */
  bool getDeviceID(uint32_t &id);
```

## Methods—DFRobot_SHT40

```C++
  /**
   * @brief  初始化传感器
  */
  void begin();

  /**
   * @brief  获取传感器的唯一标识符
   * @param  id  这里作为引用传参，将会将读取到的唯一设备标识符赋值给参数"id"
   * @return 传感器的唯一标识符
   */
  bool getDeviceID(uint32_t &id);
  
  /**
   * @brief  set the operating mode of the sensor
   * @param  mode  The operating mode of the sensor
   *               eHighPrecision           measure T & RH with high precision (high repeatability)
   *               eMediumPrecision         measure T & RH with medium precision (medium repeatability)
   *               eLowPrecision            measure T & RH with lowest precision (low repeatability)
   *               eHeaterHighPLongT        activate highest heater power & high precis. meas. (typ. 200mW @ 3.3V) for 1s
   *               eHeaterHighPShortT       activate highest heater power & high precis. meas. (typ. 200mW @ 3.3V) for 0.1s
   *               eHeaterMediumPLongT      activate medium heater power  & high precis. meas. (typ. 110mW @ 3.3V) for 1s
   *               eHeaterMediumPShortT     activate medium heater power  & high precis. meas. (typ. 110mW @ 3.3V) for 0.1s
   *               eHeaterLowPLongT         activate lowest heater power  & high precis. meas. (typ. 20mW @ 3.3V) for 1s
   *               eHeaterLowPShortT        activate lowest heater power  & high precis. meas. (typ. 20mW @ 3.3V) for 0.1s
   */
  void setMode(uint8_t mode=eHighPrecision);
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
