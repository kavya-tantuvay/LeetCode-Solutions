class StockSpanner {
public:
    vector<int>nums;
    StockSpanner() {
        
    }
    
    int next(int price) {
        nums.push_back(price);
        int cnt=1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=price)cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */