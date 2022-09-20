typedef pair<int,string> p;
class SORTracker {
public:
     
    struct max_heap{
        bool operator()(p &a,p &b){
             if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        }
    };
    struct min_heap{
        bool operator()(p &a,p &b){
            if (a.first != b.first) {
                return a.first > b.first;
            } else {
                return a.second < b.second;
            }
        }
    };
    priority_queue<p,vector<p>,max_heap>mxh;
    priority_queue<p,vector<p>,min_heap>mnp;
    
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        if((!mnp.empty()&&(mnp.top().first<score||(mnp.top().first==score&&mnp.top().second>name)))){
            p pr=mnp.top();
            mnp.pop();
            mxh.push(pr);
            mnp.push(make_pair(score,name));
           
        }
        else {
            mxh.push(make_pair(score,name)); 
        }
    }
    
    string get() {
        // cout<<mxh.size()<<" ";
        p pr=mxh.top();
        // cout<<pr.first<<" ";
        mxh.pop();
        mnp.push(pr);
        return pr.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */