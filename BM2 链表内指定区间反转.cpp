#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//������⣬�ഴ��ͷǰ�ڵ㣬����һ��

 struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int value) :val(value), next(nullptr){}
 };
 

class Solution {
public:
    /**
     *
     * @param head ListNode��
     * @param m int����
     * @param n int����
     * @return ListNode��
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* dumpy = new ListNode(-1);
		dumpy->next = head;
		ListNode* start = dumpy;
		ListNode* after_end = dumpy;
		ListNode* pre = dumpy;

		while (m--) {
			pre = start;
			start = start->next;
		}
		while (n--) {
			after_end = after_end->next;
		}
		after_end = after_end->next;
		
		pre->next = reverse(start, after_end, after_end);

		return dumpy;
    }

    ListNode* reverse(ListNode* head, ListNode* pre, ListNode* end) {
		ListNode* node = head;
		while (node != end) {
			ListNode* temp = node->next;
			node->next = pre;
			pre = node;
			node = temp;
		}
		return pre;
    }
};
