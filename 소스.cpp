#include<iostream>
#include<iomanip>
#include<fstream>
#include<cassert>
#include<vector>
using namespace std;

class Prg {
	string name;
	int score[4];
public:
	Prg(string name, int score[]) {
		this->name = name;
		for (int i = 0; i < 4; i++)this->score[i] = score[i];
	}
	string GetName() { return name; }
	int* GetScore() { return score; }
};

int main() {

	vector<Prg> std;
	int select;
	string name;
	int score[4];
	double total = 0;

	while (1) {
		cout << "\n--------------------메뉴--------------------\n";
		cout << "1. 성적입력\n" << "2. 전체 성적\n" << "3. 전체 성적 저장\n" << "4. 프로그램 종료\n";
		cout << "--------------------------------------------\n\n";
		cout << "원하는 작업의 번호를 입력하세요 : ";
		cin >> select;
		switch (select) {
		case 1: {
			cout << "이름(공백없이), 중간, 퀴즈, 기말 점수를 입력하세요 : ";
			cin >> name >> score[0] >> score[1] >> score[2];
			score[3] = 0;
			for (int i = 0; i < 3; i++)score[3] += score[i];
			total += score[3];
			Prg s(name, score);
			std.push_back(s);
			cout << "학생 성적이 올바르게 입력되었습니다.\n";
			break;
		}
		case 2: {
			cout <<"               =계절학기 성적=               "<< "\n";
			cout << left << setw(8) << "학번";
			cout << setw(8) << "이름";
			cout << setw(8) << "중간";
			cout << setw(8) << "퀴즈";
			cout << setw(8) << "기말";
			cout << setw(8) << "총점";
			cout << "\n";
			for (int i = 0; i < std.size(); i++) {
				cout << setw(8) << i;
				cout << setw(8) << std[i].GetName();
				cout << setw(8) << *(std[i].GetScore());
				cout << setw(8) << *(std[i].GetScore()+1);
				cout << setw(8) << *(std[i].GetScore()+2);
				cout << setw(8) << *(std[i].GetScore()+3);
				cout << "\n";
			}
			cout << "\n전체 평균 : " << fixed << setprecision(2) << total / std.size() << "\n";
			break;
		}
		case 3: {
			fstream fs("abc.txt",ios::out);
			if (fs.is_open()) {
				fs << "               =계절학기 성적=               " << "\n";
				fs << left << setw(8) << "학번";
				fs << setw(8) << "이름";
				fs << setw(8) << "중간";
				fs << setw(8) << "퀴즈";
				fs << setw(8) << "기말";
				fs << setw(8) << "총점";
				fs << "\n";
				for (int i = 0; i < std.size(); i++) {
					fs << left << setw(8) << i;
					fs << setw(8) << std[i].GetName();
					fs << setw(8) << *(std[i].GetScore());
					fs << setw(8) << *(std[i].GetScore() + 1);
					fs << setw(8) << *(std[i].GetScore() + 2);
					fs << setw(8) << *(std[i].GetScore() + 3);
					fs << "\n";
				}
				fs << "\n전체 평균 : " << fixed << setprecision(2) << total / std.size();
				cout << "텍스트 파일이 저장되었습니다.";
			}
			else assert(0);
			break;
		}
		case 4:
			return 0;
		}
	}
}