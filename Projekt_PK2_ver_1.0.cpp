

#include <iostream>
#include "menu.h"
#include "funkcje.h"

using namespace std;

int main()
{
	//główny odczyt plików
	vector<product*> stan_magazynowy;
	wczytaj_magazyn(stan_magazynowy);
	vector<dostawa*> zamowienia;
	wczytaj_dostawy(zamowienia);
	vector<paragon*> rachunki;
	wczytaj_paragony(rachunki);
	int wybierz_funkcje = 0;
	do
	{
		do
		{
			switch (menu())
			{
			case 6:
			case 0:
				zapisz_magazyn(stan_magazynowy);
				zapisz_paragony(rachunki);
				zapisz_dostawy(zamowienia);
				return 0;
			case 1:
				wybierz_funkcje = menu1();
				break;
			case 2:
				wybierz_funkcje = menu2();
				break;
			case 3:
				wybierz_funkcje = menu3();
				break;
			case 4:
				wybierz_funkcje = menu4();
				break;
			case 5:
				wybierz_funkcje = 50;
				break;
			}
		} while (wybierz_funkcje == 0);

		switch (wybierz_funkcje)
		{
		case 14:
		case 25:
		case 33:
		case 44:
			break;
		case 11:
			wyswietl_magazyn(stan_magazynowy);
			system("cls");
			break;
		case 12:
			dodaj_dostawe(stan_magazynowy, zamowienia);
			system("cls");
			break;
		case 13:
			przyjmij_dostawe(stan_magazynowy, zamowienia);
			system("cls");
			break;
		case 21:
			dodaj_produkt(stan_magazynowy);
			system("cls");
			break;
		case 22:
			usun_produkt(stan_magazynowy);
			system("cls");
			break;
		case 23:
			nowa_cena(stan_magazynowy);
			system("cls");
			break;
		case 24:
			nowa_nazwa(stan_magazynowy);
			system("cls");
			break;
		case 31:
			dodaj_paragon(stan_magazynowy,rachunki);
			system("cls");
			break;
		case 32:
			zwroc_towar(stan_magazynowy, rachunki);
			system("cls");
			break;
		case 41:
			raport_dobowy(rachunki);
			system("cls");
			break;
		case 42:
			raport_miesieczny(rachunki);
			system("cls");
			break;
		case 43:
			raport_roczny(rachunki);
			system("cls");
			break;
		case 50:
			remanent(stan_magazynowy);
			system("cls");
			break;
		}
	} while (1);
}

