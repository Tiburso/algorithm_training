#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

class MinStack {
    stack<pair<int, int>> stk; 
    
public:
    /** initialize your data structure here. */
    MinStack() {
        stack<pair<int, int>> stk; 
    }
    
    void push(int val) {
        int mn = val; 
        if (!stk.empty()) {
            mn = min(mn, stk.top().second); 
        }
        stk.push(make_pair(val, mn)); 
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first; 
    }
    
    int getMin() {
        return stk.top().second; 
    }
};


