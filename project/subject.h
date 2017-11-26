#ifndef SUBJECT_H
#define SUBJECT_H

#include <memory>
#include <vector>

template <typename DataType> class Observer;

template <typename DataType>
class Subject {
	std::vector<std::unique_ptr<Observer<DataType>>> observerList;
public:
	void attach(std::unique_ptr<Observer<DataType>> obs);
	void notifyAll();

};


#endif

