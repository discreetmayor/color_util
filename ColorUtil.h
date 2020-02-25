/*
 * ColorUtil.h
 *
 *  Created on: Feb 24, 2020
 *      Author: mh
 */

#ifndef COLORUTIL_H_
#define COLORUTIL_H_

#define MINZERO(a) ((a) < 0 ? 0 : (a))
#define EIGHTBIT(a) ((a) > 255 ? 255 : MINZERO(a))
#define EIGHTBIT_MAX 255

#include <stdint.h>
#include <math.h>


namespace colorUtil {

    typedef struct rgbColor {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } rgbColor;

    typedef struct rgbColorFloat {
        float red;
        float green;
        float blue;
    } rgbColorFloat;

    void colorBlend(rgbColorFloat *destC, rgbColorFloat *c1, rgbColorFloat *c2, float blendAmount);
    rgbColorFloat toFloat(rgbColor *c);
    rgbColor quantize(rgbColorFloat *c);
    uint8_t quantize(float value);

}


#endif /* COLORUTIL_H_ */
