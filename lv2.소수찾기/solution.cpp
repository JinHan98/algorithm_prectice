#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_sosu(int a){
    if(a==1||a==0)
        return 0;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)
            return 0;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    for(int i=0;i<numbers.size();i++){
        if(is_sosu(numbers[i]-48))
            answer++;
    }
    if(numbers.size()>1){
        for(int i=0;i<numbers.size()-1;i++){
            for(int j=0;j<numbers.size();j++){
                if(numbers[i]!='0'){
                    if(is_sosu(atoi(numbers.substr(i,j-i+1))))
                        answer++;
                }
            }
        }
    }
    if(numbers.size()>2){
        for(int i=0;i<numbers.size();i++){
            
        }
    }
    return answer;
}


int main(){
    cout<<is_sosu(137);
}