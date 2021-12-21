#include <string>
#include <vector>
#include <queue>
//다음에 풀자
using namespace std;

string solution(string number, int k) {
    string answer = "";
    string property="*+-";
    priority_queue<int> p;
    int temp=0;
    int prop_switch=0;
    while(1){
        int last_index=0;
        int next_index=0;
        for(int i=0;i<number.size();i++){
            if(number[i]>47&&number[i]<58){
                last_index=i;
            }
            else{
                for(int j=i;j<number.size();j++){
                    if(number[j]>41&&number[j]<47){
                        next_index=j;
                    }
                    if(j==number.size()-1)
                        next_index=number.size();
                }
                if(number[i]==property[0]){
                    switch (property[0])
                    {
                    case '*':
                        temp=stoi(number.substr(last_index,i))*stoi(number.substr(i+1,next_index));
                        break;
                    case '+':
                        temp=stoi(number.substr(last_index,i))+stoi(number.substr(i+1,next_index));
                        break;
                    default:
                        temp=stoi(number.substr(last_index,i))-stoi(number.substr(i+1,next_index));
                        break;
                    }
                    number.erase(number.begin()+last_index,number.begin()+next_index);
                    while(temp>0){
                        int p=temp%10;
                        char* a="0";
                        a[0]=a[0]+p;
                        string b=string(a);
                        number.insert(last_index,b);
                        temp=temp/10;
                    }
                }
            }
        }
        prop_switch++;
    }
    return answer;
}