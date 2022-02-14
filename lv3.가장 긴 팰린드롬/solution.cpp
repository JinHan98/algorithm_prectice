#include <iostream>
#include <string>
using namespace std;
bool is_palindrome(string a){
    int i=0;
    while(i<a.size()/2){
        if(a[i]==a[a.size()-1-i])
            i++;
        else
            return false;
    }
    return true;
}
int solution(string s)
{
    int answer=0;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]&&j-i+1>answer){
                if(is_palindrome(s.substr(i,j-i+1))){
                    answer=j-i+1;
                }
            }
        }
    }
    if(answer==0)
        return 1;
    return answer;
}

int main(){
    string a="abcdcba";
    cout<<solution(a)<<endl;
    return 0;
}