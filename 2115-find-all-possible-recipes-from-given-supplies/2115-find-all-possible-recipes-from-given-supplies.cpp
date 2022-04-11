class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>mp;
        unordered_map<string,int>indeg;
        unordered_set<string>check;
        for(auto x:recipes){
            check.insert(x);
        }
        for(int i=0;i<ingredients.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                mp[ingredients[i][j]].push_back(recipes[i]);
                indeg[recipes[i]]++;
            }
        }
        queue<string>q;
        for(auto x:supplies){
            q.push(x);
        }
        vector<string>ans;
        while(!q.empty()){
            string tp=q.front();
            q.pop();
            if(check.find(tp)!=check.end()){
                ans.push_back(tp);
            }
            for(auto x:mp[tp]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }
        return ans;
        
    }
};