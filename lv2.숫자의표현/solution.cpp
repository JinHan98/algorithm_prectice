#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 1;
    int minus=1;
    bool odd=true;
    int div=2;
    while(1){
        int temp=n;
        if(odd==true){
            temp-=minus;
            minus++;
        }
        if((temp/div)-minus+1<0)
            break;
        if(temp%div==0)
            answer++;
        if(odd==true)
            odd=false;
        else
            odd=true;
        div++;    
    }
    return answer;
}
int main(){
    cout<<solution(15);
}