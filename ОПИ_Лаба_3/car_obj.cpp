#include <iostream>
#include <Windows.h>

using namespace std;

class car_obj
{
	bool light = false;
	bool door = false;
	string name = "";
	string color = "";

public:	car_obj() :light(false), door(false), name(""), color("") {}

	  car_obj car_list_ch(car_obj _s)
	  {
		  light = _s.light;
		  door = _s.door;
		  name = _s.name;
		  color = _s.color;
		  return(_s);
	  }

	  //car_obj car_list_add(int n, int max, car_obj* prot)
	  //{
		 // car_obj* caro;
		 // caro = new car_obj[n + 1];
		 // for (max = 0; max < n; max++)
		 // {
			//  caro[max].car_list_ch(prot[max]);
		 // }
		 // prot = new car_obj[n + 1];
		 // for (max = 0; max < n; max++)
		 // {
			//  prot[max].car_list_ch(caro[max]);
		 // }
		 // return(prot[n]);
	  //}

	  void car_create()
	  {
		  cout << "Car created:\nSelect name:" << endl;
		  cin >> name;
		  cout << "Select color:" << endl;
		  cin >> color;
	  }

	  void car_ch_name()
	  {
		  cout << "������� ����� ���: ";
		  name = "";
		  cin >> name;
		  cout << "��� ���� ��������." << endl;
		  system("pause");
	  }

	  void car_ch_color()
	  {
		  cout << "������� ����� ����: ";
		  color = "";
		  cin >> color;
		  cout << "���� ��� �������." << endl;
		  system("pause");
	  }

	  void car_ch_door()
	  {
		  if (door == false) {
			  door = true;
			  cout << "����� ���� �������." << endl;
			  system("pause");
		  }
		  else {
			  door = false;
			  cout << "����� ���� �������." << endl;
			  system("pause");
		  }
	  }

	  void car_ch_light()
	  {
		  if (light == false) {
			  light = true;
			  cout << "���� ��� �������." << endl;
			  system("pause");
		  }
		  else {
			  light = false;
			  cout << "���� ��� ��������." << endl;
			  system("pause");
		  }
	  }

	  void car_delete()
	  {
		  light = false;
		  door = false;
		  name = "";
		  color = "";
	  }

	  string _l()
	  {
		  if (light == false) return("is Off");
		  else return("is on");
	  }

	  string _d()
	  {
		  if (door == false) return("Is closed");
		  else return("Is opened");
	  }

	  void car_list_out(int num)
	  {
		  if (name == "")	cout << num << " - Car is not created." << endl;
		  else
		  {
			  cout << num << " - " << "Name: " << name << "	Color: " << color << "	Light: " << _l() << "	Door: " << _d() << endl;
		  }
	  }

	  bool select(int com, bool flag)
	  {
		  switch (com)
		  {
		  case 1: {car_ch_name(); break;}
		  case 2: {car_ch_color(); break;}
		  case 3: {car_ch_door(); break;}
		  case 4: {car_ch_light(); break;}
		  case 5: {car_delete(); flag = true; break;}
		  case 6: {flag = true; break;}
				system("pause");
		  }
		  return(flag);
	  }

	  void car_mode()
	  {
		  bool flag = false;
		  while (flag == false)
		  {
			  if (name == "") car_create();

			  cout << endl << "Name: " << name << endl << "Color: " << color << endl;
			  cout << "Light: " << _l() << endl << "Door: " << _d() << endl;

			  cout << "��� �� ������ �������?:" << endl <<
				  "1 - �������� ���" << endl <<
				  "2 - �������� ����" << endl <<
				  "3 - ���/���� �����" << endl <<
				  "4 - ���/���� ����" << endl <<
				  "5 - ������� ����" << endl <<
				  "6 - ������� ����" << endl;
			  int com = 0;
			  cin >> com;
			  flag = select(com, flag);
		  }
	  }
};