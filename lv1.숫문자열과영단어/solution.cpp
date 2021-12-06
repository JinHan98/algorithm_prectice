#include <string>
#include <vector>
#include <iostream>
#include<regex>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> a;
    a.push_back("zero");
    a.push_back("one");
    a.push_back("two");
    a.push_back("three");
    a.push_back("four");
    a.push_back("five");
    a.push_back("six");
    a.push_back("seven");
    a.push_back("eight");
    a.push_back("nine");
    string b="0123456789";
    for(int i=0;i<b.size();i++){
        s=regex_replace(s,regex(a[i]),b.substr(i,1));
    }
    return stoi(s);
}

int main(){
    string a="one4seveneight";
    int sol=solution(a);
    cout<<sol;
    return 0;
}