#ifndef SUBJECT_H
#define SUBJECT_H

// #include <memory> // TODO: change to smart ptr usage
#include <vector>

template <typename DataType> class Observer;

template <typename DataType>
class Subject {
	std::vector<Observer<DataType> *> observerList;
public:
	void attach(Observer<DataType> *obs);
	void notifyAll();

};


#endif

