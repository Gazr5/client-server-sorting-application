#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#include <limits>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <algorithm>
#include <vector>

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include "client_connection_W.h"
#include "realization_and_interaction_W.h"
#else
#include "client_connection_L.h"
#include "realization_and_interaction_L.h"
#endif

#pragma warning(disable: 4996)

int main(int argc, char const* argv[])
{
	std::string path;
	std::cin >> path;
	auto files = getFileList(path);

	for (const auto& file : files) {
		std::cout << file.write() << "\n";
	}

	//SOCKET socket = makeConnection();
	//InteractionWithServer(socket);

	return 0;
}