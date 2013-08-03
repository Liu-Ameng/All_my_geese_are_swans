/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    int oneBranch(TreeNode *root, int before){
         before = before*10+root->val;
         if(root->left==NULL && root->right==NULL) return before;
         int ret=0;
         if(root->left) ret += oneBranch(root->left,before);
         if(root->right) ret += oneBranch(root->right,before);
         return ret;
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;
        return oneBranch(root,0);
    }
};