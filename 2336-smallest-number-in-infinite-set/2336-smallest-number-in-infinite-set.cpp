class SmallestInfiniteSet {
public:
    set<int> pq;
    SmallestInfiniteSet() {
        
        for(int i=1;i<=1000;i++)
            pq.insert(i);
    }
    
    int popSmallest() {
        int x=*pq.begin();
        pq.erase(x);
        return x;
    }
    
    void addBack(int num) {
        if(pq.find(num)==pq.end())
        pq.insert(num);
    }
    // == matlab nhi hai fix karle dimag me bsdk
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */