class SmallestInfiniteSet {
public:
    int min;
    set<int> s;
    SmallestInfiniteSet() {
        min = 1;
    }
    
    int popSmallest() {
        if (s.empty()){
            return min++;
        }
        else{
            int temp = *s.begin();
            s.erase(s.begin());
            return temp;
        }
        
    }
    
    void addBack(int num) {
        if (num < min)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */