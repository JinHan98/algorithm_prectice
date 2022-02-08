#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string change(string a){
    int temp=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>64&&a[i]<91)
            temp++;
    }
    if(temp==a.size())
        return a;
    if(a[0]>96&&a[0]<123){
        if(a[a.size()-1]==a[0]){
            a.pop_back();
            a.erase(a.begin());
        }
        else
            return "invalid";
    }
    
    if(a[1]>96&&a[1]<123){
        for(int i=3;i<a.size();i+=2){
            if(a[i]!=a[1])
                return "invalid";
        }
        char b=a[1];
        a.erase(remove(a.begin(),a.end(),b),a.end());
    }
    return a;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    int temp=1;
    for(int i=0;i<sentence.size()-1;i++){
        if(sentence[i]>96&&sentence[i]<123){//소문자
            if(sentence[i+1]>96&&sentence[i+1]<123){
                sentence.insert(sentence.begin()+i+1,' ');
                i++;
            }
        }
        else if(sentence[i]==' ')
            return "invalid";
    }
    for(int i=0;i<sentence.size();){
        if(sentence[i]>96&&sentence[i]<123){//소문자
            for(int j=i+1;j<sentence.size();j++){
                if(sentence[j]==sentence[i]){
                    if(j!=sentence.size()-1){
                        sentence.insert(sentence.begin()+j+1,' ');
                        i=j+1;
                        break;
                    }
                    else
                        i=j+1;
                }
            }
        }
        else if(sentence[i]>64&&sentence[i]<91){//대문자
            if(sentence[i+1]>64&&sentence[i+1]<91){
                i++;
                continue;
            }
            if(i==sentence.size()-1){
                i++;
                continue;
            }
            for(int j=i+1;sentence[j]==sentence[i+1];j+=2){
                temp=j;
            }
            if(temp+2!=sentence.size())
                sentence.insert(sentence.begin()+temp+2,' ');
            i=temp+2;
            temp=1;
            continue;
        }
        i++;
    }
    temp=0;
    for(int i=0;i<sentence.size();i++){
        if(sentence[i]==' '||i==sentence.size()-1){
            if(change(sentence.substr(temp,i))=="invalid")
                return "invalid";
            else{
                answer.append(change(sentence.substr(temp,i)));//공백 포함
                answer.push_back(' ');
                temp=i+1;
            }
        }
    }
    answer.pop_back();
    return answer;
}

int main(){
    string a="AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR";
    string b=solution(a);
    cout<<b<<endl;
}