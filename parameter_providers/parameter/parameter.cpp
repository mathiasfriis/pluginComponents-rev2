#include "parameter.h"

parameter::parameter()
{
	this->id = "N/A";
	parameter_value = 0;
}

parameter::parameter(string id)
{
	this->id = id;
	parameter_value = 0;
}

parameter::~parameter()
{

}

void parameter::set_value(double val)
{
	parameter_value = val;
}

void parameter::attach_to_source(parameter_provider& source)
{
	source.register_observer(*this, id);
}

void parameter::notify(double val)
{
	parameter_value = val;
}

double parameter::get_value()
{
	return parameter_value;
}