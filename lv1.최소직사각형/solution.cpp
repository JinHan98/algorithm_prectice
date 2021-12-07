#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector <int> > sizes) {
    int answer = 0;
    int first_row_max=0;
    int second_row_max=0;
    for(int i=0;i<sizes.size();i++){
        sort(sizes[i].begin(),sizes[i].end());
    }
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0]>first_row_max)
            first_row_max=sizes[i][0];
        if(sizes[i][1]>second_row_max)
            second_row_max=sizes[i][1];
    }
    answer=first_row_max*second_row_max;
    return answer;
}