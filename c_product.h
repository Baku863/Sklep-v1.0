/**
@file funkcje.h glowne funkcje wykonujace obliczenia i dzialania
*/
#ifndef C_PRODUCT_H
#define C_PRODUCT_H
#include "funkcje.h"

class product
{
public:
	product();
	product(std::string kod, std::string nazwa,std::string status,int ilosc,double cena);
	~product();
	/**
	metoda porównuje kod produktu z kodem podanym do funkcji
	@param kod - kod który ma byc porównany do kodu produktu
	@return 1 - jeœli kody siê zgadzaj¹ lub 0 - jeœli kody s¹ ró¿ne
	*/
	bool porownaj(std::string& kod);
	/**
	metoda tworzy linie tekstu do zapisu do pliku
	@param linijka - string do którego zostaæ ma zapisana linia tekstu
	*/
	void wpisz(std::string& linijka);
	/**
	metoda zmienia cene produktu
	*/
	void zmien_cene();
	/**
	metoda zmienia nazwe produktu
	*/
	void zmien_nazwe();

	/**
	metoda zwraca kod produktu jako string
	@return kod produktu
	*/
	std::string pobierz_kod();

	/**
	metoda zwraca iloœæ produktu jako int
	@return iloœæ produktu
	*/
	int pobierz_ilosc();

	/**
	metoda zwraca cenê produktu jako double
	@return cena produktu
	*/
	double pobierz_cene();

	/**
	metoda pobiera nazwe i zwraca j¹ jako string
	@return nazwe produktu
	*/
	std::string pobierz_nazwe();
	/**
	metoda dodaje podana liczbe do ilosci danego produktu
	@param liczba - iloœæ która ma zostaæ dodana do aktualnej iloœci produktu
	*/
	void dodaj(int liczba);

	/**
	operator porównania dla klasy product
	*/
	bool operator<(product& prawy);

private:

	/**
	zmienna przechowuj¹ca kod produktu typu const string
	*/
	const std::string kod;

	/**
	zmienna przechowuj¹ca nazwê produktu typu string
	*/
	std::string nazwa;

	/**
	zmienna przechowuj¹ca status produktu typu string
	*/
	std::string status;

	/**
	zmienna przechowuj¹ca iloœæ produktu typu int
	*/
	int ilosc;

	/**
	zmienna przechowuj¹ca cenê produktu typu double
	*/
	double cena;
};
#endif
