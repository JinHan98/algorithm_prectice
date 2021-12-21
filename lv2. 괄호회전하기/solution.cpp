#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int index=s.size();
    for(int i=0;i<index;i++){//s번 회전
        string clone=s;
        for(int k=0;k<s.size();){
            if(s[k]=='('){
                if(s[k+1]==')'){
                    s.erase(s.begin()+k);
                    s.erase(s.begin()+k);
                    k=0;
                }
                else
                    k++;
            }
            else if(s[k]=='{'){
                if(s[k+1]=='}'){
                    s.erase(s.begin()+k);
                    s.erase(s.begin()+k);
                    k=0;
                }
                else
                    k++;
            }
            else if(s[k]=='['){
                if(s[k+1]==']'){
                    s.erase(s.begin()+k);
                    s.erase(s.begin()+k);
                    k=0;
                }
                else
                    k++;
            }
            else
                k++;
        }
        if(s.empty())
            answer++;
        s=clone;
        s.push_back(s[0]);
        s.erase(s.begin());
    }
    return answer;
}

int main(){
    string a="[](){}";
    int b=solution(a);
    cout<<b<<endl;
}