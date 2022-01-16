#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int space=(2*n-1)/2;
	for(int i=0;i<n;i++){
		for(int j=0;j<space;j++){
			cout << " ";
		}
		space--;
		for(int j=0;j<2*i+1;j++){
			cout << "* ";
		       }   
		cout << endl;
	}
	cout << endl;


	return 0;
}