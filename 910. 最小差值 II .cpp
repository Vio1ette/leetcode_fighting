#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
*思路：对于每个元素，是加k，还是减k？
*要先把数组排序，
* 先考虑好考虑的一般情况：最小值很小，最大值很大，那么最小值的选择一定是加k，最大值的选择一定是减k
* 次小值大概率也是加k，次大值大概率也是减k，以此从两端到中间依次确定元素的行为
* 所以左边的一部分确定加k，右边的一部分确定减k
* 中间的一部分值比较接近，所以不确定。其实比较接近的值，最好要么都加或要么都减，才不会拉大差距
* 所以综合来看，贪心策略就是在升序数组的 i 左边全部加k，i 右边全部减k
* 
* 上述的讨论比较笼统，我们如何确定 i？
* 答案是通过枚举确定最优的i，但是确定好一个i之后，不要傻乎乎的去真的模拟，我们只需要一个差值
* 
*/

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (k == 0)return  nums[len - 1] - nums[0];
        int res = INT_MAX;
        for (int i = 0; i < len - 1; i++) {
            //划分之后，可能的最大值是左边的最后一个和右边的最后一个
            int possible_max = max(nums[i] + k, nums[len - 1] - k);
            //划分之后，可能的最大值是左边的第一个和右边的第一个
            int possible_min = min(nums[0] + k, nums[i + 1] - k);
            res = min(res, possible_max - possible_min);
        }
        //别漏了全加全减的情况
        return  min(res, nums[len - 1] - nums[0]);
    }
};

int main(int argc, char* argv[])
{
	return 0;
}



