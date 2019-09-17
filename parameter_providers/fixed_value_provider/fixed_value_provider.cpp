#include "fixed_value_provider.h"

fixed_value_provider::fixed_value_provider()
{
	value = 0;
	notify_observers(value);
}

fixed_value_provider::fixed_value_provider(double val)
{
	value = val;
	notify_observers(value);
}

void fixed_value_provider::set_value(double val)
{
	value = val;
	notify_observers(value);
}
