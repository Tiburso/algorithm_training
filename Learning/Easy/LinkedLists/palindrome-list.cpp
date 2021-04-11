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

bool isPalindrome(ListNode* head) {
	stack<int> rev;

	for (auto p = head; p != nullptr; p = p->next) {
		rev.push(p->val);
	}

	for (auto p = head; p != nullptr; p = p->next) {
		if ( p->val != rev.top() ) return false;
		rev.pop();
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ListNode* tail = new ListNode(1);
	ListNode* b = new ListNode(1, tail);
	ListNode* a = new ListNode(2, b);
	ListNode* head = new ListNode(1, a);

	if ( isPalindrome(head) ) cout << "true";
	else cout << "false";

	return 0;
}