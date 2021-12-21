#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool iseven(vector<int> i){
    int temp=1;
    for(int k=0;k<i.size();k++){
        if(i[k]%2==0)
            continue;
        else
            temp=0;
        i[k]=0;
    }
    return temp;
}

int solution(string s)
{
    int answer = -1;
    int temp=0;
    vector<int> num(26,0);
    for(int i=1;temp+i<s.size();i++){
        if(s[temp]==s[temp+i]){
            if(iseven(num)){
                temp=i+temp;
                i=0;
            }
            else
                return 0;
        }
        else{
            num[s[temp+i]-97]++;
        }
    }
    return 1;
}


int main(){
    string a="cabbaccbccbc";
    int b=solution(a);
    cout << b <<endl;
}

//정확도 시간복잡도 에러 회문확인 필요