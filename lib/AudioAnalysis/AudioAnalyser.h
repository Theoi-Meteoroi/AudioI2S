#ifndef _AUDIO_ANALYZER_H_INCLUDED
#define _AUDIO_ANALYZER_H_INCLUDED

#include <Arduino.h>

#define ARM_MATH_CM0PLUS
#include <arm_math.h>
#include <stddef.h>

#include "../AudioInput/AudioInI2S.h"
#include "ConstantsSound.h"

enum WeightingType{
	A_WEIGHTING,
   	C_WEIGHTING,
   	Z_WEIGHTING
};

enum RMSType{
	TIME_W_WIN,
	FREQ,
	TIME_WO_WIN
};

//CLASS
class AudioAnalyser
{
public:
	double rms(void *inputBuffer, int inputSize, RMSType typeRMS, int factor);
	void scaling(void *vector, int vectorSize, double factor, bool multDiv);
	void window(void *vector, int vectorSize);
	void convert2DB(void *vector, int vectorSize);

};

#endif