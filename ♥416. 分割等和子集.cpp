#include <bits/stdc++.h>
using namespace std;


//用回溯dfs的方法，准备两个桶，将元素值要么放在A桶，要么放在B桶，遍历所有可能的放法
//时间复杂度：O(2^n)，超时
//class Solution {
//public:
//
//   
//    bool canPartition(vector<int>& nums) {
//        return dfs(nums, 0, 0, 0);
//    }
//
//    bool dfs(vector<int> nums, int i, int A, int B) {
//        if (i == nums.size()) {
//            if (A == B && A != 0)return true;
//            else return false;
//        }
//        
//        return dfs(nums, i + 1, A + nums[i], B)
//            || dfs(nums, i + 1, A , B+nums[i]);
//
//    }
//
//};

//问题转化：挑出一部分物品，使其总和为sum/2

//dp[i][j]: 前i件物品是否可以填满体积为j的背包？

//dp[i][j] = dp[i-1][j] 或 dp[i-1][j-nums[i-1]]
// 第一项表示不把第i件装入背包，第二项表示把第i件装入背包

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		// sum = accumulate(nums.begin(),nums.end(),0);
		// int manxNum = *max_element(nums.begin(),nums.end());
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		if (sum % 2 != 0)return false;
		int target = sum / 2;

		int len = nums.size();

		vector<vector<bool>> dp(len + 1, vector<bool>(target + 1, false));
		
		//边界处理
		for (int i = 0; i <= len; i++) {
			dp[i][0] = true;
		}
		
		//这里要注意，i从0->len，满足dp第一维的语义，但是不满足nums[i]的语义，所以别忘了nums下标是[i-1]
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= target; j++) {
				if (j >= nums[i - 1])dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
				else dp[i][j] = dp[i - 1][j];
				if (dp[i][j] && j == target)return true;
			}
		}
		return false;

	}
};



int main()
{
		
	Solution a;
	a.canPartition({ 1,2,5 });
	return 0;
}



