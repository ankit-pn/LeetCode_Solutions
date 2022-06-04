class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
            vector<int> dp(n,0);
        dp[0]=1;
            for(int i=1;i<n;i++){
                // int x=arr[i];
                // int c=0;
                // for(int j=i-1;j>=0;j--){
                //     if(arr[j]<x){
                //         x=arr[j];
                //         c++;
                //     }
                // }
                // dp[i]=c+1;
                //////here we go , the mistake that you have done
                // if(arr[i]>arr[i-1])
                //     dp[i]=dp[i-1]+1;
                // else
                //     dp[i]=1;
                //////// again wrng approach
                int mx=0;
                for(int j=i-1;j>=0;j--){
                    if(arr[j]<arr[i])
                        mx=max(mx,dp[j]);
                }
                dp[i]=mx+1;
                // this will get accepted , thnks to 
                // https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#solution-in-on2-with-dynamic-programming
                
                // see u again
            }
     
        return *max_element(dp.begin(),dp.end());
    }
};