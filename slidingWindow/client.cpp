#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
using namespace std;

int main()
{
	int sockfd, portno, n;
	struct sockaddr_in adserver;
	struct hostent *server;
	char hostname[50];
//	char data;
	
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

	//Receiving data 
	int len;
	char data[2];
	n = recv(sockfd, data, 1, 0);
	data[1] = '\0';
	len = 23;
	cout<<"Total bytes to be received : "<<len;
	int cf=0;
	char* finalmsg;
	finalmsg[0] = '\0';

	while(cf<=len){
		n = recv(sockfd, data, 1, 0);
		data[1] = '\0';
		cout<<"Data packet "<<cf<<" received"<<endl;
		strcat(finalmsg, data);
		send(sockfd, data, 1, 0);
		cf++;
	}
	cout<<finalmsg;
	return 0;
}


	
