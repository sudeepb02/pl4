#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

using namespace std;

int main()
{
	int sockfd, portno, cfd, ws;
	socklen_t lencli;
	char msg[] = "This is a sample message";
	struct sockaddr_in adserver, adclient;

	//Get data from user
	cout<<"Enter port number for connection : ";
	cin>>portno;
	cout<<"Enter window size : ";
	cin>>ws;

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

	//Transmitting data
	int sf, lf, cf, n;
	char ack[2],data[2];
	sf = cf = 0;	//Initialize starting and current frame index to 0;
	lf = ws-1;
	int len = strlen(msg)-1;

	cout<<"Total number of packets to be sent : "<<len<<endl;
	cout<<"============================="<<endl;
	data[0] = len;
	n = send(cfd, data, 1, 0);

	while(cf < len){
		while(cf<=lf){
			data[0] = msg[cf];
			n = send(cfd, data, 1, 0);
			cout<<"Packet "<<cf<<" sent "<<endl;
			cf++;
		}
		n = recv(cfd, ack, 1, 0);
		data[0] = msg[sf];
		if(strcmp(ack,data)!=0){
			cf = sf;
		}
		else{
			cout<<"Acknowledgement for packet "<<sf<<" received "<<endl;
			sf++;
			lf++;
		}
	}
	return 0;
}

