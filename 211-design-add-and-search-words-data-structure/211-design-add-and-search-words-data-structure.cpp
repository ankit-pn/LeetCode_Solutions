class TrieNode{
    public:
    TrieNode* child[26];
    bool f;
    TrieNode(){
        f=0;
        memset(child,0,sizeof(child));
    }
};


class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root=new TrieNode;
    }
    
    void addWord(string word) {
        auto temp=root;
        for(auto &c:word){
            int x=c-'a';
            if(temp->child[x]==NULL){
                TrieNode* temp1=new TrieNode;
                temp->child[x]=temp1;
            }
            temp=temp->child[x];
        }
        temp->f=1;
    }
    
    bool search(string word) {
        auto temp=root;
       return dfs(word,temp,0);
    }
    bool dfs(string &s,TrieNode* node,int in){
        if(!node)
            return 0;
        if(in>=s.length())
            return node ? node->f : 0;
        if(s[in]=='.'){
            bool ans=0;
            for(auto &it:node->child){
                ans= ans || dfs(s,it,in+1);
                if(ans)
                    return ans;
        }
            return ans;
        }
        else{
            if(node == NULL || node->child[s[in]-'a']==NULL)
                return 0;
            else 
                return dfs(s,node->child[s[in]-'a'],in+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */