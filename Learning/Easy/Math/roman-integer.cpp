#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int romanToInt(string s) {
	int len = s.size();
	map<char,int> m = {{'I',1}, {'V', 5}, {'X',10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

	int total = 0;
	for (int i = 0; i < len; i++) {
		if (m[s[i+1]] <= m[s[i]]) total += m[s[i]];
		else total -= m[s[i]];
	} 

	return total;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << romanToInt("III") << endl;

	return 0;
}