//
// Created by james on 2/8/2018.
//

#ifndef TLC1543_H
#define TLC1543_H

#endif  TLC1543_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "Arduino.h"

#define	EOC	26
#define	Clock	27
#define	DataIn	28
#define	DataOut	29
#define	ChipSelect	30


#define    Wait1us        delayMicroseconds(1)
#define    Wait2us        delayMicroseconds(2)
#define    Wait4us        delayMicroseconds(4)
#define    Wait8us        delayMicroseconds(8)
#define    Wait10us       delayMicroseconds(10)



unsigned int analogRead(unsigned char Channel) {
    unsigned int ConvertValue;
    unsigned char i, Chan;
    unsigned char ConvertValueL, ConvertValueH;
    unsigned char delay;

    ConvertValueL = ConvertValueH = 0;
    delay = 0;
    if(digitalRead(EOC))
    {
        digitalWrite(Clock ,0);
        digitalWrite(ChipSelect ,1);
        Wait2us;
        digitalWrite(ChipSelect ,0);
        Wait2us;
        Channel = Channel << 4;
        {
            Chan = Channel;
            Chan = Chan >> 7;
            digitalWrite(DataIn,Chan & 0x01);
            Wait2us;
            digitalWrite(Clock ,1);
            digitalWrite(Clock ,0);
            Channel = Channel << 1;
        }
        for (i = 0; i < 6;i ++)
        {
            digitalWrite(Clock ,1);
            digitalWrite(Clock ,0);
        }
        digitalWrite(ChipSelect ,1);

        while ((!digitalRead(EOC)) && (delay < 10))
        {
            Wait10us;
            delay ++;
        }
        if (delay == 10)
        {
            return (0xFFFF);
        }
        else
        {
            Wait10us;
            digitalWrite(Clock ,0);
            digitalWrite(ChipSelect ,1);
            Wait1us;
            digitalWrite(ChipSelect ,0);
            Wait1us;
            for (i = 0; i < 2; i ++)
            {
                digitalWrite(Clock ,1);
                ConvertValueH <<= 1;
                if (digitalRead(DataOut))
                    ConvertValueH |= 0x1;
                digitalWrite(Clock ,0);
                Wait1us;
            }
            for (i = 0; i < 8; i ++)
            {
                digitalWrite(Clock ,1);
                ConvertValueL <<= 1;
                if (digitalRead(DataOut))
                    ConvertValueL |= 0x1;
                digitalWrite(Clock ,0);
                Wait1us;
            }
            digitalWrite(ChipSelect ,1);
            ConvertValue = ConvertValueH;
            ConvertValue <<= 8;
            ConvertValue |= ConvertValueL;
            return ConvertValue;
        }
    }
}

