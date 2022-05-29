class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>vec;
        for(int i=0;i<words.size();i++){
            int mask=0;
            for(int j=0;j<words[i].size();j++){
                mask=mask|(1<<(words[i][j] - 'a'));
            }
            vec.push_back(mask);
        }
        int ans=0;
        for(int i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){
                if((vec[i]&vec[j])==0){
                   ans=max(ans,(int) (words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};