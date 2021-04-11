#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int strStr(string haystack, string needle) {
	int hay_size = haystack.length();
	int need_size = needle.length();

	int len = hay_size - need_size;

	if (needle.empty()) return 0;

	for (int i = 0; i <= len; i++) {
		if ( haystack[i] == needle.front() && haystack.substr(i, need_size) == needle ) return i;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string hay = "";
	string needle = "";

	cout << strStr(hay, needle);

	return 0;
}