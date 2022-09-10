class RLEIterator {
public:
    unordered_map<int,int>mp;
    vector<int>vec;
    int i;
    RLEIterator(vector<int>& e) {
        int k=0;
        for(int i=0;i<e.size();i+=2){
            
            if(e[i]!=0){
                mp[k]=e[i];
            vec.push_back(e[i+1]);
                k++;
            }
            
        }
        i=0;
    }
    
    int next(int n) {
        int last=-1;
       
        // cout<<i<<" ";
        while(i<vec.size()&&n>0){
            // cout<<i<<" ";
            // cout<<i<<" "<<mp[i]<<"\n";
            if(mp[i]==0){
                i++;
            }
            if(i>=vec.size()){
                break;
            }
            if(mp[i]>=n){
                last=vec[i];
                mp[i]-=n;
                n=0;
            }
            else if(mp[i]<n){
                if(mp[i]>0){
                    last=vec[i];
                    n-=mp[i];
                    mp[i]=0;
                    i++;
                    
                }
                else{
                    last=-1;
                }
                
            }
            
            
        }
        if(n>0)return -1;
        return last;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */