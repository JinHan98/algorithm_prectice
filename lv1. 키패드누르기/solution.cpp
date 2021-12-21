#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int> right;
    vector<int> left;
    right.push_back(3);
    right.push_back(0);
    left.push_back(3);
    left.push_back(0);
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]%3==1){
            answer.push_back('L');
            left[0]=numbers[i]/3;
            left[1]=0;
        }
        else if(numbers[i]%3==0&&numbers[i]!=0){
            answer.push_back('R');
            right[0]=numbers[i]/3-1;
            right[1]=2;
        }
        else{
            int right_dis;
            int left_dis;
            if(numbers[i]==0){
                right_dis=abs(right[0]-4)+abs(right[1]-1);
                left_dis=abs(left[0]-4)+abs(left[1]-1);
                if(right_dis<left_dis){
                    answer.push_back('R');
                    right[0]=3;
                    right[1]=1;
                }
                else if(right_dis==left_dis){
                    if(hand[0]=='r'){
                    answer.push_back('R');
                    right[0]=3;
                    right[1]=1; 
                    }
                    else{
                        answer.push_back('L');
                        left[0]=3;
                        left[1]=1;
                    }
                }
                else{
                    answer.push_back('L');
                    left[0]=3;
                    left[1]=1;
                }
            }
            else{
                right_dis=abs(right[0]-(numbers[i]/3))+abs(right[1]-1);
                left_dis=abs(left[0]-(numbers[i]/3))+abs(left[1]-1);
                if(right_dis<left_dis){
                    answer.push_back('R');
                    right[0]=numbers[i]/3;
                    right[1]=1;
                }
                else{
                    if(right_dis==left_dis&&hand[0]=='r'){
                        answer.push_back('R');
                        right[0]=numbers[i]/3;
                        right[1]=1;
                        continue;
                    }
                    answer.push_back('L');
                    left[0]=numbers[i]/3;
                    left[1]=1;
                }
            }
        }
    }
    return answer;
}
//[7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]
int main(){
    vector<int> a;
    string b="left";
    a.push_back(7);
    a.push_back(0);
    a.push_back(8);
    a.push_back(2);
    a.push_back(8);
    a.push_back(3);
    a.push_back(1);
    a.push_back(5);
    a.push_back(7);
    a.push_back(6);
    a.push_back(2);
    string c=solution(a,b);
    for(int i=0;i<c.size();i++)
        cout<<c[i];
}