#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define SIZECHAR 50

enum menu {EXIT, ADD_STUDENT, PRINT_STUDENT,
		   PRINT_ALL_STUDENT, WRITE_INTO_FILE,
		   CLEAR_FILE};

void f()
{
	
}

struct StudentBaseDate 
{
    int id; 
	char group[SIZECHAR];
	char surname[SIZECHAR];
    char name[SIZECHAR];
	char Credit�ard[SIZECHAR];
	double stipend;
	double SumStipend;
	double MTotalCash;
	double STotalCash;
    StudentBaseDate* next; 
};


void _tmain()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int Menu();
	int CmdMenu;
	std::cout << "|===========================================|" 
			  << std::endl;
	std::cout << "| ��������� �� ��������			    |" 
			  << std::endl;
	std::cout << "| ����: \"����������� ���������.\"	    |"
			  << std::endl;
	std::cout << "| ��������������� ����������	            |" 
			  << std::endl;
	std::cout << "| ��� �������� ��������� ���������.         |" 
			  << std::endl;
	std::cout << "| ��������� �������� ������ ���-101         |"
			  << std::endl;
	std::cout << "| ����� �.�."" �������� �.�."
				 " ����������� �.�. ""|"
			  << std::endl;
	std::cout<< "|===========================================|";

	do
	{
		CmdMenu = Menu();
		switch (CmdMenu)
		{
			case EXIT:
				return;
				break;
			
		}
	}while(true);
	system("pause");
}

int Menu()
{
	unsigned int NumberCmdMenu;
	
		for(;;)
		{
			std::cout << std::endl;
			std::cout 
			<< "|===========================================|" 
			<< std::endl;
			std::cout 
			<< "|                   ����                    |" 
			<< std::endl;
			std::cout 
			<< "|0 - ��������� ������                       |" 
			<< std::endl;
			std::cout 
			<< "|1 - �������� ��������			    |" 
			<< std::endl;
			std::cout 
			<< "|2 - ������� ���������� �� ��������         |" 
			<< std::endl;
			std::cout 
			<< "|3 - ������� ���� ���������                 |" 
			<< std::endl;
			std::cout 
			<< "|4 - C��������, ������� � ����              |" 
			<< std::endl;
			std::cout 
			<< "|===========================================|" 
			<< std::endl;
			std::cout << "����: ";
			NumberCmdMenu = _getch() - '0';
		if(NumberCmdMenu < EXIT ||
		   NumberCmdMenu > WRITE_INTO_FILE)
		{
			std::cout<< "������ - ����� ������� ���" 
			<< std::endl;
			continue;
		}
		else
		{
			std::cout <<"����� ������� ����: ";
			std::cout << NumberCmdMenu <<std::endl;
			return NumberCmdMenu;
		}
	return NumberCmdMenu;
	}
}