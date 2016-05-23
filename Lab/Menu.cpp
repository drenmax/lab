#include <cstdio>
#include <iostream>
#include "Pass2.h"
#include "menu.h"

using namespace std;

int mainMenu(char *file1, char *file2)
	{
	class Voyage *ghul, v;
	class Passenger *vad, u;
	int k, l, n=10;
	int a, p;
	ghul=NULL;
	vad=NULL;
  
	if (file1==NULL&&file2==NULL)
		{
		cout<<"Нет файлов"<<endl;
		return 0;
		}
	MainMenu();
	while (n!=0)
		{
		cout<<"Выберите нужный пункт: ";
		cin>>n;
		switch(n)
			{
			case 1:
				ghul=LoadVo (file1, ghul, &l);
				vad=LoadPass (file2, vad, &k);
			break;
			case 2:
				a=1;
				while(a!=0)
					{
					menuInput();
					cin>>p;
					switch(p)
						{
						case 1:
							u.inputPass(file1, file2, ghul, l);
							vad=LoadPass (file2, vad, &k);
							ghul=LoadVo (file1, ghul, &l);
							v.SaveVo(file1, ghul, l);	
						break;
						case 2:
							v.inputVo(file1);
							ghul=LoadVo (file1, ghul, &l);
						break;
						case 0:
							a=0;
						break;
						default:
							cout<<"Некорректная команда"<<endl;
						}
					}
				MainMenu();
			break;
			case 3:			
				if (ghul!=NULL&&vad!=NULL)
					{
					u.ShowPass(vad, k); 
					v.ShowVo(ghul, l);
					}
				else
					cout<<"База не загужена"<<endl;
				MainMenu(); 
			break;
			case 4:
				menuSearchPass();
				u.findPass(vad, k);
				MainMenu();
			break;				
			case 5:
				menuSearchVoyage();
				v.findVo(ghul, l);
				MainMenu();
			break;				
			case 6:
				u.DelPass(file1, file2, vad, ghul, k, l);
				vad=LoadPass (file2, vad, &k);
				ghul=LoadVo (file1, ghul, &l);
				MainMenu();
			break;
			case 7:
				v.DelVo(file1, file2, ghul, vad, l, k);
				u.SavePass (file2, vad, k);
				vad=LoadPass (file2, vad, &k);
				ghul=LoadVo (file1, ghul, &l);
				MainMenu();
			break;
			case 0:
				cout<<"Выход из программы"<<endl;
				return 0;
			default:
				cout<<"Некорректная команда"<<endl;
			}
		}
	}
  
void menuInput(void)
	{
	cout<<"\n\tДобавление\n1. Добавить пассажира\n2. Добавить рейс\n0. Выход из меню добавления\n";
	}

void menuSearchPass(void)
	{
	cout<<"\n\tПоиск пассажиров\n\n1. Ф.И.О \n2. Номер паспорта\n3. Номер билета\n4. Все пассажиры на рейсе\n0. Выход\n\n";
	}

void menuSearchVoyage(void)
	{
	cout<<"\n\tПоиск рейсов\n\n1. Номер рейса \n2. Направление рейса\n3. Дата вылета рейса\n4. Количество мест на рейсе\n5. Количество свободных мест на рейсе\n0. Выход\n\n";
	}

void MainMenu(void)
	{  
	cout<<"\tМеню\n1. Загрузить данные\n2. Добавить элемент\n3. Вывести данные\n4. Поиск пассажиров\n5. Поиск рейсов\n6. Удалить пассажира\n7. Удалить рейс\n0. Выход\n";
	}
