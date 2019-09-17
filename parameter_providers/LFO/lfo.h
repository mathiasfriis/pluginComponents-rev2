#ifndef __LFO__
#define __LFO__

#include <math.h>
#include <stdlib.h>
#include <cmath>
#include "../parameter_provider.h"
#include "../parameter/parameter.h"
//
#define myPI 3.14159265358979323846
#define UINT32MAX 4294967296

//Update 1.1 - Woo, sample&hold now works!

enum lfo_mode{_sine,_square,_triangle,_sampleHold,_walk};

	class LFO: public parameter_provider
	{
	private:
	    double fs = 0,  phase = 0, LFO_value = 0, LFO_value_target = 0, walkTime = 0, walkSpeedPrSample = 0;
		bool waveShapeStatusState = false;
	    lfo_mode mode = _sine;
		bool isPhaseUnderWaveshapeLevel();
		int randomNumber = 100;
        int cnt=0;
		double value = 0;
	public:
		LFO(void);
		LFO(double sampleRate, double frequency = 1, lfo_mode mode = _sine, double waveshape = 50, double walktime = 0.3);
		parameter frequency, waveshape;
	    void setSampleRate(double sampleRate);
	    void setLFO_mode(lfo_mode newMode);
	    void setFrequency(double freq);
        void setWaveshape(double Waveshape);
		void setWalkTime(double walktime);
	    void updateLFO_value();
		double get_LFO_value();
		double get_frequency();
		virtual void update_value();
	};
#endif