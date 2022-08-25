class Solution {
public:
    vector<string> invalidTransactions(vector<string>& tr) {
        vector<vector<string>>vec(tr.size());
       for(int i=0;i<tr.size();i++){
           string name="";
            string time="";
            string amt="";
            string city="";
            string str="";
            int c=1;
           string x=tr[i];
            for(int j=0;j<tr[i].size();j++){
                if(x[j]==','){
                    if(c==1){
                       name=str;
                        str="";
                    }
                    if(c==2){
                       time=str;
                        str="";
                    }
                    if(c==3){
                       amt=str;
                        str="";
                    }
                  
                    c++;
                }
                else{
                    str.push_back(x[j]);
                }
       }
           city=str;
           // cout<<name<<" "<<time<<" "<<amt<<" "<<city<<"\n";
           vec[i].push_back(name);
           vec[i].push_back(time);
           vec[i].push_back(amt);
           vec[i].push_back(city);
               
           
    }
        vector<string>ans;
        unordered_set<int>an;
        for(int i=0;i<tr.size();i++){
            string name=vec[i][0],time=vec[i][1],amt=vec[i][2],city=vec[i][3];
            // cout<<name<<" "<<time<<" "<<amt<<" "<<city<<"\n";
            int amount=stoi(amt);
            int t=stoi(time);
            if(amount>1000){
                // cout<<i<<" ";
                an.insert(i);
                
            }
            for(int j=0;j<tr.size();j++){
                if(i==j)continue;

                string name1=vec[j][0],time1=vec[j][1],amt1=vec[j][2],city1=vec[j][3];
                int t1=stoi(time1);
                if(name1==name&&(abs(t1-t)<=60)&&city!=city1){
                    // cout<<i<<" ";
                    an.insert(j);
                    
                }
            }
        }
        for(auto x:an){
            ans.push_back(tr[x]);
        }
        return ans;
    }
};