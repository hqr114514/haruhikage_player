#include <bits/stdc++.h>
#include <thread>
#include <windows.h>
#include <mmsystem.h>
#include "resource.h"
#pragma comment(lib,"winmm.lib")
using namespace std;

bool readfile(int ID, LPCWSTR type, const char* filename) {
	HRSRC hResource = FindResource(NULL, MAKEINTRESOURCE(ID), type);
	HGLOBAL hGlobal = NULL;
	unsigned long long siz = 0;

	if (hResource) hGlobal = LoadResource(NULL, hResource);
	else return 1;

	if (hGlobal) siz = SizeofResource(NULL, hResource);
	else return 1;

	void* buf = LockResource(hGlobal);
	ofstream fout(filename, ios::out | ios::binary);
	fout.write((char*)buf, siz);
	fout.close();
	return 0;
}

void DNA() {
	cout << "为什么要演奏春日影?\nなんで「春日影」やったの?\n";
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_SYNC | SND_RESOURCE);
	return;
}

int main() {
	thread run(DNA);
	if (readfile(IDR_F1, L"F", "data.mp4")) {
		cout << "error! cannot read flac file." << endl;
		return -1;
	}
	if (readfile(IDR_F2, L"F", "ffplay.exe")) {
		cout << "error! cannot read ffplay." << endl;
		return -1;
	}
	run.join();
	system("ffplay -autoexit -fs data.mp4");
	system("del ffplay.exe");
	system("del data.mp4");
	return 0;
}