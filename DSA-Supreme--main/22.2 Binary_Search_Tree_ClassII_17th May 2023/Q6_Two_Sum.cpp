/*
APPROACH (Inorder + Two Pointers)

1) Do an inorder traversal of the BST. 
   → This gives a sorted array of node values.

2) Use two-pointer method (i=0, j=n-1):
   - If v[i] + v[j] == target → return true
   - If sum < target → move left pointer (i++)
   - If sum > target → move right pointer (j--)
   Keep doing until i >= j.

Why this works:
- Inorder traversal of BST gives sorted order.
- Two-pointer search on sorted array is optimal.

Time:  O(n)
Space: O(n)
*/

class Solution {
    public:
        void inorder(TreeNode* root, vector<int> &v){
            if(!root) return;
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    
        bool findTarget(TreeNode* root, int k) {
            vector<int> v;
            inorder(root, v);
    
            int i = 0, j = v.size() - 1;
            while(i < j){
                int sum = v[i] + v[j];
                if(sum == k) return true;
                else if(sum < k) i++;
                else j--;
            }
            return false;
        }
    };
    