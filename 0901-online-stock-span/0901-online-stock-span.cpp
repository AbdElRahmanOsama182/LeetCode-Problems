class StockSpanner {
public:
    stack<pair<int, int>> monostack;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while (!monostack.empty() && monostack.top().first <= price){
            ans += monostack.top().second;
            monostack.pop();
        }
        monostack.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */