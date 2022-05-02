#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*��Ŀ��Դ��
https://www.nowcoder.com/questionTerminal/b83f4f4950d04154a6dc053b6d419782
*/


/*
*����˼·����̬�滮��������п��ܵĺͣ��ٽ����жϺ��Ƿ�����������û��5��
* ���������֮ǰ�ġ�����������֡���������������ֵ��ܺͣ�Ȼ����һ��һ�������õ����е���Ϻ�
* 
* dp[i]����ʾ�ܺ�Ϊ i �Ƿ��п���
* 
* ���ⲻ������ϵľ������ӣ�ֻ������ϵ��ܺ�ֵ�Ƕ���
* 
* ���䡶����������֡���ά��һ�������������飬�տ�ʼֻ�� sum�������� sum �� sum - nums[0]���Դ�����
* 
* ��������ǽ���һ������Ϊsum�����飬�ͣ��±꣩������ڣ���Ԫ��ֵΪ 1
* 
* ��̬ת�Ʒ��̣� ��ǰ s[i]�����ڴ��������ÿ���ͣ�if( dp[j] == 1 && j - s[i] >= 0) dp[j - s[i]] = 1
* 
*/



//�ж��������Ƿ���5
bool five(int num) {
	while (num) {
		int temp = num % 10;
		if (temp == 5)return true;
		num /= 10;
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	int num = 0;
	vector<int> s;
	while (cin >> num) {
		s.push_back(num);
	}

	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i];
	}
	// sum�����20000
	vector<int> dp(200001, 0);
	dp[sum] = 1;
	for (int i = 0; i < s.size(); i++) {
		//�����������顱
		for (int j = 0; j <= sum; j++) {
			if (dp[j] == 1 && j - s[i] >= 0) {
				dp[j - s[i]] = 1;
			}
		}
	}

	for (int i = sum; i >= 0; i--) {
		if (dp[i] == 1 && !five(i)) {
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;

	return 0;
}