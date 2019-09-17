#include "Subject.h"
#include <iostream>
#include <string>

subject::subject()
{
}


subject::~subject()
{
}

void subject::register_observer(observer& o, string id)
{
	observers.push_back(o);
	ids.push_back(id);
}
void subject::remove_observer(string id)
{
	// Check if ID is in list of IDs
	std::vector<string>::iterator it = std::find(ids.begin(), ids.end(), id);

	// Get index of element from iterator 
	int index = std::distance(ids.begin(), it)-1;

	// Remove the observer
	ids.erase(ids.begin() + index);
	observers.erase(observers.begin() + index);
}

void subject::notify_observers(double val)
{
	for (observer& o : observers) {
		o.notify(val);
	}
}