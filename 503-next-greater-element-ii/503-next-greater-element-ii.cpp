class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && arr[i%n]>=arr[st.top()]){
                st.pop();
            }        
            if(st.empty())
            res[i%n]=-1;
            else
            res[i%n]=arr[st.top()];
            st.push(i%n);
        }
      return res;
    }
};