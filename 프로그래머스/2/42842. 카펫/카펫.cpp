#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    
    int total = brown + yellow;
    
    for(int h = 3 ; h<=total/h ; ++h){
        if(total % h==0){
            int w = total/h;
            if((w-2)*(h-2) == yellow){
                return {w,h};
            }
        }
    }
}