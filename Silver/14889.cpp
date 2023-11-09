#include <iostream>

using namespace std;
int n,S[22][22],res_min=10101010,res;
bool visit[22];
int one[11],two[11];
void func(int cur,int cnt){
    if(cnt==n/2){
        int cnt_one=0,cnt_two=0;
        for(int i=0;i<n;i++){
            if(visit[i])one[cnt_one++]=i;
            if(!visit[i])two[cnt_two++]=i;
        }
        int res_one=0,res_two=0;
        for(int i=0;i<n/2-1;i++){
            for(int j=i+1;j<n/2;j++){
                res_one+=S[one[i]][one[j]]+S[one[j]][one[i]];
                res_two+=S[two[i]][two[j]]+S[two[j]][two[i]];
            }
        }
        res=(res_one>res_two)?(res_one-res_two):(res_two-res_one);
        if(res_min>res)res_min=res;
        return;
    }
    for(int i=cur;i<n;i++){
        if(!visit[i]){
            visit[i]=1;
            func(i,cnt+1);
            visit[i]=0;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>S[i][j];
    }
    
    func(0,0);
    cout<<res_min;
}
