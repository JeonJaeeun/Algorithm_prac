#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 1000000

int prime_num[MAX + 1]; //소수 여부 확인 (0: 소수 아님, 1: 소수)
vector<int> prime; //소수 목록 저장

void primeCheck(){
    //2부터 MAX까지 소수라고 가정
    for(int i = 2; i <= MAX; i++){
        prime_num[i] = i;
    }

    for(int i = 2; i <= sqrt(MAX); i++){
        //현재 숫자가 소수라면
        if(prime_num[i] != 0){
            //i의 배수들 소수 목록에서 제거
            for(int j = i * i; j <= MAX; j += i){
                prime_num[j] = 0; // j는 소수가 아님
            }
        }
    }

    //prime_num에서 소수들만 prime 벡터에 저장
    for(int i = 2; i <= MAX; i++){
        if(prime_num[i] != 0){
            prime.push_back(prime_num[i]);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    primeCheck();
    int test_n;

    while(1){
        cin >> test_n;
        if(test_n == 0){
            break;
        }

        bool flag = false; //추측이 맞는지 여부

        //소수 목록 탐색 -> 소수 합이 test_n이 되는지 확인
        for(int i = 0; i < prime.size(); i++){
            // test_n - prime[i]가 소수인지 확인
            if(prime_num[test_n - prime[i]] == test_n - prime[i]){
                cout << test_n << " = " << prime[i] << " + " << test_n - prime[i] << '\n';
                flag = true;
                break;
            }
        }

        if(!flag){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}