#include <bits/stdc++.h>
using namespace std;
void appendAtEnd(char *arr){
	if(arr[0]=='\0'){
		return;
	}

	if(arr[0]=='x'){
		int i=0;
		for(int i=1 ; arr[i]!='\0' ; i++){
			arr[i-1]=arr[i];
		}
		arr[i]='x';
		appendAtEnd(arr);
	}
	appendAtEnd(arr+1);
	return;
}
int main() {
    char arr[1000];
    cin >> arr;
    appendAtEnd(arr);
    cout << arr << endl;
	return 0;
}