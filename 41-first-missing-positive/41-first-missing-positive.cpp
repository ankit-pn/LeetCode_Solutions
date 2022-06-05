class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        arr.push_back(0);
        int n=arr.size();
        for(int i=0;i<n;i++)
            if(arr[i]<0 || arr[i]>=n)
                arr[i]=0;
        for(int i=0;i<n;i++)
            arr[arr[i]%n]+=n;
        for(int i=1;i<n;i++)
            if(arr[i]/n==0)
                return i;
        return n;
        
    }
};