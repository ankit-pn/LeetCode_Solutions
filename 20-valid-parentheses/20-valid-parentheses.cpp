class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        int i=0;
        int f=1;
        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
            else if(st.empty())
                return 0;
            else if(s[i]==')' && st.top()=='(')
            st.pop();
             else if(s[i]=='}' && st.top()=='{')
            st.pop();
             else if(s[i]==']' && st.top()=='[')
            st.pop();
            else{
                f=0;
                return 0;
            }
            i++;
        }
        return (f && st.empty()) ? 1 : 0;
    }
};