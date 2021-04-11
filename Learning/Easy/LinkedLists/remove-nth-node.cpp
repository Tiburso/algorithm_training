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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *prev = head;
	ListNode *aux = head;

	for (int i = 0; i < n; i++) {
		aux = aux->next;

	}

	if (aux == nullptr ) return head->next;

	while (aux->next != nullptr) {
		prev = prev->next;
		aux = aux->next;
	}

	prev->next = prev->next->next;	

	return head;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ListNode c(3);
	ListNode b(2, &c);
	ListNode a(1, &b);

	cout << removeNthFromEnd(&a, 1)->val << endl;

	return 0;
}