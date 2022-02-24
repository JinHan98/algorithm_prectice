#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> w;
    for(int i=0;i<works.size();i++){
        w.push(works[i]);
    }
    for(int i=0;i<n;i++){
        if(w.top()!=0){
            w.push(w.top()-1);
            w.pop();
        }
        else
            return 0;
    }
    for(int i=0;i<works.size();i++){
        answer+=(w.top()*w.top());
        w.pop();
    }
    return answer;
}