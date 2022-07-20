class TrieNode{
    public:
  TrieNode *child[26];
    bool f;
    // initialising the objects.
    TrieNode(bool ans=0){
        memset(child,0,sizeof(child));
        f=ans;
    }
};




class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
             int xx=word[i]-'a';
            if(temp->child[xx]==NULL){
                TrieNode* temp1=new TrieNode;
                temp->child[xx]=temp1;
            }
          
            temp=temp->child[xx];
        }
        temp->f=1;
    }
    
    bool search(string word) {
        auto temp=root;
        for(auto &c:word){
            if(temp->child[c-'a']==NULL)
                return false;
            temp=temp->child[c-'a'];
        }
        if(temp->f)
            return 1;
        else
            return 0;
    }
    
    bool startsWith(string word) {
         auto temp=root;
        for(auto &c:word){
            if(temp->child[c-'a']==NULL)
                return false;
            temp=temp->child[c-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */