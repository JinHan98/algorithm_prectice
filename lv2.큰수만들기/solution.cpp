#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int temp=number.size();
    while(1){
        int big=0;
        for(int i=0;i<temp;i++){
            if(number[i]>number[big])
                big=i;
        }
        if(big>k)
            temp=big;
        else if(big==0)
            break;
        else{
            number.erase(0,big);
            k-=big;
            break;
        }
    }
    for(int i=0;i<number.size()-1&&k!=0;i++){
        if(number[i]<number[i+1]){
            number.erase(number.begin()+i);
            i-=2;
            k--;
        }
    }
    for(;k>0;k--)
        number.pop_back();
    answer=number;
    return answer;
}

int main(){
    string a="1000100011";
    int k=5;
    cout<<solution(a,k);
}