#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    for(int i=0;i<word.size();i++){
        switch (word[i])
        {
        case 'A':
            answer++;
            break;
        case 'E':
            switch (i)
            {
            case 0:
                answer=answer+782;
                break;
            case 1:
                answer=answer+157;
                break;
            case 2:
                answer=answer+32;
                break;
            case 3:
                answer=answer+7;
                break;
                break;
            default:
                answer=answer+2;
                break;
            }
            break;
        case 'I':
            switch (i)
            {
            case 0:
                answer=answer+1563;
                break;
            case 1:
                answer=answer+313;
                break;
            case 2:
                answer=answer+63;
                break;
            case 3:
                answer=answer+13;
                break;
            default:
                answer=answer+3;
                break;
            }
            break;
        case 'O':
            switch (i)
            {
            case 0:
                answer=answer+2344;
                break;
            case 1:
                answer=answer+469;
                break;
            case 2:
                answer=answer+94;
                break;
            case 3:
                answer=answer+19;
                break;
            default:
                answer=answer+4;
                break;
            }
            break;
        default:
            switch (i)
            {
            case 0:
                answer=answer+3125;
                break;
            case 1:
                answer=answer+625;
                break;
            case 2:
                answer=answer+125;                
                break;
            case 3:
                answer=answer+25;
                break;
            default:
                answer=answer+5;
                break;
            }
            break;
        }
    }
    return answer;
}