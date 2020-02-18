#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Plansza.h"
#include "Tekstury.h"

namespace stany {
	enum StanGry {
		czekanie_na_gracza, wybrany_klocek, zbijanie_klockow
	};
}

class Game
{
public:
	Game();
	void run();

private:
	stany::StanGry stanGry;
	void processEvents(); //podzia� na metody, zgodnie z zaleceniami spo�eczno�ci SFML
	void render();
	MapaTekstur mapaTekstur;
	Plansza plansza;
	int zaznaczonyKlocuszekX;
	int zaznaczonyKlocuszekY;
	int iteratorCzekania;
	

	sf::RenderWindow mWindow;	
};