#ifndef __SUBJECT__
#define __SUBJECT__

#include "Observer.h"

using namespace std;

class subject
{
public:
	subject();
	~subject();
	void register_observer(observer& o, string id);
	void remove_observer(string id);
	void notify_observers(double val);
private:
	std::vector<std::reference_wrapper<observer>> observers;
	std::vector<string> ids;
};

#endif