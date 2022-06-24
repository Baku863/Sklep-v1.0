#ifndef C_PARAGON_H
#define C_PARAGON_H
#include "funkcje.h"
/**
struktura opisujaca jedna pozycje na paragonie
*/
struct pozycja
{
	/**
	zmienna przetrzymuj¹ca kod produktu typu string
	*/
	std::string kod;

	/**
	zmienna przetrzymuj¹ca nazwê produktu typu string
	*/
	std::string nazwa;

	/**
	zmienna przetrzymuj¹ca iloœæ produktów typu int
	*/
	int ilosc;

	/**
	zmienna przetrzymuj¹ca cenê jednej sztuki produktu typu double
	*/
	double cena;
public:
	/**
	metoda wpisuj¹ca jedn¹ pozycjê do linijki tekstu 
	@param linijka - zmienna do której ma zostac zapisana linijka
	@param czy_kod - parametr okreœlaj¹cy czy do linijki ma byc wpisywany kod
	*/
	void wpisz(std::string& linijka, int czy_kod=0);
};
class paragon
{
public:
	paragon(std::string numer, std::vector<pozycja>& lista);
	paragon( std::string numer, std::string data, std::vector<pozycja> lista, double suma);

	/**
	metoda zapisuj¹ca paragon do pliku
	*/
	void zapisz_paragon();

	/**
	metoda szukaj¹ca produktu na paragonie i modyfikuj¹ca iloœæ(potrzebna do zwrotów towarów)
	@param kod - kod szukanego produktu
	@param ilosc - iloœæ o jak¹ ma zostaæ zmniejszona iloœæ produktu na paragonie
	@return 1 - jeœli produkt jest na paragonie lub 0 - jeœli produktu nie ma
	*/
	bool znajdz_produkt(std::string& kod, int& ilosc);

	/**
	metoda zwracaj¹ca cenê szukanego produktu na paragonie
	@param kod - kod szukanego produktu
	@return cenê szukanego produktu typu double
	*/
	double znajdz_cene(std::string& kod);

	/**
	metoda zmieniaj¹ca sumê na paragonie
	@param wartosc - liczba o jak¹ ma zmienic sie suma
	*/
	void uzupelnij_sume(double wartosc);

	/**
	metoda zwraca nazwe poszukiwanego produktu
	@param kod - kod szukanego produktu
	@return nazwa produktu typu string
	*/
	std::string nazwa_produktu(std::string& kod);

	/**
	metoda zwracaj¹ca rozmiar listy produktów
	@return iloœæ produktów
	*/
	int rozmiar_listy();

	friend std::ostream& operator<<(std::ostream& os,  paragon& para);

	/**
	metoda zwracaj¹ca numer paragonu
	@return numer paragonu typu string
	*/
	std::string pobierz_numer();
private:
	/**
	zmienna przetrzymuj¹ca numer paragonu typu const string
	*/
	const std::string numer;

	/**
	zmienna przetrzymuj¹ca datê paragonu typu string
	*/
	std::string data;

	/**
	wektor przetrzymuj¹cy wszystkie produkty na paragonie
	*/
	std::vector<pozycja> lista;

	/**
	zmienna przetrzymuj¹ca sumê paragonu typu double
	*/
	double suma;
};
#endif
