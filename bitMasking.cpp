#include <bits/stdc++.h>
using namespace std;
int getBit(int &n , int i){
	int mask=(1<<i);
	int bit=(n&mask)>0?1:0;
	return bit;
}
int setBit(int &n , int i){
	int mask=(1<<i);
	int bit=(n|mask);
    return bit;
}
int clearBit(int &n , int i){
	int mask=~(1<<i);
	int bit=(n&mask);
    return bit;
}
int updateBit(int &n ,int i , int v){
	int mask=~(1<<i);
	int clearbit=(n&mask);
	int updatebit=(clearbit|(v<<i));
	return updatebit;
}
int clearLastIthBits(int n , int i){
	int mask=(-1 << i);
	return (n&mask);
}
int clearBitsFromItoJ(int n , int i , int j){
	int a=(-1<<(j+1));
	int b=(1<<i)-1;
	int mask=a|b;
	return (n&mask);
}
/*
You are given two 32-bit numbers, N and M , and two bits position , i and j.
Write a method to set all bits between i and j in N equal
to M (e.g. M becomes a substring of N located at i and starting at j).
Example:
Input: N=10000000000
M=10101 , i=2 , j=6
output=10001010100
*/
int replaceBits(int n , int m , int i , int j){
	int clear=clearBitsFromItoJ(n , i , j);
	m=m<<i;
	int replacebits=(clear|m);
	return replacebits;
}
//Convert Decimal to Binary using bitwise operator
int decimalToBinary(int n){
	
	int ans=0;
	int p=1;
	while(n>0){
		int last_bit=n&1;
		ans+=p*last_bit;
		p*=10;
		n>>=1;
	}
	return ans;

}
/* UNIQUE NO II
Sample Input
4
3 1 2 1
output 
2 3
*/

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
int main() {
    int n , i;
    cin >> n >> i;
    // cout << getBit(n , i) << endl;
    // cout << setBit(n, i) << endl;
    // cout << clearBit(n , i) << endl;
    // cout << updateBit(n , i , 1) << endl;
    // cout << clearLastIthBits(n , i);
    // cout << clearBitsFromItoJ(n ,1 , 3 );
    // cout << replaceBits(15 , 2, 1 ,3) << endl;
    // cout <<decimalToBinary(n);
    unique2(); 
	return 0;
}