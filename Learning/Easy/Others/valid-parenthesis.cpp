#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

bool isValid(string s) {
	stack<char> match;

	for (char c: s) {
		switch(c) {
			case '(':
			case '[':
			case '{':
				match.push(c);
				break;
			case ')':
				if ( match.empty() || match.top() != '(') return false;
				match.pop();
				break;
			case ']':
				if ( match.empty() || match.top() != '[') return false;
				match.pop();
				break;
			case '}':
				if ( match.empty() || match.top() != '{') return false;
				match.pop();
				break;
		}
	}

	if ( !match.empty() ) return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	return 0;
}