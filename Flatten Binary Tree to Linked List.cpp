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
    TreeNode * Flatten(TreeNode *r){
        if(r==NULL) return NULL;
        if(r->left==NULL && r->right==NULL) return r;
        
        TreeNode * rr = r->right;
        TreeNode * ll;
        
        if(r->left!=NULL){
            r->right=r->left;
            r->left=NULL;
            ll = Flatten(r->right); 
            if(ll!=NULL) ll->right = rr;
            if(rr==NULL) return ll;
            else return Flatten(rr);
        }else{
            return Flatten(r->right);
        }         
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        Flatten(root);
    }
};