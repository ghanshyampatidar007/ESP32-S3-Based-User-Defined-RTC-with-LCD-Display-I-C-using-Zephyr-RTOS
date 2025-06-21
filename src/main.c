#include "lcd.h"
#include <zephyr/sys/printk.h>


static int64_t time_offset_ms = 0;

void set_time(int64_t seconds)
{
    time_offset_ms = seconds * 1000 - k_uptime_get();
}

void get_time(int64_t *hours, int64_t *minutes, int64_t *seconds)
{
    int64_t total_ms = k_uptime_get() + time_offset_ms;
    int64_t total_sec = total_ms / 1000;

    *hours = (total_sec / 3600) % 24;
    *minutes = (total_sec / 60) % 60;
    *seconds = total_sec % 60;
}

void convert_into_string(uint8_t *str,int64_t hr,int64_t min,int64_t sec){
    str[0]=(hr/10)+48;
    str[1]=(hr%10)+48;
    str[2]=':';

    str[3]=(min/10)+48;
    str[4]=(min%10)+48;
    str[5]=':';
    
    str[6]=(sec/10)+48;
    str[7]=(sec%10)+48;
    str[8]='\0';
}

int main(void) {
    uint8_t str[9];

    int64_t hr, min, sec;
    
    set_time(5 * 3600 + 3 * 60);
   // k_uptime_set(10000);
  

    const struct device *i2c_dev = DEVICE_DT_GET(DT_NODELABEL(i2c0));
    
    if (!device_is_ready(i2c_dev)) {
        printk("I2C not ready!\n");
        return 0;
    }

    lcd_init(i2c_dev);
    
    while(1){   
   // if(i>3){i=0;}
        
        lcd_send_cmd(i2c_dev,0x80);
        lcd_print(i2c_dev,"GHANSHYAM PATIDAR");
        lcd_send_cmd(i2c_dev,0xc0);
        lcd_print(i2c_dev,"Current time:- ");
        lcd_send_cmd(i2c_dev,0x94);
        lcd_print(i2c_dev,str);
        k_msleep(1000);
       
        // lcd_send_cmd(i2c_dev,0x01);
       // k_msleep(2); 

        convert_into_string(str,hr,min,sec);
        get_time(&hr, &min, &sec);
        printk("Current time: %02lld:%02lld:%02lld\n", hr, min, sec);
       
        //k_sleep(K_SECONDS(1));
    }
    while(1);
}
