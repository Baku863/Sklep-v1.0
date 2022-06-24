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
	metoda por�wnuje kod produktu z kodem podanym do funkcji
	@param kod - kod kt�ry ma byc por�wnany do kodu produktu
	@return 1 - je�li kody si� zgadzaj� lub 0 - je�li kody s� r�ne
	*/
	bool porownaj(std::string& kod);
	/**
	metoda tworzy linie tekstu do zapisu do pliku
	@param linijka - string do kt�rego zosta� ma zapisana linia tekstu
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
	metoda zwraca ilo�� produktu jako int
	@return ilo�� produktu
	*/
	int pobierz_ilosc();

	/**
	metoda zwraca cen� produktu jako double
	@return cena produktu
	*/
	double pobierz_cene();

	/**
	metoda pobiera nazwe i zwraca j� jako string
	@return nazwe produktu
	*/
	std::string pobierz_nazwe();
	/**
	metoda dodaje podana liczbe do ilosci danego produktu
	@param liczba - ilo�� kt�ra ma zosta� dodana do aktualnej ilo�ci produktu
	*/
	void dodaj(int liczba);

	/**
	operator por�wnania dla klasy product
	*/
	bool operator<(product& prawy);

private:

	/**
	zmienna przechowuj�ca kod produktu typu const string
	*/
	const std::string kod;

	/**
	zmienna przechowuj�ca nazw� produktu typu string
	*/
	std::string nazwa;

	/**
	zmienna przechowuj�ca status produktu typu string
	*/
	std::string status;

	/**
	zmienna przechowuj�ca ilo�� produktu typu int
	*/
	int ilosc;

	/**
	zmienna przechowuj�ca cen� produktu typu double
	*/
	double cena;
};
#endif
