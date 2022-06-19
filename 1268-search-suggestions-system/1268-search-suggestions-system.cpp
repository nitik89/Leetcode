class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string myword="";
        sort(products.begin(),products.end());
     
        vector<vector<string>>ans;
        for(int i=0;i<searchWord.size();i++){
            myword+=searchWord[i];
           
            int k=0;
            vector<string>an;
            for(int j=0;j<products.size();j++){
                string temp=products[j].substr(0,myword.size());
               
                if(k==3){
                    break;
                }
                
                if(temp==myword){
                    an.push_back(products[j]);
                k++;
                }
            }
            ans.push_back(an);
        }
        return ans;
    }
};