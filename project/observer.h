#ifndef OBSERVER_H
#define OBSERVER_H

template <typename DataType>
class Observer {
public:
	virtual notify(Subject<DataType> &notifier) = 0;
}


#endif
