#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t,d,n,s,p;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>d>>n>>s>>p;
		int a=d+n*p;
		int b=n*s;
		if(a<b)cout<<"parallelize\n";
		else if(a>b)cout<<"do not parallelize\n";
		else cout<<"does not matter\n";
	}
}
