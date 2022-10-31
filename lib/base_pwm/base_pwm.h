#ifndef _BASE_PWM_H_
#define _BASE_PWM_H_

#include <Arduino.h>
#define MAX_8BIT    256

typedef enum _wave_mask
{
    square,
    saw,
    triangle,
    sine
}wave_mask_t;

class c_timer
{
public:
    c_timer();
    void init();
    void start();
    void stop();
    void reset();
private:
};

class c_waveform
{
public:
    c_waveform(wave_mask_t type);
    wave_mask_t type;

private:
    uint8_t lut[MAX_8BIT] = {0};

    /*
    Calc a max amplitude squarewave of 50% duty cycle
    */
    void calc_square(){
        for(uint8_t i=0; i<(MAX_8BIT/2); i++){
            lut[i] = MAX_8BIT;
        }
        for(uint8_t i=(MAX_8BIT/2); i<MAX_8BIT; i++){
            lut[i] = 0;
        }
    }

    /*
    Calc a max amplitude rising sawtooth
    */
    void calc_saw(){
        for(uint8_t i=0; i<MAX_8BIT; i++){
            lut[i] = i;
        }
    }

    /*
    Calc a max amplitude squarewave of 50% duty cycle
    */
    void calc_triangle(){
        for(uint8_t i=0; i<(MAX_8BIT/2); i++){
            lut[i] = i * 2;
        }
        for(uint8_t i=(MAX_8BIT/2); i<MAX_8BIT; i++){
            lut[i] = MAX_8BIT - ((MAX_8BIT/2) - (i * 2));
        }
    }

    /*
    Calc a max amplitude squarewave of 50% duty cycle
    */
    void calc_sine(){

    }
};

#endif
