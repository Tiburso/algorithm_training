#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int firstUniqueChar(string s) {
	unordered_map<char, int> char_index;
	int size = s.size();

	for (int i = 0; i < size; i++) {
		char_index[s[i]]++;
	}
	
	for (int i = 0; i < size; i++) {
		if ( char_index[s[i]] == 1) return i;
	}

	return -1;
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s = "leetcode";

	int x = firstUniqueChar(s); 

	cout << x << endl;

	return 0;
}