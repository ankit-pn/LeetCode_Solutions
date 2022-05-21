class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> res(n,n);
        vector<int> prev(n,0);
        stack<int> st1;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[st1.top()]>arr[i])
        st1.pop();
        if(st1.empty())
            prev[i]=-1;
        else
            prev[i]=st1.top();
        st1.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            res[i]=arr[i]*(res[i]-prev[i]-1);
            ans=max(res[i],ans);
        }
        return ans;
    }
};