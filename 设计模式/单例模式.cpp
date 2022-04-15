#include <bits/stdc++.h>
using namespace std;

//单例模式
//参考资料：https://www.cnblogs.com/loveis715/archive/2012/07/18/2598409.html

//简单版本
class Singleton1 {
public:
	static Singleton1& getInstance() {  //注意这里是返回引用
		static Singleton1 singleton1; //局部静态变量，可以实现延迟构建实例，但不是线程安全的
		return singleton1;
	}
private:
	Singleton1() {}
};



//线程安全版本【未完待续...挖坑】
class Singleton {

public:
	//返回参数为静态引用，而不是指针，用户调用这个函数是想获得实例，而不是指向实例的指针
	static Singleton& getInstance() {  
		if (instance == nullptr) {
			instance = new Singleton();
			return *instance;
		}
		return *instance;
	}
private:
	Singleton(){}
	Singleton(const Singleton&){}
	Singleton& operator=(const Singleton&){}
	static Singleton* instance;
};

int main()
{
		
	
	return 0;
}



