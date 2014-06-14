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

#include <SoftwareSerial.h>

class ArduNoo {

  byte channel;
  SoftwareSerial serial;

  ArduNoo::ArduNoo(byte rx, byte tx, byte ch=0);
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

  // not private, but...
  void ArduNoo::command(byte channel, byte command);
}

#endif
