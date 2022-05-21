class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> ns(n,n);
        vector<int> ps(n,-1);
        stack<int> st1;
        stack<int> st2;
            for(int i=0;i<n;i++){
                while(!st1.empty() && arr[st1.top()]>arr[i]){
                    ns[st1.top()]=i;
                    st1.pop();
                }
                st1.push(i);
            }
        for(int i=0;i<n;i++){
            while(!st2.empty() && arr[st2.top()]>arr[i]){
                st2.pop();
            }
            if(!st2.empty())
                ps[i]=st2.top();
            st2.push(i);
        }
        long long ans=0;
      vector<long long> res(n,0);
        for(int i=0;i<n;i++){
            res[i]=((ns[i]-i)%mod)*((i-ps[i])%mod)%mod;
            res[i]=((res[i]%mod)*(arr[i]%mod))%mod;
            ans+=res[i];
            ans=ans%mod;
        }
        return ans;
    }
};