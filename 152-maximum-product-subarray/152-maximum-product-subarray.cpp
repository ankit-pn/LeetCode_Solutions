class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int mx=INT_MIN;
        int n=arr.size();
        int ans=1,ans2=1;
       for(int i=0;i<n;i++){
           ans*=arr[i];
           ans2*=arr[n-i-1];
           mx=max(mx,max(ans,ans2));
       if(ans==0)
           ans=1;
         if(ans2==0)
             ans2=1;
           }
         return mx;
    }
};