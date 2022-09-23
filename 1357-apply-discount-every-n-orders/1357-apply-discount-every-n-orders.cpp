class Cashier {
public:
    int nth,dis,curr;
    unordered_map<int,int>mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i=0;i<products.size();i++){
            mp[products[i]]=prices[i];
        }
        curr=0;
        nth=n;
        dis=discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill=0;
        for(int i=0;i<amount.size();i++){
            bill+=(double(mp[product[i]])*(double)(amount[i]));
        }
        curr++;
        if(curr%nth==0){
            bill=bill*((100-(double)dis)/100);
        }
        return bill;
        
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */