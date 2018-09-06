/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> st;
public:
    BSTIterator(TreeNode *root) {
        push_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* p = st.top();
        st.pop();
        if( p->right != NULL){
          push_left(p->right);
          
        }
        return p->val;
        
    }

    void push_left(TreeNode *root){
      TreeNode *p = root;
      while(p != NULL){
        st.push(p);
        p = p->left;
      }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */