#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,num;
vector<int> v;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    cout<<v[0]*v[n-1];
}
