#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

string countAndSay(int n) {
	string s = "1";

	for (int i = 1; i < n; i++) {
		int size = s.length();

		string aux = "";
		int count = 1;

		for (int j = 0; j < size; j++) {

			if ( s[j] != s[j+1] ) {
				aux.push_back('0' + count);
				aux.push_back(s[j]);
				count = 1;
			}
			else
				count++;
		}

		swap(aux, s);
	}

	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int n = 1 ; n < 31; n++)
		cout << countAndSay(n) << endl;

	return 0;
}