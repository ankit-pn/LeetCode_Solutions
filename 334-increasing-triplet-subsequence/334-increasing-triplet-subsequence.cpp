class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       // finally you arrived at soln but at what cost man.
        // pathetic, think before you speak, or think while speking.
        // do anything, but think faster.
        int n=nums.size();
        vector<int> mx(n,0);
        vector<int> mi(n,0);
        mx[n-1]=nums[n-1],mi[0]=nums[0];
        for(int i=n-2;i>=0;i--){
            mx[i]=max(nums[i],mx[i+1]);
        }
        for(int i=1;i<n;i++){
            mi[i]=min(nums[i],mi[i-1]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]<mx[i] && nums[i]>mi[i])
                return 1;
        }
        return 0;
        
        
        
    }
};