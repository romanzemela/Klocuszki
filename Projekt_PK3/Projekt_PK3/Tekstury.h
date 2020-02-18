#pragma once

#include <string>
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <assert.h>
namespace wszystkieTekstury {
	enum Tekstury {
		czerwony, zielony, niebieski, zolty, kowadelko, laserek, bombka, zaznaczenie, propozycja_ruchu
	};
}
//zalecane jest wczytanie u¿ywanych tekstur na pocz¹tku programu i przechowywanie ich w odpowiedniej zmiennej
//gra nie jest wiêc spowolniona wczytywaniem tekstur w jej trakcie
class MapaTekstur
{
public:
	MapaTekstur();
	void wczytaj(const wszystkieTekstury::Tekstury &id, const std::string &nazwaPliku);
	sf::Texture& get(const wszystkieTekstury::Tekstury &id);
private:
	//mapa zawieraj¹ca teksturê i jej id (id, tekstura)
	std::map<wszystkieTekstury::Tekstury, std::unique_ptr<sf::Texture>> mapaTekstur;

	void wczytajWszystkieTekstury();
};
