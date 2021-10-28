#include <iostream>
#include <Windows.h>
#include "car_obj.cpp"

using namespace std;

bool* light;
bool* door;
string name[100000];
string color[100000];

void car_create(int num)
{
	cout << "Car created:\nSelect name:" << endl;
	cin >> name[num];
	cout << "Select color:" << endl;
	cin >> color[num];
}

void car_ch_name(int num)
{
	cout << "Введите новое имя: ";
	name[num] = "";
	cin >> name[num];
	cout << "Имя было изменено." << endl;
	system("pause");
}

void car_ch_color(int num)
{
	cout << "Введите новый цвет: ";
	color[num] = "";
	cin >> color[num];
	cout << "Цвет был изменен." << endl;
	system("pause");
}

void car_ch_door(int num)
{
	if (door[num] == false) {
		door[num] = true;
		cout << "Двери были открыты." << endl;
		system("pause");
	}
	else {
		door[num] = false;
		cout << "Двери были закрыты." << endl;
		system("pause");
	}
}

void car_ch_light(int num)
{
	if (light[num] == false) {
		light[num] = true;
		cout << "Свет был включён." << endl;
		system("pause");
	}
	else {
		light[num] = false;
		cout << "Свет был выключен." << endl;
		system("pause");
	}
}

void car_delete(int num)
{
	light[num] = false;
	door[num] = false;
	name[num] = "";
	color[num] = "";
}

string _l(int num)
{
	if (light[num] == false) return("is Off");
	else return("is on");
}

string _d(int num)
{
	if (door[num] == false) return("Is closed");
	else return("Is opened");
}

void car_list_out(int num)
{
	if (name[num] == "")	cout << num << " - Car is not created." << endl;
	else
	{
		cout << num << " - " << "Name: " << name[num] << "	Color: " << color[num] << "	Light: " << _l(light[num]) << "	Door: " << _d(door[num]) << endl;
	}
}

bool select(int com, bool flag, int num)
{
	switch (com)
	{
	case 1: {car_ch_name(num); break; }
	case 2: {car_ch_color(num); break; }
	case 3: {car_ch_door(num); break; }
	case 4: {car_ch_light(num); break; }
	case 5: {car_delete(num); flag = true; break; }
	case 6: {flag = true; break; }
		  system("pause");
	}
	return(flag);
}

void main()
{
	system("chcp 1251");

	int com_1;
	cout << "1 - ООП\n2 - Функциональное\n3 - Структурное" << endl;
	cin >> com_1;
	switch (com_1)
	{
	case 1:	/*ООП*/
	{
		car_obj* car;
		int num = -1, max;

		cout << "Number of car:" << endl;
		cin >> num;
		max = num;
		car = new car_obj[num + 1];

		while (num != 0)
		{
			cout << "If you want to end programm press 0" << endl;

			cout << "The car(Car at the moment: " << max << " ):" << endl;
			cin >> num;

			if (num > max)
			{
				int end = max;
				car_obj* caro;
				caro = new car_obj[num + 1];
				for (max = 0; max < end; max++)
				{
					caro[max].car_list_ch(car[max]);
				}

				car = new car_obj[num + 1];
				for (max = 0; max < num; max++)
				{
					car[max].car_list_ch(caro[max]);
				}
			}

			if (num == 0) goto end;

			car[num].car_mode();

			cout << "If you want to check all car press: 0 . Else press enything else." << endl;
			cin >> num;
			if (num == 0)
			{
				for (num = 1; num <= max; num++)
				{
					car[num].car_list_out(num);
				}
			}
			else num = -1;

			system("pause");
			system("cls");

		end:;
		}
		break;
	}
	case 2:	/*Функциональное*/
	{
		int num = -1, max;

		cout << "Number of car:" << endl;
		cin >> num;
		max = num;

		light = new bool[num + 1];
		door = new bool[num + 1];

		for (int n = 0; n < num + 1; n++)
		{
			light[n] = door[n] = false;
		}

		while (num != 0)
		{
			cout << "If you want to end programm press 0" << endl;

			cout << "The car(Max at the moment: " << max << " ): " << endl;
			cin >> num;

			if (max < num)
			{
				int end = max;

				bool* indx1;
				indx1 = new bool[num + 1];

				bool* indx2;
				indx2 = new bool[num + 1];

				for (int n = 0; n < num + 1; n++)
				{
					indx1[n] = indx2[n] = false;
				}

				for (max = 0; max < end; max++)
				{
					indx1[max] = light[max];
					indx2[max] = door[max];
				}

				door = new bool[num + 1];
				light = new bool[num + 1];

				for (int n = 0; n < num + 1; n++)
				{
					light[n] = door[n] = false;
				}

				for (max = 0; max < num; max++)
				{
					door[max] = indx2[max];
					light[max] = indx1[max];
				}

			}

			bool flag = false;

			if (num == 0) goto end2;

			while (flag == false)
			{

				if (name[num] == "") car_create(num);

				cout << endl << "Name: " << name[num] << endl << "Color: " << color[num] << endl;
				cout << "Light: " << _l(num) << endl << "Door: " << _d(num) << endl;

				cout << "Что вы хотите сделать?:" << endl <<
					"1 - Изменить имя" << endl <<
					"2 - Изменить цвет" << endl <<
					"3 - Отк/закр двери" << endl <<
					"4 - Вкл/выкл свет" << endl <<
					"5 - Удалить авто" << endl <<
					"6 - Сменить авто" << endl;
				int com = 0;
				cin >> com;
				flag = select(com, flag, num);
			}

			cout << "If you want to check all car press: 0 . Else press enything else." << endl;
			cin >> num;
			if (num == 0)
			{
				for (num = 1; num <= max; num++)
				{
					car_list_out(num);
				}
			}
			else num = -1;

			system("pause");
			system("cls");
		end2:;
		}
		break;
	}
	case 3:	/*Структурное*/
	{
		int COM_STR, NUM_STR = -1, MAX_STR;

		cout << "Number of car:" << endl;

		cin >> NUM_STR;
		MAX_STR = NUM_STR;

		light = new bool[NUM_STR + 1];
		door = new bool[NUM_STR + 1];

		for (int n = 0; n < NUM_STR + 1; n++)
		{
			light[n] = door[n] = false;
		}

		while (NUM_STR != 0)
		{
			cout << "If you want to end programm press 0" << endl;

			cout << "The car(Car at the moment: " << MAX_STR << " ):" << endl;
			cin >> NUM_STR;

			if (NUM_STR > MAX_STR)
			{
				int end = MAX_STR;

				bool* indx1;
				indx1 = new bool[NUM_STR + 1];

				bool* indx2;
				indx2 = new bool[NUM_STR + 1];

				for (int n = 0; n < NUM_STR + 1; n++)
				{
					indx1[n] = indx2[n] = false;
				}

				for (MAX_STR = 0; MAX_STR < end; MAX_STR++)
				{
					indx1[MAX_STR] = light[MAX_STR];
					indx2[MAX_STR] = door[MAX_STR];
				}

				door = new bool[NUM_STR + 1];
				light = new bool[NUM_STR + 1];

				for (int n = 0; n < NUM_STR + 1; n++)
				{
					light[n] = door[n] = false;
				}

				for (MAX_STR = 0; MAX_STR < NUM_STR; MAX_STR++)
				{
					door[MAX_STR] = indx2[MAX_STR];
					light[MAX_STR] = indx1[MAX_STR];
				}

			}

			bool flag = false;

			if (NUM_STR == 0) goto end3;

			while (flag == false)
			{

				if (name[NUM_STR] == "")
				{
					cout << "Car created:\nSelect name:" << endl;
					cin >> name[NUM_STR];
					cout << "Select color:" << endl;
					cin >> color[NUM_STR];
				}

				cout << endl << "Name: " << name[NUM_STR] << endl << "Color: " << color[NUM_STR] << endl;
				cout << "Light: " << _l(NUM_STR) << endl << "Door: " << _d(NUM_STR) << endl;

				cout << "Что вы хотите сделать?:" << endl <<
					"1 - Изменить имя" << endl <<
					"2 - Изменить цвет" << endl <<
					"3 - Отк/закр двери" << endl <<
					"4 - Вкл/выкл свет" << endl <<
					"5 - Удалить авто" << endl <<
					"6 - Сменить авто" << endl;
				int com = 0;
				cin >> com;
				
				//select start

				switch (com)
				{
				case 1: /*Name change	*/ {
					cout << "Введите новое имя: ";
					name[NUM_STR] = "";
					cin >> name[NUM_STR];
					cout << "Имя было изменено." << endl;
					system("pause");
					break;
				}
				case 2: /*Colore change	*/ {
					cout << "Введите новый цвет: ";
					color[NUM_STR] = "";
					cin >> color[NUM_STR];
					cout << "Цвет был изменен." << endl;
					system("pause");
					break; }
				case 3: /*Door change	*/ {
					if (door[NUM_STR] == false) {
						door[NUM_STR] = true;
						cout << "Двери были открыты." << endl;
						system("pause");
					}
					else {
						door[NUM_STR] = false;
						cout << "Двери были закрыты." << endl;
						system("pause");
					}; break; }
				case 4: /*Light change	*/ {
					if (light[NUM_STR] == false) {
						light[NUM_STR] = true;
						cout << "Свет был включён." << endl;
						system("pause");
					}
					else {
						light[NUM_STR] = false;
						cout << "Свет был выключен." << endl;
						system("pause");
					} break; }
				case 5: /*Delete car	*/ {
					light[NUM_STR] = false;
					door[NUM_STR] = false;
					name[NUM_STR] = "";
					color[NUM_STR] = "";; flag = true; break; }
				case 6: {flag = true; break; }
					  system("pause");
				}
			}

			cout << "If you want to check all car press: 0 . Else press enything else." << endl;
			cin >> NUM_STR;
			if (NUM_STR == 0)
			{
				for (NUM_STR = 1; NUM_STR <= MAX_STR; NUM_STR++)
				{
					if (name[NUM_STR] == "")	cout << NUM_STR << " - Car is not created." << endl;
					else
					{
						cout << NUM_STR << " - " << "Name: " << name[NUM_STR] << "	Color: " << color[NUM_STR] << "	Light: " << _l(light[NUM_STR]) << "	Door: " << _d(door[NUM_STR]) << endl;
					}
				}
			}
			else NUM_STR = -1;

			system("pause");
			system("cls");
		end3:;
		}
		break;
		}
	}
}