#include "../LFO/lfo.h"

//Update 1.1 - Woo, sample&hold now works!

#define MAX_WALK_TIME 3

	LFO::LFO(void)
	{
		this->fs = 1;
		this->mode = _sine;
		this->value = 0;
		this->frequency = *new parameter();
		this->waveshape = *new parameter();
		setWalkTime(0.3);
	}

	LFO::LFO(double sampleRate, double frequency, lfo_mode mode, double waveshape, double walktime)
	{
		if (sampleRate < 1)
			this->fs = 41000;
		else
			this->fs = sampleRate;
		this->mode = mode;
		this->value = 0;
		this->frequency = *new parameter();
		this->waveshape = *new parameter();
		this->frequency.set_value(frequency);
		this->waveshape.set_value(waveshape);
		setWalkTime(walktime);
	}

	void LFO::setSampleRate(double sampleRate)
	{
		this->fs = sampleRate;
	}

	void LFO::setLFO_mode(lfo_mode mode)
	{
		this->mode = mode;
	}

	void LFO::setFrequency(double freq)
	{
		this->frequency.set_value(freq);
	}

	void LFO::setWaveshape(double waveshape)
	{
		this->waveshape.set_value(waveshape);
		setWalkTime(waveshape*MAX_WALK_TIME / 100);
	}

	void LFO::setWalkTime(double walktime)
	{
		this->walkTime = walktime;
		walkSpeedPrSample = double(1)/(walktime * this->fs);
	}

	double LFO::get_LFO_value()
	{
		return LFO_value;
	}

	double LFO::get_frequency()
	{
		return frequency.get_value();
	}

	bool LFO::isPhaseUnderWaveshapeLevel()
	{
		if (phase * 100 / (2 * myPI) < waveshape.get_value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void LFO::updateLFO_value()
	{
		phase = (phase + 2 * myPI / fs * frequency.get_value());
		phase = fmod(phase, (float)(2 * myPI));
		switch (mode)
		{
		case _sine:
			LFO_value = sin(phase) / 2 + 0.5;
			break;

		case _square:
			if (isPhaseUnderWaveshapeLevel())
			{
				LFO_value = 1;
			}
			else
			{
				LFO_value = 0;
			}
			break;

		case _triangle:
		{
			double dydt_UP = 1 / (2 * myPI / 100 * waveshape.get_value()); //slope of ramp when going up.
			double dydt_DOWN = 1 / (2 * myPI / 100 * (100 - waveshape.get_value())); //slope of ramp when going down.
			if (isPhaseUnderWaveshapeLevel())
			{
				LFO_value = phase * dydt_UP;
			}
			else
			{
				LFO_value = 1 - (phase - waveshape.get_value() * 2 * myPI / 100)*dydt_DOWN;
			}
			break;
		}
		case _sampleHold:
		{
			// Triggers at waveShape-level and at 0 ('ish)
			if (isPhaseUnderWaveshapeLevel() != waveShapeStatusState)
			{
				LFO_value = rand() / double(RAND_MAX);

				if (LFO_value < 0) LFO_value = 0;
				if (LFO_value > 1) LFO_value = 1;
			}
			//update waveShape status state
			waveShapeStatusState = isPhaseUnderWaveshapeLevel();
		}
		break;
		case _walk:
		{
			walkSpeedPrSample = waveshape.get_value() * MAX_WALK_TIME / 100 / fs;
			// Triggers at waveShape-level and at 0 ('ish)
			if (isPhaseUnderWaveshapeLevel() != waveShapeStatusState)
			{


				LFO_value_target = rand() / double(RAND_MAX);

				if (LFO_value_target < 0) LFO_value_target = 0;
				if (LFO_value_target > 1) LFO_value_target = 1;
			}

			//if current value is lower than target value
			if (LFO_value < LFO_value_target)
			{
				//If difference is lower than stepSize, stabilize.
				if (abs(LFO_value_target - LFO_value) < walkSpeedPrSample)
				{
					LFO_value = LFO_value_target;
				}
				else
				{
					LFO_value += walkSpeedPrSample;
				}
			}
			else
			{
				//If difference is lower than stepSize, stabilize.
				if (abs(LFO_value_target - LFO_value) < walkSpeedPrSample)
				{
					LFO_value = LFO_value_target;
				}
				else
				{
					LFO_value -= walkSpeedPrSample;
				}
			}

			//update waveShape status state
			waveShapeStatusState = isPhaseUnderWaveshapeLevel();
		}
		break;
		}
	}

	void LFO::update_value()
	{
		updateLFO_value();
		parameter_value = LFO_value;
	}