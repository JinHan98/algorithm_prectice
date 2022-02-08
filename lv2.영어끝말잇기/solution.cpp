#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int op=0;
    for(int i=0;i<words.size()-1;i++){
        for(int j=0;j<i+1;j++){
            if(words[i+1]==words[j]){
                op=1;
                break;
            }
        }
        if(words[i].back()!=words[i+1].front()||op==1){
            if((i+2)%n==0)
                answer.push_back(n);
            else
                answer.push_back((i+2)%n);
            if((i+2)%n==0)
                answer.push_back((i+2)/n);
            else
                answer.push_back((i+2)/n+1);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}