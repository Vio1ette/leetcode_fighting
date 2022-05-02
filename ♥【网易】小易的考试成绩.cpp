#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*题目来源：
https://www.nowcoder.com/questionTerminal/b83f4f4950d04154a6dc053b6d419782
*/


/*
*大体思路：动态规划，求出所有可能的和，再降序判断和是否满足条件（没有5）
* 这个类似于之前的《组合幸运数字》：先求出所有数字的总和，然后再一个一个减，得到所有的组合和
* 
* dp[i]：表示总和为 i 是否有可能
* 
* 此题不关心组合的具体样子，只关心组合的总和值是多少
* 
* 回忆《组合幸运数字》是维护一个“待减”数组，刚开始只有 sum，后来有 sum 和 sum - nums[0]，以此类推
* 
* 而这道题是建立一个长度为sum的数组，和（下标）如果存在，则元素值为 1
* 
* 动态转移方程： 当前 s[i]，对于待减数组的每个和，if( dp[j] == 1 && j - s[i] >= 0) dp[j - s[i]] = 1
* 
*/



//判断数字里是否有5
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
	// sum最大是20000
	vector<int> dp(200001, 0);
	dp[sum] = 1;
	for (int i = 0; i < s.size(); i++) {
		//遍历“和数组”
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