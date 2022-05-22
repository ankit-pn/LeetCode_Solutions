class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
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
        for(int i=0;i<n-1;i++){
            if(lmax[i]<=rmin[i+1])
                c++;
        }
        return c;
    }
};