class Solution {
public:
    int generate(int n){
        int sum =0;
        while(n !=0){
            int d = n%10;
            n = n/10;
            sum += (d*d);
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> st;
        while(1) {
            int s = generate(n);
            if(s == 1)
                return true;
            if(st.find(s) != st.end()){
                return false;
            } else{
                st.insert(s);
            }
            n = s;
        }
        return false;
    }
};