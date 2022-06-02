/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // error at possition where u have to pass by reference
    Node* dfs(Node* node,unordered_map<Node*,Node*> &mp){
        Node* ans=new Node(node->val);
        auto t=node->neighbors;
        vector<Node*> nng;
        mp[node]=ans;
        for(auto it:t){
            if(mp.find(it)!=mp.end())
             nng.push_back(mp[it]);
            else
            nng.push_back(dfs(it,mp));
        }
        ans->neighbors=nng;
        return ans;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(!node)
            return NULL;
        if((node->neighbors).size()==0){
            Node* ans=new Node(node->val);
            return ans;
        }
        else
        return dfs(node,mp);
    }
};