#include <iostream>

using namespace std;
long long a,b,c,d,e,f,g,h;
long long abc,abd,cda,cdb;

int ccw(pair<long long,long long>p1,pair<long long,long long>p2,pair<long long,long long>p3) {
    long long num = p1.first*p2.second+p2.first*p3.second+p3.first*p1.second-p2.first*p1.second-p3.first*p2.second-p1.first*p3.second;
    if(num<0){
        return -1;
    }
    else if(num>0){
        return 1;
    }
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pair<long long,long long>a,b,c,d;
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second>>d.first>>d.second;
    abc=ccw(a,b,c);
    abd=ccw(a,b,d);
    cda=ccw(c,d,a);
    cdb=ccw(c,d,b);
    if(abc*abd==0&&cda*cdb==0){
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        
        if(a<=d&&c<=b)cout<<1;
        else cout<<0;
    }
    else if(abc*abd<=0&&cda*cdb<=0)cout<<1;
    else cout<<0;

}
