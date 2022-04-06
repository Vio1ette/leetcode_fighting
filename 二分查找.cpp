#include <bits/stdc++.h>

using namespace std;

//��ͨ����
//û�ҵ��Ļ�����target�ĺ������λ��
int binarySearch(vector<int> nums, int target) {
	int left = 0;
	int right = nums.size()-1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}
	

	//û�ҵ�
	if (nums[left] > target) {
		return left;
	}
	else if (nums[left] < target) {
		return left + 1;
	}

}

//Ѱ����߽����
int left_bound(vector<int> nums, int target) {
	int left = 0;
	int right = nums.size();
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			right=mid;
		}
		else if (nums[mid] > target) {
			right = mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}
	
	if (left == nums.size())return -1; //������ֵ����
	return nums[left] == target ? left : -1; //������ֵ��С��-1ʱ��

}

//Ѱ���ұ߽����

int right_bound(vector<int> nums, int target) {
	int left = 0;
	int right = nums.size();
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid ; 
			//���� right = mid - 1; �Ǵ����
			//����һ��rightǰ���ֵ�պþ͵���target����ʱright�պ����ұ߽�+1
			//��left���յĽ���ǡ��ұ߽�+1��������ǰrightλ��
			//���right=mid-1�ˣ�left�͵��ﲻ��
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}

	if (left == 0)return -1; //������ֵ��С
	return nums[left - 1] == target ? left - 1 : -1; //������ֵ����-1ʱ��

}



int main() {

	return 0;
}