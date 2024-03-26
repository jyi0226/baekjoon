#include <iostream>
#include <queue>
using namespace std;

int board[20][20];
int dice[7]={0,1,6,3,4,2,5};
int n,m,x,y,k,ord,val;
int nx,ny;
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    //먼저 bfs로 연결된 개수를 구하는 보드 하나 만듬
    //이후에 주사위 굴려서 점수 합 구함
}
