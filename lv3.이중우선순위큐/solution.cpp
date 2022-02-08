#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> temp;
    priority_queue<int,vector<int>,greater<int> > upper;//오름차순
    priority_queue<int> low;//내림차순
    priority_queue<int> upper_to_low;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            upper.push(stoi(operations[i].substr(2)));
            low.push(stoi(operations[i].substr(2)));
        }
        else{
            if(operations[i][2]=='-'){//작은수 삭제
                if(!upper.empty())
                    upper.pop();
                if(low.size()==1)
                    low.pop();
            }
            else{
                if(!low.empty())
                    low.pop();
                if(upper.size()==1)
                    upper.pop();
            }
        }
    }
    if(upper.empty()||low.empty()){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }

    while(!upper.empty()){
        upper_to_low.push(upper.top());
        upper.pop();
    }
    while(!upper_to_low.empty()&&!low.empty()){
        if(upper_to_low.top()>low.top())
            upper_to_low.pop();
        else if(upper_to_low.top()<low.top())
            low.pop();
        else{
            temp.push_back(upper_to_low.top());
            upper_to_low.pop();
            low.pop();
        }
    }
    answer.push_back(temp.front());
    answer.push_back(temp.back());
    return answer;
}
int main(){
    vector<string> a;
    a.push_back("I 16");
    a.push_back("D 1");
    vector<int> b=solution(a);
    for(int i :b)
        cout<<i;
}