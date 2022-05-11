#include <iostream>
#include <vector>
using namespace std;

//思路：把数字都放在正确的位置上，最后没有在正确的位置上的就是重复数字

//我思，每当发现要交换的位置已经满足条件时，就发现重复，就将数字push_back进res数组
// 这个方法的缺陷是，一个位置会有多次被访问，这样就有可能会加入冗余的重复数字
// 所以，改进方法是，每当发现要交换的位置已经满足条件时，并不直接就push_back，而是先停止交换，并跳过当前元素，开始处理下一个元素
// 等所有的交换逻辑都处理完了之后，再执行push_back的逻辑，以免发生对于同一个位置的多次push_back

//错误实现
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
                    res.push_back(nums[i]); //这里不应该立即push_back
                    break;
                }

            }
        }
        return res;
    }
};

//正确实现
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
                //注意这里不能用 while(nums[i]!=i+1)，否则在目标交换位置已经满足条件时，会造成无限循环
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