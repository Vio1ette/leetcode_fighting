#include <bits/stdc++.h>
using namespace std;

//��̬�滮��Ҫ��N2�ı�ʱ�临�Ӷ�O(n^2)
//ע��dp[i][j]����ʾs[i...j]�Ƿ�Ϊ���Ĵ���������s[i...j]�е�����Ĵ�������ά����������¼����Ĵ�
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
        //�տ�ʼ�����ʽ��̫�ԣ�����������û���趨����ֵ
        //���ʽ���Ժ���ֻ��Ҫ��֤������û���趨����ֵ
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