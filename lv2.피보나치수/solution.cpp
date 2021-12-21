#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer; 
    vector<__int128_t> k;
    k.push_back(0);
    k.push_back(1);
    for(int i=2;i<n+1;i++)
        k.push_back((k[i-2]+k[i-1])%1234567);
    answer=k.back();
    return answer;
}

int main(){
    int a=3;
    int b=solution(a);
    cout<<b<<endl;
}