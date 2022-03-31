/* mbed Example Program
 * Copyright (c) 2006-2014 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "mbed.h"
#include "max32630fthr.h"

MAX32630FTHR pegasus(MAX32630FTHR::VIO_3V3);
SPI spi(P5_1, P5_2, P5_0); // mosi, miso, sclk
DigitalOut cs(P5_3);
 
int main()
{
    cs = 1;
    spi.format(8, 3);
    spi.frequency(900000);

        //Write to the SPI Slave and obtain the response.
        cs = 0;
        char tx_buffer = 0x80;
        char rx_data;
        spi.write(&tx_buffer, 1, &rx_data, 1);
        cs = 1;
        printf("AD ID register = 0x%X\n", rx_data);
        //wait(2);
        
        //The ADI_ID register holds a fixed code 0xAD=173
        if (rx_data==173)
            printf("Gyroscope is working\n");
        else
            printf("Gyroscope is not working\n");
        
        //cs = 0;
//        char txm_buffer = 0x81;
//        char rxm_data;
//        spi.write(&txm_buffer, 1, &rxm_data, 1);
//        cs = 1;
//        printf("MEMS ID register = 0x%X\n", rxm_data);   //MEMS ID = 0x1D
//        wait(2);
//        
//        cs = 0;
//        char txd_buffer = 0x82;
//        char rxd_data;
//        spi.write(&txd_buffer, 1, &rxd_data, 1);
//        cs = 1;
//        printf("DEV ID register = 0x%X\n", rxd_data);  //DEV ID = 0x92
//        wait(2);


////Set data ready register: 
////Set the sync bits to 01 to generate a data ready interrupt at the 
////SYNC/ASEL pin when new data becomes available
//        cs = 0;
//        char tx1_buffer = 0x012;
//        char rx1_data;
//        spi.write(&tx1_buffer, 1, &rx1_data, 1);
//        cs = 1;
//        printf("Data ready register = 0x%X\n", rx1_data);
// 
////Gyro x-axis data      
//        cs = 0;
//        char tx2_buffer = 0x88;
//        char rx2_data;
//        spi.write(&tx2_buffer, 1, &rx2_data, 1);
//        cs = 1;
//        printf("datax0 = 0x%X\n", rx2_data);
//        
//        cs = 0;
//        char tx3_buffer = 0x89;
//        char rx3_data;
//        spi.write(&tx3_buffer, 1, &rx3_data, 1);
//        cs = 1;
//        printf("datax1 = 0x%X\n", rx3_data);
// 
////Gyro y-axis data      
//        cs = 0;
//        char tx4_buffer = 0x8A;
//        char rx4_data;
//        spi.write(&tx4_buffer, 1, &rx4_data, 1);
//        cs = 1;
//        printf("datay0 = 0x%X\n", rx4_data);
//
//        cs = 0;
//        char tx5_buffer = 0x8B;
//        char rx5_data;
//        spi.write(&tx5_buffer, 1, &rx5_data, 1);
//        cs = 1;
//        printf("datay1 = 0x%X\n", rx5_data);
//
////how to multiple read??
//        short gyro_xlow = rx2_data;
//        short gyro_xhigh = rx3_data;
//        short gyro_x = gyro_xhigh <<8 | gyro_xlow;
//        
//        short gyro_ylow = rx4_data;
//        short gyro_yhigh = rx5_data;
//        short gyro_y = gyro_yhigh <<8 | gyro_ylow;
//        
//        printf("Gyro: X: %d Y: %d", gyro_x, gyro_y);
 
}