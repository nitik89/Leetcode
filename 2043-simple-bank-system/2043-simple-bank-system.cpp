class Bank {
public:
    vector<long long>vec;
    Bank(vector<long long>& balance) {
        int n=balance.size();
        vec.resize(n,0);
        vec=balance;
    }
    
    bool transfer(int ac1, int ac2, long long money) {
        if(ac1>vec.size()||ac2>vec.size())return false;
        long long v=vec[ac1-1]-money;
        if(v<0){
            return false;
        }
        vec[ac1-1]-=money;
        vec[ac2-1]+=money;
        return true;
        
    }
    
    bool deposit(int ac, long long money) {
        if(ac>vec.size())return false;
        vec[ac-1]+=money;
        return true;
    }
    
    bool withdraw(int ac, long long money) {
        if(ac>vec.size())return false;
        if(vec[ac-1]<money){
            return false;
        }
        vec[ac-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */