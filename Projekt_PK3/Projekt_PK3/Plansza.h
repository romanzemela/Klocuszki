#pragma once
#include "Klocuszek.h"
class Plansza : public sf::Drawable
{
private:	
	MapaTekstur *tekstury;
public:
	Klocuszek plansza[10][10];
	//Wype�nia pocz�tkow� plansz� losowymi klocuszkami i upewnia si�, �e nie istnieje ju� gdzie� zbijalna sekwencja
	Plansza(MapaTekstur * mapaTekstur);
	void robPlansze();
	void SzukajPoziomychCiagow(bool &jeszczeRaz);
	void SzukajPionowychCiagow(bool &jeszczeRaz);
	~Plansza();
	// Funkcja sprawdza czy istnieje jakikolwiek prawid�owy ruch na planszy. Jest wywo�ywana r�cznie przez gracza, wi�c nie spowolni gry swoj� z�o�ono�ci�
	bool Czy_jest_ruch_na_planszy();
	// Zbiera informacje jakie 2 klocuszki gracz chce zamieni� i wywo�uje metod� sprawd� poprawno��.
	bool Wykonaj_ruch(int x1, int y1, int x2, int y2);
	// Sprawdza, czy ruch wykonany przez gracza jest prawid�owy
	bool Sprawd�_poprawno��_ruchu(int x, int y);

	// Uzupe�nia luki w planszy po zniszczonych klocuszkach i zwraca, czy powsta�y combosy
	bool Uzupe�nij_plansze();



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				target.draw(plansza[i][j]);
			}
		}
	}
	
};

