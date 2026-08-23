class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       int n = tokens.size();
       int ans = 0;
       stack<int> st;
        for(int i=0; i<tokens.size(); i++) {
            string  ele = tokens[i];
            if(ele == "+" || ele == "-"  || ele == "*" || ele == "/" ) {
                int rt = st.top();
                st.pop();
                int lt = st.top();
                st.pop();
                int res;
                char ch = ele[0];
                switch (ch) {
                    case '+':
                        res = lt + rt;
                        break;
                    case '*':
                        res = lt * rt;
                        break;
                    case '-':
                        res = lt - rt;
                        break;
                    case '/':
                        res =  lt /rt;
                        break;

                }
                st.push(res);

            } else{
                int val = stoi(tokens[i]);
                st.push(val);
            }
        }
        return st.top();
    }
};