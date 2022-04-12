#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
小易的幸运数字是7，现有一个整数数组 nums，请你找出并返回能被七整除的子集合的最大和，如果找不到则返回-1。

输入描述:
一个正整数数组列表nums，用空格区分，1<=length(nums)<=100000，sum(nums) <= 1000000000

输出描述:
一个整数，最大和
*/

/*
  这道题刚开始的思路是用暴力回溯遍历所有的组合，然而超时
* 其实，这道题并没有要求给出所有的组合是什么，他要组合的和，这就是优化的点
* 
* 关键步骤
* 1. 将输入数组升序排序
* 2. 获得所有数的和
* 
* 大体思路：不是从0开始加，而是从sum开始一个一个减，因为最后要得到的是“最大值”，刚开始“待减”数组只有 sum
* 
* 例如：对于总sum，是所有数字的和
* i = 0 时
* 判断 sum - nums[0] 是否满足条件，如果不满足，将 sum - nums[0] 放入“待减”数组
* i = 1 时
* 判断“待减”数组里的两个和减去 nums[1] 后是否满足条件，由此自顶向下判断解是否满足条件
* 
* 图示：https://uploadfiles.nowcoder.com/images/20210327/118067611_1616854202480/D61EBA8CC260DFE3F6C1255E687794B8
* 
* 时间复杂度：外层 for 循环是 O(n) 的复杂度，内层循环次数呈：1,2,4,8,16,...,2^n，感觉还是挺大
*/


int main()
{
	vector<int> nums;
	int num = 0;
	while (cin >> num) {
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}

	if (sum % 7 == 0) { cout << sum << endl; return 0; }

	vector<int> delete_num;
	delete_num.push_back(sum);

	for (int i = 0; i < nums.size(); i++) {
		int len = delete_num.size();

		for (int j = 0; j < len; j++) {

			int temp = delete_num[j] - nums[i];
			if (temp != 0 && temp % 7 == 0) { cout << temp << endl; return 0; }
			else delete_num.push_back(temp);

		}
	}

	cout << -1 << endl;

	return 0;
}