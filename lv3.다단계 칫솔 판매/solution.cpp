#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(),0);
    for(int i=0;i<seller.size();i++){
        amount[i]*=100;
        for(int j=0;j<enroll.size();j++){
            if(seller[i]==enroll[j]){
                int k=j;
                while(amount[i]>0){
                    if(amount[i]%10==0){
                        answer[k]+=(amount[i]/10*9);
                        amount[i]-=(amount[i]/10*9);
                    }
                    else{
                        answer[k]+=(amount[i]-amount[i]/10);
                        amount[i]-=(amount[i]-amount[i]/10);
                    }
                    if(referral[k]!="-"){
                        for(int a=k-1;a>=0;a--){
                            if(enroll[a]==referral[k]){
                                k=a;
                                break;
                            }
                        }
                    }
                    else{
                        break;
                    }

                }
            }
        }
    }
    return answer;
}

int main(){
    vector<string> a={"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> b={"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> c={"young", "john", "tod", "emily", "mary"};
    vector<int> d={12, 4, 2, 5, 10};
    vector<int> e=solution(a,b,c,d);
    for(int i : e)
        cout<<i<<endl;
}