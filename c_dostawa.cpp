#include "c_dostawa.h"

using namespace std;
dostawa::dostawa(string numer, std::vector<element> &lista) : nr_zamowienia(numer)
{
	pozycje = lista;
}

void dostawa::zapisz_dostawe()
{
		ofstream plik("dostawy-przyjete.txt", ios_base::app);
		plik << this<<endl;
}

bool dostawa::porownaj(std::string numer)
{
	if (numer == nr_zamowienia)
		return 1;
	return 0;
}

void dostawa::uzupelnij_magazyn(std::vector<product*> lista)
{
	for (int i = 0; i < pozycje.size(); i++)
	{
		int index = binary_search(lista, pozycje[i].kod);
		if (lista[index]->porownaj(pozycje[i].kod))
			lista[index]->dodaj(pozycje[i].ilosc);	
	}
}

ostream& operator<<(ostream& os, const dostawa& zamowienie)
{
	os <<endl<< zamowienie.nr_zamowienia << endl;
	for (int i = 0; i < zamowienie.pozycje.size(); i++)
	{
		os << zamowienie.pozycje[i].kod << " " << zamowienie.pozycje[i].nazwa << " " << zamowienie.pozycje[i].ilosc << endl;
	}
	os << "$";
	return os;
}
