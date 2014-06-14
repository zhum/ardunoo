#include <ardunoo.h>

ArduNoo::ArduNoo(byte rx, byte tx, byte ch): serial(rx,tx){
  channel=ch;
}

byte ArduNoo::channel(byte ch){
  if(ch>=0)
    channel=ch;
  return channel;
}

void ArduNoo::on(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 2);
}

void ArduNoo::off(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 0);
}

void ArduNoo::onoff(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 4);
}

void ArduNoo::bind(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 15);
}

void ArduNoo::unbind(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 9);
}

void ArduNoo::slow_on(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 3);
}

void ArduNoo::slow_off(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 1);
}

void ArduNoo::slow_onoff(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 5);
}

void ArduNoo::run_scene(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 7);
}

void ArduNoo::record_scene(byte ch){
  if(ch<0)
    ch=channel;
  command(ch, 8);
}

void ArduNoo::command(byte channel, byte command){
  static byte i, buf[12]={85,B01010000,0,0,0,0,0,0,0,0,0,170};
  int sum = 0;
  
  memset(buf+2,0,9); /* clear the biody */

  buf[2] = command;
  buf[5] = channel;
  
  for(byte i = 0; i < 10; ++i) {
    sum+= buf[i];
  }
  buf[10] = lowByte(sum);
  buf[11] = 170; 
  
  for(i=0;i<12;++i){
    serial.write(buf[i]);
  } 
}
