class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Solving in 0(n) space now.
        
        // vector<int> ans(n,0);
        // ans[0]=arr[0];
        int n=nums.size();
        vector<int> right(n,0);
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        right[i]=nums[i]*right[i+1];
        
        for(int i=n-2;i>=0;i--)
        nums[(n-1)-i]*=nums[(n-2)-i];
        
        right[0]=right[1];
        for(int i=1;i<n-1;i++)
            right[i]=nums[i-1]*right[i+1];
        right[n-1]=nums[n-2];
        return right;
    }
};