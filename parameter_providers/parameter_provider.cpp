#include "parameter_provider.h"

void parameter_provider::update()
{
	update_value();
	notify_observers(parameter_value);
}

void parameter_provider::update_value()
{
	throw "Unimplemented funtion. Use derived class.";
}

parameter_provider::parameter_provider()
{

}
parameter_provider::~parameter_provider()
{

}

double parameter_provider::get_value()
{
	return parameter_value;
}