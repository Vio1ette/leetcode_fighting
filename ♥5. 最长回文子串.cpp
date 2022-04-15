#include <bits/stdc++.h>
using namespace std;

//动态规划，要填N2的表，时间复杂度O(n^2)
//注意dp[i][j]，表示s[i...j]是否为回文串，而不是s[i...j]中的最长回文串，额外维护变量来记录最长回文串
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }
        int ret = INT_MIN;
        int len = s.size();
        //不用维护结果字串，维护左右边界即可
        //string ret_str = "";
        int left = 0;
        int right = 0;
        //刚开始的填表方式不太对，导致引用了没有设定过的值
        //填表方式可以很灵活，只需要保证不引用没有设定过的值
        for (int i = len - 1; i >= 0; i--) {
            for (int j = len - 1; j > i; j--) {
                //字符不等
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else if (j - i + 1 <= 2) { //字符相等，长度为2，是回文串
                    dp[i][j] = true;
                }
                else dp[i][j] = dp[i + 1][j - 1]; //字符相等，长度超过2，依赖于内部是不是回文串
                //更新
                if (dp[i][j] && j - i + 1 > ret) {
                    ret = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};

int main()
{
    Solution a;
    a.longestPalindrome("aaaa");
	return 0;
}