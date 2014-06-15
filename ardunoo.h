/*-----------------------------------------------
 *
 *  Library for NooLite modules like MT1132
 *
 * (c) Sergey Zhumatiy 2014
 * http://github.com/zhum/ardunoo/
 *
 *-----------------------------------------------
 */


#ifndef ARDUNOO_H
#define ARDUNOO_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <SoftwareSerial.h>

class ArduNoo {

  byte chnl;
  SoftwareSerial ns;

public:
  ArduNoo(byte rx, byte tx, byte ch=0);
  byte channel(byte ch=-1);
  void on(byte ch=-1);
  void off(byte ch=-1);
  void onoff(byte ch=-1);
  void bind(byte ch=-1);
  void unbind(byte ch=-1);
  void slow_on(byte ch=-1);
  void slow_off(byte ch=-1);
  void slow_onoff(byte ch=-1);
  void run_scene(byte ch=-1);
  void record_scene(byte ch=-1);

  bool command(byte channel, byte command);
};

#endif
