#include <iostream>
#include <cmath>
#include <cstdio>
#include <windows.h>
#include <fstream>
using namespace std;
int version = -999, linemode;

void in_one( char *s1, const char *s2 );//提前声明
void read() {//读取版本号模块
	ifstream infile;
	infile.open("version.dat");
	infile >> version;
	infile.close();
	system("del version.dat");
	system("cls");
}

int upload() {//检测更新模块
	int yn = 3;
	int v = 001;
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
	return yn;
}



int update(int yn) {//自动更新模块

	if (yn == 1) {
		//合并字符串用于wget
		char dlv[100];//下载版本
		_itoa(version, dlv, 100);//int to char
		char http[1000] = "echo wget -O 检测更新.exe me.miangou.xyz/dl/"; //下载得api
		char _exe[100] = ".exe >>ti.bat";
		in_one( http, dlv );//合并字符串函数
		in_one( http, _exe );//合并字符串函数
		system(http);//下载
		cout << http << endl;
		system("echo start 检测更新.exe>>ti.bat");
		system("echo del ti.bat>>ti.bat");
		system("ti.bat");




	} else if (yn == 2) {
		system("pause");
		return 0;
	}
	system("pause");
}

//合并char字符串模块
void in_one( char *s1, const char *s2 ) {
	while ( *s1 != '\0' )
		s1++;

	for ( ; *s1 = *s2; s1++, s2++ )
		; // empty statement
}

//废弃的检测是否在线模块
//int on_offline() {
//	system("start ping me.miangou.xyz -n 2\" | findstr /i \"TTL\" >nul 2>nul && echo 1>version.dat || echo 2>version.dat");
//}

int main() {
	system("del ti.bat&cls");
	system("echo @echo off>ti.bat");
	system("echo taskkill /f /im 检测更新.exe >>ti.bat");
	int yn = upload();
	update(yn);
	return 0;
}
