//2941

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	vector<string> list = { "c=", "c-","dz=","d-","lj","nj","s=","z=" };

	//목록에 있으면 목록 문자를 1개로 count -> 목록문자를 하나의 문자 a로 치환
	//목록에 없으면 문자 하나당 1개로 count

	for (int i = 0; i < list.size(); i++) {
		while (1) {
			//s의 목록 문자를 a로 치환
			//replace(위치, 찾아야할 문자열의 길이, 교체할 새로운 문자열)
			int pos = s.find(list[i]);

			if (pos == std::string::npos)
				break;
			s.replace(pos, list[i].length(), "a");
		}
	}

	cout << s.length();
}