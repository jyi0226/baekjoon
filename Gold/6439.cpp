#include <iostream>

using namespace std;
long long abc,abd,cda,cdb;
int tc;
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
bool func(pair<long long,long long>a,pair<long long,long long>b,pair<long long,long long>c,pair<long long,long long>d){
    abc=ccw(a,b,c);
    abd=ccw(a,b,d);
    cda=ccw(c,d,a);
    cdb=ccw(c,d,b);
    if(abc*abd==0&&cda*cdb==0){
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        
        if(a<=d&&c<=b)return 1;
        else return 0;
    }
    else if(abc*abd<=0&&cda*cdb<=0)return 1;
    else return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>tc;
    while(tc--){
        pair<long long,long long>a,b,c,d,e,f;
        cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second>>d.first>>d.second;
        if(a.first>b.first){
            int val=a.first;
            a.first=b.first;
            b.first=val;
            val=a.second;
            a.second=b.second;
            b.second=val;
        }
        if(c.first>d.first){
            int val=c.first;
            c.first=d.first;
            d.first=val;
        }
        if(c.second>d.second){
            int val=c.second;
            c.second=d.second;
            d.second=val;
        }
        e.first=c.first;
        e.second=d.second;
        f.first=d.first;
        f.second=c.second;
        //cout<<c.first<<" "<<c.second<<" "<<d.first<<" "<<d.second<<" "<<e.first<<" "<<e.second<<" "<<f.first<<" "<<f.second<<"\n";
        //cout<<func(a,b,c,f)<<func(a,b,d,f)<<func(a,b,e,d)<<func(a,b,c,e);
        if(func(a,b,c,f)||func(a,b,d,f)||func(a,b,e,d)||func(a,b,c,e))cout<<"T\n";
        else{
            if((a.first>c.first&&a.first<d.first)&&(b.first>c.first&&b.first<d.first)&&(a.second>c.second&&a.second<d.second)&&(b.second>c.second&&b.second<d.second))cout<<"T\n";
            else cout<<"F\n";
        }
    }
}
