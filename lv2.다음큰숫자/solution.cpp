#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// case1 일반적인 케이스 0이 연속해서 나오는 제일 마지막에 있는 0을 1로 나머지 0을 뒤에 붙이고 남은 자리를 1로 메꾸기
// case2 1111100 처럼 0다음에 1이 없는경우 자리수 하나 늘이고 0 다붙이고 1 다 붙이기  
// case3 111111 처럼 1만 있는경우 두번째에 0을 넣어준다


string to_2digit(int i){
    string a;
    while(i>0){
        int k=i%2;
        a.push_back(k+48);
        i/=2;
    }
    reverse(a.begin(),a.end());
    return a;
}

int to_int(string s){
    int temp=1;
    int answer=0;
    while(s.empty()!=true){
        if(s.back()=='1')
            answer+=(temp*1);
        temp*=2;
        s.pop_back();
    }
    return answer;
}

int solution(int n) {
    int answer = 0;
    int one_many=0;
    int last=0;
    string temp=to_2digit(n);
    for(int i=0;i<temp.size();i++){
        if(last!=0){
            sort(temp.begin()+last+1,temp.end());
            break;
        }
        if(temp[i]=='1'){
            one_many++;
        }
        else{
            for(int j=i;j<temp.size();j++){
                if(temp[j]=='1'){
                    last=j-1;
                    temp[j-1]='1';
                    temp[j]=0;
                    break;
                }
                if(j==temp.size()-1){
                    int zero_many=temp.size()-one_many;
                    temp.clear();
                    temp.insert(temp.begin(),'1');
                    temp.insert(temp.begin()+1,zero_many,'0');
                    for(int i=0;i<one_many;i++){
                        temp.push_back('1');
                    }
                    break;
                }
            }
        }
    }
    if(one_many==temp.size())
        temp.insert(temp.begin()+1,'0');
    answer=to_int(temp);
    return answer;
}

int main(){
    int k=62;
    k=solution(k);
    cout<<k<<endl;
    return 0;
}