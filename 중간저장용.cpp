//20057
#include <iostream>
#include <algorithm>
using namespace std;

int sand[555][555];
int n;
int dir=0;
int cx,cy;
long long res=0;

//해야할거//
//1.방향별 모래날림 구현

void func(int x,int y,int dir){
    
    int ten=sand[x][y]/10;
    int seven=sand[x][y]*7/100;
    int two=sand[x][y]/50;
    int one=sand[x][y]/100;
    int five=sand[x][y]/20;
    int a=sand[x][y]-(ten+one+seven+two)*2-five;
    sand[x][y]=0;
    
    cout<<a<<" "<<ten<<" "<<seven<<" "<<five<<" "<<two<<" "<<one<<"\n";
    if(dir==0){
        if(y-2<1)res+=five;
        else sand[x][y-2]+=five;
        
        if(y-1<1)res+=(ten+a+ten);
        else{
            if(x-1<1)res+=ten;
            else sand[x-1][y-1]+=ten;
            sand[x][y-1]+=a;
            sand[x+1][y-1]+=ten;
        }
        
        if(x-2<1)res+=two;
        else sand[x-2][y]+=two;
        if(x-1<1)res+=seven;
        else sand[x-1][y]+=seven;
        sand[x+1][y]+=seven;
        sand[x+2][y]+=two;
        
        if(x-1<1)res+=one;
        else sand[x-1][y+1]+=one;
        sand[x+1][y+1]+=one;
    }
    else if(dir==1){
        
    }
    else if(dir==2){
        
    }
    else{
        
    }
}

int nx(int x,int dir){
    if(dir==0){
        x-=1;
    }
    else if(dir==2){
        x+=1;
    }
    return x;
}
int ny(int y,int dir){
    if(dir==1){
        y+=1;
    }
    else if(dir==3){
        y-=1;
    }
    return y;
}

void print(int k){
    cout<<cx<<" "<<cy<<" "<<k<<"\n";
}

int main(){
    cin>>n;
    cx=n/2+1;
    cy=cx;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>sand[i][j];
    }
    
    //cout<<cx<<" "<<cy<<"\n";
    
    /*for(int k=1;k<n;k++){
        if(k==n-1){
            for(int l=0;l<3;l++){
                for(int i=0;i<k;i++){
                    cx=nx(cx,dir);
                    cy=ny(cy,dir);
                    func(cx,cy,dir);
                    //print(k);
                }
                dir=(dir+1)%4;
            }
        } 
        else{
            for(int l=0;l<2;l++){
                for(int i=0;i<k;i++){
                    cx=nx(cx,dir);
                    cy=ny(cy,dir);
                    func(cx,cy,dir);
                    //print(k);
                }
                dir=(dir+1)%4;
            }
        }
    }*/
    
    
    
    func(cx-1,cy-1,0);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<sand[i][j]<<" ";
        cout<<"\n";
    }
    
    cout<<res;
}
