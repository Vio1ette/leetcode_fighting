#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

//ϴ���㷨��������n��Ԫ�ص�������˵��Ϊ�˱�֤ϴ�ƵĹ�ƽ�ԣ�Ӧ��Ҫ�ܹ��ȸ��ʵ�ϴ��n!�ֽ����

//ÿ����������ȵĸ��ʱ��ŵ�����һ��λ���У���ÿ��λ���г�������һ�����ĸ��ʶ�����ͬ��

/*
* ��ʼ�����������Ԫ�أ�
* ��ǰ����������ѡһ���������������н�����ÿ�����������֮һ�ĸ��ʱ����������һ��λ�ã�
* ��ǰ�ĸ��������ѡһ��������ĸ������н�����ÿ�������� 4/5 * 1/4 = 1/5 �ĸ��ʱ����������ĸ�λ�ã�
* ��ǰ�����������ѡһ����������������н�����ÿ�������� 4/5 * 3/4 * 1/3 = 1/5 �ĸ��ʱ�������������λ�ã�
*/

//��ͼ˵����https://pic.leetcode-cn.com/1616380923-YvHlbL-53BF82B993210EA6F26B63EC7BDBFB04.png


class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }

    vector<int> reset() {
        return arr;
    }

    vector<int> shuffle() {
        vector<int> nums(arr);
        for (int i = 0; i < nums.size(); i++) {
            int index = i + rand() % (nums.size() - i);
            swap(nums, index, i);
        }
        return nums;
    }

    void swap(vector<int>& a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    vector<int> arr;
};


int main(int argc, char* argv[])
{	

	cout << sizeof(a) << endl;
	return 0;
}


