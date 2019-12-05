//
// Created by Timothée Couble on 03/11/2019.
//

#include "EasingFunctions.hpp"

float ease::outBounce(float t, float b , float c, float d) {
    if ((t/=d) < (1/2.75f)) {
        return c*(7.5625f*t*t) + b;
    } else if (t < (2/2.75f)) {
        float postFix = t-=(1.5f/2.75f);
        return c*(7.5625f*(postFix)*t + .75f) + b;
    } else if (t < (2.5/2.75)) {
        float postFix = t-=(2.25f/2.75f);
        return c*(7.5625f*(postFix)*t + .9375f) + b;
    } else {
        float postFix = t-=(2.625f/2.75f);
        return c*(7.5625f*(postFix)*t + .984375f) + b;
    }
}

float ease::inBack(float t, float b , float c, float d) {
    float s = 2.1f;
    float postFix = t/=d;
    return c*(postFix)*t*((s+1)*t - s) + b;
}