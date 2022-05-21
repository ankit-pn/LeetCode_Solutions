class Solution {
public:
    string removeKdigits(string arr, int k) {
            stack<char> st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k && st.top()>arr[i]){
                st.pop();
                k--;
            }
            st.push(arr[i]);
        }
        if(k){
            while(!st.empty() && k){
                st.pop();
                k--;
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        string temp="";
        int i=0;
        while(res[i]=='0' && i<res.size()){
            i++;
        }
        res=res.substr(i,n-i+1);
        return res=="" ? "0" : res;
    }
};