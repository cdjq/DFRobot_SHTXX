/*!
 * @file DFRobot_SHT40.cpp
 * @brief Implementation of DFRobot_SHT40 class
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @SKU SEN0428
 * @licence The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version V1.0
 * @date 2021-03-19
 * @url  https://github.com/DFRobot/DFRobot_SHTXX
 */

#include "DFRobot_SHT40.h"

DFRobot_SHT40::DFRobot_SHT40(uint8_t addr, TwoWire *pWire):
DFRobot_SHTXX(addr, pWire, deviceinit, this)
{
  deviceinit[SHTXX_CONFIG_ID].addr = SHT40_COM_READ_SERIAL;
  deviceinit[SHTXX_CONFIG_SOFT_RESET].addr = SHT40_COM_SOFT_RESET;
  deviceinit[SHTXX_CONFIG_MODE].addr = 0;
  deviceinit[SHTXX_CONFIG_ID].len = deviceinit[SHTXX_CONFIG_SOFT_RESET].len = deviceinit[SHTXX_CONFIG_MODE].len = 1;
  deviceinit[SHTXX_CONFIG_ID].fun = (void(*)(...))&DFRobot_SHT40::getDeviceIDCB;
  deviceinit[SHTXX_CONFIG_SOFT_RESET].fun = (void(*)(...))&DFRobot_SHT40::softwareResetCB;
  deviceinit[SHTXX_CONFIG_MODE].fun = (void (*)(...))&DFRobot_SHT40::setModeCB;
}

void DFRobot_SHT40::begin()
{
  DFRobot_SHTXX::begin();
  softwareReset();
}

void DFRobot_SHT40::setModeCB(void * calssPtr, uint16_t mode){
  uint16_t time;
  DFRobot_SHT40 * temp = (DFRobot_SHT40 *)calssPtr;

  switch(mode){
  case temp->eHighPrecision:
    time = 9;
    break;
  case temp->eMediumPrecision:
    time = 5;
    break;
  case temp->eLowPrecision:
    time = 2;
    break;
  case temp->eHeaterHighPLongT:
    time = 1200;
    break;
  case temp->eHeaterHighPShortT:
    time = 110;
    break;
  case temp->eHeaterMediumPLongT:
    time = 1100;
    break;
  case temp->eHeaterMediumPShortT:
    time = 110;
    break;
  case temp->eHeaterLowPLongT:
    time = 1100;
    break;
  case temp->eHeaterLowPShortT:
    time = 110;
    break;
  default :
    time = 9;
    break;
  }
  delay(time);
}

void DFRobot_SHT40::softwareResetCB(...)
{
  delayMicroseconds(1000);
}

void DFRobot_SHT40::getDeviceIDCB(void * classPtr, void * id)
{
  DFRobot_SHT40 * temp = (DFRobot_SHT40 *)classPtr;
  uint8_t idArray[6];

  temp->writeCommand((uint8_t *)&temp->deviceinit[SHTXX_CONFIG_ID].addr, temp->deviceinit[SHTXX_CONFIG_ID].len);
  delay(8);
  temp->readValue((void*)idArray, 6);

  if(temp->checkCrc(idArray[0], idArray[1], idArray[2]) && temp->checkCrc(idArray[3], idArray[4], idArray[5])){
    *(uint32_t *)id= ((uint32_t)idArray[0] << 24) | ((uint32_t)idArray[1] << 16) | ((uint32_t)idArray[3] << 8) | idArray[4];
  } else{
    *(uint32_t *)id = 0;
  }
}