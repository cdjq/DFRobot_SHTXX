/*!
 * @file DFRobot_SHTXX.h
 * @brief 包含了SHT系列传感器的父类的定义
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version V1.0
 * @date 2021-03-19
 * @url  https://github.com/DFRobot/DFRobot_SHTXX
 */
#ifndef _DFROBOT_SHTXX_H_
#define _DFROBOT_SHTXX_H_

#include <Arduino.h>
#include <Wire.h>



//打开这个宏，可以看到程序的详细运行过程
#define ENABLE_DBG

#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

/******************************************构造了一个父类访问子类数据和方法的结构体****************************************/
typedef void (*funPtr)(...);
typedef struct {
  uint16_t addr;
  uint8_t len;
  funPtr fun;
}sDev_t;

/* 结构体数组的成员数目 */
#define SHTXX_CONFIG_MAX           3

#define SHTXX_CONFIG_ID            0       //结构体数组的第一位成员，指定为ID相关内容
#define SHTXX_CONFIG_SOFT_RESET    1       //结构体数组的第二位成员，指定为软件复位相关内容
#define SHTXX_CONFIG_MODE          2       //结构体数组的第三位成员，指定为设置传感器工作模式相关内容
/**********************************************************************************************************************/

class DFRobot_SHTXX{
public:

  DFRobot_SHTXX(uint8_t addr,TwoWire *pWire,sDev_t * dev,void * p);
  ~DFRobot_SHTXX(){};

  /**
   * @brief  对主控板的IIC进行了初始化
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
   * @brief  获取温湿度数据
   * @param   tem  存放温度数据的引用
   * @param   hum  存放湿度数据的引用
   */
  void  getTemHum(float &tem , float &hum);

  /**
   * @brief  设置传感器工作模式
   * @param  mode  传感器的工作模式
   * @n            SHTC3：
   * @n                    eEnClkStretch                              Clock Stretching Enabled 
   * @n                    eDisClkStretch                             Clock Stretching Disabled 
   * @n                    eEnClkStretchLowP                          Clock Stretching Enabled & Low Power
   * @n                    eDisClkStretchLowP                         Clock Stretching Disabled & Low Power
   * @n            SHT40:
   * @n                    eHighPrecision                             measure T & RH with high precision (high repeatability) 
   * @n                    eMediumPrecision                           measure T & RH with medium precision (medium repeatability)
   * @n                    eLowPrecision                              measure T & RH with lowest precision (low repeatability) 
   * @n                    eHeaterHighPLongT                          activate highest heater power & high precis. meas. (typ. 200mW @ 3.3V) for 1s 
   * @n                    eHeaterHighPShortT                         activate highest heater power & high precis. meas. (typ. 200mW @ 3.3V) for 0.1s
   * @n                    eHeaterMediumPLongT                        activate medium heater power  & high precis. meas. (typ. 110mW @ 3.3V) for 1s 
   * @n                    eHeaterMediumPShortT                       activate medium heater power  & high precis. meas. (typ. 110mW @ 3.3V) for 0.1s 
   * @n                    eHeaterLowPLongT                           activate lowest heater power  & high precis. meas. (typ. 20mW @ 3.3V) for 1s 
   * @n                    eHeaterLowPShortT                          activate lowest heater power  & high precis. meas. (typ. 20mW @ 3.3V) for 0.1s 
   */
   void setMode(uint16_t mode) ;

  /**
   * @brief  获取传感器的唯一标识符
   * @return 获取成功返回传感器的唯一标识符，失败返回0
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
   bool getTandRHRawData(uint16_t *temp,uint16_t *hum);

  
  /**
   * @brief  将从传感器获得的数据进行再次校验比对，判断从传感器获得的数据是否正确
   * @param  data1  High 8 bits to check value
   * @param  data2  LOW 8 bits to check value
   * @param  crcValue  Check value returned by the sensor
   * @return Check success return true ;Check failed return false
   */
  bool checkCrc(uint8_t data1,uint8_t data2,uint8_t crcValue);

  /**
   * @brief  对传感器进行写命令操作
   * @param  command  指向命令的指针
   * @param  len      命令长度
   */
   void writeCommand(uint8_t* command,uint8_t len);

  /**
   * @brief 读取传感器采集的数据
   * @param pBuf 要写入数据的存放缓存
   * @param size 要写入数据的长度
   * @return 返回实际读取的长度，返回0表示读取失败
   */
  uint8_t readValue(void* pBuf, size_t size);

protected:
  TwoWire *_pWire;
  void* _p;
  uint8_t _deviceAddr;
  sDev_t * _dev;
  uint16_t _mode;

};

#include "DFRobot_SHT40.h"
#include "DFRobot_SHTC3.h"

#endif
