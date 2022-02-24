#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a,string b){
    return a[3]==61;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    sort(data.begin(),data.end(),compare);
    for(int i=0;i<data.size();i++){
        if(data[i][3]=='='){
            an
        }
    }
    return answer;
}

int main(){
    vector<string> a={"R~T>2","M~C<2", "C~M>1","N~F=0"};
    solution(4,a);
}