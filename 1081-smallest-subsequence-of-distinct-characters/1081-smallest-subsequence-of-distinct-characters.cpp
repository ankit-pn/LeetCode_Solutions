class Solution {
public:
    string smallestSubsequence(string s) {
         vector<bool> b(26,0);
            vector<int> in(26,0);
            int n=s.length();
            for(int i=0;i<n;i++){
                in[s[i]-'a']=i;
            }
            stack<char> st;
            int i=0;
        while(i<n){
              
            if(b[s[i]-'a']){
                 i++;
                continue;
            }
            while(!st.empty() && st.top()>s[i] && in[st.top()-'a']>i){
                b[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            b[s[i]-'a']=1;
            i++;
         
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};