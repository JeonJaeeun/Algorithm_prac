#include <iostream>

using namespace std;

int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main(){
    int first_num, first_den; //첫번째 분자 분모
    int second_num, second_den; //두번째 분자 분모
    int num, den; // 더한 후 분자 분모

    cin >> first_num >> first_den;
    cin >> second_num >> second_den;

    den = first_den * second_den;
    num = first_num * second_den + second_num * first_den;

    // num, den의 최대공약수로 나누기
    int g;
    g = gcd(num, den);
    cout << num / g << " " << den / g;

}