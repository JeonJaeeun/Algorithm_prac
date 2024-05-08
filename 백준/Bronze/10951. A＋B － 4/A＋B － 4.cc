/*A+B-4*/

/*
   더이상 읽을 수 있는 데이터가 없는 경우, 
   즉 파일의 끝일 때 이를 EOF(End Of File)이라고 한다.
*/

#include <iostream>

using namespace std;

int main() {
	int a, b;
	
	while (true) {
		cin >> a >> b;
		
		if (cin.eof() == true)
			break;

		cout << a + b << endl;
	}
}