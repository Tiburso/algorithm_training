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

bool hasCycle(ListNode* head) {
	if ( !head ) return false;

	for ( auto slow = head, fast = head->next; slow->next && fast->next && fast->next->next ;  slow = slow->next, fast = fast->next->next) {

		if ( slow == fast ) {
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ListNode* tail = new ListNode(5);
	ListNode* b = new ListNode(4, tail);
	ListNode* a = new ListNode(3, b);
	ListNode* e = new ListNode(2, a);
	ListNode* head = new ListNode(1, e);
	tail->next = head;

	if ( hasCycle(head) ) cout << "true";
	else cout << "false";

	return 0;
}