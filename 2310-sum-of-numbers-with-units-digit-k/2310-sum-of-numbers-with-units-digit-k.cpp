class Solution {
public:
    int minimumNumbers(int num, int k) {
        
        if(!num)
            return num;
        if(num<k)
            return -1;
        vector<int> dp(11,0);
        for(int i=1;i<11;i++){
            dp[i]=(k*(i))%10;
        }
        int x=num%10;
        int ans=-1;
        for(int i=1;i<11;i++)
            if(x==dp[i]){
                if(i*k<=num){
                    ans=i;
                    break;
                }
            }
        return ans;
    }
};