#include <bits/stdc++.h>
#define longlong as ll

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrder(TreeNode* root, vector<int>& v) {
	if ( root ) {
		inOrder(root->left, v);
		v.push_back(root->val);
		inOrder(root->right, v);
	}
}

bool isValidBST(TreeNode* root) {
	vector<int> v;

	inOrder(root, v);

	int len = v.size();
	for (int i = 0; i < len-1; i++) {
		cout << v[i] << " " << v[i+1];
		if ( v[i] >= v[i+1] ) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);



	return 0;
}