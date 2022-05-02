#include <bits/stdc++.h>
#include <unordered_set>
#include <iostream>

using namespace std;

/*
* ˼·��
* dp[i]��ʾ��s[i]��β������ֵ
* pre_index[0..26]��ʾ26����ĸ��һ�γ��ֵ��±꣬��δ���ֵı�Ϊ-1
* ��ʼ��dp[0]=1;  pre_index[s[0]-'a']=0;
* ����[0...i-1]�Ѿ�������ϣ����ڴ���s[i]
* ���������ַ�����β�����������
* ��1��s[i]�ǵ�һ�γ��֣���dp[0...i]��Ҫ��1���ܹ���i
* ��2��s[i]�Ѿ����ֹ�����һ�γ��ֵ��±�Ϊpre_index[s[i]-'a']����Ϊj����dp[0...j]�����䣬dp[j+1...i]��Ҫ��1���ܹ���i-j����[j+1...i]���Ӵ�����
* 
* ���⻰��ƽʱ������������������ʱ�������ö�άdp������ dp[i...j] ��ʾ [i...j] ������ֵ����һ�� n^2 �ı���ٰ����з�Χ������ֵ���
* ���������ô���ᳬʱ��
* ��������⣬ÿ������һ���ַ�ʱ��dp�ı仯���й��ɵģ����Һü���ģ��Ϳ���ֱ�Ӽ���Ӻͣ�������һ��һ�������
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

			if (pre_index[cur] == -1) {  //�ַ���δ���ֹ�
				pre_index[cur] = i;
				//i=0ʱ���⴦��һ��
				dp[i] = i > 0 ? dp[i - 1] + i + 1 : 1;
			}
			else {  //�Ѿ����ֹ�
				int old_index = pre_index[cur];
				//i-(old_index+1)+1��[old_index+1,i]��s[i]��β���ִ�����
				dp[i] = dp[i - 1] + (i - (old_index + 1) + 1);
				//����pre_index
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
