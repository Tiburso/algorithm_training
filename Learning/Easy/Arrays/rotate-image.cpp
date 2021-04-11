#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int len = matrix.size(); 
	for (int x = 0; x < (len+1)/2; x++) {
		for (int y = 0; y < len/2; y++) {
			int tmp = matrix[len-1-y][x];
			matrix[len-1-y][x] = matrix[len-1-x][len-1-y];
			matrix[len-1-x][len-1-y] = matrix[y][len-1-x];
			matrix[y][len-1-x] = matrix[x][y];
			matrix[x][y] = tmp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	return 0;
}