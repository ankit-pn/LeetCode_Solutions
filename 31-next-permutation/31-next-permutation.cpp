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
        int ind=0;
        for(int i=n;i>=in;i--){
            if(arr[i] > arr[in-1]){
                ind=i;
                break;
            }
        }
        swap(arr[in-1],arr[ind]);
        reverse(arr.begin()+in,arr.end());
    }
};