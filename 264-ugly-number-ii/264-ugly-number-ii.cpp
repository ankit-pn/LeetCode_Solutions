class Solution {
public:
    int nthUglyNumber(int n) {
        // u are fucking blushit not able to write even a shittest code .
        
        // priority_queue<int,vector<int>,greater<int>> pq;
        // pq.push(1);
        // int c=0;
        // while(pq.size()<=n){
        //     int x=pq.top();
        //     pq.push(2*x);
        //     pq.push(3*x);
        //     pq.push(5*x);
        //     pq.pop();
        // }
        // while(c!=n){
        //     ans=pq.top();
        //     pq.pop();
        //     c++;
        // }
        // return ans;
      // wait for writing dp soln you need to maintain t1,t2,t3 three variables.
        
        
        // lemme start now.
        // one of best problem of dynamic programming
        
        int t1=1,t2=1,t3=1;
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=min({2*dp[t1],3*dp[t2],5*dp[t3]});
            if(dp[i]==2*dp[t1])t1++;
             if(dp[i]==3*dp[t2])t2++;
             if(dp[i]==5*dp[t3])t3++;
        }
        return dp[n];
    }
};