#include "mbed.h"
#include "HEPTA_EPS.h"
#include "HEPTA_SENSOR.h"
HEPTA_EPS eps(PA_0,PA_4);
HEPTA_SENSOR sensor(PA_7,PB_7,PB_6,0xD0);
RawSerial pc(USBTX,USBRX,9600);
int main()
{   
    float ax,ay,az;
    pc.printf("Acceleration Sensor\r\n");
    eps.turn_on_regulator(); //Turn on 3.3V converter
    sensor.setup();
    for(int i=0;i<50;i++){
        //
        sensor.sen_acc(&ax,&ay,&az);
        pc.printf("%f,%f,%f\r\n",ax,ay,az);
        wait_ms(1000);
    }
}