#include <bits/stdc++.h>
using namespace std;

typedef struct{
    long long gun;
    long long bok;
}Menu;

bool comp(Menu a, Menu b)
{
    if(a.gun==b.gun)return a.bok>b.bok;
    else return a.gun>b.gun;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    long long d,n,m,k;
    cin>>d>>n>>m>>k;
    Menu mu[4];
    
    long long n_rest=n%d;
    long long m_rest=m%d;

    mu[0].gun=n/d+m/d+k/d;
    mu[0].bok=k;
    mu[1].gun=(n+k)/d+m/d;
    mu[1].bok=k-(d-n_rest);
    mu[2].gun=n/d+(m+k)/d;
    mu[2].bok=k-(d-m_rest);
    mu[3].gun=n/d+m/d;
    mu[3].bok=0;
    if(d-n_rest+d-m_rest<=k)
    {
        k-=(d-n_rest+d-m_rest);
        mu[3].gun+=2;
        mu[3].gun+=k/d;
        mu[3].bok=k;
    }
    sort(mu,mu+4,comp);
    cout<<mu[0].bok;
}