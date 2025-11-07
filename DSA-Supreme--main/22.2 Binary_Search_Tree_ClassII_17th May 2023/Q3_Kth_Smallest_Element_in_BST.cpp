class Solution {
public:
    int helper(TreeNode *root, int &k){
        if(!root) return -1;

        int left = helper(root->left, k);
        if(left != -1) return left;

        k--;
        if(k == 0) return root->val;

        return helper(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
};