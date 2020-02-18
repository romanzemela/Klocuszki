#include "Klocuszek.h"

MapaTekstur * Klocuszek::mapaTekstur = nullptr;


kolor::KolorKlocuszka Klocuszek::getKolorKlocuszka() {
	return this->kolorKlocuszka;
}



Klocuszek::Klocuszek()
{
}

Klocuszek::Klocuszek(int _rzad, int _kolumna, kolor::KolorKlocuszka kolor, rodzaj::RodzajKlocuszka rodzaj)
{
	rzad = _rzad;
	kolumna = _kolumna;
	kolorKlocuszka = kolor;
	rodzajKlocuszka = rodzaj;
	switch (kolor)
	{
	case kolor::czerwony:
		spriteKlocuszkaKolor.setTexture(mapaTekstur->get(wszystkieTekstury::czerwony));
		break;
	case kolor::zielony:
		spriteKlocuszkaKolor.setTexture(mapaTekstur->get(wszystkieTekstury::zielony));
		break;
	case kolor::niebieski:
		spriteKlocuszkaKolor.setTexture(mapaTekstur->get(wszystkieTekstury::niebieski));
		break;
	case kolor::zolty:
		spriteKlocuszkaKolor.setTexture(mapaTekstur->get(wszystkieTekstury::zolty));
		break;
	}
	switch (rodzaj)
	{
	case rodzaj::bombka:
		spriteKlocuszkaRodzaj.setTexture(mapaTekstur->get(wszystkieTekstury::bombka));
		break;
	case rodzaj::kowade³ko:
		spriteKlocuszkaRodzaj.setTexture(mapaTekstur->get(wszystkieTekstury::kowadelko));
		break;
	case rodzaj::laserek:
		spriteKlocuszkaRodzaj.setTexture(mapaTekstur->get(wszystkieTekstury::laserek));
		break;
	}

	spriteKlocuszkaKolor.setPosition(_rzad * rozmiar, _kolumna * rozmiar);
	spriteKlocuszkaRodzaj.setPosition((_rzad * rozmiar)+16, (+kolumna * rozmiar) + 16); //16 pikseli, ¿eby 32 pikselowy obrazek, by³ na œrodku 64 piskelowego
}


void Klocuszek::zmienKolorKlocuszka(kolor::KolorKlocuszka _kolorKlocuszka)
{
	this->kolorKlocuszka = _kolorKlocuszka;
	switch (_kolorKlocuszka)
	{
	case kolor::czerwony:
		spriteKlocuszkaKolor.setTexture(mapaTekstur->get(wszystkieTekstury::czerwony));
		break;
	case kolor::zielony:
		spriteKlocuszkaKolor.setTexture(mapaTekstur->get(wszystkieTekstury::zielony));
		break;
	case kolor::niebieski:
		spriteKlocuszkaKolor.setTexture(mapaTekstur->get(wszystkieTekstury::niebieski));
		break;
	case kolor::zolty:
		spriteKlocuszkaKolor.setTexture(mapaTekstur->get(wszystkieTekstury::zolty));
		break;
	}
}


Klocuszek::~Klocuszek()
{	
}

void Klocuszek::PokazProponowanyRuch()
{
	this->spriteObramowania.setTexture(mapaTekstur->get(wszystkieTekstury::propozycja_ruchu));
	this->spriteObramowania.setPosition(rzad *64, kolumna * 64);
	this->stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::proponowany;
}
