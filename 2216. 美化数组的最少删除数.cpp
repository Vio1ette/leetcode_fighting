#include <bits/stdc++.h>
using namespace std;

//用删除数模拟下标变换
//index-cnt为下标真是值，如果index-cnt为偶数，则判断，然后更新删除数
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if ((i - cnt) % 2 == 0&&nums[i]==nums[i+1]) {
                cnt++;
            }
        }
        if (((nums.size() - 1 - cnt) % 2) == 0)cnt++;
        return cnt;
    }
    
};

int main()
{

    Solution a;
    return 0;
}