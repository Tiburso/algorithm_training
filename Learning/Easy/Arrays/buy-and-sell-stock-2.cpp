#include <bits/stdc++.h>
#define long long as ll

using namespace std;

int maxProfit(vector<int>& prices) {
	int maxprofit = 0;

	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i-1]) maxprofit += prices[i] - prices[i-1];
	}

	return maxprofit;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	std::vector<int> v = {7,1,5,3,6,4};

	int profit = maxProfit(v);

	cout << profit << endl;

	return 0;
}