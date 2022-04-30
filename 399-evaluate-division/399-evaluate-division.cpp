class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>vec;
    double dfs(string start,string end,unordered_set<string>&vis){
        if(start==end){
            return 1.0;
        }
        vis.insert(start);
        for(auto x:vec[start]){
            if(vis.find(x.first)==vis.end()){
            double ans=dfs(x.first,end,vis);
            if(ans>=0){
                return ans*x.second;
            }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equ, vector<double>& values, vector<vector<string>>& que) {
        
        for(int i=0;i<equ.size();i++){
            vec[equ[i][0]].push_back({equ[i][1],values[i]});
            vec[equ[i][1]].push_back({equ[i][0],1/values[i]});
        }
        vector<double>ans;
        for(auto x:que){
            if(vec.find(x[0])==vec.end()||vec.find(x[1])==vec.end()){
                ans.push_back(-1.0);
                continue;
            }
            else{
                unordered_set<string>vis;
                double val=dfs(x[0],x[1],vis);
                ans.push_back(val);
            }
        }
        return ans;
        
    }
};