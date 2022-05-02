#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
С�׵�����������7������һ���������� nums�������ҳ��������ܱ����������Ӽ��ϵ����ͣ�����Ҳ����򷵻�-1��

��������:
һ�������������б�nums���ÿո����֣�1<=length(nums)<=100000��sum(nums) <= 1000000000

�������:
һ������������
*/

/*
  �����տ�ʼ��˼·���ñ������ݱ������е���ϣ�Ȼ����ʱ
* ��ʵ������Ⲣû��Ҫ��������е������ʲô����Ҫ��ϵĺͣ�������Ż��ĵ�
* 
* �ؼ�����
* 1. ������������������
* 2. ����������ĺ�
* 
* ����˼·�����Ǵ�0��ʼ�ӣ����Ǵ�sum��ʼһ��һ��������Ϊ���Ҫ�õ����ǡ����ֵ�����տ�ʼ������������ֻ�� sum
* 
* ���磺������sum�����������ֵĺ�
* i = 0 ʱ
* �ж� sum - nums[0] �Ƿ�������������������㣬�� sum - nums[0] ���롰����������
* i = 1 ʱ
* �жϡ�������������������ͼ�ȥ nums[1] ���Ƿ������������ɴ��Զ������жϽ��Ƿ���������
* 
* ͼʾ��https://uploadfiles.nowcoder.com/images/20210327/118067611_1616854202480/D61EBA8CC260DFE3F6C1255E687794B8
* 
* ʱ�临�Ӷȣ���� for ѭ���� O(n) �ĸ��Ӷȣ��ڲ�ѭ�������ʣ�1,2,4,8,16,...,2^n���о�����ͦ��
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