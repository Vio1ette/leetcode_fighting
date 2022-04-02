#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

//双指针+哈希表
//这题不难，但细节需要注意下
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int left = 0;
        int right = 0;
        int ret = 0;
        while (right < s.size())
        {
            if (mp.find(s[right]) != mp.end()) //发现有重复
            {
                if (mp[s[right]] >= left) {  //@滑动窗口以外的重复不计算，不更新left
                    ret = max(ret, right - left);
                    left = mp[s[right]] + 1;
                }
                mp[s[right]] = right;  //@不管重复是不是在滑动窗口以外，但当前字符的哈希位置一定要更新的
            }
            else
            {
                mp.insert({ s[right], right });
            }
            right++;
        }
        ret = max(ret, right - left);  //@别忘记right到末尾了也要更新一次ret
        return ret;
    }
};

int main()
{

    Solution a;
    a.lengthOfLongestSubstring("aabaab!bb");

    return 0;
}