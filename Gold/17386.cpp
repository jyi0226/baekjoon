#include <iostream>

using namespace std;
long long a,b,c,d,e,f,g,h;
long long abc,abd,cda,cdb;

long long ccw(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3) {
    long long a = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if(a<0){
        return 1;
    }
    else{
        return -1;
    }
        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    abc=ccw(a,b,c,d,e,f);
    abd=ccw(a,b,c,d,g,h);
    cda=ccw(e,f,g,h,a,b);
    cdb=ccw(e,f,g,h,c,d);
    if(abc*abd<=0&&cda*cdb<=0)cout<<1;
    else cout<<0;

}
