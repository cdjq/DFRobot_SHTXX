/*!
 * @file DFRobot_SHT40.h
 * @brief 定义了DFRobot_SHT40的类
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version V1.0
 * @date 2021-03-19
 * @get from https://www.dfrobot.com
 * @url  https://github.com/DFRobot/DFRobot_SHTXX
 */
#ifndef __DFROBOT_SHT40_H__
#define __DFROBOT_SHT40_H__


#include"DFRobot_SHT.h"
class DFRobot_SHT40:public DFRobot_SHTXX{
public:

  #define  SHT40_AD1B_IIC_ADDR                     0x44
  #define  SHT40_BD1B_IIC_ADDR                     0x45

  #define  COM_READ_SERIAL                   0x89
  #define  COM_SOFT_RESET                    0x94

  #define  PRECISION_HIGH_HEATER_OFF                   0xFD               /* measure T & RH with high precision (high repeatability) */
  #define  PRECISION_MID_HEATER_OFF                    0xF6               /* measure T & RH with medium precision (medium repeatability) */
  #define  PRECISION_LOW_HEATER_OFF                    0xE0               /* measure T & RH with lowest precision (low repeatability) */
  #define  PRECISION_HIGH_HEATER_1S                    0x39               /* activate highest heater power & high precis. meas. for 1s */
  #define  PRECISION_HIGH_HEATER_100MS                 0x32               /* activate highest heater power & high precis. meas. for 0.1s */
  #define  PRECISION_MID_HEATER_1S                     0x2F               /* activate medium heater power  & high precis. meas. for 1s */
  #define  PRECISION_MID_HEATER_100MS                  0x24               /* activate medium heater power  & high precis. meas. for 0.1s */
  #define  PRECISION_LOW_HEATER_1S                     0x1E               /* activate lowest heater power  & high precis. meas. for 1s */
  #define  PRECISION_LOW_HEATER_100MS                  0x15               /* activate lowest heater power  & high precis. meas. for 0.1s */
  sDev_t deviceinit[SHTXX_CONFIG_MAX];
public:

  /**
   * @brief  constructed function
   * @param  pWire  When instantiate this class, you can specify its twowire
   */
  DFRobot_SHT40(uint8_t addr, TwoWire *pWire = &Wire);

  /**
   * @brief  初始化Wire,并且对传感器进行软件复位
   */
  void begin();

private:
  /**
   * @brief  父类方法setMode()对应子类的“类回调函数”,这里用作设置延时
   * @param   classPtr  指向子类的指针
   * @param   mode  用户指定的设备工作模式
   */
  static void setModeCB(void * calssPtr, uint16_t mode);

  /**
   * @brief  父类方法softwareReset()对应子类的“类回调函数”,这里用作设置延时
   * @param  ...  可变参数,这里不用任何用途
   */
  static void softwareResetCB(...);

  /**
   * @brief   父类方法getDeviceIDCB()对应子类的“类回调函数”,这里用作获取传感器的设备ID
   * @param   classPtr  指向子类的指针
   * @param   id  指向设备ID的指针
   */
  static void getDeviceIDCB(void * classPtr, void * id);

};

#endif
