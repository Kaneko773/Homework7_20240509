// Homework7_20240509.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> flags(8);
string symptoms[8] = {
	"熱がある",
	"頭が痛い",
	"お腹が痛い",
	"喉が痛い",
	"体がだるい",
	"めまいがする",
	"咳が出る",
	"くしゃみが出る"
};
string conditions[2] = {
	"あなたは健康体です",
	"あなたの体は最悪の状態です"
};

int flag_Set(int x) {
	return 1 << x;
}

void Show(int condi) {
	system("cls");
	int symptomNum = 0;
	for (int i = 0; i < 8; ++i) {
		if (condi & (1 << i)) {
			if (symptomNum == 0)cout << endl << "あなたの今の症状は " << flush;
			cout << symptoms[i] << ",";
			++symptomNum;
		}
	}cout << endl;
	if (symptomNum == 0) cout << conditions[0] << endl;
	if (symptomNum == 8) cout << conditions[1] << endl;
	cout << endl;
}

void Symptoms_Update(int& condi) {
	bool conti = true;
	do {
		Show(condi);
		int input;
		cout << "1:熱がある\n2:頭が痛い\n3:お腹が痛い\n4:喉が痛い\n5:体がだるい\n\
6:めまいがする\n7:咳が出る\n8:くしゃみが出る\n9:終了\n\n症状を入力(再入力で症状を消せます)　＞　" << flush;
		cin >> input;
		switch (input)
		{
		case 1:
		case 2:
		case 3:
		case 4: 
		case 5:
		case 6:
		case 7:
		case 8:
			(condi & flags[input - 1]) ? condi &= ~flags[input - 1] : condi |= flags[input - 1];
			break;
		case 9: conti = false; break;
		default: break;
		}
	} while (conti);
}

int main()
{
	for (int i = 0; i < flags.size(); ++i) {
		flags[i] = flag_Set(i);
	}

	int condition_flags = 0;

	bool conti = true;
	do {
		Show(condition_flags);
		int input;
		cout << "１：症状の更新　２：終了　＞　" << flush;
		cin >> input;
		switch (input)
		{
		case 1: Symptoms_Update(condition_flags); break;
		case 2: conti = false;  break;
		default: break;
		}
	} while (conti);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
