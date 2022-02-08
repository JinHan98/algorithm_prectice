#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> a;
    if(s.size()%2!=0)
        return false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            a.push(s[i]);
        else if(s[i]==')'){
            if(a.empty())
                return false;
            if(a.top()=='(')
                a.pop();
            else
                return false;
        }
    }
    if(!a.empty())
        return false;
    return answer;
}

int main(){
    string a="))";
    cout<<solution(a);
}