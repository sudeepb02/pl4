#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace std;

int main()
{
	int sockfd, portno, n;
	struct sockaddr_in adserver;
	struct hostent *server;
	char hostname[50];
	char data[256];
	
	//Get data from user
	cout<<"Enter port number : ";
	cin>>portno;
	cout<<"Enter host name : ";
	cin>>hostname;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		cout<<"Error creating socket";
	}
	

/*	server = gethostbyname(hostname);
	if(server==NULL){
		cout<<"Error locating host ";
	}
*/
	adserver.sin_family = AF_INET;
	adserver.sin_port = htons(portno);

	if(connect(sockfd, (struct sockaddr*)&adserver,sizeof(adserver))<0){
		cout<<"Error connecting to server";
	}

	n = recv(sockfd, data, 256, 0);
	cout<<data;
	return 0;
}


	
