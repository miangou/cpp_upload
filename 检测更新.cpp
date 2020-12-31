#include <iostream>
#include <cmath>
#include <cstdio>
#include <windows.h>
#include <fstream>
using namespace std;
int version = -999, linemode;

void read() {
	ifstream infile;
	infile.open("version.dat");
	infile >> version;
	infile.close();
	system("del version.dat");
	system("cls");
}

//
//int on_offline() {
//	system("start ping me.miangou.xyz -n 2\" | findstr /i \"TTL\" >nul 2>nul && echo 1>version.dat || echo 2>version.dat");
//}

int main() {
	int v = 001;
	int yn = 3;
	//使用curl获取版本号
	system("del version.dat");
	system("cls");
	//on_offline();
	system("curl me.miangou.xyz/update.txt > version.dat");
	system("cls");
	read();
	_sleep(1000);
	if (version == 0) {
		cout << "网络未连接:(" << endl;
		system("pause");
		return 0;
	}
	if (version < 10) {
		cout << "网络已连接:)" << endl;
		cout << "最新版本:00" << version << endl;;
	} else if (version < 100) {
		cout << "网络已连接:)" << endl;
		cout << "最新版本:0" << version << endl;
	} else {
		cout << "网络已连接:)" << endl;
		cout << "最新版本:" << version << endl;
	}
	if (v < 10) {
		cout << "本地版本:00" << v << endl;;
	} else if (v < 100) {
		cout << "本地版本:0" << v << endl;
	} else {
		cout << "本地版本:" << v << endl;
	}
	if (v > version) {
		cout << "网络错误:(" << endl;
		return 0;
	} else if (v == version) {
		cout << "恭喜，您的版本是最新版本 :)" << endl;
	} else if (v < version) {
		cout << "有新版本可以更新！" << endl << "是/否升级？(1/2)" << endl;
		cin >> yn;
	}

	if (yn == 1) {
		system("wget -P ./download me.miangou.xyz/update.txt ");
	} else if (yn == 2) {
		system("pause");
		return 0;
	}
	system("pause");

	return 0;
}
