/* C++ Program - Read a File */
		
#include<iostream>
#include<conio>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
void main()
{
	clrscr();
	char c[1000];
	ifstream ifile;
	ifile.open("filename.txt") ;
	if(!ifile)
	{
		cout<<"Error in opening file..!!";
		getch();
		exit(1);
	}
	cout<<"Data in file = ";
	while(ifile.eof()==0)
	{
		ifile>>c;
		cout<<c<<" ";
	}
	ifile.close();
	getch();
}