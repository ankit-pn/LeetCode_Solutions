class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // suming them up will not work.
        // int slow = nums[0];
        // int fast= nums[nums[0]];
        // while(slow!=fast){
        //     slow=nums[slow];
        //     fast=nums[nums[fast]];
        // }
        // slow=0;
        // while(slow!=fast){
        //     slow=nums[slow];
        //     fast=nums[fast];
        // }
        // return slow;
        
        
        // secondapproach using same array.
        
        for(int i=0;i<nums.size();i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0)
                return x;
            else
                nums[x-1]*=-1;
        }
        return -1;
    }
};