class Solution {
public:
    bool strongPasswordCheckerII(string pass) {
        if(pass.size()<8){
            return false;
        }
        vector<int>check(4,0);
        string str="!@#$%^&*()-+";
        
        for(int j=0;j<pass.size();j++){
            if(j>0&&(pass[j]==pass[j-1])){
                    return false;
                }
            for(int i=0;i<str.size();i++){
                if(pass[j]==str[i]){
                    check[0]++;
                    break;
                }
            }
            if(pass[j]>='0'&&pass[j]<='9'){
                
                check[1]++;
                
            }
            if(pass[j]>='a'&&pass[j]<='z'){
                
                if(j>0&&(pass[j]==pass[j-1])){
                    return false;
                }
                check[2]++;
            }
            if(pass[j]>='A'&&pass[j]<='Z'){
                if(j>0&&(pass[j]==pass[j-1])){
                    return false;
                }
                check[3]++;
            }
        }
        for(auto x:check){
            if(x==0){
                return false;
            }
            
        }
        return true;
    }
};