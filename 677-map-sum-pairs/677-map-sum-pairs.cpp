class TrieNode{
    public:
  TrieNode* child[26];
    int value;
    TrieNode(){
        memset(child,0,sizeof(child));
        value=0;
    }
};


class MapSum {
    TrieNode* root;
public:
    
    
    MapSum() {
        root=new TrieNode;    
    }
    map<string,int> mp;
    void insert(string key, int val) {
        int cont=mp[key];
        mp[key]=val;
        auto temp=root;
        for(auto &c:key){
            int x=c-'a';
            if(!temp->child[x]){
                auto temp1=new TrieNode;
                temp->child[x]=temp1;
            }
           
            temp=temp->child[x];
             temp->value+=(val-cont);
        }

    }
    
    int sum(string prefix) {
        auto temp=root;
        for(auto &c:prefix){
            int x=c-'a';
            if(!temp->child[x])
                return 0;
            temp=temp->child[x];
        }
        return temp->value;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */