class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // same as previous problem , using same array to store the data.
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]>0)
                nums[x-1]*=-1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};