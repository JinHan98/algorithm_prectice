#include <string>
#include <vector>
#include <stack>
using namespace std;

bool is_right(string a){
    stack<int> b;
    for(int i=0;i<a.size();i++){
        if(a[i]=='(')
            b.push(a[i]);
        else{
            if(b.empty())
                return false;
            if(b.top()=='('){
                b.pop();
            }
        }
    }
    if(b.empty())
        return true;
    return false;
}

string solution(string p) {
    string answer = "";
    string u;
    string v;
    string temp;
    int num_open=0;
    int num_close=0;
    if(p.empty())
        return "";
    for(int i=0;i<p.size();i++){
        if(p[i]=='(')
            num_open++;
        else if(p[i]==')')
            num_close++;
        if(num_open==num_close){
            num_open=0;
            num_close=0;
            u=p.substr(0,i+1);
            v=p.substr(i+1);
            break;
        }
    }
    if(is_right(u)){
        answer=u+solution(v);
        return answer;
    }
    else{
        temp.push_back('(');
        if(!v.empty())
            temp.append(solution(v));
        temp.push_back(')');
        u.erase(u.begin());
        u.pop_back();
        for(int i=0;i<u.size();i++){
            if(u[i]=='(')
                u[i]=')';
            else
                u[i]='(';
        }
        temp.append(u);
        return temp;
    }
}

int main(){
    string s="())((())()))((";
    solution(s);
}