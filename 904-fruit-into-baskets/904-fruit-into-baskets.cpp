class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        int c2=0;
        int c1=arr[0];
        // finding 2nd element 
        for(int i=0;i<n;i++){
            if(arr[i]!=c1){
                c2=arr[i];
                break;
            }
        }
        // cout<<c2<<"\n";
        int ans=0;
        int i=1;
        int curr=0;
        // rq is the index of previos one 
        // ex - 1 2 1 1 2 2 2 2 3
        // since when we start from 3 all we need is to maintain index of 2 ie from 2 2 2 2 3 wla index. thats all we need.
        int rq=0;
        while(i<n){
            // curr is used to find the index of position from where 2 starts again, i,e unequal part.
            // 
            while(i<n && (arr[i]==c1 || arr[i]==c2)){
                if(arr[i]!=arr[i-1])
                    curr=i;
                    i++;
            }
            // cout<<i<<rq<<"\n";
            // then we will find requ ans, and max it.
            ans=max(i-rq,ans);
            // update the rq index
            rq=curr;
            // update c1 and c2 for next search
            if(i<n)
            c2=arr[i];
            if(curr<n)
            c1=arr[curr];
        }
        return ans;
    }
};