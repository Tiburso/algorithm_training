#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

int maxProfit(vector<int>& prices) {
	int min_p = prices[0];
	int max_p = 0;

	int len = prices.size();
	for (int i = 1; i < len; i++) {
		min_p = min(prices[i], min_p);
		max_p = max(max_p, prices[i]-min_p);
	}

	return max_p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = {7,6,4,3,1};

	cout << maxProfit(v) << endl;

	return 0;
}