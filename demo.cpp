#include <iostream>
#include <cstring>
using namespace std;
void unique2(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int res=0;
	for(int i=0;i<n;i++){
		res=res^a[i];
	}
	cout << res << endl;
	int temp=res;
	int pos=0;
	while((temp&1)!=1){
		pos++;
		temp=temp>>1;
	}
	int mask=(1<<pos);
	int x=0 , y=0;
	for(int i=0;i<n;i++){
		if((a[i]&mask)>0){
			x=x^a[i];
		}
	}
	y=res^x;
	cout << min(x , y) << " " << max(x , y) << endl;
}
void unique3(){
	int cnt[64]={0};
	int n, no;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> no;
		int j=0;
		while(no>0){
			int lastbit=(no&1);
			cnt[j]+=lastbit;
			j++;
			no=no>>1;
		}
	}
	int ans=0;
	int p=1;
	for(int i=0;i<64;i++){
		cnt[i]%=3;
		ans+=cnt[i]*p;
		p=p<<1;
	}
	cout << ans << endl;

}
//Exponential Power Using Bit Masking
int power(int n , int m){
	int ans=1;
	int p=1;
	while(m>0){
		if((m&1)==1){
			ans=ans*n;
		}
		n*=n;
		m=m>>1;

	}
	return ans;
}
//Generate Subset Using Bit Masking
void filterCharacter(char a[] , int n){
	int j=0;
	while(n>0){
		int lastbit=n&1;
		if(lastbit==1){
			cout << a[j];
		}
		j++;
		n=n>>1;
	}
	cout << endl;
}
void subSet(char a[]){
	int n=strlen(a);
	for(int i=0;i<(1<<n);i++){
		filterCharacter(a , i);
	}
	return;
}
int main() {
    // unique3();
    // cout << power(3 , 5) << endl;
    char a[100];
    cin >> a;
    subSet(a);

}
// #include <bits/stdc++.h>
// using namespace std;
// string reverseByWord(string s){
// 	vector<string>v;
// 	string str;
// 	int n=s.size();
// 	for(int i=0;i<n;i++){
//         if(s[i]==' '){
//         	v.push_back(str);
//         	str="";
//         }
//         else{
//         	str.push_back(s[i]);
//         }
// 	}
// 	v.push_back(str);

// 	string ans;
// 	for(int i=v.size()-1;i>=0;i--){
//         ans+=v[i]+' ';
// 	}
// 	return ans;
// }
// int main() {
//     string s;
//     getline(cin , s);
//     cout << reverseByWord(s);
// 	return 0;
// }
