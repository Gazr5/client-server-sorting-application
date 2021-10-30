#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <sys/stat.h>

//#include <limits>
//#include <cstdio>
#include <iostream>
//#include <fstream>
//#include <bitset>
//#include <string>
//#include <algorithm>
//#include <vector>

//#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>

#pragma warning(disable: 4996)

SOCKET makeConnection();

SOCKET makeConnection()
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(8080);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: Failed connect to server.\n";
		return Connection;
	}
	std::cout << "Connected!\n";

	return Connection;
}