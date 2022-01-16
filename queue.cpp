#include <bits/stdc++.h>
using namespace std;
class Queue{
	int *arr;
	int ms;
	int cs;
	int f;
	int r;
	public :
	Queue(int ds=5){
		arr=new int[ds];
		ms=ds;
		f=0;
		r=ms-1;
		cs=0;
	}
	bool full(){
		return cs==ms;
	}
	void push(int d){
		if(!full()){
			r=(r+1)%ms;
			arr[r]=d;
			cs++;
		}
	}
	bool empty(){
		return cs==0;
	}
	void pop(){
		if(!empty()){
			f=(f+1)%ms;
			cs--;
		}
	}
	int front(){
		return arr[f];
	}
	int rear(){
		return arr[r];
	}
	~Queue(){
		if(arr!=NULL){
			delete [] arr;
			arr=NULL;
		}
	}

};


void firstNonRepeatingCharacter(){
    queue<char>q;
    int freq[27]={0};
    char ch;
    cin >> ch;
    while(ch!='.'){
        q.push(ch);
        freq[ch-'a']++;
        while(!q.empty()){
            int idx=q.front()-'a';
            if(freq[idx] > 1){
                q.pop();
            }
            else{
                cout << q.front() << endl;
                break;
            }
        }

        if(q.empty()){
            cout << "-1" << endl;
        }

        cin >> ch;
    }
}
int main() {
	// Queue q;
	// for(int i=1 ; i<=6 ; i++){
	// 	q.push(i);
	// }
	// q.pop();
	// q.pop();
	// q.push(7);
	// while(!q.empty()){
	// 	cout << q.front() << " ";
	// 	q.pop();
	// }

	firstNonRepeatingCharacter();

	return 0;
}