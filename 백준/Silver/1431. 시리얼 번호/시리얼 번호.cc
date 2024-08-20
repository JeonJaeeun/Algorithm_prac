#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문자열에서 숫자만 더하는 함수
int numSum(string a){
    int sum = 0;

    for(int i = 0; i < a.length(); i++){
        if(a[i] -'0' <= 9 && a[i] - '0' >= 0){
            sum += a[i] - '0';
        }
    }

    return sum;
}

bool compare(string a, string b){
    //1. 길이가 짧은 것이 먼저
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    else{
        //2. 숫자 합이 작은 것이 먼저저
        int a_sum = numSum(a);
        int b_sum = numSum(b);

        if(a_sum != b_sum){
            return a_sum < b_sum;
        }
        else{
            //3. 사전 순
            return a < b;
        }
    }
}

int main(){

    int n;
    cin >> n;
    
    string input;
    vector<string> guitar;

    for(int i = 0; i < n ;i++){
        cin >> input;
        guitar.push_back(input);
    }

    sort (guitar.begin(), guitar.end(), compare);

    for(int i = 0; i < n; i++){
        cout << guitar[i] << '\n';
    }
}