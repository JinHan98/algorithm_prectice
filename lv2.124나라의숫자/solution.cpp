#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    string temp="412";
    while(1){
        int k=n%3;
        switch(k)
        {
        case 1:
            answer.insert(0,1,temp[1]);
            n=n/3;
            break;
        case 2:
            answer.insert(0,1,temp[2]);
            n=n/3;
            break;
        
        default:
            answer.insert(0,1,temp[0]);
            n=n/3;
            n--;
            break;
        }
        if(n==0)
        break;
    }
    return answer;
}