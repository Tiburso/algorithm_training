#include <bits/stdc++.h>
#define long long as ll

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;
	int t1 = 0, t2 = 0; 

	cin >> s1 >> s2; 

	for (int i = 0;i < s1.length(); i++) s1[i] = tolower(s1[i]);
	for (int i = 0;i < s2.length(); i++) s2[i] = tolower(s2[i]); 


	int lex = 0;
	if ( s1 < s2 ) lex = -1;
	else if (s1 > s2 ) lex = 1;
	
	cout << lex << endl;

	return 0;
}