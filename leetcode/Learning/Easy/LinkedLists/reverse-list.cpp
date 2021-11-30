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

ListNode* reverseList(ListNode* head) {
	ListNode* prev = NULL;
	ListNode* curr = head;

	while ( curr != NULL ) {
		ListNode* aux = curr->next;
		curr->next = prev;                            
		prev = curr;
		curr = aux;
	}

	return prev;
}

void printList(ListNode* head) {
	for (ListNode* p = head; p ; p = p->next) {
		cout << p->val << " ";
	}

	cout << endl;
}

ListNode* addValue(ListNode* head, int val) {
	ListNode* n = new ListNode(val);

	head->next = n;

	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ListNode* e = new ListNode(5);
	ListNode* d = new ListNode(4,e);
	ListNode* c = new ListNode(3, d);
	ListNode* b = new ListNode(2, c);
	ListNode* head = new ListNode(1, b);

	printList(head);

	ListNode* final = reverseList(head);
	
	printList(final);

	return 0;
}