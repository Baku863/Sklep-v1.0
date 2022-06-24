#include "funkcje.h"
using namespace std;

//*Magazyn*
void wyswietl_magazyn(vector<product*> &lista)
{
	time_t czas;
	tm* data;
	std::time(&czas);
	data = localtime(&czas);
	cout << "Stan na: " << asctime(data) << endl;
	cout << pierwsza_linia << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		string linijka;
		lista[i]->wpisz(linijka);
		cout << linijka << endl;
	}
	enter();
}

void dodaj_dostawe(vector<product*> &lista, vector<dostawa*> &zamowienia)
{
	vector<element> pozycje;
	time_t czas;
	tm* data;
	std::time(&czas);
	data = localtime(&czas);
	string numer=utworz_numer(data);
	do
	{
		string kod;
		system("cls");
		cout << "Podaj kod produktu ktory chcesz zamowic: ";
		cin >> kod;
		cout << "\n";
		int index = binary_search(lista, kod);
		if (lista[index]->porownaj(kod))
		{
			int ilosc;
			string nazwa = lista[index]->pobierz_nazwe();
			cout << nazwa << endl;
			cout << "Ile sztuk zamowic?" << endl;
			cin >> ilosc;
			element nowa_pozycja{ kod,nazwa,ilosc };
			pozycje.push_back(nowa_pozycja);
			cout << "Enter - zamow kolejny produkt" << endl << "Backspace - wroc do menu glownego" << endl;
		}
		else
		{
			cout << "Nie ma podanego produktu. Sprobuj ponownie." << endl;
			cout << "Enter - sprobuj ponownie" << endl << "Backspace - wroc do menu glownego" << endl;
		}
	} while (dalej());
	zamowienia.push_back(new dostawa(numer, pozycje));
	zapisz_dostawy(zamowienia);
}

void przyjmij_dostawe(vector<product*> &lista, vector<dostawa*> &zamowienia)
{	
	string nr_zam;
	do
	{
		int przyjeto = 0;
		cout << "Podaj numer dostawy ktora chcesz przyjac: ";
		cin >> nr_zam;
		cout << "\n";
		for (int i = 0; i < zamowienia.size(); i++)
		{
			if (zamowienia[i]->porownaj(nr_zam))
			{
				++przyjeto;
				zamowienia[i]->uzupelnij_magazyn(lista);
				zamowienia[i]->zapisz_dostawe();
				zamowienia.erase(zamowienia.begin() + i);
				cout << "Pomyslnie przyjeto dostawe" << endl;
				cout << "Enter - przyjmij kolejna dostawe" << endl << "Backspace - wroc do menu glownego" << endl;
			}
		}
		if (przyjeto == 0)
		{
			cout << "Nie znaleziono zamowienia o podanym kodzie. Sprobuj ponownie" << endl;
			cout << "Enter - sprobuj ponownie" << endl << "Backspace - wroc do menu glownego" << endl;
		}
	} while (dalej());
	zapisz_dostawy(zamowienia);
	zapisz_magazyn(lista);
}

//*Oferta*
void dodaj_produkt(vector<product*>& lista)
{
	do
	{
		string kod;
		float cena;
		string nazwa;
		int ponownie = 0;
		do
		{
			system("cls");
			bool blad = 0;
			cout << "Podaj kod produktu skladajacy sie z samych cyfr w formacie xxxxxx: ";
			cin >> kod;
			if (kod.size() != 6)
			{
				cout << "Bledna dlugosc kodu" << endl;
				cout << "Enter - sprobuj ponownie" << endl << "Backspace - powrot do menu glownego";
				if (dalej())
					continue;
				else
					return;
			}
			for (int i = 0; i < kod.size(); i++)
			{
				if (!isdigit(kod[i]))
				{
					blad = true;
					break;
				}
			}
			if (blad)
			{
				cout << "Podano bledny znak"<<endl;
				cout << "Enter - sprobuj ponownie" <<endl<< "Backspace - powrot do menu glownego";
				if (dalej())
					continue;
				else
					return ;
			}
			if (kod == lista[binary_search(lista, kod)]->pobierz_kod())
			{
				cout << "Kod znajduje sie juz na liscie" << endl;
				cout << "Enter - sprobuj ponownie" << endl << "Backspace - powrot do menu glownego";
				if (dalej())
					continue;
				else
					return;
			}
			else
			{
				break;
			}
			
		} while (1);
			do
			{
				system("cls");
				cout << "Podaj nazwe produktu(max 20 znakow)" << endl;
				cin >> nazwa;
				if (nazwa.size() > 20)
				{
					cout << "Za dluga nazwa, wymysl inna" << endl;
					cout << "Wcisnij dowolny klawisz aby kontynuowac";
					_getch();
				}
				else
				{
					break;
				}
			} while (1);
			do
			{
				cout << endl << "Podaj cene produktu(max 9999.99)" << endl;
				cin >> cena;
				if (cena >= 10000 or cena<0)
				{
					cout << "Cena nie miesci sie w przedziale" << endl;
					cout << "Wcisnij dowolny klawisz aby kontynuowac";
					_getch();
				}
				else
				{
					break;
				}
			} while (1);
			cout << endl;
			binary_sort(lista,new product(kod, nazwa, "brak", 0, cena));
			cout << "Enter - dodaj nastepny produkt" << endl << "Backspace - wroc do menu glownego" << endl;
			if (!dalej())
			{
				break;
			}
	} while (1);
	zapisz_magazyn(lista);
}

void usun_produkt(vector<product*> &lista)
{
	do
	{
		system("cls");
		string kod;
		int blad = 0;
		cout << "Podaj kod produktu ktory chcesz usunac: ";
		cin >> kod;
		if (kod.size() < 6)
		{
			cout << "Bledny kod" << endl;
			cout << "Enter - sprobuj ponownie" << endl << "Backspace - powrot do menu glownego" << endl;
			if (dalej())
				continue;
			else
				break;
		}
		cout << "\n";
		int index = binary_search(lista, kod);
		product* wsk = lista[index];
		if (wsk->porownaj(kod))
		{
			if (wsk->pobierz_ilosc())
			{
				cout << "Produkt jest jeszcze na magazynie" << endl;
				blad = 1;
			}
			else
			{
				lista.erase(lista.begin() + index);
			}
		}
		if (blad)
		{
			cout << "Enter - sprobuj ponownie" << endl << "Backspace - powrot do menu glownego" << endl;
			if (dalej())
				continue;
			else
				break;
		}
		else
		{
			cout << "Enter - usun inny produkt" << endl << "Backspace - powrot do menu glownego" << endl;
			if (dalej())
				continue;
			else
				break;
		}
	} while (true);
	zapisz_magazyn(lista);
	
}

void nowa_cena(vector<product*> &lista)
{
	do
	{
		string kod;
		int znalezione = 0;
		system("cls");
		cout << "Podaj kod produktu ktorego chcesz zmienic cene: ";
		cin >> kod;
		cout << "\n";
		int index = binary_search(lista, kod);
		product* wsk = lista[index];
		if (wsk->porownaj(kod))
		{
			wsk->zmien_cene();
			cout << "Pomyslnie zmieniono cene." << endl;
			cout << "Enter - zmien kolejna cene" << endl << "Backspace - wroc do menu glownego" << endl;
			if (dalej())
				continue;
			else
				break;
		}
		else
		{
			cout << "Nie znaleziono produktu o podanym kodzie. Sprobuj ponownie" << endl;
			cout << "Enter - sprobuj ponownie" << endl << "Backspace - wroc do menu glownego" << endl;
			if (dalej())
				continue;
			else
				break;
		}
	} while (1);
	zapisz_magazyn(lista);
}

void nowa_nazwa(vector<product*>& lista)
{
	do
	{
		string kod;
		int znalezione = 0;
		system("cls");
		cout << "Podaj kod produktu ktorego chcesz zmienic nazwe: ";
		cin >> kod;
		cout << "\n";
		int index = binary_search(lista, kod);
		product* wsk = lista[index];
		if (wsk->porownaj(kod))
		{
			wsk->zmien_nazwe();
			cout << "Pomyslnie zmieniono nazwe." << endl;
			cout << "Enter - zmien kolejna nazwe" << endl << "Backspace - wroc do menu glownego" << endl;
			if (dalej())
				continue;
			else
				break;
		}
		else
		{
			cout << "Nie znaleziono produktu o podanym kodzie. Sprobuj ponownie" << endl;
			cout << "Enter - sprobuj ponownie" << endl << "Backspace - wroc do menu glownego" << endl;
			if (dalej())
				continue;
			else
				break;
		}
	} while (1);
	zapisz_magazyn(lista);
}

//*Paragony/zwroty*
void dodaj_paragon(vector<product*> &lista, vector<paragon*>& rachunki)
{
	vector<pozycja> koszyk;
	do
	{
		string kod;
		system("cls");
		std::cout << "Podaj kod produktu ktory chcesz dodac do paragonu: ";
		cin >> kod;
		cout << "\n";
		int index = binary_search(lista, kod);
		if (lista[index]->porownaj(kod))
		{

			int ilosc;
			cout << lista[index]->pobierz_nazwe() << endl;
			cout << "Ile sztuk?" << endl;
			cin >> ilosc;
			bool pomin = true;
			for (int y = 0; y < koszyk.size(); y++)
			{
				if (lista[index]->pobierz_nazwe() == koszyk[y].nazwa)
				{
					koszyk[y].ilosc += ilosc;
					lista[index]->dodaj(-ilosc);
					pomin = false;
				}
			}
			if (pomin)
			{
				pozycja nowa{ lista[index]->pobierz_kod(), lista[index]->pobierz_nazwe(),ilosc,lista[index]->pobierz_cene() };
				koszyk.push_back(nowa);
				lista[index]->dodaj(-ilosc);
			}
			cout << "Enter - dodaj kolejny produkt" << endl << "Backspace - zapisz paragon" << endl;
			break;
		}
		else
		{
			cout << "Nie ma podanego produktu. Sprobuj ponownie." << endl;
			cout << "Enter - sprobuj ponownie" << endl << "Backspace - wroc do menu glownego" << endl;
		}
	}while (dalej());
	time_t czas;
	tm* data;
	std::time(&czas);
	data = localtime(&czas);
	rachunki.push_back(new paragon{utworz_numer(data),koszyk });
	zapisz_paragony(rachunki);
	zapisz_magazyn(lista);
}

void zwroc_towar(std::vector<product*>& lista, std::vector<paragon*>& rachunki)
{
	string numer;
	cout << "Podaj numer paragonu: ";
	cin >> numer;
	cout << endl;
	bool znalezione = 0;
	for (int i = 0; i < rachunki.size(); i++)
	{
		if (rachunki[i]->pobierz_numer()==numer)
		{
			znalezione = true;
			do
			{
				string kod;
				int ilosc;
				system("cls");
				cout << "Podaj kod i ilosc produktu ktory chcesz zwrocic: ";
				cin >> kod>>ilosc;
				cout << endl;
				if (rachunki[i]->znajdz_produkt(kod, ilosc))
				{
					double cena=rachunki[i]->znajdz_cene(kod);
					rachunki[i]->uzupelnij_sume(-(ilosc * cena));
					int index = binary_search(lista, kod);
					if (lista[index]->pobierz_kod() == kod)
					{
						lista[index]->dodaj(ilosc);
						cout << "Pomyslnie zwrocono towar" << endl;
						cout << "Enter - zwroc kolejny produkt z paragonu" << endl;
						cout << "Backspace - wroc do menu glownego";
						break;
					}
					else
					{
						cout << "Pomyslnie zwrocono towar" << endl;
						cout << "Enter - zwroc kolejny produkt z paragonu" << endl;
						cout << "Backspace - wroc do menu glownego";
						lista.push_back(new product(kod, rachunki[i]->nazwa_produktu(kod), "Dostepny", ilosc, cena));
					}
				}
			} while (dalej());
			if (rachunki[i]->rozmiar_listy() == 0)
			{
				rachunki.erase(rachunki.begin() + i);
			}
			zapisz_paragony(rachunki);
			break;
		}
	}
	if (!znalezione)
	{
		cout<<"Nie znaleziono paragonu o podanym numerze."<<endl;
	}
}

//*Raporty*
void raport_dobowy(std::vector<paragon*>& rachunki)
{
	time_t czas;
	tm* data;
	std::time(&czas);
	data = localtime(&czas);
	string numer = utworz_numer(data);
	for (int i = 8; i < 12; i++)
	{
		numer[i] = '0';
	}
	for (int i = rachunki.size()-1; i >= 0; i--)
	{
		if (numer < rachunki[i]->pobierz_numer())
		{
			cout << *rachunki[i] << endl;
		}
		else
		{
			break;
		}
	}
	enter();
}

void raport_miesieczny(std::vector<paragon*> rachunki)
{
	time_t czas;
	tm* data;
	std::time(&czas);
	data = localtime(&czas);
	string numer = utworz_numer(data);
	for (int i = 8; i < 14; i++)
	{
		numer[i] = '0';
	}
	{
		double liczba = atof(numer.c_str());
		liczba -= 100000000;
		numer = to_string(liczba);
	}
	for (int i = rachunki.size() - 1; i >= 0; i--)
	{
		if (numer < rachunki[i]->pobierz_numer())
		{
			cout << *rachunki[i] << endl;
		}
		else
		{
			break;
		}
	}
	enter();
}

void raport_roczny(std::vector<paragon*> rachunki)
{
	time_t czas;
	tm* data;
	std::time(&czas);
	data = localtime(&czas);
	string numer = utworz_numer(data);
	for (int i = 4; i < 14; i++)
	{
		numer[i] = '0';
	}
	{
		double liczba = atof(numer.c_str());
		liczba -= 10000000000;
		numer = to_string(liczba);
	}
	for (int i = rachunki.size() - 1; i >= 0; i--)
	{
		if (numer < rachunki[i]->pobierz_numer())
		{
			cout << *rachunki[i] << endl;
		}
		else
		{
			break;
		}
	}
	enter();
}

//*Remanent*
void remanent(vector<product*>& lista)
{
	vector<product*> spis;
	ifstream remanent("remanent.txt");
	if (remanent.is_open())
	{
		string kod, nazwa, status;
		int ilosc;
		double cena;
		getline(remanent,kod);
		while (remanent >> kod)
		{
			remanent >> nazwa;
			remanent >> status;
			remanent >> ilosc;
			remanent >> cena;
			spis.push_back(new product(kod, nazwa, status, ilosc, cena));
		}
	}
	remanent.close();
	ifstream dostawy("dostawy-przyjete.txt");
	if (dostawy.is_open())
	{
		string numer, kod, nazwa;
		int ilosc;
		while (dostawy >> numer)
		{
			while (dostawy >> kod)
			{
				if (kod == "$")
					break;
				dostawy >> nazwa;
				dostawy >> ilosc;
				if (spis[binary_search(spis, kod)]->pobierz_kod() == kod)
				{
					spis[binary_search(spis, kod)]->dodaj(ilosc);
				}
				else
				{
					binary_sort(spis, new product(kod, nazwa, "dostepny", ilosc, 0));
				}
			}
		}
	}
	dostawy.close();
	ifstream paragony("paragony.txt");
	if (paragony.is_open())
	{
		string numer, data, czas, kod, nazwa;
		char kosz;
		int ilosc;
		double cena,suma;
		while (paragony >> numer)
		{
			paragony >> data;
			paragony >> czas;
			while (paragony >> kod)
			{
				if (kod == "Suma:")
					break;
				paragony >> nazwa;
				paragony >> ilosc;
				paragony >> kosz;
				paragony >> cena;
				spis[binary_search(spis, kod)]->dodaj(-ilosc);
			}
			paragony >> suma;
			paragony >> kosz;
		}
	}
	for (int i = 0; i < spis.size(); i++)
	{
		string kod = spis[i]->pobierz_kod();
		int index = binary_search(lista, kod);
		if (lista[index]->pobierz_kod() == kod)
		{
			if (spis[i]->pobierz_ilosc() != lista[index]->pobierz_ilosc())
			{
				for (int i = spis.size() - 1; i >= 0; i--)
				{
					delete spis[i];
					spis.pop_back();
				}
				cout << "Cos poszlo nie tak" << endl;
				cout << "Wcisnij dowolny klawisz aby kontynuowac";
				_getch();
				return;
			}
		}
		else
		{
			if (spis[i]->pobierz_ilosc() != 0)
			{
				for (int i = spis.size() - 1; i >= 0; i--)
				{
					delete spis[i];
					spis.pop_back();
				}
				cout << "Cos poszlo nie tak" << endl;
				cout << "Wcisnij dowolny klawisz aby kontynuowac";
				_getch();
				return;
			}
		}
	}
	for (int i = spis.size()-1; i>=0; i--)
	{
		delete spis[i];
		spis.pop_back();
	}
	cout << "Remanent przeprowadzony pomyslnie"<<endl;
	cout << "Wcisnij dowolny klawisz aby kontynuowac";
	_getch();
	
}

//*Funkcje ogolne*

//Tworzenie numerow na podstawie daty

string utworz_numer(tm* data)
{
	string numer;
	numer += to_string(data->tm_year + 1900);
	if (data->tm_mon + 1 < 10)
	{
		numer += "0" + to_string(data->tm_mon+1);
	}
	else
	{
		numer += to_string(data->tm_mon+1);
	}
	if (data->tm_mday  < 10)
	{
		numer += "0" + to_string(data->tm_mday);
	}
	else
	{
		numer += to_string(data->tm_mday);
	}
	if (data->tm_hour < 10)
	{
		numer += "0" + to_string(data->tm_hour);
	}
	else
	{
		numer += to_string(data->tm_hour);
	}
	if (data->tm_min < 10)
	{
		numer += "0" + to_string(data->tm_min);
	}
	else
	{
		numer += to_string(data->tm_min);
	}
	if (data->tm_sec < 10)
	{
		numer += "0" + to_string(data->tm_sec);
	}
	else
	{
		numer += to_string(data->tm_sec);
	}
	return numer;
}

//Funkcje do obslugi klawiatury

bool dalej()
{
	int przycisk;
	do
	{
		przycisk = _getch();
		if (przycisk == 13)
		{
			return 1;
		}
	} while (przycisk != 8);
	return 0;
}

void enter()
{
	cout << "Wcisnij Enter aby kontynuowac" << endl;
	int guzik;
	guzik = _getch();
	while (guzik != 13)
	{
		guzik = _getch();
	}
}

// Wczytywanie/zapis danych z/do pliku

void wczytaj_magazyn(vector<product*> &lista)
{
	ifstream magazyn("magazyn.txt");
	if (magazyn.is_open())
	{
		int ilosc;
		string kodp, nazwa, status;
		float cena;
		getline(magazyn, kodp);
		while (magazyn >> kodp)
		{
			magazyn >> nazwa;
			magazyn >> status;
			magazyn >> ilosc;
			magazyn >> cena;
			lista.push_back(new product(kodp,nazwa,status,ilosc,cena));
		}
	}
	magazyn.close();
}

void zapisz_magazyn(vector<product*> &lista)
{
	ofstream magazyn_zapis("magazyn.txt");
	magazyn_zapis << pierwsza_linia << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		string linijka;
		lista[i]->wpisz(linijka);
		magazyn_zapis << linijka << endl;
	}
	magazyn_zapis.close();
}

void wczytaj_dostawy(vector<dostawa*> &zamowienia)
{
	ifstream dostawy("dostawy.txt");
	string nr_zam;
	while (dostawy >> nr_zam)
	{
		vector<element> pozycje;
		element pozycja;
		while (dostawy >> pozycja.kod)
		{
			if (pozycja.kod == "$")
				break;
			dostawy >> pozycja.nazwa;
			dostawy >> pozycja.ilosc;
			pozycje.push_back(pozycja);
		}
		zamowienia.push_back(new dostawa(nr_zam, pozycje));
	}
	dostawy.close();
}

void zapisz_dostawy(std::vector<dostawa*>& zamowienia)
{
	ofstream dostawy("dostawy.txt");
	for (int y = 0; y < zamowienia.size(); y++)
	{
		dostawy << *zamowienia[y];
	}
	dostawy.close();
}

void wczytaj_paragony(vector<paragon*>& rachunki)
{
	ifstream ksiegowa("paragony.txt");
	string numer, data, godzina;
	double suma;
	while (ksiegowa >> numer)
	{
		vector<pozycja> lista;
		ksiegowa>>data;
		data += "   ";
		ksiegowa >> godzina;
		data += godzina;
		string nazwa,kod;
		char kosz;
		int ilosc;
		double cena;
		while (ksiegowa >> kod)
		{
			if (kod == "Suma:")
				break;
			ksiegowa >> nazwa;
			ksiegowa >> ilosc;
			ksiegowa >> kosz;
			ksiegowa >> cena;
			pozycja nowa{kod, nazwa,ilosc,cena };
			lista.push_back(nowa);
		}
		ksiegowa >> suma;
		ksiegowa >> kosz;
		rachunki.push_back(new paragon(numer, data, lista, suma));
	}
	ksiegowa.close();
}

void zapisz_paragony(std::vector<paragon*>& rachunki)
{
	ofstream czyszczenie("paragony.txt", ios_base::trunc);
	czyszczenie.close();
	for (int i = 0; i < rachunki.size(); i++)
	{
		rachunki[i]->zapisz_paragon();
	}
}

//Wyszukiwanie i sortowanie binarne

int binary_search(std::vector<product*>& tab, std::string& value)
{
	int min = 0;
	int max = tab.size() - 1;
	while (1)
	{
		int avg = (min + max) / 2;
		if (stoi(tab[avg]->pobierz_kod()) < stoi(value))
		{
			min = avg;
		}
		else
		{
			if (stoi(tab[avg]->pobierz_kod()) > stoi(value))
			{
				max = avg;
			}
			else
				return avg;
		}
		if (min + 1 == max && max == tab.size()-1)
		{
			return max;
		}
		if (min==max || min+1==max)
		{
			return min;
		}
	}
}

void binary_sort(std::vector<product*>& tab, product* wsk)
{
	int min = 0;
	int max = tab.size() - 1;

	if (stoi(wsk->pobierz_kod()) > stoi(tab[max]->pobierz_kod()))
	{
		tab.push_back(wsk);
		return;
	}
	while (1)
	{
		int avg = (min + max) / 2;
		if (stoi(tab[avg]->pobierz_kod()) < stoi(wsk->pobierz_kod()))
		{
			min = avg;
		}
		else
		{
			max = avg;
		}
		if (min + 1 == max)
		{
			tab.insert(tab.begin() + max, wsk);
			return;
		}
	}
}
