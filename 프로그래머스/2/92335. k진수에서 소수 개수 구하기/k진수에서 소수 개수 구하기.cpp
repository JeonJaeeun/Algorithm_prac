#include <string>
#include <vector>

using namespace std;

string toBaseK(int n, int k){
    string result = "";
    while(n>0){
        int remainder = n % k;
        result = to_string(remainder) + result;
        n /= k;
    }
    return result;
}

bool isPrime(long long num){
    if(num < 2) return false;
    for(long long i = 2; i*i <=num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    string baseK = toBaseK(n, k);
    string cur = ""; // 현재 숫자를 임시로 저장할 문자열
    int answer = 0;
    
    for(char c: baseK){
        if(c != '0'){
            cur += c;
        }
        else{
            if(!cur.empty()){
                long long num = stoll(cur);
                if(isPrime(num)) answer++;
                cur = "";
            }
        }
    }
    
    // 마지막 남은 숫자 처리 (끝이 0으로 안끝나는 경우
    if(!cur.empty()){
        long long num = stoll(cur);
        if(isPrime(num)) answer++;
    }
    return answer;
}