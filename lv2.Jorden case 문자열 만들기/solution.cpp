#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    if(s[0]>96&&s[0]<123)
        s[0]=s[0]-32;
    for(int i=1;i<s.size();i++){
        if(s[i]==' '){
            if(s[i+1]!=' '){
                if(s[i+1]>96&&s[i+1]<123){
                    s[i+1]=s[i+1]-32;
                    i++;
                    continue;
                }
                else
                    i++;
            }
            else
                continue;
        }
        else{
            if(s[i]>64&&s[i]<91)
                s[i]=s[i]+32;
        }
    }
    return s;
}

int main(){
    string a="AAA aaAa AA aaAAA aaAA a";
    a=solution(a);
    for(auto i:a)
        cout<<i;
}