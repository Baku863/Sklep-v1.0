#ifndef FUNKCJE_H
#define FUNKCJE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <ctime>
#include "c_product.h"
#include "c_dostawa.h"
#include "c_paragon.h"



//*Magazyn*

/**
funkcja ktora ma wyswietlic stan magazynowy sklepu
@param lista - wektor zawierajacy stan magazynowy
*/
void wyswietl_magazyn(std::vector<class product*> &lista);
/**
funkcja ktora ma dodac nowa dostawe
@param lista - wektor zawierajacy stan magazynowy
@param zamowienia - wektor zawierajacy nieprzyjete dostawy
*/
void dodaj_dostawe(std::vector<product*> &lista, std::vector<class dostawa*>& zamowienia);
/**
funkcja ktora ma przyjac nowa dostawe i uzupelnic magazyn
@param lista - wektor zawierajacy stan magazynowy
@param zamowienia - wektor zawierajacy nieprzyjete dostawy
*/
void przyjmij_dostawe(std::vector<product*> &lista, std::vector<class dostawa*> &zamowienia);

//*Oferta*

/**
funkcja ktora ma dodac produkt do oferty sklepu
@param lista - wektor zawierajacy stan magazynowy
*/
void dodaj_produkt(std::vector<product*> &lista);
/**
funkcja ktora ma usunac produkt z oferty sklepu
@param lista - wektor zawierajacy stan magazynowy
*/
void usun_produkt(std::vector<product*> &lista);
/**
funkcja ktora ma zmienic cene produktu w sklepie
@param lista - wektor zawierajacy stan magazynowy
*/
void nowa_cena(std::vector<product*>& lista);
/**
funkcja ktora ma zmienic nazwe produktu w sklepie
@param lista - wektor zawierajacy stan magazynowy
*/
void nowa_nazwa(std::vector<product*> &lista);

//*Paragony/zwroty*

/**
funkcja generujaca paragon rownoznaczna sprzedazy artykulow
@param lista - wektor zawierajacy stan magazynowy
@param zamowienia - wektor zawierajacy nieprzyjete dostawy
*/
void dodaj_paragon(std::vector<product*> &lista, std::vector<class paragon*>& zamowienia);

/**
funkcja pozwalajaca zwrocic towar na magazyn
@param lista - wektor zawierajacy stan magazynowy
@param rachunki - wektor zawierajacy wszystkie paragony
*/
void zwroc_towar(std::vector<product*>& lista, std::vector<class paragon*>& rachunki);

//*Raporty*

/**
funkcja generujaca raport dobowy tz. drukujaca wszystkie transakcje(paragony) aktualnego dnia
@param rachunki - wektor zawierajacy wszystkie paragony
*/
void raport_dobowy(std::vector<paragon*>& rachunki);

/**
funkcja generujaca raport miesieczny tz. drukujaca wszystkie transakcje(paragony) aktualnego miesiaca
@param rachunki - wektor zawierajacy wszystkie paragony
*/
void raport_miesieczny(std::vector<paragon*> rachunki);

/**
funkcja generujaca raport roczny tz. drukujaca wszystkie transakcje(paragony) aktualnego roku
@param rachunki - wektor zawierajacy wszystkie paragony
*/
void raport_roczny(std::vector<paragon*> rachunki);

//*Remanent*

/**
funkcja dokonujaca remanentu
@param lista - wektor zawierajacy stan magazynowy
@param rachunki - wektor zawierajacy wszystkie paragony
*/
void remanent(std::vector<product*>& lista);

//*Funkcje ogolne*

/**
stala zmienna odpowiadajaca pierwszej linijce magazynu
*/
const std::string pierwsza_linia = "Kod      Nazwa                  Status     Szt.    Cena   ";
/**
funkcja tworzaca numer na podstawie aktualnego czasu
@param data - wskaznik na zmienna typu tm do wyznaczenia aktualnego czasu
*/
std::string utworz_numer(tm* data);

/**
funkcja czekajaca na decyzje uzytkownika czy ponowic probe czy powrocic do menu glwonego
*/
bool dalej();

/**
funkcja czekajaca na wcisniecie przycisku enter
*/
void enter();

/**
funkcja wczytujaca stan magazynu z pliku do vector<product*>
@param lista - vector<product*> do którego ma zostaæ wczytany stan magazynowy
*/
void wczytaj_magazyn(std::vector<product*> &lista);
/**
funkcja zapisujaca do pliku vector<product*>
@param lista - vector<product*> z którego ma zostaæ zapisany stan magazynowy
*/
void zapisz_magazyn(std::vector<product*> &lista);

/**
funkcja wczytujaca wszytskie planowane dostawy z pliku do vector<dostawa*>
@param zamowienia - vector<dostawa*> do którego maj¹ zostaæ wczytane planowane zamówienia
*/
void wczytaj_dostawy(std::vector<dostawa*> &zamowienia);

/**
funkcja zapisujaca do pliku vector<dostawa*>
@param zamowienia - vector<dostawa*> z którego maj¹ zostaæ zapisane planowane zamówienia
*/
void zapisz_dostawy(std::vector<dostawa*>& zamowienia);

/**
funkcja wczytujaca wszystkie paragony z pliku do vector<paragon*>
@param rachunki - vector<paragon*> do którego maj¹ zostaæ wczytane wszystkie paragony
*/
void wczytaj_paragony(std::vector<paragon*>& rachunki);

/**
funkcja zapisujaca do pliku vector<paragon*>
@param rachunki - vector<paragon*> z którego maj¹ zostaæ zapisane wszystkie paragony
*/
void zapisz_paragony(std::vector<paragon*>& rachunki);

/**
funkcja wyszukiwania binarnego 
@param tab - tablica ktora ma zostac przeszukana
@param value - wartosc szukana w tablicy
*/
int binary_search(std::vector<product*>&tab, std::string &value);

/**
funkcja sortujaca na podstawie wyszukiwania binarnego ktora wklada do zbioru nowy element
@param tab - tablica do ktorej dodajemy nowy element
@param wsk - wskaznik na element ktory chcemy dodac
*/
void binary_sort(std::vector<product*>& tab, product* wsk);
#endif

