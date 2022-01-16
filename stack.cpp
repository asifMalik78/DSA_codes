#include <iostream>
#include <vector>
#include <stack>
using namespace std;
template<typename T>
class Stack {
private :
  vector<T>v;
public :
  void Push(T data) {
    v.push_back(data);
  }
  void Pop() {
    if (!empty())
      v.pop_back();
  }
  bool empty() {
    return v.size() == 0;
  }
  T top() {
    return v[v.size() - 1];
  }
};


void transfer(stack<int>&s1 , stack<int>&s2 , int n) {
  for (int i = 0 ; i < n ; i++) {
    s2.push(s1.top());
    s1.pop();
  }
}
void reverseStack(stack<int>&s1) {
  stack<int>s2;
  int n = s1.size();
  for (int i = 0 ; i < n ; i++) {
    int x = s1.top();
    s1.pop();
    transfer(s1 , s2 , n - 1 - i);
    s1.push(x);
    transfer(s2 , s1 , n - 1 - i);
  }
}

void insertAtBottom(stack<int>&s , int x) {
  if (s.empty()) {
    s.push(x);
    return;
  }
  int d = s.top();
  s.pop();
  insertAtBottom(s , x);
  s.push(d);
}

void reverseStackRecursion(stack<int>&st) {
  if (st.empty()) {
    return ;
  }
  int x = st.top();
  st.pop();
  reverseStackRecursion(st);
  insertAtBottom(st , x);

}

bool balanced(string ch) {
  stack<char>st;
  bool ans = true;
  for (int i = 0 ; i < ch.size() ; i++) {
    if (ch[i] == '(' or ch[i] == '{' or ch[i] == '[') {
      st.push(ch[i]);
    }
    else if (ch[i] == ')') {
      if (st.empty() or st.top() != '(') {
        return false;
      }
      st.pop();
    } else if (ch[i] == '}') {
      if (st.empty() or st.top() != '{') {
        return false;
      }
      st.pop();
    }
    else if (ch[i] == ']') {
      if (st.empty() or st.top() != '[') {
        return false;
      }
      st.pop();
    }

  }
  return st.empty();
}
// ------> S.T.O.C.K -- S.P.A.N
//   100 , 80 , 60 , 70 , 60 , 75 , 85

void bruteForce(int *arr , int n , int *temp) {
  temp[0] = 1;
  int k = 1;
  int idx = 0;
  for (int i = 1 ; i < 7 ; i++) {
    for (int j = i ; j >= 0 ; j--) {
      if (arr[i] < arr[j]) {
        idx = j;
        break;
      }
    }
    temp[k++] = i - idx;
  }
}

void stockSpanOptimized(int *price , int n , int *temp) {
  stack<int>st;
  temp[0] = 1;
  st.push(0);
  for (int i = 1 ; i < n ; i++) {
    int currentPrice = price[i];
    while (!st.empty() && price[st.top()] <= currentPrice) {
      st.pop();
    }
    if (!st.empty()) {
      int prevPrice = st.top();
      temp[i] = i - prevPrice;
    }
    else {
      temp[i] = i + 1;
    }
    st.push(i);
  }
}


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
    return -1;
  }
}
void infixToPostfix() {
  string str;
  cin >> str;
  stack<char>st;
  string temp = "";
  for (int i = 0 ; i < str.size() ; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      temp.push_back(str[i]);
    }
    else if (str[i] == '(') {
      st.push(str[i]);
    }
    else if (str[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        temp.push_back(st.top());
        st.pop();
      }
      if (!st.empty()) {
        st.pop();
      }
    }
    else {
      while (!st.empty() && prec(st.top()) >= prec(str[i])) {
        temp.push_back(st.top());
        st.pop();
      }
      st.push(str[i]);
    }
  }
  if (!st.empty()) {
    temp.push_back(st.top());
    st.pop();
  }
  cout << temp << endl;
}

void infixToPrefix() {
  string str;
  cin >> str;
  reverse(str.begin() , str.end());
  for (int i = 0 ; i < str.size() ; i++) {
    if (str[i] == ')') {
      str[i] = '(';
    }
    else if (str[i] == '(') {
      str[i] = ')';
    }
  }
  stack<char>st;
  string temp = "";
  for (int i = 0 ; i < str.size() ; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      temp.push_back(str[i]);
    }
    else if (str[i] == '(') {
      st.push(str[i]);
    }
    else if (str[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        temp.push_back(st.top());
        st.pop();
      }
      if (!st.empty()) {
        st.pop();
      }
    }
    else {
      while (!st.empty() && prec(st.top()) >= prec(str[i])) {
        temp.push_back(st.top());
        st.pop();
      }
      st.push(str[i]);
    }
  }
  if (!st.empty()) {
    temp.push_back(st.top());
    st.pop();
  }
  cout << temp << endl;
}
int main() {
  stack<int>s1;
  for (int i = 1 ; i <= 5 ; i++) {
    s1.push(i);
  }
// reverseStackRecursion(s1);
  while (!s1.empty()) {
    cout << s1.top() << endl;
    s1.pop();
  }
  // string ch;
  // cin >> ch;
  // if (balanced(ch)) {
  //   cout << "Yes" << endl;
  // }
  // else {
  //   cout << "No" << endl;
  // }

}
