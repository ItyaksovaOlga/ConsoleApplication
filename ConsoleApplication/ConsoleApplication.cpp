/*******Данное консольное приложение предназначено****** 
********для чтения загрузочной записи диска*************
********под управлением файловой системы NTFS**********/
#include <iostream>
#include "FSDLL.h"

using namespace std;

int main()
{
	string diskName;

	while (1)
	{
		cout << "***You are welcome by a program that reads the disk boot record***" << endl;
		cout << "Please enter disk name" << endl;
		diskName = cin.get();

		//если на вход получен не один символ - выход
		if (diskName.length() == 1) 
		{
			break;
		}
	}



	//вызов функции для получения типа файловой системы
	//123
	string fsName = getNameFS(diskName);

	//создание полного пути для отработки функции
	//после слешей и перед двоеточием передаем в строку полученную от пользователя букву
	string diskNameFull = "\\\\.\\" + diskName + ":";

	//Вызов структуры
	NTFS pBoot;

	//Вызов функций
	//получение информации о стурктуре загрузочной записи и
	//соответственно вывод информации на косоль
	if (GetInfo(diskNameFull, &pBoot))
	{
		PrintInfo(pBoot);
	}

	system("pause");
	return 0;
}
