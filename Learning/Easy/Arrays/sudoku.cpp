#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> b_row(9,0);
    vector<int> b_col(9,0);
    vector<int> b_blc(9,0);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            int val = pow(2, board[i][j] - '0');
            
            if (b_row[i] & val) return false;
            b_row[i] += val;
            
            if (b_col[j] & val) return false;
            b_col[j] += val;
            
            int mod = (3 * (i / 3)) + (j / 3);
            if (b_blc[mod] & val) return false;
            b_blc[mod] += val; 
        }
    }

    return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	return 0;
}