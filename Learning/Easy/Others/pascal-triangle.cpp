#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> triangle = {{1}};

	int left, rigth;
	for (int i = 0; i < numRows-1; i++)  {
		vector<int> newRow;
		int len = triangle[i].size();
		
		newRow.push_back(1);
		for (int j = 0; j < len-1; j++) {
			left = triangle[i][j];
			rigth = triangle[i][j+1];

			newRow.push_back(left+rigth);

		}

		newRow.push_back(1);
		triangle.push_back(newRow);
	}

	return triangle;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;

	vector<vector<int>> triangle = generate(x);

	int len = triangle.size();
	for (int i = 0; i < len; i++) {
		for (int n : triangle[i]) cout << n << " ";
		cout << endl;
	}

	return 0;
}