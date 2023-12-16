#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int a,b,c;
vector<int> num;
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++)num.push_back(i);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        reverse(num.begin()+a,num.begin()+b+1);
        
    }
    for(int i=1;i<=n;i++)cout<<num[i]<<" ";
}
