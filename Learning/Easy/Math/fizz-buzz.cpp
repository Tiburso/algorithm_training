#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string> final;
	for (int i = 1; i <= n; i++) {
		if (i % 15 == 0) final.push_back("FizzBuzz");
		else if (i % 3 == 0) final.push_back("Fizz");
		else if (i % 5 == 0) final.push_back("Buzz");

		else final.push_back(to_string(i));
	}

	return final;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (auto x : fizzBuzz(30)) cout << x << " ";
	cout << endl;

	return 0;
}