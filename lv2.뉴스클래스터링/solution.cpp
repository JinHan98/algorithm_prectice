#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> make(string a){
    vector<string> temp(a.size());
    int index=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='a'&& a[i]<123){
            if(temp[0]==""){
                temp[0].push_back(a[i]);
                continue;
            }
            temp[index].push_back(a[i]);
            temp[index+1].push_back(a[i]);
            index++;
            continue;
        }
            
        if(a[i]>='A'&&a[i]<='Z'){
            if(temp[0]==""){
                temp[0].push_back(a[i]+32);
                continue;
            }
            temp[index].push_back(a[i]+32);
            temp[index+1].push_back(a[i]+32);
            index++;
            continue;
        }
    }
    for(;index<a.size();index++)
        temp.pop_back();
    return temp;
}

int solution(string str1, string str2) {
    int answer = 0;
    int union_1=0;
    int intersection=0;
    vector<string>::iterator point;
    if(str1.empty()||str2.empty())
        return 1;
    vector<string> a=make(str1);
    vector<string> b=make(str2);
    sort(a.begin(),b.begin());
    sort(b.begin(),b.end());
    vector<string> a_union_b(a.size()+b.size());
    point=set_union(a.begin(),a.end(),b.begin(),b.end(),a_union_b.begin());
    a_union_b.erase(point,a_union_b.end());
    union_1=a_union_b.size();
    intersection=a.size()+b.size()-union_1;
    double c=(double)intersection/(double)union_1;
    answer=int(65536*c);
    return answer;
}

int main(){
    string a="FRANCE";
    string b="french";
    int c=solution(a,b);
    cout<<c<<endl;
}