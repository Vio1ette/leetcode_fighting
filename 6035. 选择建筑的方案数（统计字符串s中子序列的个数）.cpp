#include <bits/stdc++.h>
using namespace std;

//��s��ͳ��"101"��"010"�ĸ���
class Solution {
public:
    long long numberOfWays(string s) {
        return find(s, "101")+find(s, "010");
    }
    //���κ�������Ѱ�����������е�ͨ��ģ��
    long long find(string s, string goal) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == goal[0])a++;
            if (s[i] == goal[1])b += a;
            if (s[i] == goal[2])c += b;
        }
        return c;
    }
};

int main()
{

    Solution a;
    return 0;
}