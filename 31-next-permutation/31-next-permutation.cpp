class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size()-1;
        int in=0,f=0;
        for(int i=n;i>0;i--){
            if(arr[i]>arr[i-1]){
                f=1;
                in=i;
                break;
            }
        }
        if(f==0){
            reverse(arr.begin(),arr.end());
            return ;
        }
        int mi=INT_MAX;
        int ind=0;
        for(int i=n;i>=in;i--){
            
            if(arr[i] > arr[in-1]){
                mi=arr[i];
                ind=i;
                break;
            }
        }
        int y=arr[in-1];
        int d=0;
        swap(arr[in-1],arr[ind]);
        reverse(arr.begin()+in,arr.end());
    }
};