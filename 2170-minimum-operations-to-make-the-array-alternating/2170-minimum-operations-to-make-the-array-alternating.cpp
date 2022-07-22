class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>even;
        unordered_map<int,int>odd;
        for(int i=0;i<n;i++){
            if(i%2==0){
                even[nums[i]]++;
            }
            else{
                odd[nums[i]]++;
            }
        }
        int mxe=-1,ve=-1;
        int mxo=-1,vo=-1;
        for(auto x:even){
            if(mxe<x.second){
                mxe=x.second;
                ve=x.first;
            }
        }
        for(auto x:odd){
            if(mxo<x.second){
                mxo=x.second;
                vo=x.first;
            }
        }
        if(vo==ve&&(mxe+mxo==n)){
            return n/2;
        }
        priority_queue<pair<int,int>>ev;
        priority_queue<pair<int,int>>od;
        for(auto x:even){
            ev.push({x.second,x.first});
        }
        for(auto x:odd){
            od.push({x.second,x.first});
        }
        while(!ev.empty()&&!od.empty()){
            int v1=ev.top().second;
            int v2=od.top().second;
             int c1=ev.top().first;
            int c2=od.top().first;
            // cout<<v1<<" "<<v2<<" "<<c1<<" "<<c2<<"\n";
            if(v1!=v2){
                // cout<<v1<<" "<<v2<<"\n";
                return n-c1-c2;
            }
           
            else{
                auto x=od.top();
                auto y=ev.top();
                od.pop();
                ev.pop();
                if(od.size()==0){
                    od.push(x);
                }
                else if(ev.size()==0){
                    ev.push(y);
                }
                else{
                    auto l=od.top();
                    auto k=ev.top();
                    if(x.first+k.first>l.first+y.first){
                        od.push(x);
                    }
                    else{
                        ev.push(y);
                    }
                }
            }
            
        }
        return 0;
        
        
        
        
    }
};