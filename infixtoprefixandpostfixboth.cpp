#include <iostream>
#include <stack>
using namespace std;
int prec(char ch) {
    if (ch == '^') {
        return 3;
    }
    else if (ch == '*' or ch == '/') {
        return 2;
    }
    else if (ch == '+' or ch == '-') {
        return 1;
    }
    else {
        return 0;
    }
}
void conversion(string str) {
    stack<string>postfix;
    stack<string>prefix;
    stack<char>operators;
    for (int i = 0 ; i < str.size() ; i++) {
        char ch = str[i];
        if (ch == '(') {
            operators.push(ch);
        }
        else if ((ch >= 'a' && ch <= 'z') or (ch >= 'A' && ch <= 'Z') or (ch >= '0' && ch <= '9')) {
            string s(1 , ch);
            postfix.push(s);
            prefix.push(s);
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char ops = operators.top();
                operators.pop();


                string postS2 = postfix.top();
                postfix.pop();
                string postS1 = postfix.top();
                postfix.pop();
                string post = postS1 + postS2 + ops;
                postfix.push(post);


                string preS2 = prefix.top();
                prefix.pop();
                string preS1 = prefix.top();
                prefix.pop();
                string pre = ops + preS1 + preS2;
                prefix.push(pre);
            }
            operators.pop();
        }
        else if (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^') {
            while (!operators.empty()  && prec(operators.top()) >= prec(ch)) {
                char ops = operators.top();
                operators.pop();


                string postS2 = postfix.top();
                postfix.pop();
                string postS1 = postfix.top();
                postfix.pop();
                string post = postS1 + postS2 + ops;
                postfix.push(post);


                string preS2 = prefix.top();
                prefix.pop();
                string preS1 = prefix.top();
                prefix.pop();
                string pre = ops + preS1 + preS2;
                prefix.push(pre);
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        char ops = operators.top();
        operators.pop();


        string postS2 = postfix.top();
        postfix.pop();
        string postS1 = postfix.top();
        postfix.pop();
        string post = postS1 + postS2 + ops;
        postfix.push(post);


        string preS2 = prefix.top();
        prefix.pop();
        string preS1 = prefix.top();
        prefix.pop();
        string pre = ops + preS1 + preS2;
        prefix.push(pre);
    }
    cout << postfix.top() << endl;
    cout << prefix.top() << endl;
}

void prefixToInfix(string str){ // to convert post fix to infix add op2+ch+op1
    stack<string>st;
    for(int i=str.size()-1 ; i>=0 ; i--){
        char ch=str[i];
        if(ch>='a' and ch<='z' or ch>='A' and ch<='z'){
            string s(1 , ch);
            st.push(s);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string newstr="("+op1+ch+op2+")";
            st.push(newstr);

        }
    }

    string a=st.top();
    st.pop();
    cout << a << endl;
}
int main() {
    string str;
    getline(cin , str);
    conversion(str);
    string s;
    cin >> s;
    prefixToInfix(s);
}