#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

	if (strs.empty()) return "";
	
	int size = strs.size();
	string prefix = strs[0];

	for (int i = 1; i < size; i++) {
		
		string s = strs[i];
		int size1 = prefix.length(), size2 = s.length();

		string aux = ""; 
		for (int j = 0, m = 0; j < size1 && m < size2; j++, m++) {
			if (prefix[j] != s[m]) break;

			aux.push_back(prefix[j]);
		}
		swap(aux, prefix);
	}

	return prefix;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<string> v = {"dog","racecar","car"};

	cout << longestCommonPrefix(v) << endl;

	return 0;
}