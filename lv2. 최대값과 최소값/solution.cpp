#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string itos(int i){
    string k;
    int option=0;
    if(i<0){
        option=1;
        i=abs(i);
    }
    if(i==0)
        k.push_back('0');
    while(i>0){
        int temp=i%10;
        k.push_back(temp+48);
        i/=10;
    }
    reverse(k.begin(),k.end());
    if(option==1)
        k.insert(0,"-");
    return k;
}

string solution(string s) {
    string answer = "";
    vector<int> num;
    int last=0;
    int now;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            now=i;
            string temp=s.substr(last,now);
            num.push_back(stoi(temp));
            last=now;
        }
        if(i==s.size()-1){
            string temp=s.substr(now+1,s.size());
            num.push_back(stoi(temp));
        }
    }
    sort(num.begin(),num.end());
    answer.insert(0,itos(num[num.size()-1]));
    answer.insert(0," ");
    answer.insert(0, itos(num[0]));
    return answer;
}

int main(){
    string a="1 3 5 7 -9";
    string b=solution(a);
    for(auto i:b)
        cout<<i<<' ';
}