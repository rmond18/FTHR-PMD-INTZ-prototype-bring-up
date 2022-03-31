/*******************************************************************************
* Copyright (C) 2018 Maxim Integrated Products, Inc., All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
*******************************************************************************
*/
#include "mbed.h"
#include "max32630fthr.h"
#include <DigitalOut.h>

MAX32630FTHR pegasus(MAX32630FTHR::VIO_3V3);

//SPI PINS
DigitalOut sck_pin(P5_0);
DigitalOut mosi_pin(P5_1);      
DigitalOut miso_pin(P5_2);
DigitalOut cs_pin(P5_3);
DigitalOut spi_gpio0_pin(P4_0);
DigitalOut spi_gpio1_pin(P5_6);
DigitalOut spi_gpio2_pin(P5_5);
DigitalOut spi_gpio3_pin(P5_4);

//I2C PINS
DigitalOut scl_pin(P3_5);
DigitalOut sda_pin(P3_4);
DigitalOut i2c_gpio0_pin(P3_3);
DigitalOut i2c_gpio1_pin(P3_2);



int main()
{
    while(1){
        scl_pin=1;
        sda_pin=1;
        sck_pin=1;
        mosi_pin=1;
        miso_pin=1;
        cs_pin=1;
        spi_gpio0_pin=1;
        spi_gpio1_pin=1;
        spi_gpio2_pin=1;
        spi_gpio3_pin=1;
        i2c_gpio0_pin=1;
        i2c_gpio1_pin=1;
        printf("spi ans i2c pinouts SET TO HIGH\n");
        wait(3);
        
        scl_pin=0;
        sda_pin=0;
        sck_pin=0;
        mosi_pin=0;
        miso_pin=0;
        cs_pin=0;
        spi_gpio0_pin=0;
        spi_gpio1_pin=0;
        spi_gpio2_pin=0;
        spi_gpio3_pin=0;
        i2c_gpio0_pin=0;
        i2c_gpio1_pin=0;
        printf("spi and i2c pinouts SET TO LOW\n");
        wait(3);

    }
}

