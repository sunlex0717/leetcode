/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// BSF
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> BFS;
        if(root==NULL){
            return true;
        }
        BFS.push(root);
        while(!BFS.empty()){
            int size = BFS.size();
            vector<int> check;
            int p=0;
            for(int i=0;i<size;++i){
                TreeNode* cur = BFS.front();
                BFS.pop();
                if(cur->left!=NULL){
                    BFS.push(cur->left);
                    check.push_back(cur->left->val);
                    p++;
                }else{
                    check.push_back(INT_MAX);
                }

                if(cur->right!=NULL){
                    BFS.push(cur->right);
                    check.push_back(cur->right->val);
                    p++;
                }else{
                    check.push_back(INT_MAX);
                }
            }
            if(p==0){
                return true;
            }
            if(p%2 == 1){
                return false;
            }else{
                for(int i=0;i<check.size()/2;++i){
                    if(check[i]!=check[check.size()-1-i]){
                        return false;
                    }
                }

            }
        }
        return true;
        //vector<int> level_val;
       
    }
};