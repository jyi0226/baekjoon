#include <iostream>

using namespace std;
int n;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    if(n%2==0) cout<<"CY";
    else cout<<"SK";
}
