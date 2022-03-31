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

MAX32630FTHR pegasus(MAX32630FTHR::VIO_3V3);

int main() {
    I2C i2c(P3_4, P3_5); //sda, scl
    int addr=0x48<<1;
    char datread[1];
    char cmd[1];
 
// //device address 
    cmd[0] = 0x0B;
    int data=i2c.write(addr, cmd, 1, true);    //serial bus register = 0x48
    if ( data== 0) //return zero on success
        printf("i2c write done\n");
    else
        printf("i2c write1 failed addr=%d\n",data);  


 //read data byte from address  
    if (i2c.read((addr|1), datread, 1) == 0){ //return zero on success
        printf("i2c read done\n");
        printf("ADT7420 ID read = %d\n", datread[0]); //ID default value= 0xCB=203
        }
    else
        printf("i2c read failed\n");
        
return 0;

}

