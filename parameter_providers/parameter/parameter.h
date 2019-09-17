#ifndef __PARAMETER__
#define __PARAMETER__

#include "../Observer_Pattern/Observer.h"
#include "../parameter_provider.h"

using namespace std;

class parameter :public observer
{
public:
	parameter();
	~parameter();
	parameter(string);
	void attach_to_source(parameter_provider&);
	void set_value(double);
	virtual void notify(double val);
	double get_value();
private:
	double parameter_value;
	string id;
};
#endif // !__PARAMETER__
