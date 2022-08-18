class Bitset {
public:
    int bitset=0;
    int sz;
    int zero=0,onee=0;
   string temp,temp1;
    bool flipp;
    Bitset(int size) {
        
        sz=size;
        for(int i=0;i<size;i++){
            temp.push_back('0');
            temp1.push_back('1');
            
        }
        flipp=false;
        zero=size;
    }
    
    void fix(int idx) {
        if(temp[idx]=='0'&&!flipp){
            zero--;
            temp[idx]='1';
            temp1[idx]='0';
        onee++;
        }
        else if(temp1[idx]=='0'&&flipp){
            zero--;
            temp[idx]='0';
            temp1[idx]='1';
            onee++;
        }
        
    }
    
    void unfix(int idx) {
        if(temp[idx]=='1'&&!flipp){
            onee--;
            temp[idx]='0';
            temp1[idx]='1';
            zero++;
        }
        else if(temp1[idx]=='1'&&flipp){
            onee--;
            temp1[idx]='0';
            temp[idx]='1';
            zero++;
        }
        
    }
    
    void flip() {
        int y=onee;
        onee=zero;
        zero=y;
        flipp=!flipp;
    }
    
    bool all() {
        
        return onee==sz;
    }
    

    bool one() {
        
        return onee>0;
    }
    
    int count() {
      
        return onee;
    }
    
    string toString() {
       return !flipp?temp:temp1; 
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */