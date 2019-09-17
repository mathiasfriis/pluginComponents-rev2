#include "../mixer/mixer.h"

mixer::mixer(void)
{
	init_parameters();
	set_level_ch_1(1);
	set_level_ch_2(1);
}

mixer::mixer(string id)
{
	this->id = id;
	init_parameters();
	set_level_ch_1(1);
	set_level_ch_2(1);
}

mixer::mixer(string id, double l_ch_1, double l_ch_2)
{
	this->id = id;
	init_parameters();
	set_level_ch_1(l_ch_1);
	set_level_ch_2(l_ch_2);
}

void mixer::init_parameters()
{
	level_ch_1 = *new parameter(this->id+"__level_ch_1");
	level_ch_2 = *new parameter(this->id + "__level_ch_2");
	sig_ch_1 = *new parameter(this->id + "__sig_ch_1");
	sig_ch_2 = *new parameter(this->id + "__sig_ch_2");
}

void mixer::set_level_ch_1(double level)
{
	level_ch_1.set_value(level);
}

void mixer::set_level_ch_2(double level)
{
	level_ch_2.set_value(level);
}

void mixer::set_mix(double level)
{
	set_level_ch_1(level);
	set_level_ch_2(1 - level);
}

float mixer::get_level_ch_1()
{
	return level_ch_1.get_value();
}

float mixer::get_level_ch_2()
{
	return level_ch_2.get_value();
}

void mixer::update_value()
{
	parameter_value = level_ch_1.get_value()*sig_ch_1.get_value() + level_ch_2.get_value()*sig_ch_2.get_value();
	notify_observers(parameter_value);
}