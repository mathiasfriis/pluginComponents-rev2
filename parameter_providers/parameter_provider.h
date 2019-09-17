#ifndef __PARAMETER_PROVIDER__
#define __PARAMETER_PROVIDER__
#include "Observer_Pattern/Subject.h"

class parameter_provider:public subject
{
public:
	void update();
	parameter_provider();
	~parameter_provider();
	virtual double get_value();
	double parameter_value;
private:
	virtual void update_value();
};

#endif
