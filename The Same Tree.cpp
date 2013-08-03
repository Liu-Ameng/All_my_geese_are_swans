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

    bool isSameStruct(TreeNode *p, TreeNode *q){
        if(p->left!=NULL && q->left==NULL)
            return false;
        if(p->left==NULL && q->left!=NULL)
            return false;
        if(p->right!=NULL && q->right==NULL)
            return false;
        if(p->right==NULL && q->right!=NULL)
            return false;
        return true;
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p==NULL && q==NULL) return true;
        if(p!=NULL && q==NULL) return false;
        if(p==NULL && q!=NULL) return false;
        if((p->val != q->val) || isSameStruct(p,q)==false ){
            return false;
        }
        if(p->left){
            if(isSameTree(p->left,q->left)==false)
                return false;
        }
        if(p->right){
            if(isSameTree(p->right,q->right)==false)
                return false;
        }
        return true;
    }
};