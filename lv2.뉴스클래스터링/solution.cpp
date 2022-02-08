#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> make(string a){// 방식을 바꿔야함 하나씩 비교해서 넣는게 아니라 2개씩 확인해야함 알파벳이 아닌문자들은 순서쌍에서 무조건 제외해야함
    vector<string> temp;
    for(int i=0;i<a.size()-1;i++){
        if((a[i]>64&&a[i]<91)||(a[i]>96&&a[i]<123)){
            if((a[i+1]>64&&a[i+1]<91)||(a[i+1]>96&&a[i+1]<123)){
                string b;
                b.push_back((a[i] > 96) ? a[i]-32 : a[i]);
                b.push_back((a[i+1] > 96) ? a[i+1]-32 : a[i+1]);
                temp.push_back(b);
            }
        }
    }
    return temp;
}

int solution(string str1, string str2) {
    int answer = 0;
    int union_1=0;
    int intersection=0;
    vector<string>::iterator point;
    vector<string> a=make(str1);
    vector<string> b=make(str2);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a.size()==0&&b.size()==0)
        return 65536;
    vector<string> a_union_b(a.size()+b.size());
    point=set_union(a.begin(),a.end(),b.begin(),b.end(),a_union_b.begin());
    a_union_b.erase(point,a_union_b.end());
    union_1=a_union_b.size();
    intersection=a.size()+b.size()-union_1;
    double c=(double)intersection/(double)union_1;
    answer=int(65536*c);
    return answer;
}

int main(){
    string a="aa1+aa2";
    string b="AAAA12";
    int c=solution(a,b);
    cout<<c<<endl;
}