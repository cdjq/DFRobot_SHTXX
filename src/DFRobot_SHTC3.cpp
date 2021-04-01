/*!
 * @file DFRobot_SHTC3.cpp
 * @brief Implementation of DFRobot_SHTC3 class
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @SKU SEN0414
 * @licence The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version V1.0
 * @date 2021-02-20
 * @get from https://www.dfrobot.com
 * @url  https://github.com/DFRobot/DFRobot_SHTXX
 */
#include "DFRobot_SHTC3.h"
DFRobot_SHTC3::DFRobot_SHTC3(TwoWire *pWire):
DFRobot_SHTXX(SHTC3_IIC_ADDR , pWire , deviceinit , this)
{
  deviceinit[SHTXX_CONFIG_ID].addr = COMMAND_DEVICE_ID;
  deviceinit[SHTXX_CONFIG_SOFT_RESET].addr = COMMAND_SOFTWARE_RESET;
  deviceinit[SHTXX_CONFIG_MODE].addr = 0;
  deviceinit[SHTXX_CONFIG_ID].len = deviceinit[SHTXX_CONFIG_SOFT_RESET].len = deviceinit[SHTXX_CONFIG_MODE].len = 2;
  deviceinit[SHTXX_CONFIG_ID].fun = (void(*)(...))&DFRobot_SHTC3::getDeviceIDCB;
  deviceinit[SHTXX_CONFIG_SOFT_RESET].fun = (void (*)(...))&DFRobot_SHTC3::softwareResetCB;
  deviceinit[SHTXX_CONFIG_MODE].fun = (void (*)(...))&DFRobot_SHTC3::setModeCB;
}

void DFRobot_SHTC3::begin()
{
  DFRobot_SHTXX::begin();
  wakeup();
  softwareReset();
  sleep();
}

void DFRobot_SHTC3::softwareResetCB(...)
{
  delayMicroseconds(173);
}

void DFRobot_SHTC3::wakeup()
{
  uint16_t addr = COMMAND_WAKEUP;
  writeCommand( ( uint8_t * )&addr , 2 );
  delayMicroseconds(500);
}

void DFRobot_SHTC3::sleep()
{ 
  uint16_t addr = COMMAND_SLEEP;
  writeCommand( ( uint8_t * )&addr , 2 );
  delayMicroseconds(230);
}

void DFRobot_SHTC3::setModeCB(...)
{
  delayMicroseconds(12000);
}

void DFRobot_SHTC3::getDeviceIDCB( void * classPtr , void * id )
{
  DFRobot_SHTC3 * temp = ( DFRobot_SHTC3 *)classPtr;
  uint8_t idArray[3];
  uint16_t id1=0;

  temp->writeCommand( (uint8_t *)&temp->deviceinit[SHTXX_CONFIG_ID].addr , temp->deviceinit[SHTXX_CONFIG_ID].len );
  delayMicroseconds(12000);
  temp->readValue( ( void* )idArray , 3 );

  if(temp->checkCrc( idArray[0] , idArray[1] , idArray[2]) ){
    id1 = ( idArray[0] << 8 ) | idArray[1];
    if( ( id1 & 0x807 )  == 0x807 ){
      *(uint16_t *)id = id1;
    } else{
      *(uint16_t *)id = 0;
    }
  } else{
    *(uint16_t *)id = 0 ;
  }
}
