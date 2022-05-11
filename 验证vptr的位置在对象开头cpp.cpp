#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

class C {
public:
	C():m_x(0){}
	virtual ~C(){}

public:
	static ptrdiff_t member_offset(const C& c) {
		const char* p = reinterpret_cast<const char*>(&c);
		const char* q = reinterpret_cast<const char*>(&c.m_x);
		return q - p;
	}

private:
	int m_x;
};

int main(int argc, char* argv[])
{	
	C c;
	cout <<C::member_offset(c)<< endl;
	return 0;
}


