#ifndef TSQUEUE_H
#define TSQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <class T>
class tsqueue{
	std::queue<T> dataQueue;
	
	std::mutex lck;
	std::condition_variable emptyCondition;
public:
	void push(T element){
		std::lock_guard<std::mutex> guard(lck);
		dataQueue.push(element);
		emptyCondition.notify_one();
	};
	
	T pop(){
		return dataQueue.front();
	};
	
	bool empty(){
		return true;
	};
	
	void clear(){
	
	};
};

#endif