#ifndef SUBJECT_H
#define SUBJECT_H

// #include <memory> // TODO: change to smart ptr usage
#include <vector>

template <typename DataType> class Observer;

template <typename DataType>
class Subject {
	// shared_ptr used because unique_ptr doesn't allow for incomplete type deletion
	std::vector<Observer<DataType> *> observerList;
protected:
	void notifyAll();
public:
	void attach(Observer<DataType> *obs);
	virtual DataType getData() const = 0;

	// virtual ~Subject();

};


template <typename DataType>
void Subject<DataType>::attach(std::shared_ptr<Observer<DataType>> observerPointer) {
	observerList.emplace_back(observerPointer);
}

template <typename DataType>
void Subject<DataType>::notifyAll() {
	for (auto i = observerList.begin(); i != observerList.end(); ++i) {
		(*(*i)).notify(*this);
	}
}


#endif

