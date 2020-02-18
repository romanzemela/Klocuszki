#pragma once
#include "Tekstury.h"
namespace kolor {
	enum KolorKlocuszka { czerwony, zielony, niebieski, zolty };
}

namespace rodzaj {
	enum RodzajKlocuszka { zwyk³y, bombka, kowade³ko, laserek };
}

namespace stanyKlocuszka {
	enum StanKlocuszka {
		domyslny, do_zniszczenia
	};
}

namespace stanyZaznaczeniaKlocuszka {
	enum StanRamkiKlocuszka {
		brak_zaznaczenia, wybrany, proponowany
	};
}


class Klocuszek : public sf::Drawable
{
private:	
	rodzaj::RodzajKlocuszka rodzajKlocuszka;	
	static const int rozmiar = 64; //w pikselach		
	sf::Sprite spriteKlocuszkaKolor;
	sf::Sprite spriteKlocuszkaRodzaj; //tutaj na klocuszka nak³adamy teksturê specjaln¹ np. bombka, laserek, kowade³ko	
public:
	kolor::KolorKlocuszka kolorKlocuszka;
	stanyKlocuszka::StanKlocuszka stanKlocuszka = stanyKlocuszka::domyslny;
	stanyZaznaczeniaKlocuszka::StanRamkiKlocuszka stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
	sf::Sprite spriteObramowania;
	static MapaTekstur *mapaTekstur;
	kolor::KolorKlocuszka getKolorKlocuszka();
	int rzad;
	int kolumna;
	Klocuszek();
	Klocuszek(int _rzad, int _kolumna, kolor::KolorKlocuszka kolor, rodzaj::RodzajKlocuszka rodzaj);
	~Klocuszek();
	void zmienKolorKlocuszka(kolor::KolorKlocuszka _kolorKlocuszka);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if(stanRamkiKlocuszka ==stanyZaznaczeniaKlocuszka::proponowany|| stanRamkiKlocuszka == stanyZaznaczeniaKlocuszka::wybrany)target.draw(spriteObramowania);
		if (stanKlocuszka != stanyKlocuszka::do_zniszczenia)target.draw(spriteKlocuszkaKolor);
		if (stanKlocuszka != stanyKlocuszka::do_zniszczenia)target.draw(spriteKlocuszkaRodzaj);
	}

	void PokazProponowanyRuch();
};

