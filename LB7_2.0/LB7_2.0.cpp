#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include "list.h"

int main(){
	 setlocale(LC_ALL, "RUS");

	CList<int> list_int;
    CList<double> list_double;
    CList<char*> list_char;
	CList<Clist> list_list;

	char *String="";
	
	int val;
	double d_val;
	char* i_val="";
	int key, key1, key2, key3, key4, key5,key6, key7, key8, key9, key10, key11;
	
	Clist my_list;
		cout<<"1-�������� � int"<<endl;
		cout<<"2-�������� � double"<<endl;
		cout<<"3-�������� � char*"<<endl;
		cout<<"4-�������� � list"<<endl;
		key=_getch();
		switch (key){
			case '1':
			do{
					cout<<"1-��������� ������"<<endl;
					cout<<"2-������������ ������"<<endl;
					cout<<"3-������� �������� �������"<<endl;
					cout<<"4-������� ������"<<endl;
					key1=_getch();
					switch (key1){
						case '1':
							do{
							cout<<"������� int:"<<endl;
							cin>>val;
							list_int.AddItem(val);
							cout<<"�������� ��� �������?"<<endl;
							key2=_getch();
							}
							while(key2!=27);
							break;
						case '2':
							list_int.DisplayList();
							break;
						case '3':
							list_int.DeleteFirstNotOdd();
							break;
						case '4':
							list_int.ReleaseList();
							break;	
					}
				}
				while(key1!=27);
				break;	
			case '2':
				do{
					cout<<"1-��������� ������"<<endl;
					cout<<"2-������������ ������"<<endl;
					cout<<"3-������� �������� �������"<<endl;
					cout<<"4-������� ������"<<endl;
					key3=_getch();
					switch (key3){
						case '1':
							do{
							cout<<"������� double:"<<endl;
							cin>>d_val;
							list_double.AddItem(d_val);
							cout<<"�������� ��� �������?"<<endl;
							key4=_getch();
							}
							while(key4!=27);
							break;
						case '2':
							list_double.DisplayList();
							break;
						case '3':
							list_double.DeleteFirstNotOdd();
							break;
						case '4':
							list_double.ReleaseList();
							break;	
					}
				}
				while(key3!=27);
				break;
		case '3':
				do{
					cout<<"1-��������� ������"<<endl;
					cout<<"2-������������ ������"<<endl;
					cout<<"3-������� �������� �������"<<endl;
					cout<<"4-������� ������"<<endl;
					key5=_getch();
					switch (key5){
						case '1':
							do{
								String = (char*)malloc(10);
							cin>>String;
							
							list_char.AddItem(String);
							cout<<"�������� ��� �������?"<<endl;
							key6=_getch();
							}
							while(key6!=27);
							break;
						case '2':
							list_char.DisplayList();
							break;
						case '3':
							list_char.DeleteFirstNotOdd();
							break;
						case '4':
							list_char.ReleaseList();
							break;	
					}
				}
				while(key5!=27);
				break;	
		case '4':
			do{		    
					cout<<"1-��������� ������"<<endl;
					cout<<"2-������������ ������"<<endl;
					cout<<"3-������� �������� �������"<<endl;
					cout<<"4-������� ������"<<endl;
					key7=_getch();
					switch (key7){
						case '1':
							do{
								my_list.ReleaseList();
								cin>>my_list;
								list_list.AddItem(my_list);
								cout<<"�������� ��� ���� ������ � ������?";
								key8=_getch();
							}
							while(key8!=27);
							break;
						case '2':
							cout<<list_list;
							break;
						case '3':
							list_list.DeleteFirstNotOdd();
							break;
						case '4':
							list_list.ReleaseList();
							break;
					}
				}
				while(key7!=27);
				break;				
				}while(key!=27);		
	system("pause");
	return 0;
	}
	
	
	


