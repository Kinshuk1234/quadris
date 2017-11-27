#include "subject.h"

using namespace std;

template <typename DataType>
void Subject<DataType>::attach(Observer<DataType> *observerPointer) {
	observerList.emplace_back(observerPointer);
}

template <typename DataType>
void Subject<DataType>::notifyAll() {
	for (auto i = observerList.begin(); i != observerList.end(); ++i) {
		i->notify(*this);
	}
}


