#include <bits/stdc++.h>
#include <unordered_set>
#include <iostream>

using namespace std;

// dp[i][j]：[i...j]是否为回文
// 维护一个 t 记录回文的个数
// 同样是填n^2的表格，整体逻辑不是很复杂
// 1. 注意填表顺序
// 2. 注意虽然一个字母不算回文，但是为了填表，dp[i][j]要初始化为T
// 转移方程：
// s[i]==s[j]：
// (1)j-i+1==2，dp[i][j]=true
// (2)j-i+1>2，dp[i][j]=dp[i+1][j-1]
// s[i]!=s[j]，dp[i][j]=F

int fun(string s) {
	int len = s.size();
	vector<vector<bool>> dp(len, vector<bool>(len, false));
	for (int i = 0; i < len; i++) {
		dp[i][i] = true;
	}
	int t = 0;
	for (int i = len - 1; i >= 0; i--) {
		for (int j = len - 1; j > i; j--) {
			if (s[i] == s[j]) {
				if (j - i + 1 <= 2) {
					dp[i][j] = true;
				}
				else dp[i][j] = dp[i + 1][j - 1];
			}
			else dp[i][j] = false;
			if (dp[i][j]) {
				t++;
			}
		}
	}
	return t;
}

int main(int argc, char* argv[])
{	
	fun("abbcbb");

	return 0;
}
