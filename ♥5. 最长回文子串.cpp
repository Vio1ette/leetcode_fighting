#include <bits/stdc++.h>
using namespace std;

//动态规划，要填N2的表，时间复杂度O(n^2)
//注意dp[i][j]，表示s[i...j]是否为回文串，而不是s[i...j]中的最长回文串，额外维护变量来记录最长回文串
class Solution {
public:
    string longestPalindrome(string s){
        int left = 0;
        int right = s.size() - 1;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }
        int ret = INT_MIN;
        int len = s.size();
        string ret_str = "";
        //刚开始的填表方式不太对，导致引用了没有设定过的值
        //填表方式可以很灵活，只需要保证不引用没有设定过的值
        for (int i = len -1; i >=0; i--) {
            for (int j = len - 1; j > i; j--) {

                if ((j == (i + 1)) && s[i] == s[j]) {
                    dp[i][j] = true;
                }
                else if (s[i] == s[j] && j - i + 1 > 2) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else if (s[i] != s[j]) {
                    dp[i][j] = false;
                }


                if (dp[i][j] && j - i + 1 > ret) {
                    ret = j - i + 1;
                    ret_str = s.substr(i, j - i + 1);
                }
            }
        }
        return ret_str == "" ? s.substr(0, 1) : ret_str;
    }
};

int main()
{
    Solution a;
    a.longestPalindrome("aaaa");
	return 0;
}