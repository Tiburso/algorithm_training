#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

bool isAnagram(string s, string t) {
	int size = s.length();
	if ( size != t.length() ) return false;
	map<char,int> anagram;

	for (int i = 0; i < size; i++) {
		anagram[ s[i] ]++;
		anagram[ t[i] ]--;
	}

	for (auto x : anagram) if (x.second != 0) return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1 = "rat";
	string s2 = "cat";

	if ( isAnagram(s1, s2) ) cout << "true" << endl;
	else cout << "false" << endl;

	return 0;
}