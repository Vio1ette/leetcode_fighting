#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

//Լɪ�����⣬��ס�ݹ鹫ʽ���У�f(n,k)=(f(n-1,k)+k)%n;

//��Ҫע�������0��ʼ����1��ʼ�������΢С�Ĳ�ͬ����0��ʼʱ����Ҫ��1

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;                           //base����
        int ans = (findTheWinner(n - 1, k) + k) % n;    //�׹�ʽ
        if (ans == 0)return n;                          //��Ϊ��1��ʼ���������ʣ�µı��Ϊ0�ǲ������ģ���ʵ���ʣ�µı����n����ʾf(n,k)=n�����Լ���һ��f(3,2)�����
        else return ans;
    }
};


int main(int argc, char* argv[])
{	
	Solution a;
	a.findTheWinner(6, 5);
	return 0;
}


