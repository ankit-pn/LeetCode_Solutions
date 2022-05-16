class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long n=nums.size();
        long long res=nums[0];
        for(int i=1;i<n;i++){
            res^=nums[i];
        }
        res&=(-res);
        vector<int> ans={0,0};
        for(int i=0;i<n;i++){
            if((res&nums[i])==0)
                ans[0]^=nums[i];
            else
                ans[1]^=nums[i];
        }
        return ans;
    }
};