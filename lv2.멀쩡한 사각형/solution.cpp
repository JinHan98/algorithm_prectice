#include <iostream>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    double inclination=-(double)h/(double)w;
    for(int i=1;i<h;i++){
        double temp=((double)i-(double)h)/inclination;
        int minus=int(temp);
        answer=answer+minus;
    }
    answer=answer*2;
    return answer;
}

int main(){
    int a=100;
    int b=102;
    long long c=solution(a,b);
    cout<<c<<endl;
}