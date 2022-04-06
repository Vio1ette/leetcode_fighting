#include <bits/stdc++.h>

using namespace std;

//普通二分
//没找到的话返回target的合理插入位置
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
	

	//没找到
	if (nums[left] > target) {
		return left;
	}
	else if (nums[left] < target) {
		return left + 1;
	}

}

//寻找左边界二分
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
	
	if (left == nums.size())return -1; //比所有值都大
	return nums[left] == target ? left : -1; //比所有值都小（-1时）

}

//寻找右边界二分

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
			//这里 right = mid - 1; 是错误的
			//想象一下right前面的值刚好就等于target，此时right刚好是右边界+1
			//而left最终的结果是“右边界+1”，即当前right位置
			//如果right=mid-1了，left就到达不了
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}

	if (left == 0)return -1; //比所有值都小
	return nums[left - 1] == target ? left - 1 : -1; //比所有值都大（-1时）

}



int main() {

	return 0;
}