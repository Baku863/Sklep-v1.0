#ifndef C_PARAGON_H
#define C_PARAGON_H
#include "funkcje.h"
/**
struktura opisujaca jedna pozycje na paragonie
*/
struct pozycja
{
	/**
	zmienna przetrzymuj�ca kod produktu typu string
	*/
	std::string kod;

	/**
	zmienna przetrzymuj�ca nazw� produktu typu string
	*/
	std::string nazwa;

	/**
	zmienna przetrzymuj�ca ilo�� produkt�w typu int
	*/
	int ilosc;

	/**
	zmienna przetrzymuj�ca cen� jednej sztuki produktu typu double
	*/
	double cena;
public:
	/**
	metoda wpisuj�ca jedn� pozycj� do linijki tekstu 
	@param linijka - zmienna do kt�rej ma zostac zapisana linijka
	@param czy_kod - parametr okre�laj�cy czy do linijki ma byc wpisywany kod
	*/
	void wpisz(std::string& linijka, int czy_kod=0);
};
class paragon
{
public:
	paragon(std::string numer, std::vector<pozycja>& lista);
	paragon( std::string numer, std::string data, std::vector<pozycja> lista, double suma);

	/**
	metoda zapisuj�ca paragon do pliku
	*/
	void zapisz_paragon();

	/**
	metoda szukaj�ca produktu na paragonie i modyfikuj�ca ilo��(potrzebna do zwrot�w towar�w)
	@param kod - kod szukanego produktu
	@param ilosc - ilo�� o jak� ma zosta� zmniejszona ilo�� produktu na paragonie
	@return 1 - je�li produkt jest na paragonie lub 0 - je�li produktu nie ma
	*/
	bool znajdz_produkt(std::string& kod, int& ilosc);

	/**
	metoda zwracaj�ca cen� szukanego produktu na paragonie
	@param kod - kod szukanego produktu
	@return cen� szukanego produktu typu double
	*/
	double znajdz_cene(std::string& kod);

	/**
	metoda zmieniaj�ca sum� na paragonie
	@param wartosc - liczba o jak� ma zmienic sie suma
	*/
	void uzupelnij_sume(double wartosc);

	/**
	metoda zwraca nazwe poszukiwanego produktu
	@param kod - kod szukanego produktu
	@return nazwa produktu typu string
	*/
	std::string nazwa_produktu(std::string& kod);

	/**
	metoda zwracaj�ca rozmiar listy produkt�w
	@return ilo�� produkt�w
	*/
	int rozmiar_listy();

	friend std::ostream& operator<<(std::ostream& os,  paragon& para);

	/**
	metoda zwracaj�ca numer paragonu
	@return numer paragonu typu string
	*/
	std::string pobierz_numer();
private:
	/**
	zmienna przetrzymuj�ca numer paragonu typu const string
	*/
	const std::string numer;

	/**
	zmienna przetrzymuj�ca dat� paragonu typu string
	*/
	std::string data;

	/**
	wektor przetrzymuj�cy wszystkie produkty na paragonie
	*/
	std::vector<pozycja> lista;

	/**
	zmienna przetrzymuj�ca sum� paragonu typu double
	*/
	double suma;
};
#endif
