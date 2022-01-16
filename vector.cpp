// #include <bits/stdc++.h>
// using namespace std;
// bool compare(pair<int ,int>a , pair<int,int>b){
// 	int d1=a.first*a.first + a.second*a.second;
// 	int d2=b.first*b.first + b.second*b.second;
// 	if(d1==d2){
// 		return a.first < b.first;
// 	}
// 	return d1 < d2;
// }
// void usingPair(){
// 	vector<pair<int , int>>v;
// 	int n;
// 	cin >> n;
// 	for(int i=0;i<n;i++){
// 		int a , b;
// 		cin >> a >> b;
// 		v.push_back(make_pair(a , b));
// 	}
// 	sort(v.begin() , v.end(), compare);
// 	for(auto s : v){
// 		cout << s.first << " " << s.second << endl;
// 	}
// }
// int main() {
// 	usingPair();

// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// class Car {
// public:
// 	string carName;
// 	int x;
// 	int y;
// 	Car(){

// 	}
// 	Car(string name , int x , int y){
// 		carName=name;
// 		this->x=x;
// 		this->y=y;
// 	}
// 	int distance(){
// 		return x*x+y*y;
// 	}


// };
// bool compare(Car a , Car b){
// 	int d1=a.distance();
// 	int d2=b.distance();
// 	if(d1==d2){
// 		return a.x < b.x;
// 	}
// 	return d1 < d2;
// }

// int main() {
// 	int n;
// 	cin >> n;
// 	vector<Car>v;
// 	for(int i=0;i<n;i++){
// 		string name;
// 		int x , y;
// 		cin >> name >> x >> y;
// 		Car temp(name , x , y);
// 		v.push_back(temp);

// 	}
// 	sort(v.begin() , v. end() , compare);
// 	for(auto i : v){
// 		cout << i.carName << " " << i.x  << " " << i.y << endl;
// 	}



// 	return 0;
// }