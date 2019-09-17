#ifndef __OBSERVER__
#define __OBSERVER__

#include <vector>
#include <functional>
class observer
{
public:
	virtual void notify(double val) = 0;
	observer();
	~observer();
};

#endif
