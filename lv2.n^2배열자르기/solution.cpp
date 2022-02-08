#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int a;
    int b;
    for(long long i=left;i<right+1;i++){
        a=i/n+1;
        b=i%n+1;
        if(b>a){//몫이 나머지보다 작을때
            answer.push_back(b);
        }
        else
            answer.push_back(a);
    }
    return answer;
}

int main(){
    vector<int> a=solution(3,2,5);
    for(int i : a)
        cout<<i<<' ';
}