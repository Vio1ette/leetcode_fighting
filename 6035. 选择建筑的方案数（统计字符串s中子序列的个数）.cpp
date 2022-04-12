#include <bits/stdc++.h>
using namespace std;

//在s中统计"101"或"010"的个数
class Solution {
public:
    long long numberOfWays(string s) {
        return find(s, "101")+find(s, "010");
    }
    //在任何序列中寻找三个子序列的通用模板
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