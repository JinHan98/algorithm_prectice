#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int> > num(n);
    int mode=1;
    int how_many=n;
    int temp=0;
    int this_num=1;
    while(how_many>0){
        for(int i=0;i<how_many;i++){
            switch (mode)
            {
            case 1:
                num[i+(temp*2)].insert(num[i+(temp*2)].begin()+temp,this_num);
                break;
            case 2:
                num[n-1-temp].insert(num[n-1-temp].begin()+i+temp+1,this_num);
                break;
           default:
                num[n-2-i-temp].insert(num[n-2-i-temp].end()-temp,this_num);
                break;
            }
            this_num++;
        }
        if(mode==1)
            mode++;
        else if(mode==2)
            mode++;
        else{
            temp++;
            mode=1;
        }
        how_many--;
    }
    for(int j=0;j<num.size();j++){
        for( auto i : num[j]){
            answer.push_back(i);
        }
    }
    return answer;
}

int main(){
    int a=5;
    vector<int> k=solution(a);
    for(int i:k)
        cout<<i<<endl;
}