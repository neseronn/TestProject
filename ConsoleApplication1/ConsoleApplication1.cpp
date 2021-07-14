#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>

#define SIZECHAR 50

enum menu {EXIT, ADD_STUDENT, PRINT_STUDENT,
		   PRINT_ALL_STUDENT, WRITE_INTO_FILE};

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

void ReadFromFile(StudentBaseDate* head);
void WriteIntoFile(StudentBaseDate* head);

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

	StudentBaseDate* head = new StudentBaseDate; 
    head->next = NULL;
    head->id = 0;
    ReadFromFile(head);

	// комент
	

	do
	{
		CmdMenu = Menu();
		switch (CmdMenu)
		{
			case EXIT:
				return;
				break;
			case PRINT_ALL_STUDENT:
			{
				StudentBaseDate* buffer = head->next;  
				while (buffer->next != NULL)
				// ���� �� ����� �� ����������
				{
					std::cout << std::endl;
					std::cout << "id - " << buffer->id 
					<< std::endl;
					std::cout << "������: " << buffer->group 
					<< std::endl;
					std::cout << "������� � ��� ��������: "
					<< buffer->surname 
					<< ' '<<buffer->name << std::endl;
					std::cout << "����� �������� ������: " 
					<< buffer->Credit�ard << std::endl;
					std::cout << "��������� � �����: "
					<< buffer->stipend<<std::endl;
					std::cout << "��������� �� �������: "
					<< buffer->SumStipend<<std::endl;

					buffer = buffer->next; 
					// ������ ��������� ��� �������� ���������
				}
				std::cout << std::endl;
				std::cout << "id - " << buffer->id 
				<< std::endl;
				std::cout << "������: " << buffer->group 
				<< std::endl;
				std::cout << "������� � ��� ��������: "
				<< buffer->surname 
				<< ' '<<buffer->name 
				<< std::endl;
				std::cout << "����� �������� ������: " 
				<< buffer->Credit�ard 
				<< std::endl;
				std::cout << "��������� � �����: "
				<< buffer->stipend
				<<std::endl;
				std::cout << "��������� �� �������: "
				<< buffer->SumStipend
				<<std::endl;
			}
			break;
			case PRINT_ONE_STUDENT:
			{
				if()
				{
					//uiqquhfqbafnanlna
					//oquhfhafjakf
					//aofjkzc/ajalj
					//aocjln
					//aocjhadh
					//apdmalkjdla
				}
			}
			break;
			case ADD_STUDENT:
			{
				//apkafjiafsjapifjiafjioafjijla;dilajdi

				if(a==0)
				{
					//kd
					a = 0;
					//fskfjaf
					//afafafafdsgsg
					return;
				}
				else if(0<a<10)
				{
					a = 1;
					//fasggag
					//SgSGSH
					//esgs
					return;
				}
				else if(a>10)
				{
					//alfkJOFLShGJ
					a = 2;
					//aflHIFLhGLIHNLGNLSNv
					
				}
			}
			break;
			case WRITE_INTO_FILE:
			{
				WriteIntoFile(head);
			}	
			break;
		}
	}while(true);
	system("pause");
}

void ReadFromFile(StudentBaseDate* head) // ������ �� �����
{
    StudentBaseDate* buffer; // ����� ��� �������� ������

    std::ifstream file;
    file.open("StudentBaseDate.txt");  // ��������� ����
    if (file.is_open()) //��������� �������� ��
    {
        buffer = head; // ����� ��������� �� ������ ������
        while(!file.eof()) // ���� ���� �� ����������
        {
			 // ������ ����������� ����� ���������
            StudentBaseDate* NewElement = new StudentBaseDate; 
            file >> NewElement->group; // ��������� �� �� �����
            file >> NewElement->surname;
			file >> NewElement->name;
			file >> NewElement->Credit�ard;
			file >> NewElement->stipend;
			file >> NewElement->SumStipend;
			// id ����� ����� �� ���� ������ ����������
            NewElement->id = buffer->id + 1; 
            // �.�. ���� ������� ���� ��������� ��� ����� = NULL
			NewElement->next = NULL; 
			// ����������� ����� ������� � ������
            buffer->next = NewElement;

            buffer = NewElement; 
			// ������ ����� ��������� �� ����� �������
        }
    }
    else
        return;
    file.close(); // ��������� ����
}

void WriteIntoFile(StudentBaseDate* head) // ������ � ����
{
	
    std::ofstream file;
    file.open("StudentBaseDate.txt"); // ������� ���� 
    if (file.is_open()) // ��������� ��������
    {
		// ��������� �� ���� ����� ������,
		// ����� �� ������� ������ � ����
		StudentBaseDate* buffer = head->next; 
        while (buffer->next != NULL) 
		// ���� ��������� next �� ������ NULL
        {
			file << buffer->group << ' ' <<
			buffer->surname<< ' ' << buffer->name
			<< ' ' << buffer->Credit�ard << 
			' ' << buffer->stipend << ' ' <<
			buffer->SumStipend << '\n';

			// ���������� � ����
            buffer = buffer->next; 
			// ������ ��������� ��� �������� �� ������
        }
        file << buffer->group << ' ' << buffer->surname<<
		' ' << buffer->name<< ' ' << buffer->Credit�ard<<
		' ' << buffer->stipend << ' ' << buffer->SumStipend;
		
		// ���������� ��������� �������
    }
    else
        return;
    file.close(); // ��������� ����
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