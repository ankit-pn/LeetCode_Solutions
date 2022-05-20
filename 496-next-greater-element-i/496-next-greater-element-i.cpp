class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>st.top()){
                int m=st.top();
                mp[m]=arr[i];
                st.pop();  
            }
            st.push(arr[i]);
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
        
    }
};