#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue <int> q;
    for(int i=0;i<priorities.size();i++)
        q.push(priorities[i]);
    
    while(1){
        if(priorities[0]==q.top()){
            priorities.erase(priorities.begin());
            q.pop();
            answer++;
            if(location==0)
                return answer;
            location--;
        }
        else{
            if(location==0)
                location=priorities.size()-1;
            else {
                location--;
            }
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
        }
    }
}

int main(){
    vector<int> p;
    int b=0;
    p.push_back(1);
    p.push_back(1);
    p.push_back(9);
    p.push_back(1);
    p.push_back(1);
    p.push_back(1);
    int c=solution(p,b);
    cout<<c<<endl;
}