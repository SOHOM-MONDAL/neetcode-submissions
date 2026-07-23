class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto c : tokens){
            if(c == "+"|| c== "-" || c == "*" || c == "/" ){
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
                st.pop();
                int rem ;
                if(c == "+"){
                    rem = a + b;
                }
                else if(c == "-"){
                    rem = a- b;

                }
                else if(c == "*"){
                    rem = a* b;
                }
                else{
                    rem = a/b;
                }
                st.push(to_string(rem));
            }
            else{
                st.push(c);
            }
        }
        return stoi(st.top());
    }
};
