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

TreeNode* auxToBST(vector<int>& nums,int min,int max){
	if ( min > max ) return nullptr;

	int mid = min + (max-min)/2;

	TreeNode* head = new TreeNode(nums[mid]);

	head->right = auxToBST(nums, mid+1, max);
	head->left = auxToBST(nums, min, mid-1);

	return head;

}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return auxToBST(nums, 0, nums.size()-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	return 0;
}
