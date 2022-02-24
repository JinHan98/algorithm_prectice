#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> sol;
    sol.push_back(numbers[0]);
    for(int i=1;i<numbers.size();i++){
        for(int j=0;j<pow(2,i-1);j++){
            sol.push_back(sol[j]-numbers[i]);
            sol[j]+=numbers[i];
        }
    }
    for(int i=0;i<sol.size();i++){
        if(sol[i]==target||sol[i]==target+(numbers[0]*2))
            answer++;
            
    }
    return answer;
}

int main(){
    vector<int> a;
    int b=3;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    cout<<solution(a,b);
}