#include <iostream>
char gear[4][8];
int k;
using namespace std;

void turn_1(int num){
    char val=gear[num][7];
    for(int i=7;i>0;i--)gear[num][i]=gear[num][i-1];
    gear[num][0]=val;
}
void turn_0(int num){
    char val=gear[num][0];
    for(int i=0;i<7;i++)gear[num][i]=gear[num][i+1];
    gear[num][7]=val;
}

void turn(int num,int dir){
    if(num==1){
        if(dir==1){
            if(gear[0][2]!=gear[1][6]){
                if(gear[1][2]!=gear[2][6]){
                    if(gear[2][2]!=gear[3][6]){
                        turn_0(3);
                    }
                    turn_1(2);
                }
                turn_0(1);
            }
            turn_1(0);
        }
        else{
            if(gear[0][2]!=gear[1][6]){
                if(gear[1][2]!=gear[2][6]){
                    if(gear[2][2]!=gear[3][6]){
                        turn_1(3);
                    }
                    turn_0(2);
                }
                turn_1(1);
            }
            turn_0(0);
        }
    }
    else if(num==2){
        if(dir==1){
            if(gear[0][2]!=gear[1][6]){
                turn_0(0);
            }
            if(gear[1][2]!=gear[2][6]){
                if(gear[2][2]!=gear[3][6]){
                    turn_1(3);
                }
                turn_0(2);
            }
            turn_1(1);
        }
        else{
            if(gear[0][2]!=gear[1][6]){
                turn_1(0);
            }
            if(gear[1][2]!=gear[2][6]){
                if(gear[2][2]!=gear[3][6]){
                    turn_0(3);
                }
                turn_1(2);
            }
            turn_0(1);
        }
    }
    else if(num==3){
        if(dir==1){
            if(gear[2][2]!=gear[3][6]){
                turn_0(3);
            }
            if(gear[1][2]!=gear[2][6]){
                if(gear[0][2]!=gear[1][6]){
                    turn_1(0);
                }
                turn_0(1);
            }
            turn_1(2);
        }
        else{
            if(gear[2][2]!=gear[3][6]){
                turn_1(3);
            }
            if(gear[1][2]!=gear[2][6]){
                if(gear[0][2]!=gear[1][6]){
                    turn_0(0);
                }
                turn_1(1);
            }
            turn_0(2);
        }
    }
    else{
        if(dir==1){
            if(gear[2][2]!=gear[3][6]){
                if(gear[1][2]!=gear[2][6]){
                    if(gear[0][2]!=gear[1][6]){
                        turn_0(0);
                    }
                    turn_1(1);
                }
                turn_0(2);
            }
            turn_1(3);
        }
        else{
            if(gear[2][2]!=gear[3][6]){
                if(gear[1][2]!=gear[2][6]){
                    if(gear[0][2]!=gear[1][6]){
                        turn_1(0);
                    }
                    turn_0(1);
                }
                turn_1(2);
            }
            turn_0(3);
        }
    }
}



int main()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++)cin>>gear[i][j];
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int num,dir;
        cin>>num>>dir;
        turn(num,dir);
    }
    int cnt=0;
    if(gear[0][0]=='1')cnt+=1;
    if(gear[1][0]=='1')cnt+=2;
    if(gear[2][0]=='1')cnt+=4;
    if(gear[3][0]=='1')cnt+=8;
    cout<<cnt;
}
