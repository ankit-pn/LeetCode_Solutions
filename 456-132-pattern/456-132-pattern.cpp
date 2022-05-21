class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n=arr.size();
        int t=INT_MIN;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<t)
                return 1;
            while(!st.empty() && arr[i]>st.top()){
                t=st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        return 0;
    }
};