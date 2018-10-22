class NumArray {
private:
  vector<int> mem;
public:
    NumArray(vector<int> nums) {
      int len = nums.size();
      if(len > 0){
        mem.push_back(nums[0]);
        for(int i = 1;i<len;i++){
          mem.push_back(mem[i-1]+nums[i]);
        }
      }
      
    }
    
    int sumRange(int i, int j) {
      if(i==0){
        return mem[j];
      }else{
        return mem[j]-mem[i-1];
      }
     
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */