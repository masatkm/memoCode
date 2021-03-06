// ConsoleApplication2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>

#define OUT_FILE_PATH "outfile.csv"

/// [string, string]
class MDataBase
{
private:
	std::map <std::string, std::string> data{};// ["column", "value"]のmapを作成
public:
	
	void insert(const std::string &key, const std::string &value) {
		data.insert(std::make_pair(key, value));// データ追加
	}

	void erase(const std:: string &key) {
		data.erase(key);//データ削除
	}


	int dataLen() {
		return data.size();
	}

	std::vector<std::string> split(char *c) {

		std::vector<std::string> spl;
		std::string tmp = "";

		while (*c !='\0')
		{
			if (*c != '_') {
				tmp += *c;
			}
			else {
				spl.push_back(tmp);
				tmp = "";
			}
			c++;
		}

		return spl;
	}

	/// 先頭から設定した階層だけ分割しない
	std::vector<std::string> splitRank(char *c, int setRank) {

		std::vector<std::string> spl;
		std::string tmp = "";
		int rank = 0;

		while (*c != '\0')
		{
			if (*c != '_') {
				tmp += *c;
			}
			else if (rank < setRank) {
				rank++;
				tmp += *c;
			}
			else {
				spl.push_back(tmp);
				tmp = "";
			}
			c++;
		}

		return spl;
	}

	void compare(FILE *fp, std::string key, std::string value) {

		try {
			if (data.at(key).compare(value)) {
				printf("%s,%s,match\n", key, value);
			}
			else {
				printf("%s,%s,not match\n", key, value);
			}
		}
		catch (_exception e){
			printf("%s,%s,not found\n", key, value);
		}


		

	}

	void fileOut(int max) {
		FILE *fp = fopen(OUT_FILE_PATH, "a");

		if (fp == NULL) {
			printf("FILE OPEN ERROR.\n");
			exit(1);
		}

		for (int i = 0; i < max; i++) {
			compare(fp, "key", "value");
		}

		fclose(fp);
	}

};


int main()
{
    std::cout << "Hello World!\n"; 

	std::map <std::string, std::string> dataBase{};

	
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
