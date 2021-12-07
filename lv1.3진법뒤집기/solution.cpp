#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

string make_3_re(int num){
    string ret;
    while(num>2){
        ret.push_back(num%3+48);
        num=num/3;
    }
    ret.push_back(num+48);
    return ret;
}
int make_10(string s){
    int sum=0;
    int temp=0;
    for(int i=s.size()-1;i>-1;i--){
        sum=sum+(s[i]-48) * pow(3,temp);
        temp++;
    }
    return sum;
}

int solution(int n) {
    int answer = 0;
    string temp=make_3_re(n);
    answer=make_10(temp);
    return answer;
}

int main(){
    int a=3;
    int b=solution(a);
    cout<<b<<endl;
    return 0;
}