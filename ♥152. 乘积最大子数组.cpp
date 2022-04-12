#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


//思路：动态规划
// f[i]是以 i 结尾的子数组乘积最大值
// 考虑在只有正整数、0的的情况下，f[i] = f[i-1] * nums[i]
// 如果有0，前面乘积为0，那么新的 f[i] = nums[i];
// 再考虑如果有负数的情况
// 如果当前 nums[i] 是负数，意味着之前的最大值会变最小，而之前的最小值会变最大
// 所以考虑不仅仅维护一个子数组最大乘积f[i]
// 同时也维护一个子数组最小乘积g[i]
// 则nums[i]为负数时，f[i]=max(g[i-1]*nums[i],nums[i]);
// 因为f[i-1] * nums[i] <= g[i-1] * nums[i]，所以用 g[i-1] 代替 f[i-1]

// 对于 g[i] 的维护，同理
// 在 nums[i]>=0 时，g[i] = min(g[i-1]*nums[i],nums[i]);
// 在 nums[i] < 0 时，g[i] =min(f[i-1]*nums[i],nums[i]);

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> f(nums.size());
        vector<int> g(nums.size());
        f[0] = nums[0];
        g[0] = nums[0];
        int res = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                f[i] = max(f[i - 1] * nums[i], nums[i]);
                g[i] = min(g[i - 1] * nums[i], nums[i]);
            }
            else {
                f[i] = max(g[i - 1] * nums[i], nums[i]);
                g[i] = min(f[i - 1] * nums[i], nums[i]);
            }
            //注意f[i]是以i结尾的最大值，整个数组的最大子数组不一定以i结尾
            //所以每次都要更新res
            res = max(res, f[i]);
        }
        res = max(res, f[0]);
        return res;
    }
};

int main()
{
    Solution a;
    a.maxProduct({-1});
	return 0;
}