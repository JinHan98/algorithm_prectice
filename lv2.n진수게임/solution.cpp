#include <string>
#include <vector>
#include <iostream>

using namespace std;

string now_num(int num,int digit){
    string k;
    if(num==0)
        k.push_back('0');
    while(num!=0){
        int temp=num%digit;
        if(temp<10)
            k.insert(k.begin(),temp+48);
        else
            k.insert(k.begin(),temp+55);
        num=num/digit;
    }
    return k;
}

string solution(int n/*진법*/, int t/*미리구할숫자의 갯수*/, int m/*참가인원*/, int p/*순서*/) {
    string answer = "";
    int this_num=0;
    int how_many=1;
    while(1){
        string now_=now_num(this_num,n);
        for(int i=0;i<now_.size();i++){
            if(how_many%m==p%m){
                answer.push_back(now_[i]);
                t--;
                if(t==0)
                    break;
            }
            how_many++;
        }
        if(t==0)
            break;
        this_num++;
    }
    return answer;
}

int main(){
    string k=solution(2,4,2,1);
    cout<<k;
}