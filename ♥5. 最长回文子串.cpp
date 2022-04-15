#include <bits/stdc++.h>
using namespace std;

//��̬�滮��Ҫ��N2�ı�ʱ�临�Ӷ�O(n^2)
//ע��dp[i][j]����ʾs[i...j]�Ƿ�Ϊ���Ĵ���������s[i...j]�е�����Ĵ�������ά����������¼����Ĵ�
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }
        int ret = INT_MIN;
        int len = s.size();
        //����ά������ִ���ά�����ұ߽缴��
        //string ret_str = "";
        int left = 0;
        int right = 0;
        //�տ�ʼ�����ʽ��̫�ԣ�����������û���趨����ֵ
        //���ʽ���Ժ���ֻ��Ҫ��֤������û���趨����ֵ
        for (int i = len - 1; i >= 0; i--) {
            for (int j = len - 1; j > i; j--) {
                //�ַ�����
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else if (j - i + 1 <= 2) { //�ַ���ȣ�����Ϊ2���ǻ��Ĵ�
                    dp[i][j] = true;
                }
                else dp[i][j] = dp[i + 1][j - 1]; //�ַ���ȣ����ȳ���2���������ڲ��ǲ��ǻ��Ĵ�
                //����
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