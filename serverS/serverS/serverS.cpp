#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ws2tcpip.h>
#include <sstream>

#pragma warning(disable: 4996)

void InteractionWithClient(SOCKET Connection);
SOCKET makeConnection();

int main(int argc, char const* argv[])
{
	SOCKET socket = makeConnection();

	InteractionWithClient(socket);

	return 0;
}

void InteractionWithClient(SOCKET Connection) 
{
	//send(Connection, msg, sizeof(msg), NULL);
	//recv(Connection, msg, sizeof(msg), NULL);
	//recv, send, recv
	char msg[256];

	recv(Connection, msg, sizeof(msg), NULL);//get first message
	std::cout << msg << std::endl;

	std::string answer;
	std::cin >> answer;
	strcpy(msg, answer.c_str());
	send(Connection, msg, sizeof(msg), NULL);

	

	/*int msg_size;

	recv(Connection, (char*)&msg_size, sizeof(int), NULL);
	
	char *msg1 = new char[msg_size];

	recv(Connection, msg1, msg_size, NULL);
	*/
	char msg1[256];
	int i = 0;
	std::cout << i << std::endl;
	recv(Connection, (char*)&i, sizeof(int), NULL);

	std::cout << i << std::endl;
	std::cout << "That's end of program" << std::endl;

	delete[] msg1;

	//exit(0);
	
}

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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeofaddr);
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	if (newConnection == 0) {
		std::cout << "Error #2\n";
	}
	else {

		std::cout << "Client Connected!\n";
	}
	return newConnection;
}