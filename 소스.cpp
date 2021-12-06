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
		cout << "\n--------------------�޴�--------------------\n";
		cout << "1. �����Է�\n" << "2. ��ü ����\n" << "3. ��ü ���� ����\n" << "4. ���α׷� ����\n";
		cout << "--------------------------------------------\n\n";
		cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";
		cin >> select;
		switch (select) {
		case 1: {
			cout << "�̸�(�������), �߰�, ����, �⸻ ������ �Է��ϼ��� : ";
			cin >> name >> score[0] >> score[1] >> score[2];
			score[3] = 0;
			for (int i = 0; i < 3; i++)score[3] += score[i];
			total += score[3];
			Prg s(name, score);
			std.push_back(s);
			cout << "�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";
			break;
		}
		case 2: {
			cout <<"               =�����б� ����=               "<< "\n";
			cout << left << setw(8) << "�й�";
			cout << setw(8) << "�̸�";
			cout << setw(8) << "�߰�";
			cout << setw(8) << "����";
			cout << setw(8) << "�⸻";
			cout << setw(8) << "����";
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
			cout << "\n��ü ��� : " << fixed << setprecision(2) << total / std.size() << "\n";
			break;
		}
		case 3: {
			fstream fs("abc.txt",ios::out);
			if (fs.is_open()) {
				fs << "               =�����б� ����=               " << "\n";
				fs << left << setw(8) << "�й�";
				fs << setw(8) << "�̸�";
				fs << setw(8) << "�߰�";
				fs << setw(8) << "����";
				fs << setw(8) << "�⸻";
				fs << setw(8) << "����";
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
				fs << "\n��ü ��� : " << fixed << setprecision(2) << total / std.size();
				cout << "�ؽ�Ʈ ������ ����Ǿ����ϴ�.";
			}
			else assert(0);
			break;
		}
		case 4:
			return 0;
		}
	}
}