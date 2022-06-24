#include "menu.h"

int menu() 
{
	std::string teksty[7]{ "MENU","Magazyn","Oferta","Sprzedaz/zwroty","Raporty","Remanent roczny","Zakoncz dzialanie programu"};
	std::pair<char, int> strzalka{ '>',1 };
	std::cout << teksty[0] << std::endl;
	for (int i = 1; i < 7; i++)
	{
		if (i == strzalka.second)
		{
			std::cout << strzalka.first << teksty[i]<<std::endl;
		}
		else
		{
			std::cout << " " << teksty[i]<<std::endl;
		}
	}
	int znak = _getch();
	do
	{
		int przycisk = 0;
		switch (znak)
		{
		default:
			break;
		case 224:
			przycisk = _getch();
			break;
		case 13:
			system("cls");
			return(strzalka.second);
		case 27:
			return 0;
		}
		system("cls");
		switch (przycisk)
		{
		case 72:
			if (strzalka.second > 1)
			{
				--strzalka.second;
			}
			break;
		case 80:
			if (strzalka.second < 6)
			{
				++strzalka.second;
			}
			break;
		}
		for (int i = 0; i < 7; i++)
		{
			if (i == 0)
			{
				std::cout << teksty[i]<<std::endl;
			}
			else
			{
				if (i == strzalka.second)
				{
					std::cout << strzalka.first << teksty[i] << std::endl;
				}
				else
				{
					std::cout << " " << teksty[i] << std::endl;
				}
			}
		}
		znak=_getch();
	} while (znak != 27);
	return 0;
}
int menu1()
{
	std::string teksty[5]{"MAGAZYN","Wyswietl stan magazynowy","Zaplanuj dostawy","Przyjmij dostawe","Powroc do menu glownego"};
	std::pair<char, int> strzalka{ '>',1 };
	for (int i = 0; i < 5; ++i)
	{
		if (i == 0)
		{
			std::cout << teksty[i]<<std::endl;
		}
		else
		{
			if (strzalka.second == i)
			{
				std::cout << strzalka.first << teksty[i] << std::endl;
			}
			else
			{
				std::cout << " " << teksty[i] << std::endl;
			}
		}
	}
	int znak = _getch();
	do
	{
		int przycisk = 0;
		switch (znak)
		{
		default:
			break;
		case 224:
			przycisk = _getch();
			break;
		case 13:
			system("cls");
			return(strzalka.second+10);
		case 8:
			system("cls");
			return 0;
		}
		system("cls");
		switch (przycisk)
		{
		case 72:
			if (strzalka.second > 1)
			{
				--strzalka.second;
			}
			break;
		case 80:
			if (strzalka.second < 4)
			{
				++strzalka.second;
			}
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			if (i == 0)
			{
				std::cout << teksty[i] << std::endl;
			}
			else
			{
				if (i == strzalka.second)
				{
					std::cout << strzalka.first << teksty[i] << std::endl;
				}
				else
				{
					std::cout << " " << teksty[i] << std::endl;
				}
			}
		}
		znak = _getch();
	} while ( znak != 8);
	system("cls");
	return 0;
}
int menu2()
{
	std::string teksty[6]{ "OFERTA","Dodaj produkt do oferty","Usun produkt z oferty","Zmien cene produktu","Zmien nazwe produktu","Powroc do menu glownego"};
	std::pair<char, int> strzalka{ '>',1 };
	for (int i = 0; i < 6; ++i)
	{
		if (i == 0)
		{
			std::cout << teksty[i] << std::endl;
		}
		else
		{
			if (strzalka.second == i)
			{
				std::cout << strzalka.first << teksty[i] << std::endl;
			}
			else
			{
				std::cout << " " << teksty[i] << std::endl;
			}
		}
	}
	int znak = _getch();
	do
	{
		int przycisk = 0;
		switch (znak)
		{
		default:
			break;
		case 224:
			przycisk = _getch();
			break;
		case 13:
			system("cls");
			return(strzalka.second + 20);
		case 8:
			system("cls");
			return 0;
		}
		system("cls");
		switch (przycisk)
		{
		case 72:
			if (strzalka.second > 1)
			{
				--strzalka.second;
			}
			break;
		case 80:
			if (strzalka.second < 5)
			{
				++strzalka.second;
			}
			break;
		}
		for (int i = 0; i < 6; i++)
		{
			if (i == 0)
			{
				std::cout << teksty[i] << std::endl;
			}
			else
			{
				if (i == strzalka.second)
				{
					std::cout << strzalka.first << teksty[i] << std::endl;
				}
				else
				{
					std::cout << " " << teksty[i] << std::endl;
				}
			}
		}
		znak = _getch();
	} while ( znak != 8);
	system("cls");
	return 0;
}
int menu3()
{
	std::string teksty[4]{ "SPRZEDAZ/ZWROTY","Dodaj paragon","Zwroc towar","Powroc do menu glownego"};
	std::pair<char, int> strzalka{ '>',1 };
	for (int i = 0; i < 4; ++i)
	{
		if (i == 0)
		{
			std::cout << teksty[i] << std::endl;
		}
		else
		{
			if (strzalka.second == i)
			{
				std::cout << strzalka.first << teksty[i] << std::endl;
			}
			else
			{
				std::cout << " " << teksty[i] << std::endl;
			}
		}
	}
	int znak = _getch();
	do
	{
		int przycisk = 0;
		switch (znak)
		{
		default:
			break;
		case 224:
			przycisk = _getch();
			break;
		case 13:
			system("cls");
			return(strzalka.second + 30);
		case 8:
			system("cls");
			return 0;
		}
		system("cls");
		switch (przycisk)
		{
		case 72:
			if (strzalka.second > 1)
			{
				--strzalka.second;
			}
			break;
		case 80:
			if (strzalka.second < 3)
			{
				++strzalka.second;
			}
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				std::cout << teksty[i] << std::endl;
			}
			else
			{
				if (i == strzalka.second)
				{
					std::cout << strzalka.first << teksty[i] << std::endl;
				}
				else
				{
					std::cout << " " << teksty[i] << std::endl;
				}
			}
		}
		znak = _getch();
	} while (znak!=8);
	system("cls");
	return 0;
}
int menu4()
{
	std::string teksty[5]{ "RAPORTY","Dobowy","Miesieczny","Roczny","Powrot do menu glownego"};
	std::pair<char, int> strzalka{ '>',1 };
	for (int i = 0; i < 5; ++i)
	{
		if (i == 0)
		{
			std::cout << teksty[i] << std::endl;
		}
		else
		{
			if (strzalka.second == i)
			{
				std::cout << strzalka.first << teksty[i] << std::endl;
			}
			else
			{
				std::cout << " " << teksty[i] << std::endl;
			}
		}
	}
	int znak = _getch();
	do
	{
		int przycisk=0;
		switch (znak)
		{
		default:
			break;
		case 224:
			przycisk = _getch();
			break;
		case 13:
			system("cls");
			return(strzalka.second + 40);
		case 8:
			system("cls");
			return 0;
		}
		system("cls");
		switch (przycisk)
		{
		case 72:
			if (strzalka.second > 1)
			{
				--strzalka.second;
			}
			break;
		case 80:
			if (strzalka.second < 4)
			{
				++strzalka.second;
			}
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			if (i == 0)
			{
				std::cout << teksty[i] << std::endl;
			}
			else
			{
				if (i == strzalka.second)
				{
					std::cout << strzalka.first << teksty[i] << std::endl;
				}
				else
				{
					std::cout << " " << teksty[i] << std::endl;
				}
			}
		}
		znak = _getch();
	} while (znak != 8);
	system("cls");
	return 0;
}
