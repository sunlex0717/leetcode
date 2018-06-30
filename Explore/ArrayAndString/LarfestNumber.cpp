class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int length = nums.size();
        if(length <= 2){
            return -1;
        }
        // find largest one
        int largest=0;
        int largest_index;
        int second_largest=0;
        for(largest_index =0 ;largest_index<length;++largest_index){
            if( (item=nums[largest_index]) >largest){
                largest = item;
            }
        }
        for(int& item:nums){
            if( (item!=largest) && (item>second_largest) ){
                second_largest = item;
                if(2*second_largest >= largest){
                    std::cout<<"no valid found"<<endl;
                    return -1;
                }
            }
        }
        return largest_index;
    }
};