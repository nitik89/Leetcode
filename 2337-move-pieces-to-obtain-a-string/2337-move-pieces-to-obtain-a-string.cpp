class Solution {
public:
    bool canChange(string start, string target) {
        int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
        for(auto i : start) { 
            if(i == 'L') l1++;
            else if(i == 'R') r1++;
        }
        for(auto i : target) { 
            if(i == 'L') l2++;
            else if(i == 'R') r2++;
        }
        if(l1 == l2  && r1 == r2){ 
            vector<int> ym1;
            vector<int> ym2;
            for(int i = 0;i<start.size();i++){ 
                if(start[i] != '_') ym1.push_back(i);
            }
            for(int i = 0;i<start.size();i++){ 
                if(target[i] != '_') ym2.push_back(i);
            }
            bool f = 1;
            for(int i = 0;i<ym1.size();i++){ 
                if(start[ym1[i]] != target[ym2[i]]){ f = 0;}
                else { 
                    if(start[ym1[i]] == 'L'){ 
                        if(ym1[i] < ym2[i]) f = 0;
                        
                    }else { 
                        if(ym1[i] > ym2[i]) f = 0;
                        
                    }
                }

            }
            if(f) return true;
            return false;
        }
        return false;
    }
};