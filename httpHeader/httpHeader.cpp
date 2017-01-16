#include<iostream>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<string.h>
using namespace std;

int main()
{
	char cmd;
	cout<<"================================"<<endl;
	cout<<"HTTP HEADER"<<endl;
	cout<<"================================"<<endl;

	system("curl -v http://google.com > header.txt 2>&1");

	ifstream fd;
	fd.open("header.txt", ios::in);
	string line;
	cout<<"REQUEST MESSAGE"<<endl;

	do
	{
			getline(fd, line);

			if((line.find("User-Agent",0))!=string::npos){
				cout<<line<<endl;
			}
			if((line.find("GET",0))!=string::npos){
				cout<<"METHOD :\t GET"<<endl;
			}
			else if((line.find("POST",0))!=string::npos){
				cout<<"METHOD :\t POST"<<endl;
			}
			else if((line.find("HTTP/1.1",0))!=string::npos){
				cout<<"HTTP version :\t1.1"<<endl;
			}
			if((line.find("Host",0))!=string::npos){
				cout<<line<<endl;
			}

	}while(!fd.eof());
	fd.close();

	fd.open("header.txt", ios::in);
	cout<<"==================================="<<endl;
	cout<<"HTTP RESPONSE"<<endl;
	cout<<"===================================="<<endl;
	do
	{
		getline(fd,line);

		if((line.find("HTTP/1.1",0))!=string::npos){
			cout<<"HTTP version :\t1.1"<<endl;
		}

		if((line.find("Found",0))!=string::npos){
			cout<<"Status code :\t"<<line<<endl;
		}

		if((line.find("Date",0))!=string::npos){
			cout<<"Request received on :\t"<<line<<endl;
		}

		if((line.find("Server",0))!=string::npos){
			cout<<"Server :\t"<<line<<endl;
		}

		if((line.find("Location",0))!=string::npos){
			cout<<line<<endl;
		}

		if((line.find("Content-Language",0))!=string::npos){
			cout<<"Content-Language :\t"<<line<<endl;
		}

		if((line.find("Content-Type",0))!=string::npos){
			cout<<line<<endl;
		}

		if((line.find("Content-Length",0))!=string::npos){
			cout<<line<<endl;
		}
	}while(!fd.eof());

	fd.close();

	return 0;
}
