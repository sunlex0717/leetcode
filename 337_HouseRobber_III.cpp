/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// rob(root) = max(val+ rob(root.child.childs), rob(root.left) + rob(root.right))
#include <unordered_map>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
using namespace std;
class Solution {

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> DP;
        return subrob(root,DP );
    }

    int subrob(TreeNode* root, unordered_map<TreeNode*, int>& DP){
        if(root==nullptr){
            return 0;
        }
        if(DP.find(root)!=DP.end()){
            return DP.at(root);
        }

        int val = 0;

        if(root->left != nullptr){
            val+= subrob(root->left->left,DP) + subrob(root->left->right,DP);
        }

        if(root->right != nullptr){
            val+= subrob(root->right->left,DP) + subrob(root->right->right,DP);
        }

        int res = max(root->val + val, subrob(root->left,DP)+subrob(root->right,DP));

        DP[root] = res;

        return res;
    }
};