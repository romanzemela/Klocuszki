#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(800, 640), "Epicki Niszczyciel Klocuszkow 3000")
	, mapaTekstur()
	, plansza(&mapaTekstur)
	{
	mWindow.setFramerateLimit(60);
	sf::Image ikona;
	ikona.loadFromFile("tekstury/ikona.png");
	mWindow.setIcon(128, 128, ikona.getPixelsPtr());
	Klocuszek::mapaTekstur = &mapaTekstur;
	plansza.robPlansze();
	stanGry = stany::czekanie_na_gracza;
	}

void Game::run()
{
	while (mWindow.isOpen()) //g³ówna pêtla
	{ //wywo³uje wszytko co potrzebne do dzia³ania gry		
		processEvents();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event)) 
	{		
		if (event.type == sf::Event::Closed) //zamykanie okna po naciœniêciu X(zamknij)
			mWindow.close();		
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (stanGry==stany::czekanie_na_gracza) {
				if (event.mouseButton.x < 640 && event.mouseButton.x > 0 && event.mouseButton.y < 640 && event.mouseButton.y > 0) {
					int x = event.mouseButton.x / 64;
					int y = event.mouseButton.y / 64;
					plansza.plansza[x][y].spriteObramowania.setTexture(this->mapaTekstur.get(wszystkieTekstury::zaznaczenie));
					plansza.plansza[x][y].spriteObramowania.setPosition(x * 64, y * 64);
					zaznaczonyKlocuszekX = x;
					zaznaczonyKlocuszekY = y;
					stanGry = stany::wybrany_klocek;
					plansza.plansza[x][y].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::wybrany;
					if (x != 9) plansza.plansza[x + 1][y].PokazProponowanyRuch();
					if (x != 0) plansza.plansza[x - 1][y].PokazProponowanyRuch();
					if (y != 9) plansza.plansza[x][y + 1].PokazProponowanyRuch();
					if (y != 0) plansza.plansza[x][y - 1].PokazProponowanyRuch();					
				}
			}
			else if (stanGry==stany::wybrany_klocek)
			{
				if (event.mouseButton.x < 640 && event.mouseButton.x > 0 && event.mouseButton.y < 640 && event.mouseButton.y > 0) {
					int x = event.mouseButton.x / 64;
					int y = event.mouseButton.y / 64;
					if (x==zaznaczonyKlocuszekX && y == zaznaczonyKlocuszekY)
					{
						plansza.plansza[x][y].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia; //tutaj odklikamy zaznaczony klocek (anulowanie ruchu)
						if (x != 9) plansza.plansza[x + 1][y].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
						if (x != 0) plansza.plansza[x - 1][y].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
						if (y != 9) plansza.plansza[x][y + 1].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
						if (y != 0) plansza.plansza[x][y - 1].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
						stanGry = stany::czekanie_na_gracza;
					}
					if (plansza.plansza[x][y].stanRamkiKlocuszka == stanyZaznaczeniaKlocuszka::proponowany)
					{
						kolor::KolorKlocuszka tmp = plansza.plansza[x][y].kolorKlocuszka;
						plansza.plansza[x][y].zmienKolorKlocuszka(plansza.plansza[zaznaczonyKlocuszekX][zaznaczonyKlocuszekY].kolorKlocuszka);
						plansza.plansza[zaznaczonyKlocuszekX][zaznaczonyKlocuszekY].zmienKolorKlocuszka(tmp);

						if (plansza.Wykonaj_ruch(x, y, zaznaczonyKlocuszekX, zaznaczonyKlocuszekY))
						{
							stanGry = stany::zbijanie_klockow;							
							plansza.plansza[zaznaczonyKlocuszekX][zaznaczonyKlocuszekY].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
							if (x != 9 && x!=8) plansza.plansza[zaznaczonyKlocuszekX + 1][zaznaczonyKlocuszekY].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
							if (x != 0) plansza.plansza[zaznaczonyKlocuszekX - 1][zaznaczonyKlocuszekY].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
							if (y != 9) plansza.plansza[zaznaczonyKlocuszekX][zaznaczonyKlocuszekY + 1].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;
							if (y != 0) plansza.plansza[zaznaczonyKlocuszekX][zaznaczonyKlocuszekY - 1].stanRamkiKlocuszka = stanyZaznaczeniaKlocuszka::brak_zaznaczenia;							
						}	
						else //jak ruch by³ nieprawid³owy, to go cofamy
						{
							kolor::KolorKlocuszka tmp = plansza.plansza[x][y].kolorKlocuszka;
							plansza.plansza[x][y].zmienKolorKlocuszka(plansza.plansza[zaznaczonyKlocuszekX][zaznaczonyKlocuszekY].kolorKlocuszka);
							plansza.plansza[zaznaczonyKlocuszekX][zaznaczonyKlocuszekY].zmienKolorKlocuszka(tmp);
						}
					}					
				}
			}			
		}	
		else if (stanGry == stany::zbijanie_klockow) {
			sf::Time czas = sf::seconds(0.4f);
			sf::sleep(czas);
			if(plansza.Uzupe³nij_plansze()==false) stanGry = stany::czekanie_na_gracza;
		}
	}
}


void Game::render()
{
	mWindow.clear();
	mWindow.draw(plansza);
	mWindow.display();
}