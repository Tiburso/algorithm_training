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

ListNode* addValue(ListNode* head, ListNode* other) {
    ListNode* front = head;
    for (; front->next; front = front->next){}

    front->next=other;

    return head;
}

ListNode* createLinkedList(vector<int>& v) {
    ListNode* start = new ListNode();
    ListNode* final = start;

    for (int x : v) {
        final = addValue(final, x);
    }

    return start->next;
}


int getSize(ListNode* head) {
    int i = 0;
    for (; head; head=head->next, i++){}
    return i;
}

ListNode* getIntersectionNode(ListNode* listA, ListNode* listB) {
    int c1 = getSize(listA);
    int c2 = getSize(listB);
    
    if ( c1 > c2 ) {
        for (int i=c1-c2; i > 0; i--, listA=listA->next) {}
    } else {
        for (int i=c2-c1; i > 0; i--, listB=listB->next) {}
    }

    for (ListNode *p1=listA, *p2=listB ; p1 && p2; p1=p1->next, p2=p2->next) {
        if ( p1 == p2 ) {
            return p1;
        }
    }

    return NULL;
}

int main() {
    // List 1
    vector<int> v1 = { 4, 1 };
    vector<int> v2 = { 5, 6, 1};
    vector<int> v3 = { 8, 4, 5 };

    ListNode* list1 = createLinkedList(v1);
    ListNode* list2 = createLinkedList(v2);
    ListNode* intersection = createLinkedList(v3);

    addValue(list1, intersection);
    addValue(list2, intersection);

    printList(list1);
    printList(list2);


    ListNode* final = getIntersectionNode(list1, list2);

    printList(final);

    return 0;
}