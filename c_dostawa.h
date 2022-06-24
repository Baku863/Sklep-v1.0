#ifndef C_DOSTAWA_H
#define C_DOSTAWA_H
#include "funkcje.h"
/**
struktura opisujaca jeden element(produkt) dostawy 
*/
struct element
{
	/**
	skladowa zawierajaca unikalny kod produktu
	*/
	std::string kod;
	/**
	skladowa zawierajaca nazwe produktu
	*/
	std::string nazwa;
	/**
	skladowa zawierajaca ilosc zamowionego produktu
	*/
	int ilosc;
};
class dostawa
{
public:
	dostawa(std::string numer, std::vector<element> &lista);
	/**
	metoda zapisujaca dostawe do pliku 
	*/
	void zapisz_dostawe();
	/**
	metoda porownujaca numer zamowienia dostawy z numerem podanym do funkcji
	@param numer - numer ktory jest porownywany do produktu
	*/
	bool porownaj(std::string numer);
	/**
	metoda uzupelniajaca magazyn przez wskazana dostawe
	@param lista - wektor zawierajacy stan magazynowy
	*/
	void uzupelnij_magazyn(std::vector<class product*> lista);
	/**
	operator strumienia <<
	*/
	friend std::ostream& operator<<(std::ostream& os,const dostawa& zamowienie);

private:
	/**
	skladowa zawierajaca unikalny numer dostawy
	*/
	const std::string nr_zamowienia;
	/**
	skladowa zawierajaca wektor z przedmiotami ktore sa w dostawie
	*/
	std::vector<element> pozycje;
};
#endif