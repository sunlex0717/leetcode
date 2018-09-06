/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class KthLargest {
private:
  struct TreeNode {
      int val;
      int cnt; // number of 
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x),cnt(1), left(NULL), right(NULL) {}
  };
  TreeNode* root_;
  int k_;
public:
    KthLargest(int k, vector<int> nums) {
        int size = nums.size();
        this->k_ = k;
        // construc tree. if a>= b then a is at right child.
        root_ = NULL;
        for(int i=0;i<size;i++){//construct the whole tree
            root_ = insert_node(root_,nums[i]);
          }
    }
    
    
    int add(int val) {
        //insert
        root_=insert_node(root_,val);
        // find 
       
        //print_tree(root_);
        //cout<<endl;
        int res = find_kth(root_,k_);
        return res;
    }

private:
  TreeNode * insert_node(TreeNode * root, int val){
    if(root == NULL){
      root = new TreeNode(val);
      return root;
    }
    root->cnt ++;
    if(val >= root->val ){ //right subtree
      if( root->right == NULL){
        root->right = new TreeNode(val);
        return root;
      }else{
        root->right = insert_node(root->right,val);
      }
    }else { // left subtree
      if(root->left == NULL){
        root->left = new TreeNode(val);
      }else{
        root->left = insert_node(root->left,val);
      }
    }
    return root;
  }

  void print_tree(TreeNode * root){
    if(root == NULL){
      return ;
    }
    print_tree(root->left);
    cout<< root->val<<","<<root->cnt <<" ";
    print_tree(root->right);
  }

  int find_kth(TreeNode* root,int k){
    TreeNode * left;
    left = root->left;
    TreeNode * right ;
    right = root->right;
    if(right == NULL && left != NULL){ // then the root is largest one
      if(k==1){
        return root->val;
      }else{
        return find_kth(left,k-1);
      }
    }else if(right !=NULL && left==NULL){
      if(k == root->cnt){
        return root->val;
      }else{
        return find_kth(right,k);
      }
    }else if(right != NULL && left != NULL){
      if(right->cnt >= k){
        return find_kth(right,k);
      }else{
        if(right->cnt +1 == k){
          return root->val;
        }
        return find_kth(left,k - 1 - right->cnt);
      }
    }

    return root->val;

  }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */