#ifndef SUBJECT_H
#define SUBJECT_H

// #include <memory> // TODO: change to smart ptr usage
#include <vector>
#include "observer.h"

#include <iostream> // TEMP


// template <typename DataType> class Observer; // 

template <typename DataType> class Subject {
	// shared_ptr used because unique_ptr doesn't allow for incomplete type deletion
	std::vector<Observer<DataType> *> observerList;
public:
	void notifyAll();
	void attach(Observer<DataType> *obs);
	virtual DataType getData() = 0;

	// Big 5 + ctor

};


template <typename DataType>
void Subject<DataType>::attach(Observer<DataType> *observerPointer) {
	observerList.emplace_back(observerPointer);
}

template <typename DataType>
void Subject<DataType>::notifyAll() {
	// for (auto i = observerList.begin(); i != observerList.end(); ++i) {
	// 	(*i)->notify(*this);
	// }
	for (auto &ob : observerList) {
		ob->notify(*this);
	}
}



#endif

