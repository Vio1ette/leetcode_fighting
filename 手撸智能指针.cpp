#include <bits/stdc++.h>
#include <unordered_set>
#include <iostream>

using namespace std;

class RefCount {
//首先应该写个public，class默认为public【1】
public:
	//应该初始化为1【2】
	RefCount(int c = 0):count_(c){}
	void add() { count_++; }
	void minus() { count_--; }
	int getCount() { return count_; }
private:
	atomic<int> count_;
};

template <typename T>
class Shared_ptr {
	//首先应该写个public，class默认为public【3】
public:

	Shared_ptr(T* pr=nullptr):ptr_(pr),c(new RefCount()){}
	~Shared_ptr() { clean(); }

	Shared_ptr(const Shared_ptr& sp):c_(sp->c_),ptr_(sp->ptr_){
		c_->add();
	}

	Shared_ptr& operator=(const Shared_ptr& sp) {
		clean();
		c_ = sp->c_;
		c_->add();
		if (ptr_ != sp->ptr_)ptr_ = sp->ptr_;
		return this*;
	}

	Shared_ptr(Shared_ptr&& sp) :c_(sp->c_), ptr_(sp->ptr_) {
		sp->c_ = nullptr;
		sp->ptr_ = nullptr;
	}

	Shared_ptr& operator=(Shared_ptr&& sp) {
		clean();
		c_ = sp->c_;
		if (ptr_ != sp->ptr_)ptr_ = sp->ptr_;
		sp->c_ = nullptr;
		sp->ptr_ = nullptr;
		return this*;
	}

	T* operator->() {
		return ptr_;
	}

	T& operator*() {
		return *ptr_;
	}

private:
	void clean() {
		if (c_) {
			c_->minus();
			if (c_->getCount() == 0) {
				if (ptr_) {
					delete ptr_;
				}
				//还应该delete c_;【4】
				delete c_;
			}
		}
	}
private:
	RefCount* c_;
	T* ptr_;
};

int main(int argc, char* argv[])
{	
	
	return 0;
}
