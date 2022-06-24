#include "c_paragon.h"
using namespace std;

void pozycja::wpisz(std::string& linijka, int czy_kod)
{
	int dlugosc;
	if (czy_kod)
	{
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
		string il = to_string(ilosc);
		for (int i = 0; i < 5 - il.size(); i++)
		{
			linijka += " ";
		}
		linijka += il;
		linijka += " x";
		linijka += "   ";
		string cen = to_string(cena);
		int koniec = cen.size();
		for (int i = 0; i < koniec; i++)
		{
			linijka += cen[i];
			if (cen[i] == '.')
				koniec = i + 3;
		}
	}
	else
	{
		linijka += nazwa;
		if (linijka.size() < 20)
		{
			dlugosc = 20 - linijka.size();
			for (int i = 0; i < dlugosc; i++)
			{
				linijka += ' ';
			}
		}
		linijka += "   ";
		string il = to_string(ilosc);
		for (int i = 0; i < 5 - il.size(); i++)
		{
			linijka += " ";
		}
		linijka += il;
		linijka += " x";
		linijka += "   ";
		string cen = to_string(cena);
		int koniec = cen.size();
		for (int i = 0; i < koniec; i++)
		{
			linijka += cen[i];
			if (cen[i] == '.')
				koniec = i + 3;
		}
	}
}

paragon::paragon(std::string numer, std::vector<pozycja>& lista_nowa) : numer(numer)
{
	this->data.clear();
	for (int i = 0; i < 12; i++)
	{
		this->data += this->numer[i];

		switch (i)
		{
		case 3:
		case 5:
			this->data += '.';
			break;
		case 7:
			this->data += "   ";
			break;
		case 9:
			this->data += ':';
			break;
		}
	}
	this->suma = 0;
	this->lista = lista_nowa;
	for (int i = 0; i < lista_nowa.size(); i++)
	{
		this->suma += (double)(lista_nowa[i].cena * lista_nowa[i].ilosc);
	}
}

paragon::paragon(std::string numer, std::string data, std::vector<pozycja> lista, double suma) :numer(numer)
{
	this->data = data;
	this->lista = lista;
	this->suma = suma;
}

std::string paragon::pobierz_numer()
{
	return this->numer;
}

void paragon::zapisz_paragon()
{
	ofstream paragony("paragony.txt", ios_base::app);
	paragony << numer << endl;
	paragony << data<<endl;
	for (int i = 0; i < lista.size(); i++)
	{
		string linijka;
		lista[i].wpisz(linijka,1);
		paragony << linijka << '\n';
	}
	paragony << "Suma: " << suma<<'\n'<<"$"<<'\n';
}

bool paragon::znajdz_produkt(std::string& kod, int& ilosc)
{
	bool znaleziono = false;
	for (int i = 0; i < this->lista.size(); i++)
	{
		if (lista[i].kod == kod)
		{
			do
			{
				znaleziono = true;
				if (lista[i].ilosc - ilosc >= 0)
				{
					lista[i].ilosc -= ilosc;
					break;
				}
				else
				{
					system("cls");
					cout << "Podana ilosc jest za duza, maksymalnie " << lista[i].ilosc << " sztuk" << endl;
					cin >> ilosc;
				}
				if (lista[i].ilosc == 0)
				{
					lista.erase(lista.begin() + i);
				}
			} while (1);
		}
		if (znaleziono)
		{
			break;
		}
	}
	if (!znaleziono)
	{
		return 0;
	}
	else
		return 1;
}

double paragon::znajdz_cene(std::string& kod)
{
	for (int i = 0; i < this->lista.size(); i++)
	{
		if (lista[i].kod == kod)
		{
			return lista[i].cena;
		}
	}
}

void paragon::uzupelnij_sume(double wartosc)
{
	suma += wartosc;
}

std::string paragon::nazwa_produktu(std::string& kod)
{
	for (int i = 0; i < this->lista.size(); i++)
	{
		if (lista[i].kod == kod)
		{
			return lista[i].nazwa;
		}
	}
}

int paragon::rozmiar_listy()
{
	return lista.size();
}

ostream& operator<<(ostream& os, paragon& para)
{
	os << para.numer << endl;
	os << para.data << endl;
	for (int i = 0; i < para.lista.size(); i++)
	{
		string linijka;
		para.lista[i].wpisz(linijka);
		os << linijka << '\n';
	}
	os << "Suma: " << para.suma << '\n' << "----------------" << '\n';
	return os;
}
