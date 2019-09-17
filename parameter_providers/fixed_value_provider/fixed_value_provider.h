#ifndef __FIXED_VALUE_PROVIDER__
#define __FIXED_VALUE_PROVIDER__

#include "../parameter_provider.h"
class fixed_value_provider : public parameter_provider
{
private:
	double value;
public:
	fixed_value_provider();
	fixed_value_provider(double val);
	void set_value(double val);
};
#endif