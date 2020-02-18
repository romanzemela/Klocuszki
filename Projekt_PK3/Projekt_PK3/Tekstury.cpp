#include "Tekstury.h"

MapaTekstur::MapaTekstur()
{
	wczytajWszystkieTekstury();
}

void MapaTekstur::wczytaj(const wszystkieTekstury::Tekstury &id, const std::string &nazwaPliku)
{	
	sf::Texture * tekstura = new sf::Texture;	
	if (!tekstura->loadFromFile(nazwaPliku))
	{
		std::cout << "B³¹d wczytywania pliku" + nazwaPliku << std::endl;		
	}
	mapaTekstur.insert(std::make_pair(id, tekstura));
}

sf::Texture & MapaTekstur::get(const wszystkieTekstury::Tekstury &id)
{
	auto found = mapaTekstur.find(id);
	return *found->second; //wska¿nik na szukan¹ teksturê
}

void MapaTekstur::wczytajWszystkieTekstury()
{
	wczytaj(wszystkieTekstury::bombka, "tekstury/bombka.png");
	wczytaj(wszystkieTekstury::kowadelko, "tekstury/kowadelko.png");
	wczytaj(wszystkieTekstury::laserek, "tekstury/laserek.png");
	wczytaj(wszystkieTekstury::zolty, "tekstury/zolty.png");
	wczytaj(wszystkieTekstury::czerwony, "tekstury/czerwony.png");
	wczytaj(wszystkieTekstury::zielony, "tekstury/zielony.png");
	wczytaj(wszystkieTekstury::niebieski, "tekstury/niebieski.png");
	wczytaj(wszystkieTekstury::zaznaczenie, "tekstury/zaznaczenie.png");
	wczytaj(wszystkieTekstury::propozycja_ruchu, "tekstury/propozycja_ruchu.png");
}
