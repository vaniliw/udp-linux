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

	bind(sock,(struct sockaddr*)&addr,sizeof(addr));
	cout<<"Configured!"<<endl;

	char buf[100];
	int addrlen=sizeof(addr);
	int reciv=recvfrom(sock,buf,100,0,(struct sockaddr*)&addr,(socklen_t*)&addrlen);
	cout<<buf;
	sendto(sock,"salam",5,0,(struct sockaddr*)&addr,addrlen); //5 OR  strlen

}


















