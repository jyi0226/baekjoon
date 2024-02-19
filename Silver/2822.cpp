#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos{
    int x,y;
};

bool comp(pos a,pos b){
    return a.x>b.x;
}
bool comp2(pos a,pos b){
    return a.y<b.y;
}

vector<pos> v;
int num,sum=0;
int main()
{
    for(int i=1;i<9;i++){
        cin>>num;
        pos val;
        val.x=num;val.y=i;
        v.push_back(val);
    }
    sort(v.begin(),v.end(),comp);
    sort(v.begin(),v.begin()+5,comp2);
    for(int i=0;i<5;i++)sum+=v[i].x;
    cout<<sum<<"\n";
    for(int i=0;i<5;i++)cout<<v[i].y<<" ";
}
