class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>vec( numCourses);
        vector<int>ans;
        vector<int>indeg(numCourses,0);
        for(auto x:pre){
            vec[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        queue<int>q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
        int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto y:vec[x]){
                indeg[y]--;
                if(indeg[y]==0){
                    q.push(y);
                }
            }
        }
        reverse(ans.begin(),ans.end());
      if(ans.size()==numCourses){
          return ans;
      }
        return {};
        
    }
};