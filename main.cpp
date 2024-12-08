#include "mbed.h"
#include "LITE_EPS.h"
#include "LITE_SENSOR.h"
LITE_EPS eps(PA_0,PA_4);
LITE_SENSOR sensor(PA_7,PB_7,PB_6);
RawSerial pc(USBTX,USBRX,9600);
int main()
{
    float ax,ay,az;
    pc.printf("Acceleration Sensor\r\n");
    eps.turn_on_regulator();
    sensor.set_up();
    for(int i = 0; i < 10; i++){
        sensor.sen_acc(&ax,&ay,&az);
        pc.printf("acc : %f,%f,%f\r\n",ax,ay,az);
        wait_ms(1000);
    }
}