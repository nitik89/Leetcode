class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        // vector<string>temp(n,"");
        vector<string>vec(n,"");
        int ans=strs[0].size();
        for(int j=0;j<strs[0].size();j++){
          
        for(int i=0;i<strs.size();i++){
            char str=strs[i][j];
            // cout<<str<<" ";
            vec[i].push_back(str);
            // temp[i].push_back(str);
        }
            // sort(temp.begin(),temp.end());
            int b=0;
            for(int i=1;i<n;i++){
                // cout<<temp[i]<<" "<<vec[i]<<"\n";
                if(vec[i]<vec[i-1]){
                    
                    b=1;
                    break;
                }
            }
            if(b){
                for(int i=0;i<n;i++){
                    // temp[i].pop_back();
                    vec[i].pop_back();
                }
            }
           
            
        }
        return strs[0].size()-vec[0].size();
    }
};