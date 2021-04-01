/*!
 * @file DFRobot_SHTC3.h
 * @brief 定义了DFRobot_SHTC3类
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version V1.0
 * @date 2021-03-19
 * @get from https://www.dfrobot.com
 * @url  https://github.com/DFRobot/DFRobot_SHTXX
 */
#ifndef __DFROBOT_SHTC3_H__
#define __DFROBOT_SHTC3_H__

#include "DFRobot_SHTXX.h"

class DFRobot_SHTC3: public DFRobot_SHTXX {

public:

  #define SHTC3_IIC_ADDR                             0x70
  #define COMMAND_SLEEP                              0xB098
  #define COMMAND_SOFTWARE_RESET                     0x805D
  #define COMMAND_WAKEUP                             0x3517
  #define COMMAND_DEVICE_ID                          0xEFC8

  typedef enum{ 
    eEnClkStretch = 0x7CA2,                                   /* Clock Stretching Enabled */
    eDisClkStretch = 0x7866,                                  /* Clock Stretching Disabled */
    eEnClkStretchLowP = 0x6458,                              /* Clock Stretching Enabled & Low Power */
    eDisClkStretchLowP = 0x609C,                             /* Clock Stretching Disabled & Low Power */
  }eWorkingMode_t;

  sDev_t deviceinit[SHTXX_CONFIG_MAX];

public:

  /**
   * @brief  constructed function
   * @param  pWire  When instantiate this class, you can specify its twowire
   */
  DFRobot_SHTC3(TwoWire *pWire = &Wire);
  
  /**
   * @brief  Destructor
   */
  ~DFRobot_SHTC3(){};
  
  /**
   * @brief  初始化Wire，并且对传感器进行软件复位，然后使传感器进入睡眠状态，需要使用时，在对其进行唤醒。
   */
  void begin();



  /**
   * @brief  当传感器处于睡眠模式时，在进行任何进一步的通信之前，需要唤醒
   */
  void wakeup();
  
  /**
   * @brief  设置传感器为睡眠模式，设置后，在未唤醒前无法进行数据采集
   */
  void sleep();

private:
  /**
   * @brief  父类方法setMode()对应子类的“类回调函数”，这里用作设置延时
   * @param  ...  可变参数，这里不用任何用途
   */
  static void setModeCB(...);

  /**
   * @brief  父类方法softwareReset()对应子类的“类回调函数”，这里用作设置延时
   * @param  ...  可变参数，这里不用任何用途
   */
  static void softwareResetCB(...);

  /**
   * @brief   父类方法getDeviceIDCB()对应子类的“类回调函数”，这里用作获取传感器的设备ID
   * @param   classPtr  指向子类的指针
   * @param   id  指向设备ID的指针
   */
  static void getDeviceIDCB(void * classPtr ,void * id);

};
#endif