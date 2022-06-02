class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        // intiallising the array;
        dp[n-1][m-1]=max(0,-arr[n-1][m-1])+1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)
                    continue;
                int a=1e5;
                int b=1e5;
                if(i+1<n)
                a=dp[i+1][j];
                if(j+1<m)
                b=dp[i][j+1];
                if(min(a,b)==1e5)
                    a=0;
                dp[i][j]=max(1,min(a,b)-arr[i][j]);
                
            }
        }
        // for(auto it:dp){
        //     for(auto it1:it){
        //         cout<<it1<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[0][0];
        
    }
};