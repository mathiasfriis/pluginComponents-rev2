#ifndef __MIXER__
#define __MIXER__
#include "../parameter_provider.h"
#include "../parameter/parameter.h"

	class mixer: public parameter_provider
	{
	private:
		virtual void update_value();
		void init_parameters();
		string id;
	public:
		parameter level_ch_1, level_ch_2, sig_ch_1, sig_ch_2;
		mixer(void);
		mixer(string);
		mixer(string id, double l_ch_1, double l_ch_);
		void set_level_ch_1(double level);
		void set_level_ch_2(double level);
		void set_mix(double level);

		float get_level_ch_1();
		float get_level_ch_2();
	};
#endif