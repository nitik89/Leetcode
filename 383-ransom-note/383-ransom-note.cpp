class Solution {
public:
    bool canConstruct(string ran, string mag) {
       vector<int>vec(26,0);
        for(int i=0;i<mag.size();i++){
        vec[mag[i] - 'a']++;
        }
        for(int i=0;i<ran.size();i++){
            if(vec[ran[i] - 'a']>0){
                vec[ran[i] - 'a']--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};