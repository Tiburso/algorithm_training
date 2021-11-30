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

ListNode* createLinkedList(vector<int>& v) {
    ListNode* start = new ListNode();
    ListNode* final = start;

    for (int x : v) {
        final = addValue(final, x);
    }

    return start->next;
}

ListNode* oddEvenList(ListNode* head) {
    if (!head) {
        return head;
    }

    ListNode* even = head;
    ListNode* odd = head->next;

    while (odd && odd->next) {
        ListNode* tmp = odd->next;
        
        odd->next = tmp->next;
        tmp->next = even->next;
        even->next = tmp;
        
        even = even->next;
        odd = odd->next; 
    }

    return head;       
}

int main() {
    // List 1
    vector<int> v = { };

    ListNode* head = createLinkedList(v);

    printList(head);

    ListNode* final = oddEvenList(head);

    printList(final);

    return 0;
}