#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,k;
int arr[202020];
int num[202020];
int idx[202020];
int cnt[202020];
bool state[202020];
vector<int> v[202020];
vector<string> s[2];
string str;

bool func(int a,int b){
    if((s[0][a].back()=='#'&&s[1][b].front()=='#')||(s[1][a].back()=='#'&&s[0][b].front()=='#'))return 1;
    return 0;
}
void print(){
    cout<<"\n";
    for(int i=0;i<k;i++)cout<<arr[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++)cout<<s[j][i]<<"\n";
        cout<<cnt[i]<<" "<<state[i]<<"\n";
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>arr[i];
        arr[i]--;
    }
    for(int i=0;i<n;i++){
        cin>>str;
        s[0].push_back(str);
        cin>>str;
        s[1].push_back(str);
    }
    
    for(int i=0;i<n;i++){
        int size=s[0][i].size();
        bool val=0;
        for(int j=0;j<size;j++){
            if(s[0][i][j]=='#'&&s[1][i][j]=='#'){
                val=1;
                state[i]=1;
                break;
            }
        }
        if(val)continue;
        
        for(int j=0;j<size-1;j++){
            if((s[0][i][j]=='#'&&s[1][i][j+1]=='#')||(s[0][i][j+1]=='#'&&s[1][i][j]=='#')){
                val=1;
                state[i]=1;
                break;
            }
        }
        if(val)continue;
        
        state[i]=0;
        for(int j=0;j<size;j++){
            if(s[0][i][j]=='#')v[i].push_back(0);
            if(s[1][i][j]=='#')v[i].push_back(1);
        }
        int cur=0;
        if(v[i].size()<=1){
            cnt[i]=size-1;
        }
        else{
            for(int j=0;j<v[i].size()-1;j++){
                if(v[i][j]!=v[i][j+1])cur++;
            }
            cnt[i]=size-1+cur;
        }
    }
    //print();
    long long res=0;
    
    if(k==1){
        if(state[arr[0]])cout<<-1;
        else cout<<cnt[arr[0]];
    }
    else if(k==2){
        if(state[arr[0]]||state[arr[1]]||func(arr[0],arr[1])){
            cout<<-1;
            return 0;
        }

        res=cnt[arr[0]]+cnt[arr[1]]+1;
        
        if(!v[arr[0]].empty()&&!v[arr[1]].empty()){
            if(v[arr[0]].back()!=v[arr[1]].front())res++;   
        }
        cout<<res;
        return 0;
    }
    else{
        int val=0;
        for(int i=0;i<k;i++){
            if(state[arr[i]]){
                cout<<-1;
                return 0;
            }
            if(v[arr[i]].empty()){
                res+=cnt[arr[i]]+1;
                continue;
            }
            idx[val]=i;
            num[val]=arr[i];
            val++;
        }

        res+=cnt[num[0]];
        if(state[num[0]]){
            cout<<-1;
            return 0;
        }
        for(int i=1;i<val;i++){
            if(state[num[i]]||(func(num[i-1],num[i])&&idx[i-1]+1==idx[i])){
                cout<<-1;
                return 0;
            }
            else{
                res+=cnt[num[i]]+1;
                if(v[num[i-1]].back()!=v[num[i]].front())res++;
            }
        }
        cout<<res;
    }
}
