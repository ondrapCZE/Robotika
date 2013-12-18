#ifndef TSQUEUE_H
#define TSQUEUE_H

#include <deque>
#include <mutex>
#include <condition_variable>

template <class T>
class tsqueue{
	std::deque<T> dataDeque;
	
	std::mutex lck;
	std::condition_variable emptyCondition;
public:
	void push(T element){
		std::lock_guard<std::mutex> guard(lck);
		dataDeque.push_back(element);
		emptyCondition.notify_one();
	};
	
	bool tryPop(T &element){
		std::lock_guard<std::mutex> guard(lck);		
		if(dataDeque.empty())
			return false;
		
		element = dataDeque.front();
		dataDeque.pop_front();
		return true;
	}
	
	T pop(){
		std::unique_lock<std::mutex> uq_lck(lck);
		emptyCondition.wait(uq_lck,[](){return !dataDeque.empty();});
		T copy = dataDeque.front();
		dataDeque.pop_front();
		return copy;
	};
	
	bool empty(){
		std::lock_guard<std::mutex> guard(lck);
		return dataDeque.empty();
	};
	
	void clear(){
		std::lock_guard<std::mutex> guard(lck);
		dataDeque.clear();
	};
};

#endif