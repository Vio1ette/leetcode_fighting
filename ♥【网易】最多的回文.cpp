#include <bits/stdc++.h>
#include <unordered_set>
#include <iostream>

using namespace std;

// dp[i][j]��[i...j]�Ƿ�Ϊ����
// ά��һ�� t ��¼���ĵĸ���
// ͬ������n^2�ı�������߼����Ǻܸ���
// 1. ע�����˳��
// 2. ע����Ȼһ����ĸ������ģ�����Ϊ�����dp[i][j]Ҫ��ʼ��ΪT
// ת�Ʒ��̣�
// s[i]==s[j]��
// (1)j-i+1==2��dp[i][j]=true
// (2)j-i+1>2��dp[i][j]=dp[i+1][j-1]
// s[i]!=s[j]��dp[i][j]=F

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
