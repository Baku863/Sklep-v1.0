#ifndef MENU_H 
#define MENU_H
#include <iostream>
#include <string>
#include <conio.h>

/**
funkcja wyswietlajaca menu glowne programu
@return numer linijki
*/
int menu();

/**
funkcja wyswietlajaca menu "Magazyn"
@return (numer linijki z poprzedniego menu * 10) + numer aktualnie wybranej linijki 
*/
int menu1();

/**
funkcja wyswietlajaca menu "Oferta"
@return (numer linijki z poprzedniego menu * 10) + numer aktualnie wybranej linijki
*/
int menu2();

/**
funkcja wyswietlajaca menu "Paragony/zwroty"
@return (numer linijki z poprzedniego menu * 10) + numer aktualnie wybranej linijki
*/
int menu3();

/**
funkcja wyswietlajaca menu "Raporty"
@return (numer linijki z poprzedniego menu * 10) + numer aktualnie wybranej linijki
*/
int menu4();

#endif
