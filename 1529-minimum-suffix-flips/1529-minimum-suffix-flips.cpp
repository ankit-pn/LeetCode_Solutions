class Solution {
public:
    int minFlips(string target) {
        int n=target.size();
        // char end=target[n-1];
        // int i;
        // for(i=n-1;i>=0;i--){
        //     if(target[i]!=end){
        //         break;
        //     }
        // }
        target= '0'+target;
        int c=0;
        for(int i=0;i<n;i++){
            if(target[i]!=target[i+1])
                c++;
        }
        return c;
    }
};