#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode();
	ListNode* p = head; 

	ListNode* p1 = l1;
	ListNode* p2 = l2;

	while (p1 != nullptr && p2 != nullptr) {
		if (p1->val < p2->val) {
			p->next = p1;
			p1 = p1->next;
		}

		else {
			p->next = p2;
			p2 = p2->next;
		} 

		p = p->next;
	}

	if (p1 != nullptr) {
		p->next = p1;
	}

	if (p2 != nullptr) {
		p->next = p2;
	}

	return head->next;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ListNode* tail = new ListNode(4);
	ListNode* a = new ListNode(3, tail);
	ListNode* l1 = new ListNode(1, a);

	ListNode* tail2 = new ListNode(4);
	ListNode* b = new ListNode(2, tail2);
	ListNode* l2 = new ListNode(1, b);

	ListNode* final = mergeTwoLists(l1, l2);

	for (auto x = final; x != nullptr; x=x->next) cout << x->val << " ";

	return 0;
}

