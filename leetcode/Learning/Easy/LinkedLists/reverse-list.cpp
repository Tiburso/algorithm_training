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

ListNode* reverseList(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* curr = head;

	while ( curr != nullptr ) {
		ListNode* aux = curr->next;
		curr->next = prev;
		prev = curr;
		curr = aux;
	}

	return prev;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ListNode e(5);
	ListNode d(4,&e);
	ListNode c(3, &d);
	ListNode b(2, &c);
	ListNode head(1, &b);

	ListNode* final = reverseList(nullptr);
	
	if (final) cout << final->val << endl;

	return 0;
}