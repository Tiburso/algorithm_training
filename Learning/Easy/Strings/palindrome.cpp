#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

bool isPalindrome(string s) {
	int j = s.length()-1;
	int i = 0;

	while (i < j) {
		if ( !isalnum(s[i]) ) i++;
		else if ( !isalnum(s[j]) ) j--;
		else if ( tolower(s[i++]) != tolower(s[j--]) ) return false;
	}

	return true;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s = "";

	if ( isPalindrome(s) ) cout << "true";
	else cout << "false";

	return 0;
}