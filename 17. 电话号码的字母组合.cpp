#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//ºÜÆÕÍ¨µÄDFS
class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits == "")return {};
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        find(digits, 0, "", mp);
        return res;
    }
    void find(string digits, int depth, string cur, unordered_map<int, string> mp) {
        if (depth == digits.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < mp[digits[depth]-'0'].size(); i++) {
            cur.append({ mp[digits[depth] - '0'][i]});
            find(digits, depth + 1, cur, mp);
            cur.pop_back();
        }
    }
};


int main()
{
    Solution a;
    a.letterCombinations("23");
	return 0;
}