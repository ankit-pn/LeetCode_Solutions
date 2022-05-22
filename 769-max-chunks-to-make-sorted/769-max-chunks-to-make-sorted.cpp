class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
//         int n=arr.size();
//         vector<int> res(n,n);
//         stack<int> st;
//         vector<int> res1(n,n);
//         stack<int> st1;
//         for(int i=0;i<n;i++){
//             while(!st.empty() && arr[st.top()]>arr[i]){
//                 st.pop();
//             }
//             st.push(i);
//         }
//         for(int i=n-1;i>=0;i--){
//             while(!st1.empty() && arr[st1.top()]<arr[i]){
//                 st1.pop();
//             }
//             st1.push(i);
//         }
       
//         return min(st.size(),st1.size());
        
        // rm - c found when all element of left is smaller than all element to right.
        // so for getting this , maxofleft<=minofright
        int n=arr.size();
        vector<int> lmax(n,0);
        vector<int> rmin(n,0);
        lmax[0]=arr[0];
        rmin[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],arr[i]);
            rmin[n-i-1]=min(rmin[n-i],arr[n-i-1]);
        }
        int c=1;
        // for(auto it:lmax){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        //  for(auto it:rmin){
        //     cout<<it<<" ";
        // }
        for(int i=0;i<n-1;i++){
            if(lmax[i]<=rmin[i+1])
                c++;
        }
        return c;
        
    }
};