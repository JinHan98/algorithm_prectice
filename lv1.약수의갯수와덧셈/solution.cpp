#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int count=0;
    for(int i=left;i<right+1;i++){
        for(int j=1;j<=sqrt(i);j++){
            if(i%j==0){
                if(i/j==j){
                    count++;
                }
                else{
                    count=count+2;
                }
            }
        }
        if(count%2==1)
            answer=answer-i;
        else
            answer=answer+i;
        count=0;
    }
    return answer;
}

int main(){
    int a=13;
    int b=17;
    int c=solution(a,b);
    cout<<c<<endl;
    return 0;
}