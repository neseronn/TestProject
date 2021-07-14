#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>

#define SIZECHAR 50

enum menu {EXIT, ADD_STUDENT, PRINT_STUDENT,
		   PRINT_ALL_STUDENT, WRITE_INTO_FILE};

struct StudentBaseDate 
{
    int id; 
	char group[SIZECHAR];
	char surname[SIZECHAR];
    char name[SIZECHAR];
	char CreditСard[SIZECHAR];
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
	std::cout << "| Программа по практике			    |" 
			  << std::endl;
	std::cout << "| Тема: \"Электронная ведомость.\"	    |"
			  << std::endl;
	std::cout << "| Вспомогательное приложение	            |" 
			  << std::endl;
	std::cout << "| для подсчёта стипендии студентов.         |" 
			  << std::endl;
	std::cout << "| Выполнили студенты группы ИВТ-101         |"
			  << std::endl;
	std::cout << "| Шитый А.Д."" Авдеенко Е.Е."
				 " Кондратенко М.В. ""|"
			  << std::endl;
	std::cout<< "|===========================================|";

	StudentBaseDate* head = new StudentBaseDate; 
    head->next = NULL;
    head->id = 0;
    ReadFromFile(head);

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
				// пока не дойдём до последнего
				{
					std::cout << std::endl;
					std::cout << "id - " << buffer->id 
					<< std::endl;
					std::cout << "Группа: " << buffer->group 
					<< std::endl;
					std::cout << "Фамилия и имя студента: "
					<< buffer->surname 
					<< ' '<<buffer->name << std::endl;
					std::cout << "Номер зачётной книжки: " 
					<< buffer->CreditСard << std::endl;
					std::cout << "Стипендия в месяц: "
					<< buffer->stipend<<std::endl;
					std::cout << "Стипендия за семестр: "
					<< buffer->SumStipend<<std::endl;

					buffer = buffer->next; 
					// меняем указатель для перебора элементов
				}
				std::cout << std::endl;
				std::cout << "id - " << buffer->id 
				<< std::endl;
				std::cout << "Группа: " << buffer->group 
				<< std::endl;
				std::cout << "Фамилия и имя студента: "
				<< buffer->surname 
				<< ' '<<buffer->name 
				<< std::endl;
				std::cout << "Номер зачётной книжки: " 
				<< buffer->CreditСard 
				<< std::endl;
				std::cout << "Стипендия в месяц: "
				<< buffer->stipend
				<<std::endl;
				std::cout << "Стипендия за семестр: "
				<< buffer->SumStipend
				<<std::endl;
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

void ReadFromFile(StudentBaseDate* head) // чтение из файла
{
    StudentBaseDate* buffer; // буфер для перебора списка

    std::ifstream file;
    file.open("StudentBaseDate.txt");  // открываем файл
    if (file.is_open()) //проверяем открылся ли
    {
        buffer = head; // буфер указывает на начало списка
        while(!file.eof()) // пока файл не закончился
        {
			 // создаём динамически новую структуру
            StudentBaseDate* NewElement = new StudentBaseDate; 
            file >> NewElement->group; // заполняем ей из файла
            file >> NewElement->surname;
			file >> NewElement->name;
			file >> NewElement->CreditСard;
			file >> NewElement->stipend;
			file >> NewElement->SumStipend;
			// id новой будет на один больше предыдущей
            NewElement->id = buffer->id + 1; 
            // т.к. этот элемент пока последний его адрес = NULL
			NewElement->next = NULL; 
			// прикрепляем новый элемент к списку
            buffer->next = NewElement;

            buffer = NewElement; 
			// теперь буфер указывает на новый элемент
        }
    }
    else
        return;
    file.close(); // закрываем файл
}

void WriteIntoFile(StudentBaseDate* head) // запись в файл
{
	
    std::ofstream file;
    file.open("StudentBaseDate.txt"); // открыли файл 
    if (file.is_open()) // проверили открытие
    {
		// указывает на след после головы,
		// чтобы не вносить голову в файл
		StudentBaseDate* buffer = head->next; 
        while (buffer->next != NULL) 
		// пока указатель next не станет NULL
        {
			file << buffer->group << ' ' <<
			buffer->surname<< ' ' << buffer->name
			<< ' ' << buffer->CreditСard << 
			' ' << buffer->stipend << ' ' <<
			buffer->SumStipend << '\n';

			// записываем в файл
            buffer = buffer->next; 
			// меняем указатель для движения по списку
        }
        file << buffer->group << ' ' << buffer->surname<<
		' ' << buffer->name<< ' ' << buffer->CreditСard<<
		' ' << buffer->stipend << ' ' << buffer->SumStipend;
		
		// записываем последний элемент
    }
    else
        return;
    file.close(); // закрываем файл
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
			<< "|                   Меню                    |" 
			<< std::endl;
			std::cout 
			<< "|0 - завершить работу                       |" 
			<< std::endl;
			std::cout 
			<< "|1 - Добавить студента			    |" 
			<< std::endl;
			std::cout 
			<< "|2 - Вывести информацию об студенте         |" 
			<< std::endl;
			std::cout 
			<< "|3 - Вывести всех студентов                 |" 
			<< std::endl;
			std::cout 
			<< "|4 - Cохранить, записав в файл              |" 
			<< std::endl;
			std::cout 
			<< "|===========================================|" 
			<< std::endl;
			std::cout << "Ввод: ";
			NumberCmdMenu = _getch() - '0';
		if(NumberCmdMenu < EXIT ||
		   NumberCmdMenu > WRITE_INTO_FILE)
		{
			std::cout<< "Ошибка - такой команды нет" 
			<< std::endl;
			continue;
		}
		else
		{
			std::cout <<"Номер команды меню: ";
			std::cout << NumberCmdMenu <<std::endl;
			return NumberCmdMenu;
		}
	return NumberCmdMenu;
	}
}