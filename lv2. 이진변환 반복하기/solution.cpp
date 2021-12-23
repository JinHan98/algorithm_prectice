#include <string>
#include <vector>
#include <iostream>

using namespace std;

string make_2(int num){
    string temp="";
    while(num!=0){
        int n=num%2;
        temp.insert(temp.begin(),n+48);
        num=num/2;
    }
    return temp;
}


vector<int> solution(string s) {
    vector<int> answer;
    int zero_many=0;
    int chg_many=0;
    while(s!="1"){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                s.erase(s.begin()+i);
                zero_many++;
                i--;
            }
        }
        s=make_2(s.size());
        chg_many++;
    }
    answer.push_back(chg_many);
    answer.push_back(zero_many);
    return answer;
}

int main(){
    string k="110010101001";
    vector<int> j=solution(k);
    cout<<j[0]<<' '<<j[1]<<endl;
    return 0;
}