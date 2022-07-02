class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       // still not getting how to solve this problem in given constrain.
        
        
        // solving the constrain in this game.
        
        
        // one of best questions that  i have encounter so far.
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int x= abs(nums[i]);
            if(nums[x-1]<0)
                ans.push_back(abs(x));
            else
                nums[x-1]*=-1;
        }
        return ans;
        
        
    }
};