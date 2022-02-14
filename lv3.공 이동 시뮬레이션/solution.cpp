#include <string>
#include <vector>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    for(int i=queries.size()-1;i>=0;i--){
        switch (queries[i][0])
        {
        case 0:
            if(queries[i][1]+y<m)
                y+=queries[i][1];
            break;
        case 1:
            if(queries[i][1]<=y)
                y-=queries[i][1];
            break;
        case 2:
            if(queries[i][1]+x<n)
                x+=queries[i][1];
            break;
        default:
            if(queries[i][1]<=x)
                x-=queries[i][1];
            break;
        }
        

    }
    return answer;
}