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

void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ListNode c(3);
	ListNode b(2, &c);
	ListNode a(1, &b);

	deleteNode(&b);

	cout << b.val << endl;

	return 0;  
}