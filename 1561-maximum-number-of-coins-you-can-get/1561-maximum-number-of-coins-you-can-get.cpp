class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int sum=0,k=piles.size()/3,n=piles.size();
        for(int i=n-2;i>=0 && k>0;k--,i-=2){
            sum+=piles[i];
        }
        return sum;
    }
};