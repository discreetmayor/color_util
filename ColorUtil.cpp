/*
 * ColorUtil.cpp
 *
 *  Created on: Feb 19, 2020
 *      Author: mh
 */

#include "ColorUtil.h"

namespace colorUtil {

    void blend(rgbColorFloat *destC, rgbColorFloat *c1, rgbColorFloat *c2, float blendAmount) {
        destC->red   = (c1->red * (1-blendAmount)) + (c2->red * blendAmount);
        destC->green = (c1->green * (1-blendAmount)) + (c2->green * blendAmount);
        destC->blue  = (c1->blue * (1-blendAmount)) + (c2->blue * blendAmount);
    }

    rgbColorFloat toFloat(rgbColor *c) {
        rgbColorFloat color = {
             red: (float)c->red/EIGHTBIT_MAX,
             green: (float)c->green/EIGHTBIT_MAX,
             blue: (float)c->blue/EIGHTBIT_MAX
        };
        return color;
    }

    rgbColor quantize(rgbColorFloat *c) {
        rgbColor color = {
             red: (uint8_t)(EIGHTBIT(c->red*EIGHTBIT_MAX)),
             green: (uint8_t)(EIGHTBIT(c->green*EIGHTBIT_MAX)),
             blue: (uint8_t)(EIGHTBIT(c->blue*EIGHTBIT_MAX))
        };
        return color;
    }

    uint8_t quantize(float value) {
        return (uint8_t)(EIGHTBIT(value*EIGHTBIT_MAX));
    }
}
