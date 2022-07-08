class Solution {
public:
    int triangleNumber(vector<int>& arr) {
       // 1 2 3 4 5 6
        // 1 2 3 4 11
        
        // suppose we want to sum < 11
        // for every number..
        // well it is like prefix sum.
        // but there is more to game
        // 1 3 7
        // use two pointer bitch.
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int c=0;
        // well welcome to dog shit.
        for(int k=n-1;k>=2;k--){
            // for(int i=0;i<k;i++){
            //     // for(int j=i+1;j<k;j++){
            //     //     if(arr[i]+arr[j]>arr[k]){
            //     //         c++;
            //     //     // cout<<i<<" "<<j<<" "<<k<<" \n";
            //     //     }
            //     // }
            //     if(arr[i]+arr[0]>arr[k])
            //         c+=k-i;
            // }
            int i=0,j=k-1;
            while(i<j){
                if(arr[i]+arr[j]>arr[k]){
                    c+=j-i;
                    j--;
                }else
                    i++;
            }
            
        }
        return c;
        
        
        
        
        
    }
};