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

bool isMirror(TreeNode* left, TreeNode* right) {
	if ( !left && !right ) return true;

	return (left && right && right->val == left->val && isMirror(left->left, right->right) && isMirror(left->right, right->left) );
}

bool isSymmetric(TreeNode* root) {
	return isMirror(root->left, root->right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	return 0;
}