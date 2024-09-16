//20057
#include <iostream>
#include <algorithm>
using namespace std;

int sand[555][555];
int n;
int dir=0;
int cx,cy;

//해야할거//
//1.방향별 모래날림 구현
//2.토네이도 움직이는거 구현

void func(int dir,int x,int y){
    if(dir==0){
        
    }
    else if(dir==1){
        
    }
    else if(dir==2){
        
    }
    else{
        
    }
}

int nx(int x,int dir,int k){
    if(dir==0){
        x-=k;
    }
    else if(dir==2){
        x+=k;
    }
    return x;
}
int ny(int y,int dir,int k){
    if(dir==1){
        y+=k;
    }
    else if(dir==3){
        y-=k;
    }
    return y;
}

int main(){
    cin>>n;
    cx=n/2+1;
    cy=cx;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>sand[i][j];
    }
    for(int k=1;k<n;k++){
        if(k==n-1){
            for(int l=0;l<3;l++){
                
                dir=(dir+1)%4;
            }
        }
        else{
            for(int l=0;l<2;l++){
                
                dir=(dir+1)%4;
            }
        }
    }
}
