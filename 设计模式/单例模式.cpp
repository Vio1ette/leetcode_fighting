#include <bits/stdc++.h>
using namespace std;

//����ģʽ
//�ο����ϣ�https://www.cnblogs.com/loveis715/archive/2012/07/18/2598409.html

//�򵥰汾
class Singleton1 {
public:
	static Singleton1& getInstance() {  //ע�������Ƿ�������
		static Singleton1 singleton1; //�ֲ���̬����������ʵ���ӳٹ���ʵ�����������̰߳�ȫ��
		return singleton1;
	}
private:
	Singleton1() {}
};



//�̰߳�ȫ�汾��δ�����...�ڿӡ�
class Singleton {

public:
	//���ز���Ϊ��̬���ã�������ָ�룬�û������������������ʵ����������ָ��ʵ����ָ��
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



