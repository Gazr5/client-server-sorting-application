#pragma once
//#include <stdlib.h>
//#include <stdio.h>
//#include <sys/stat.h>

//#include <limits>
//#include <cstdio>
#include <iostream>
//#include <fstream>
//#include <bitset>
#include <string>
//#include <algorithm>
#include <vector>

#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>

#include "file_struct.h"

std::vector<File> getFileList(std::string DATA_DIR)
{
	DATA_DIR += "\\*";

	HANDLE hFind;
	FILETIME ftCreate;
	SYSTEMTIME stUTC;
	WIN32_FIND_DATAA data;

	hFind = FindFirstFileA(DATA_DIR.c_str(), &data);

	std::vector<File> result;

	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			printf("%s\n", data.cFileName);

			GetFileTime(hFind, &ftCreate, NULL, NULL);
			FileTimeToSystemTime(&ftCreate, &stUTC);

			File file;
			std::string name = data.cFileName;
			std::cout << "_1" << std::endl;
			if (name != "." && name != "..") {
				if (find(name.begin(), name.end(), '.') != name.end()) {
					std::cout << "_2" << std::endl;
					copy(name.begin(), find(name.begin(), name.end(), '.'), file.name.begin());
					std::cout << "_3" << std::endl;
					copy(find(name.begin(), name.end(), '.'), name.end(), file.extension.begin());
					std::cout << "_4" << std::endl;
					file.is_file = false;
					std::cout << "_5" << std::endl;
					file.date = Date(stUTC.wYear, stUTC.wMonth, stUTC.wDay, stUTC.wHour, stUTC.wMinute);
					std::cout << "_6" << std::endl;
				}
				else {
					file.is_file = true;
					file.files = getFileList(DATA_DIR + "\\" + file.name);
				}

				result.push_back(file);
			}

		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}

	return std::vector<File>(result.begin(), result.end());
}

void InteractionWithServer(SOCKET Connection) {
	//send(newConnection, msg, sizeof(msg), NULL);
	//recv(newConnection, msg, sizeof(msg), NULL);
	char msg[256] = "Write full path to directory for sorting or just press Enter for Client path";
	send(Connection, msg, sizeof(msg), NULL);
	char msg1[256];

	recv(Connection, msg1, sizeof(msg1), NULL);

	std::string path;
	if (msg1 == "") {
		path = __FILE__;
	}
	else {
		path = msg1;
	}
	
	std::vector<File> files = getFileList(path);
	
	int fileCount = 0;

	for (const auto& file : files) {
		if (file.is_file) fileCount += file.files.size();
		else fileCount++;
	}

	std::cout << fileCount << std::endl;

	send(Connection, (char*)&fileCount, sizeof(int), NULL);
	

	/*
	int msg_size = sFiles.size();
	std::cout << msg_size << std::endl;
	send(Connection, (char*)&msg_size, sizeof(int), NULL);
	send(Connection, sFiles.c_str(), msg_size, NULL);
	*/
	/*
	if (sFiles == "") {
		std::string msg = "There are no files in the folder, so I won't sort anything";
		int msg_size = msg.size();
		send(Connection, (char*)&msg_size, sizeof(int), NULL);
		send(Connection, msg, msg_size, NULL);
	}
	else {
		int msg_size = sFiles.size();
		std::cout << msg_size << std::endl;
		send(Connection, (char*)&msg_size, sizeof(int), NULL);
		send(Connection, sFiles.c_str(), msg_size, NULL);
	}
	*/
}