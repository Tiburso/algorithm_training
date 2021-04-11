#include <bits/stdc++.h>
#define long long as ll

using namespace std;

void reverseString(vector<char>& s) {
	for (int i = 0, j = s.size()-1; i <= j; i++, j--) {
		swap(s[i], s[j]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<char> s = {'t','e','s','t','e'};

	reverseString(s);

	for (char c : s) cout << c;
	cout << endl;

	return 0;
}