#include "c_product.h"
using namespace std;

product::product(): kod("000000")
{
	nazwa = "nieznane";
	status = "brak";
	ilosc = 0;
	cena = 0;
}

product::product(std::string kod, std::string nazwa, std::string status, int ilosc,double cena): kod(kod)
{
	this->nazwa = nazwa;
	this->status = status;
	this->ilosc = ilosc;
	this->cena = cena;
}

product::~product()
{
}

bool product::porownaj(std::string& kod)
{
	if (kod == this->kod)
		return 1;
	else
		return 0;
}

void product::wpisz(string& linijka)
{
	int dlugosc;
	linijka += kod;
	linijka += "   ";
	for (int i = 0; i < nazwa.size(); i++)
	{
		linijka += nazwa[i];
	}
	if (linijka.size() < 29)
	{
		dlugosc = 29 - linijka.size();
		for (int i = 0; i < dlugosc; i++)
		{
			linijka += ' ';
		}
	}
	linijka += "   ";
	linijka += status;
	if (status == "brak")//dostepny
	{
		linijka += "    ";
	}
	linijka += "   ";
	string il = to_string(ilosc);
	linijka += il;
	if (il.size() < 5)
	{
		dlugosc = 5 - il.size();
		for (int i = 0; i < dlugosc; i++)
		{
			linijka += ' ';
		}
	}
	linijka += "   ";
	string cen= to_string(cena);
	int koniec = cen.size();
	for(int i=0;i<koniec;i++)
	{
			linijka += cen[i];
			if (cen[i] == '.')
				koniec=i+3;
	}
	while (linijka.size() < 58)
	{
		linijka += " ";
	}
	
}

void product::zmien_cene()
{
	float nowa_cena;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Bylo: " << cena << endl << endl;
	cout << "Podaj nowa cene: ";
	cin >> nowa_cena;
	cout << "\n";
	cena = nowa_cena;
}

void product::zmien_nazwe()
{
	string nowa_nazwa;
	cout << "Bylo: " << nazwa << endl << endl;
	cout << "Podaj nowa nazwe: ";
	cin >> nowa_nazwa;
	cout << "\n";
	nazwa=nowa_nazwa;
}

std::string product::pobierz_kod()
{
	return this->kod;
}

int product::pobierz_ilosc()
{
	return ilosc;
}

double product::pobierz_cene()
{
	return cena;
}

std::string product::pobierz_nazwe()
{
	return nazwa;
}

void product::dodaj(int liczba)
{
	ilosc += liczba;
	if (ilosc > 0)
		status = "dostepny";
	if (ilosc == 0)
		status = "brak";
}

bool product::operator<(product& prawy)
{
	if (this->kod < prawy.kod)
	{
		return true;
	}
	return false;
}
