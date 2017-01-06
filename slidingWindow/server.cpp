#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace std;

int main()
{
	int sockfd, portno, cfd;
	socklen_t lencli;
	char msg[] = "This is a sample message";
	struct sockaddr_in adserver, adclient;

	//Get data from user
	cout<<"Enter port number for connection : ";
	cin>>portno;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0){
		cout<<"Error creating socekt";
	}

	adserver.sin_family = AF_INET;
	adserver.sin_addr.s_addr = INADDR_ANY;
	adserver.sin_port = htons(portno);

	//Bind the socket
	if(bind(sockfd, (struct sockaddr *)&adserver, sizeof(adserver))<0){
		cout<<"Error binding socket";
	}

	listen(sockfd, 5);

	lencli = sizeof(adclient);

	cfd = accept(sockfd, (struct sockaddr *)&adclient, &lencli);
	if(cfd<0){
		cout<<"Error accepting connections ";
	}
	
	int n = send(cfd, msg, sizeof(msg),0);

	return 0;
}

