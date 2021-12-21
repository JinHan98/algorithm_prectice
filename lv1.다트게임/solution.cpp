#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int k=0;
    vector<int> num;
    for(int i=0;i<dartResult.size();i++){
        if(dartResult[i]=='1'&&dartResult[i+1]=='0'){
            num.push_back(10);
            i++;
        }
        else if(dartResult[i]>='0'&&dartResult[i]<='9'){
            num.push_back(dartResult[i]-'0');
        }
        else if(dartResult[i]=='S')
            continue;
        else if(dartResult[i]=='D')
            num.back()=pow(num.back(),2);
        else if(dartResult[i]=='T')
            num.back()=pow(num.back(),3);
        else if(dartResult[i]=='*'){
            switch (num.size())
            {
            case 0:
                answer=2;
                break;
            case 1:
                num.back()=num.back()*2;
                break;
            case 2:
                num[0]=num[0]*2;
                num[1]=num[1]*2;
                break;
            case 3:
                num[1]=num[1]*2;
                num[2]=num[2]*2;
                break;
            default:
                break;
            }
        }
        else if(dartResult[i]=='#')
            num.back()=num.back()*-1;
    }
    for(int i=0;i<3;i++)
        answer=answer+num[i];
    
    return answer;
}
int main(){
    string a="1S2D*3T";
    int b=solution(a);
    cout<<b;
}