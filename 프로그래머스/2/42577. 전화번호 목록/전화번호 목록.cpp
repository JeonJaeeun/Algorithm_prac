#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0;i<phone_book.size() - 1;i++){
        //다음 번호가 현재 번호를 접두어로 가지고 있는지 확인
        if(phone_book[i+1].substr(0,phone_book[i].size()) == phone_book[i]){
            return false;
        }
    }
    return true;
}