#include <bits/stdc++.h>
#include <unordered_set>
#include <iostream>

using namespace std;

/*
* 思路：
* dp[i]表示以s[i]结尾的引力值
* pre_index[0..26]表示26个字母上一次出现的下标，从未出现的标为-1
* 初始化dp[0]=1;  pre_index[s[0]-'a']=0;
* 假设[0...i-1]已经处理完毕，现在处理s[i]
* 将它当作字符串结尾，有两种情况
* （1）s[i]是第一次出现，则dp[0...i]都要加1，总共加i
* （2）s[i]已经出现过，上一次出现的下标为pre_index[s[i]-'a']，记为j；则dp[0...j]都不变，dp[j+1...i]都要加1，总共加i-j，即[j+1...i]的子串个数
* 
* 题外话：平时遇到这种连续子序列时，会想用二维dp，比如 dp[i...j] 表示 [i...j] 的引力值，填一个 n^2 的表格，再把所有范围的引力值相加
* 但这道题这么做会超时。
* 对于这道题，每次增加一个字符时，dp的变化是有规律的，而且好计算的，就可以直接计算加和，而不是一个一个得填表
* 
*/

class Solution {
public:
	long long appealSum(string s) {
		int len = s.size();
		long long t = 0;
		vector<int> dp(len);
		vector<int> pre_index(26, -1);
		for (int i = 0; i < len; i++) {
			int cur = s[i] - 'a';

			if (pre_index[cur] == -1) {  //字符从未出现过
				pre_index[cur] = i;
				//i=0时特殊处理一下
				dp[i] = i > 0 ? dp[i - 1] + i + 1 : 1;
			}
			else {  //已经出现过
				int old_index = pre_index[cur];
				//i-(old_index+1)+1是[old_index+1,i]以s[i]结尾的字串个数
				dp[i] = dp[i - 1] + (i - (old_index + 1) + 1);
				//更新pre_index
				pre_index[cur] = i;
			}

			t += dp[i];
		}
		return t;
	}
};

int main(int argc, char* argv[])
{	
	Solution a;
	a.appealSum("abbca");

	return 0;
}
