#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
*˼·������ÿ��Ԫ�أ��Ǽ�k�����Ǽ�k��
*Ҫ�Ȱ���������
* �ȿ��Ǻÿ��ǵ�һ���������Сֵ��С�����ֵ�ܴ���ô��Сֵ��ѡ��һ���Ǽ�k�����ֵ��ѡ��һ���Ǽ�k
* ��Сֵ�����Ҳ�Ǽ�k���δ�ֵ�����Ҳ�Ǽ�k���Դ˴����˵��м�����ȷ��Ԫ�ص���Ϊ
* ������ߵ�һ����ȷ����k���ұߵ�һ����ȷ����k
* �м��һ����ֵ�ȽϽӽ������Բ�ȷ������ʵ�ȽϽӽ���ֵ�����Ҫô���ӻ�Ҫô�������Ų���������
* �����ۺ�������̰�Ĳ��Ծ�������������� i ���ȫ����k��i �ұ�ȫ����k
* 
* ���������۱Ƚ���ͳ���������ȷ�� i��
* ����ͨ��ö��ȷ�����ŵ�i������ȷ����һ��i֮�󣬲�Ҫɵ������ȥ���ģ�⣬����ֻ��Ҫһ����ֵ
* 
*/

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (k == 0)return  nums[len - 1] - nums[0];
        int res = INT_MAX;
        for (int i = 0; i < len - 1; i++) {
            //����֮�󣬿��ܵ����ֵ����ߵ����һ�����ұߵ����һ��
            int possible_max = max(nums[i] + k, nums[len - 1] - k);
            //����֮�󣬿��ܵ����ֵ����ߵĵ�һ�����ұߵĵ�һ��
            int possible_min = min(nums[0] + k, nums[i + 1] - k);
            res = min(res, possible_max - possible_min);
        }
        //��©��ȫ��ȫ�������
        return  min(res, nums[len - 1] - nums[0]);
    }
};

int main(int argc, char* argv[])
{
	return 0;
}



