/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //first find the node
        if(root==NULL){
            return root;
        }
        if(root->val == key){//base case
            if(root->left == NULL && root->right ==NULL){
                delete root;
                return NULL;
            }else if( root->left == NULL && root->right != NULL ){ //
                TreeNode* cur = root->right;
                delete root;
                return cur;   
            }else if(root->left != NULL && root->right == NULL){
                TreeNode* cur = root->left;
                delete root;
                return cur; 
            }else{ // two child find inorder successor
                TreeNode* suc = find_successor(root->right);
                swap(suc->val,root->val);
                //
                root->right = deleteNode(root->right, key);
            }

        }else if( root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            root->right = deleteNode(root->right,key);
        }
        
        

        return root;

    }
    TreeNode* find_successor(TreeNode* root){
       if(root->left!=NULL) return find_successor(root->left);
        return root;
    }

};