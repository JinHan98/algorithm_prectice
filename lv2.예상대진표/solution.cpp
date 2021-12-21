#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while(1){
    int max_num=max(a,b);
    if(abs(a-b)==1&&max_num%2==0)
        return answer;
    if(a%2==1)
        a=a/2+1;
    else
        a=a/2;
    if(b%2==1)
        b=b/2+1;
    else   
        b=b/2;
    answer++;
    }
}

int main(){
    int a=8;
    int b=4;
    int c=7;
    int d=solution(a,b,c);
    cout<<d<<endl;
    return 0;
}