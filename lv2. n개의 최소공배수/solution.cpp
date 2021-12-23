#include <string>
#include <vector>

using namespace std;


int lcm(int a,int b){
    int c;
    int temp=a*b;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return temp/a;
}

int solution(vector<int> arr) {
    int answer = 0;
    answer=lcm(arr[0],arr[1]);
    for(int i=2;i<arr.size();i++){
        answer=lcm(answer,arr[i]);
    }
    return answer;
}