#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
long long p,num;
vector<long long> sec[505];
int item[505];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>p;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>num;
            if(num==-1){
                item[i]++;
                sec[i].push_back(0);
            }
            else{
                sec[i].push_back(num);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        sort(sec[i].begin(),sec[i].end());
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(p<sec[i][j]){
                while(item[i]!=0){
                    item[i]--;
                    p*=2;
                    if(p>=sec[i][j])break;
                }
                if(p<sec[i][j]){
                    cout<<0;
                    return 0;
                }
            }
            p+=sec[i][j];
        }
        while(item[i]!=0){
            p*=2;
            item[i]--;
        }
    }
    cout<<1;
}
