#include <iostream>
#include <vector>
using namespace std;

//˼·�������ֶ�������ȷ��λ���ϣ����û������ȷ��λ���ϵľ����ظ�����

//��˼��ÿ������Ҫ������λ���Ѿ���������ʱ���ͷ����ظ����ͽ�����push_back��res����
// ���������ȱ���ǣ�һ��λ�û��ж�α����ʣ��������п��ܻ����������ظ�����
// ���ԣ��Ľ������ǣ�ÿ������Ҫ������λ���Ѿ���������ʱ������ֱ�Ӿ�push_back��������ֹͣ��������������ǰԪ�أ���ʼ������һ��Ԫ��
// �����еĽ����߼�����������֮����ִ��push_back���߼������ⷢ������ͬһ��λ�õĶ��push_back

//����ʵ��
class Solution {
public:

    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[nums[i] - 1] != nums[i])
                    swap(nums, i, nums[i] - 1);
                else {
                    res.push_back(nums[i]); //���ﲻӦ������push_back
                    break;
                }

            }
        }
        return res;
    }
};

//��ȷʵ��
class Solution {
public:

    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != nums[nums[i] - 1]) { 
                //ע�����ﲻ���� while(nums[i]!=i+1)��������Ŀ�꽻��λ���Ѿ���������ʱ�����������ѭ��
                swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i] - 1)
                res.push_back(nums[i]);
        }
        return res;
    }
};