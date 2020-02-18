#pragma once
#include "Klocuszek.h"
class Plansza : public sf::Drawable
{
private:	
	MapaTekstur *tekstury;
public:
	Klocuszek plansza[10][10];
	//Wype³nia pocz¹tkow¹ planszê losowymi klocuszkami i upewnia siê, ¿e nie istnieje ju¿ gdzieœ zbijalna sekwencja
	Plansza(MapaTekstur * mapaTekstur);
	void robPlansze();
	void SzukajPoziomychCiagow(bool &jeszczeRaz);
	void SzukajPionowychCiagow(bool &jeszczeRaz);
	~Plansza();
	// Funkcja sprawdza czy istnieje jakikolwiek prawid³owy ruch na planszy. Jest wywo³ywana rêcznie przez gracza, wiêc nie spowolni gry swoj¹ z³o¿onoœci¹
	bool Czy_jest_ruch_na_planszy();
	// Zbiera informacje jakie 2 klocuszki gracz chce zamieniæ i wywo³uje metodê sprawdŸ poprawnoœæ.
	bool Wykonaj_ruch(int x1, int y1, int x2, int y2);
	// Sprawdza, czy ruch wykonany przez gracza jest prawid³owy
	bool SprawdŸ_poprawnoœæ_ruchu(int x, int y);

	// Uzupe³nia luki w planszy po zniszczonych klocuszkach i zwraca, czy powsta³y combosy
	bool Uzupe³nij_plansze();



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

