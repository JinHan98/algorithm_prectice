#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
// +-*  +*-  *+- *-+  -+*  -*+

string lltos(long long k){
    string a;
    int op=0;
    if(k==0)
        return "0";
    if(k<0){
        k=-k;
        op=1;
    }
    while(k>0){
        int temp=k%10;
        a.push_back(temp+48);
        k/=10;
    }
    reverse(a.begin(),a.end());
    if(op==1)
        a.insert(a.begin(),'-');
    return a;
}

long long solution(string number) {
    long long answer;
    string property;
    priority_queue<long long> p;
    vector<string> temp;
    vector<string> temp1;
    int last=0;
    int sol=0;
    int switer=0;
    for(int i=0;i<number.size();i++){
        if(number[i]=='+'||number[i]=='-'||number[i]=='*'){
            temp.push_back(number.substr(last,i-last));
            temp.push_back(number.substr(i,1));
            last=i+1;
        }
        if(i==number.size()-1)
            temp.push_back(number.substr(last,i+1));
    }
    for(int i=0;i<6;i++){
        switch (i)
        {
        case 0:
            property="+-*";
            break;
        case 1:
            property="+*-";
            break;
        case 2:
            property="*+-";
            break;
        case 3:
            property="*-+";
            break;
        case 4:
            property="-+*";
            break;
        default:
            property="-*+";
            break;
        }
        temp1=temp;
        while(switer<3){
            for(int j=0;j<temp1.size();j++){
                string a;
                long long im;
                if(temp1[j][0]==property[switer]){
                    if(property[switer]=='+')
                        im=stoll(temp1[j-1])+stoll(temp1[j+1]);
                    else if(property[switer]=='-'&&temp1[j].size()==1)
                        im=stoll(temp1[j-1])-stoll(temp1[j+1]);
                    else if(property[switer]=='*')
                        im=stoll(temp1[j-1])*stoll(temp1[j+1]);
                    a=lltos(im);
                    temp1.erase(temp1.begin()+j-1,temp1.begin()+j+2);
                    temp1.insert(temp1.begin()+j-1,a);
                    j--;
                }
            }
            switer++;
        }
        switer=0;
        p.push(abs(stoll(temp1[0])));
    }
    answer=p.top();
    return answer;
}

int main(){
    string b="177-661*999*99-133+221+334+555-166-144-551-166*166-166*166-133*88*55-11*4+55*888*454*12+11-66+444*99";
    long long c=solution(b);
    cout<<c<<endl;
}
