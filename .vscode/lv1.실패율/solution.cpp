#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<long double> fail_per(N);
    vector<int> not_clear(N);
    vector<int> come(N);
    for(int i=0;i<stages.size();i++){
        for(int j=1;j<N+2;j++){
            if(j==N+1){
                for(int p=0;p<j-1;p++)
                    come[p]++;
                break;
            }
            if(stages[i]==j){
                not_clear[j-1]++;
                for(int k=0;k<j;k++)
                    come[k]++;
                break;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(come[i]==0){
            fail_per[i]=0.0;
            continue;
        }
        fail_per[i]=(long double)not_clear[i]/(long double)come[i];
    }
    for(int i=0;i<N;i++){
        int temp=max_element(fail_per.begin(),fail_per.end())-fail_per.begin();
        fail_per[temp]=-1;
        answer.push_back(temp+1);
    }
    return answer;
}


int main(){
    vector<int> a;
    int b=4;
    a.push_back(5);
    a.push_back(5);
    a.push_back(3);
    a.push_back(3);
    a.push_back(1);
    vector<int> c=solution(b,a);
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<endl;
    return 0;
}