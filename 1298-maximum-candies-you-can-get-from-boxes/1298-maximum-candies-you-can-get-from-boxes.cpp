class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
            queue<int> q;
            int sum=0;
        int c=0;
            for(auto it:initialBoxes)
                q.push(it);
            int prev=INT_MAX;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                if(status[curr]){
                    sum+=candies[curr];
                for(auto it:keys[curr])
                    status[it]=1;
                for(auto it:containedBoxes[curr])
                    q.push(it);
            }
            else
            q.push(curr); 
                if(q.size()==prev)
                    c++;
                if(c==500)
                    break;
            prev=q.size();
        }
        return sum;
        
        
        
        
    }
};