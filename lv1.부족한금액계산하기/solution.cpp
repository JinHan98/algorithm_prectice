#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer=0;
    for(int i=1;i<count+1;i++){
        answer=answer+price*i;
    }
    if(money-answer<0)
        answer=abs(money-answer);
    else
        answer=0;
    return answer;
}


int main(){
    int price=3;
    int money=20;
    int count=4;
    long long a=solution(price,money,count);
    cout<<a<<endl;
}