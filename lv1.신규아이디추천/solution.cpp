#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool level_2(char a){
    if(96<a&&a<123)
        return false;
    if(47<a&&a<58)
        return false;
    if(a==45)
        return false;
    if(a==95)
        return false;
    if(a==46)
        return false;
    return true;
}

string solution(string new_id) {
    string answer = "";
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]>64&&new_id[i]<91)
            new_id[i]=new_id[i]+32;
    }
    new_id.erase(remove_if(new_id.begin(),new_id.end(),level_2),new_id.end());
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]=='.'){
            for(int j=i+1;j<new_id.size();){
                if(new_id[j]=='.'){
                    new_id.erase(new_id.begin()+j);
                }
                else
                    break;
            }
        }
    }
    if(new_id[0]=='.')
        new_id.erase(new_id.begin());
    if(new_id[new_id.size()-1]=='.')
        new_id.pop_back();
    if(new_id.empty())
        new_id.push_back('a');
    if(new_id.size()>15)
        new_id=new_id.substr(0,15);
    if(new_id[new_id.size()-1]=='.')
        new_id.pop_back();
    if(new_id.size()<3)
        while(new_id.size()<3)
            new_id.push_back(new_id[new_id.size()-1]);
    return new_id;
}


int main(){
    string a="abcdefghijklmn.p" ;
    string b=solution(a);
    cout<<b<<endl;
}