#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
double score,score_sum=0,grade_sum=0;
string grade;
string sub;
int main()
{
    for(int i=0;i<20;i++){
        cin>>sub>>score>>grade;
        if(grade=="A+"){
            grade_sum+=score*4.5;
            score_sum+=score;
        }
        else if(grade=="A0"){
            grade_sum+=score*4.0;
            score_sum+=score;
        }
        else if(grade=="B+"){
            grade_sum+=score*3.5;
            score_sum+=score;
        }
        else if(grade=="B0"){
            grade_sum+=score*3.0;
            score_sum+=score;
        }
        else if(grade=="C+"){
            grade_sum+=score*2.5;
            score_sum+=score;
        }
        else if(grade=="C0"){
            grade_sum+=score*2.0;
            score_sum+=score;
        }
        else if(grade=="D+"){
            grade_sum+=score*1.5;
            score_sum+=score;
        }
        else if(grade=="D0"){
            grade_sum+=score*1.0;
            score_sum+=score;
        }
        else if(grade=="F"){
            score_sum+=score;
        }
    }
    if(score_sum==0)cout<<0.0;
    else cout<<grade_sum/score_sum;
}
