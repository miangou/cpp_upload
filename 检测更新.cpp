#include <iostream>
#include <cmath>
#include <cstdio>
#include <windows.h>
#include <fstream>
using namespace std;
int version = -999, linemode;

void in_one( char *s1, const char *s2 );//��ǰ����
void read() {//��ȡ�汾��ģ��
	ifstream infile;
	infile.open("version.dat");
	infile >> version;
	infile.close();
	system("del version.dat");
	system("cls");
}

int upload() {//������ģ��
	int yn = 3;
	int v = 001;
	//ʹ��curl��ȡ�汾��
	system("del version.dat");
	system("cls");
	//on_offline();
	system("curl me.miangou.xyz/update.txt > version.dat");
	system("cls");
	read();
	_sleep(1000);
	if (version == 0) {
		cout << "����δ����:(" << endl;
		system("pause");
		return 0;
	}
	if (version < 10) {
		cout << "����������:)" << endl;
		cout << "���°汾:00" << version << endl;;
	} else if (version < 100) {
		cout << "����������:)" << endl;
		cout << "���°汾:0" << version << endl;
	} else {
		cout << "����������:)" << endl;
		cout << "���°汾:" << version << endl;
	}
	if (v < 10) {
		cout << "���ذ汾:00" << v << endl;;
	} else if (v < 100) {
		cout << "���ذ汾:0" << v << endl;
	} else {
		cout << "���ذ汾:" << v << endl;
	}
	if (v > version) {
		cout << "�������:(" << endl;
		return 0;
	} else if (v == version) {
		cout << "��ϲ�����İ汾�����°汾 :)" << endl;
	} else if (v < version) {
		cout << "���°汾���Ը��£�" << endl << "��/��������(1/2)" << endl;
		cin >> yn;
	}
	return yn;
}



int update(int yn) {//�Զ�����ģ��

	if (yn == 1) {
		//�ϲ��ַ�������wget
		char dlv[100];//���ذ汾
		_itoa(version, dlv, 100);//int to char
		char http[1000] = "echo wget -O ������.exe me.miangou.xyz/dl/"; //���ص�api
		char _exe[100] = ".exe >>ti.bat";
		in_one( http, dlv );//�ϲ��ַ�������
		in_one( http, _exe );//�ϲ��ַ�������
		system(http);//����
		cout << http << endl;
		system("echo start ������.exe>>ti.bat");
		system("echo del ti.bat>>ti.bat");
		system("ti.bat");




	} else if (yn == 2) {
		system("pause");
		return 0;
	}
	system("pause");
}

//�ϲ�char�ַ���ģ��
void in_one( char *s1, const char *s2 ) {
	while ( *s1 != '\0' )
		s1++;

	for ( ; *s1 = *s2; s1++, s2++ )
		; // empty statement
}

//�����ļ���Ƿ�����ģ��
//int on_offline() {
//	system("start ping me.miangou.xyz -n 2\" | findstr /i \"TTL\" >nul 2>nul && echo 1>version.dat || echo 2>version.dat");
//}

int main() {
	system("del ti.bat&cls");
	system("echo @echo off>ti.bat");
	system("echo taskkill /f /im ������.exe >>ti.bat");
	int yn = upload();
	update(yn);
	return 0;
}
