class Bank {
vector<long long>b;
public:
    Bank(vector<long long>& balance) {
        pushAccounts(balance);
    }
    
    bool transfer(int account1, int account2, long long money) {
        int i=account1-1;
        int j=account2-1;
        if((i<b.size() && j<b.size())&& money<=b[i]){
            b[i]-=money;
            b[j]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        int i=account-1;
        if(i<b.size()){
            b[i]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        int i=account-1;
        if(i<b.size() && money<=b[i]){
            b[i]-=money;
            return true;
        }
        return false;
    }
private:
    void pushAccounts(vector<long long>&balance){
        for(long long i:balance){
            b.push_back(i);
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */