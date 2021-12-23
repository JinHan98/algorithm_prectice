#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*생각해야하는 경우의 수
1. 일반적
2. 뒤에 A가 나오는 경우
3. 앞에 A가 나오는 경우
4. 앞,뒤에 A가 나오는 경우
5. 중간에 A가 연속으로 나오는데 앞이나 뒤로 갔다가 돌아와도 A의 갯수보다 적을 경우*/
int solution(string name) {
    int answer = 0;
    int A_count=0;
    if(name.size()==1)
        return min(91-name[0],name[0]-'A');
    for(int i=0;i<name.size();i++)
        answer=answer+min(91-name[i],name[i]-'A');
    if(name[1]=='A'||name[name.size()-1]=='A'){
        int front=0;
        int back=0;
        for(int i=1;i<name.size();i++){
            if(name[i]=='A')
                front++;
            else
                break;
        }
        for(int i=name.size()-1;i>0;i++){
            if(name[i]=='A')
                back++;
            else
                break;
        }
        answer=answer+(name.size()-1-max(front,back));
        return answer;
    }
    int A=0;
    int start_index=0;
    int end_index;
    int err=0;
    for(int i=1;i<name.size();i++){
        if(name[i]=='A'){
            if(start_index==0)
                start_index=i;
            A++;
            if(A>A_count){
                A_count=A;
            }
            else{
                start_index=0;
            }
        }
        else{
            A=0;
        }
    }
    int f_dis=start_index-1;
    int e_dis=name.size()-(start_index+A_count);
    if(A_count>min(f_dis*2+e_dis,e_dis*2+f_dis))
        answer=answer+min(f_dis*2+e_dis,e_dis*2+f_dis);
    else
        answer=answer+name.size()-1;
    return answer;
}

int main(){
    string a="BBAAAAB";
    int k=solution(a);
    cout<<k;
}