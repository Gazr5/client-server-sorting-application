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

std::vector<std::string> getFileList(std::string DATA_DIR) {

	//std::string s = "cd " + DATA_DIR;
	//char command[50] = s;
	//system(command);
	std::vector<std::string> s;
	char command[50] = "ls -l";
	system(command);
	getline(std::cin, s[s.size()]);
	

	std::vector<File> files;
	

	for (size_t i = 0; i < s.size(); i++) {

	}

	
}

void InteractionWithServer(int Connection) {



}