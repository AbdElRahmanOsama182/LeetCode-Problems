class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (s.find(val) != s.end()) return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end()) return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        return *next(s.begin(), rand() % s.size()); 
    }
};