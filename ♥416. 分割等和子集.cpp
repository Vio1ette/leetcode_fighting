#include <bits/stdc++.h>
using namespace std;


//�û���dfs�ķ�����׼������Ͱ����Ԫ��ֵҪô����AͰ��Ҫô����BͰ���������п��ܵķŷ�
//ʱ�临�Ӷȣ�O(2^n)����ʱ
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

//����ת��������һ������Ʒ��ʹ���ܺ�Ϊsum/2

//dp[i][j]: ǰi����Ʒ�Ƿ�����������Ϊj�ı�����

//dp[i][j] = dp[i-1][j] �� dp[i-1][j-nums[i-1]]
// ��һ���ʾ���ѵ�i��װ�뱳�����ڶ����ʾ�ѵ�i��װ�뱳��

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
		
		//�߽紦��
		for (int i = 0; i <= len; i++) {
			dp[i][0] = true;
		}
		
		//����Ҫע�⣬i��0->len������dp��һά�����壬���ǲ�����nums[i]�����壬���Ա�����nums�±���[i-1]
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



