#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct num_many
{
    int num;
    int howmany=1;
};


vector<int> solution(string s) {
    vector<int> answer;
    vector<num_many> a;
    string temp;
    num_many p;
    int swt=0;
    int many=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]>'/'&&s[i]<':')
            temp.push_back(s[i]);
        if(s[i]=='}'||s[i]==','){
            if(temp.empty())
                continue;
            p.num=stoi(temp);
            temp.clear();
            for(int k=0;k<a.size();k++){
                if(a[k].num==p.num){
                    a[k].howmany++;
                    swt=1;
                    break;
                }
            }
            if(swt==0)
                a.push_back(p);
            swt=0;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i].howmany>many)
            many=a[i].howmany;
    }
    while(many>0){
        for(int i=0;i<a.size();i++){
            if(a[i].howmany==many){
                answer.push_back(a[i].num);
                many--;
                break;
            }
        }
    }
    return answer;
}

int main(){
    string a="{{20,111},{111}}";
    vector<int> b=solution(a);
    for(int i:b)
        cout<<i<<' ';
}