class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // another greedy problem nd you motherfucker is not able to solve it
        // we will make a diff array
        // -2 -2 -2 3 3
        // -2 -4 -6 -6 -6
        //  0  0  0  3  6
        // -2 -4 -6 3 0
        // if sum<0 return 0
        // else return max index.
        // -1 3 -4 2 -1 3 -4
        //-1 2 -2 0
        
        // -1   3 -4 2
        // -1 2 -2 0
        // if we are starting from any point we know its left sum , upto this point, we know the total sum 
        // maintaing positive prefix values
        // 0 3 3 5
        // -1 -1 -5 -5
        // u failed, no longeer eligible for any  kind of intern. period akit.
        
        
        // well people are saying this is kadane.
        // period , now think with hints.
        
        // well it is like cercular array.
        
        //
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;

        int sum=0,n=gas.size(),sum1=0;
        for(int i=0;i<n;i++){
            gas[i]=gas[i]-cost[i];
            if(gas[i]<0)
            sum1+=gas[i];
        }
        cout<<sum<<" ";
        int start=0,ans=0,mx=0;
        for(int i=0;i<2*n;i++){
            sum+=gas[i%n];
            if(sum<0){
                start=i+1;
                sum=0;
            }
            // this is beauty of kadane we have to update the value everytime.
            if(sum>mx){
                mx=sum;
                ans=start;
            }
        }
        // you have no fucking idea now how to deal with -1 case
       return ans;  
    }
};