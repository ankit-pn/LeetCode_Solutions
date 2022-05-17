class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        queue<int> q;
        q.push(0);
        vector<int> dp(n+1,0);
        while(!q.empty()){
            int y1=q.front();
            // cout<<y1<<endl;
            q.pop();
            
            for(auto &ss : wordDict){
                int j = 0 , f = 1;
                
                for(auto &p1 : ss){
                    if(p1 != s[y1+j]){
                        f = 0;
                        break;
                    }
                    ++j;
                }
                
                if(f){
                    
                    if(y1 + ss.length() < n && !dp[y1 + ss.length() - 1]){
                        q.push(y1 + ss.length());
                        // cout<<y1+ss.length()<<endl;
                    }
                    dp[y1 + ss.length() - 1] = 1;
                }
                
                
            }
            
        
        }
        return dp[n-1];
    }
};