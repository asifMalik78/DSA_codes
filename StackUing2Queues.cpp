#include <iostream>
#include <queue>
using namespace std;
    class Stack{
        queue<int>q1;
        queue<int>q2;
        public :
        void push(int data){
            q1.push(data);
        }
        void pop(){
            if(q1.empty()){
                return;
            }
            while(q1.size() >1){
                int elmt=q1.front();
                q2.push(elmt);
                q1.pop();
            }
            q1.pop();
            swap(q1, q2);
        }
        int top(){
            while(q1.size() > 1){
                int elmt=q1.front();
                q2.push(elmt);
                q1.pop();
            }
            int element=q1.front();
            q1.pop();
            q2.push(element);
            swap(q1 , q2);
            return element;
        }
        int size(){
            return q1.size()+q2.size();
        }
        bool empty(){
            return size()==0;
        }
    };



int main() {

Stack st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
while(!st.empty()){
    cout << st.top() << endl;
    st.pop();
}

    
}

