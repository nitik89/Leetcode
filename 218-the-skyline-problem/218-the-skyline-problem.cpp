class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& build) {
        vector<pair<int,int>>temp;
        for(auto x:build){
            temp.push_back({x[0],x[2]}); //for adding the element
            temp.push_back({x[1],-x[2]}); //for removal of that element
        }
        //this is the label graph
        sort(temp.begin(),temp.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        });
        multiset<int>pq; //it helps in removal of any number
        pq.insert(0);
        vector<vector<int>>ans;
        int curr=0;
        for(auto x:temp){
            // cout<<x.first<<" "<<x.second<<"\n";
            if(x.second<0){
                pq.erase(pq.find(-x.second));
            }
            else {
                pq.insert(x.second);
            }
            if(*pq.rbegin()!=curr){
                curr=*pq.rbegin();
                ans.push_back({x.first,curr});
            }
        }
        return ans;
    }
};