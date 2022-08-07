class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string  s = to_string(n);
        sort(s.begin() , s.end());
        do{
            int x = stoi(s);
            int ct = 0;
            while(x!=0){
                x = x&(x-1);
                ct++;
            }
            if(ct==1 and s[0]!='0'){
                return true;
            }
        }while(next_permutation(s.begin() , s.end()));
        return false;
    }
};