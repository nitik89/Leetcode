class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        char prev='-';
        while(i<name.size()&&j<typed.size()){
            if(name[i]==typed[j]){
                 prev=name[i];
                i++;
                j++;
               
            }
            else if(name[i]!=typed[j]){
                if(prev==typed[j]){
                    j++;
                }
                else{
                    return false;
                }
                
                
            }
            
        }
        while(j<typed.size()&&typed[j]==prev){
            j++;
        }
        if(i==name.size()&&j==typed.size()){
            return true;
        }
        return false;
    }
};