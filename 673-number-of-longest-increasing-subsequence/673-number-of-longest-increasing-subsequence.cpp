class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // again the same code as previous one, lemee write again to mke sure
        // to wrk on etics to perform good
        
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=1;
        vector<int> cp(n,0);
        cp[0]=1;
        dp[0]=1;
        for(int i=1;i<n;i++){
            int mx=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    mx=max(mx,dp[j]);
                }
            }
                int c1=0;
                for(int k=i-1;k>=0;k--)
                    if(dp[k]==mx && nums[k]<nums[i])
                        c1+=cp[k];
                cp[i]=max(c1,1);
                dp[i]=1+mx;
        }
        // for(auto it:dp)
        //     cout<<it<<" ";
        // cout<<"\n";
        //  for(auto it:cp)
        //     cout<<it<<" ";
        int y=*max_element(dp.begin(),dp.end());
        cout<<y;
        int c=0;
        // this question has much mre modf.
        int sum=0;
        for(int i=0;i<n;i++)
            if(dp[i]==y)
                sum+=cp[i];
        return sum;
    }
};