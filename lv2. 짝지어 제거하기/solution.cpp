#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


int solution(string s)
{
    stack<char> a;
    a.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(a.empty()){
            a.push(s[i]);
            continue;
        }
        if(a.top()==s[i])
            a.pop();
        else
            a.push(s[i]);
    }
    if(a.empty())
        return 1;
    else
        return 0;
}


int main(){
    string a="cabbaccbccbc";
    int b=solution(a);
    cout << b <<endl;
}

//정확도 시간복잡도 에러 회문확인 필요