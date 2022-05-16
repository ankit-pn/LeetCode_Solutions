class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
       stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()=='[' && s[i]==']')
                st.pop();
            else
            st.push(s[i]);
        }  
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        n=ans.length();
        n=n/2;
        return (n+1)/2;
        
        
    }
};