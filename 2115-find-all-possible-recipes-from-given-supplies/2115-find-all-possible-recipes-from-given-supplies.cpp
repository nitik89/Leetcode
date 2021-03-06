class Solution {
public:
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //vector to store our final ans
        vector<string> res;
        
		//map to store indegree of our recipes , initially indegree of all = 0
        unordered_map<string,int> in;
        for(auto &rec : recipes) in[rec] = 0;
        
		//our directed graph
        unordered_map<string,vector<string>> g;
        
		//set to store supplies
        unordered_set<string> st;
        for(auto &sup : supplies) st.insert(sup);
        
		//iterate over recipes and check which recipes can be made with initial supplies available
        for(int i=0;i<size(recipes);i++)
        {
            for(int j=0;j<size(ingredients[i]);j++)
            {
			//in case a recipe cann't be made
                if(st.find(ingredients[i][j]) == st.end())
                {
					//increase its indegree by 1 and make a directed edge between that ingredient and recipe
                    in[recipes[i]]++;
                    g[ingredients[i][j]].push_back(recipes[i]);
                }
            }
        }
        
		//from here we just did our standard topo sort, which'll give us our required ans
        queue<string> q;
        for(auto &[key,value] : in)
        {
            if(value == 0)
                q.push(key);
        }
        
        while(!q.empty())
        {
            int c = size(q);
            for(int i=0;i<c;i++)
            {
                auto rec = q.front(); q.pop();
                res.push_back(rec);
                for(auto &child : g[rec])
                {
                    in[child]--;
                    if(in[child] == 0) q.push(child);
                }
            }
        }
        
        return res;
    }

};