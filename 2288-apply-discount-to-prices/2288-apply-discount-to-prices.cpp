class Solution {
public:
    string discountPrices(string sen, int dis) {
        string ans="";
        for(int i=0;i<sen.size();i++){
            if(sen[i]=='$'&&(i==0||sen[i-1]==' ')){
                // cout<<i<<" ";
                i++;
                string val="";
                int fl=0;
                // cout<<i<<" ";
                while(i<sen.size()&&sen[i]!=' '){
                    if(sen[i]>='0'&&sen[i]<='9'){
                        val+=sen[i];
                        i++;
                    }
                    else{
                        
                        fl=1;
                        break;
                    }
                }
               
                // cout<<i<<" ";
                if(fl==0&&val!=""){
                     // cout<<val<<" ";
                    double v=stoll(val);
                double c=v*((dis*1.0)/100);
                    string t=to_string(v);
                    string an="";
                    int k=0;
                   
                     stringstream ss;
                ss<< fixed << setprecision(2) <<(v-c);
                // string t='$'+ss.str();
                    // setprecision(2);
                    ans+='$'+ss.str()+" ";
                }
                else{
                    ans+='$'+val;
                    i--;
                }
            }
            else{
                ans+=sen[i];
            }
        }
        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
        
    }
};