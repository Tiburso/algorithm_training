#include <bits/stdc++.h>
#define longlong as ll

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
	for (; head ; head = head->next) {
		cout << head->val << " ";
	}

	cout << endl;
}

ListNode* addValue(ListNode* head, int val) {
	ListNode* n = new ListNode(val);

	head->next = n;

	return n;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* start = new ListNode();	
	ListNode* final = start;

	int carry = 0;
	while (l1 || l2) {
		int s = 0;

		if (l1) {
			s += l1->val;
			l1 = l1->next;
		}

		if (l2) {
			s += l2->val;
			l2 = l2->next;
		}

		s += carry;
		carry = s / 10;

		final = addValue(final, s % 10);
	}

	if (carry) {
		final = addValue(final, carry);
	}

	return start->next;
}

int main() {
	// List 1
	ListNode* a = new ListNode(2);
	ListNode* b = new ListNode(4, a);
	ListNode* l1 = new ListNode(3, b);

	// List 2
	ListNode* c = new ListNode(5);
	ListNode* d = new ListNode(6, c);
	ListNode* l2 = new ListNode(4, d);

	ListNode* final = addTwoNumbers(l1, l2);

	printList(final);

	return 0;
}