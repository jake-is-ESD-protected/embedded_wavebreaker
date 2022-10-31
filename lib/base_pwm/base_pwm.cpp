#include "base_pwm.h"

c_waveform::c_waveform(wave_mask_t type)
{
    switch (type)
    {
    case square:
        calc_square();
        type = square;
        break;
    case saw:
        calc_saw();
        type = saw;
        break;
    case triangle:
        calc_triangle();
        type = triangle;
        break;
    case sine:
        calc_sine();
        type = sine;
        break;    
    default:
        // add error handler
        break;
    }
}