class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(res[i]==-1)
                res[i]=0;
            else
                res[i]=res[i]-i;
        }
        return res;
    }
};