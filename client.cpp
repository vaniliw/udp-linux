#include <iostream>
#include <string>
#include <ctime>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

using namespace std;
//-----------------
int main()
{
	int sock=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr;
	addr.sin_port=htons(2770);
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=INADDR_ANY;

	int addrlen=sizeof(addr);
	char buf[100]="ABCD";
	sendto(sock,buf,5,0,(struct sockaddr*)&addr,addrlen);
	cout<<"PACKET SENDED!";
	recvfrom(sock,buf,5,0,(struct sockaddr*)&addr,(socklen_t*)&addrlen);
	cout<<"recived:"<<buf; //&buf

}