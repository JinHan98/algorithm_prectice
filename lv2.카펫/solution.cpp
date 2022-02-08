#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
가로가 x, 세로가 y라고 하면
brown=2(x-1)+2(y-1)

brown=2x+2y-4

2x=brown-2y+4

x=brown/2-y+2

yellow=(x-2)(y-2)

yellow=(brown/2-y)(y-2)

2=(5-y)(y-2)

2=-y^2+7y-10

yellow=y(brown/2)-brown-y^2+2y

yellow+brown=y(brown/2)-y^2+2y


10 2
y^2-(2+brwon/2)y+(yellow+brown)

y^2-7y+12

y=2+brown/2+squrt((2+brown)^2-4(yellow+brown))/2


yellow+brown=y(brown/2-y+2)

(yellow+brown)/y=brown/2-y+2
y=(yellow+brown)/y



yellow=

*/


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int i=2+brown/2;
    int j=yellow+brown;
    int x=(i+sqrt(pow(i,2)-(4*j)))/2;
    int y=(i-sqrt(pow(i,2)-(4*j)))/2;
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}