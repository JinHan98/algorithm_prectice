#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

vector<int> key;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    for(int i=0;i<completion.size();i++){
        if(participant[i].compare(completion[i])==0)
            continue;
        else{
            answer=participant[i];
            return answer;
        }
    }
    answer=participant.back();
    return answer;
}

int main(){
    vector<string> a;
    vector<string> b;
    string c;
    a.push_back("mislav");
    a.push_back("stanko");
    a.push_back("mislav");
    a.push_back("ana");
    b.push_back("stanko");
    b.push_back("ana");
    b.push_back("mislav");
    c=solution(a,b);
    cout<<c<<endl;
}