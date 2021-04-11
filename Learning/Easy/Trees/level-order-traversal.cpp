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

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> final;
	queue<TreeNode*> current; 
	queue<TreeNode*> next;

	if ( !root ) return final;

	current.push(root);
	vector<int> aux;

	while ( !current.empty() ) {

		TreeNode* tmp = current.front();
		aux.push_back(tmp->val);
		current.pop();

		if (tmp->left) next.push(tmp->left);
		if (tmp->right) next.push(tmp->right);

		if (current.empty()) {
			final.push_back(aux);
			aux.clear();
			swap(current, next);
		}
	}

	return final;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	return 0;
}