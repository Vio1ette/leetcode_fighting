#include <bits/stdc++.h>
using namespace std;


//������Ҫ���춯̬�滮+��������
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int len = nums.size();
        while (len) {
            for (int i = 0; i + 1 < len; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            len--;
        }
        return nums[0];
    }
};

int main()
{

    Solution a;
    return 0;
}