#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

//约瑟夫环问题，记住递归公式就行：f(n,k)=(f(n-1,k)+k)%n;

//还要注意计数从0开始、从1开始，会产生微小的不同，从0开始时，答案要加1

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;                           //base条件
        int ans = (findTheWinner(n - 1, k) + k) % n;    //套公式
        if (ans == 0)return n;                          //因为从1开始计数，最后剩下的编号为0是不正常的，其实最后剩下的编号是n，表示f(n,k)=n，可以计算一下f(3,2)来理解
        else return ans;
    }
};


int main(int argc, char* argv[])
{	
	Solution a;
	a.findTheWinner(6, 5);
	return 0;
}


