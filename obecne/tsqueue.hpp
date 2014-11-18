#ifndef TSQUEUE_H
#define TSQUEUE_H

#include <deque>
#include <mutex>
#include <condition_variable>

//! Thread safe deque
template<class T>
class tsqueue {
	std::deque<T> dataDeque;

	std::mutex lck;
	std::condition_variable emptyCondition;
public:
	//! Insert element at the end
	void push_back(T element) {
		std::lock_guard < std::mutex > guard(lck);
		dataDeque.push_back(element);
		emptyCondition.notify_one();
	}
	;

	//! Insert element at the front
	void push_front(T element) {
		std::lock_guard < std::mutex > guard(lck);
		dataDeque.push_front(element);
		emptyCondition.notify_one();
	}
	;

	//! Delete first element
	bool pop_front() {
		std::lock_guard < std::mutex > guard(lck);
		if (dataDeque.empty())
			return false;

		dataDeque.pop_front();
		return true;
	};

	//! Delete last element
	bool pop_back() {
		std::lock_guard < std::mutex > guard(lck);
		if (dataDeque.empty())
			return false;

		dataDeque.pop_back();
		return true;
	};

	//! Access first element if exist
	bool try_front(T &element) {
		std::lock_guard < std::mutex > guard(lck);
		if (dataDeque.empty())
			return false;

		element = dataDeque.front();
		return true;
	};

	//! Access last element if exist
	bool try_back(T &element) {
		std::lock_guard < std::mutex > guard(lck);
		if (dataDeque.empty())
			return false;

		element = dataDeque.back();
		return true;
	};

	//! Access first element
	T front() {
		std::unique_lock < std::mutex > uq_lck(lck);
		emptyCondition.wait(uq_lck, [this] {return !dataDeque.empty();});
		T copy = dataDeque.front();
		dataDeque.pop_front();
		return copy;
	}
	;

	//! Access last element
	T back() {
		std::unique_lock < std::mutex > uq_lck(lck);
		emptyCondition.wait(uq_lck, [this] {return !dataDeque.empty();});
		T copy = dataDeque.back();
		dataDeque.pop_back();
		return copy;
	}
	;

	//! Test whether container is empty
	bool empty() {
		std::lock_guard < std::mutex > guard(lck);
		return dataDeque.empty();
	}
	;

	//! Erase all elements
	void clear() {
		std::lock_guard < std::mutex > guard(lck);
		dataDeque.clear();
	}
	;
};

#endif
