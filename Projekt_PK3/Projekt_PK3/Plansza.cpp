#include "Plansza.h"
#include <cstdlib>
#include <ctime>


//Wype�nia pocz�tkow� plansz� losowymi klocuszkami i upewnia si�, �e nie istnieje ju� gdzie� zbijalna sekwencja
Plansza::Plansza(MapaTekstur * mapaTekstur)
{
	tekstury = mapaTekstur;
}


void Plansza::robPlansze() {
	srand((int)time(0));
	for (int i = 0; i < 10; i++) //10 to rozmiar planszy
	{
		for (int j = 0; j < 10; j++) //10 to rozmiar planszy
		{
			Klocuszek klocuszek(i, j, static_cast<kolor::KolorKlocuszka>(rand() % 4), rodzaj::zwyk�y);
			this->plansza[i][j] = klocuszek;
		}
	}
	bool jeszczeRaz = 0;
	do
	{
		jeszczeRaz = 0;
		SzukajPoziomychCiagow(jeszczeRaz);
		SzukajPionowychCiagow(jeszczeRaz);
	} while (jeszczeRaz);
}

void Plansza::SzukajPionowychCiagow(bool &jeszczeRaz)
{
	srand((int)time(0));
	int ciag = 0;
	for (int i = 0; i < 10; i++) //10 to rozmiar planszy
	{
		kolor::KolorKlocuszka tmpKolor = this->plansza[i][0].getKolorKlocuszka();
		for (int j = 0; j < 10; j++) //10 to rozmiar planszy
		{
			if (tmpKolor == this->plansza[i][j].getKolorKlocuszka()) //Je�eli dochodzimy do prawej �ciany, to i tak ko�czymy ci�g
			{
				ciag++;
			}
			else
			{
				if (ciag > 2)
				{
					for (int k = 0; k < ciag; k++)
					{
						Klocuszek klocuszek(i, (j - k), static_cast<kolor::KolorKlocuszka>(rand() % 4), rodzaj::zwyk�y);
						this->plansza[i][j - k] = klocuszek;
					}
					ciag = 1;
					jeszczeRaz = 1;
				}
				else
				{
					tmpKolor = this->plansza[i][j].getKolorKlocuszka();
					ciag = 1;
				}
			}
		}
		if (ciag > 2)
		{
			for (int k = 0; k < ciag; k++)
			{
				Klocuszek klocuszek(i, (9 - k), static_cast<kolor::KolorKlocuszka>(rand() % 4), rodzaj::zwyk�y);
				this->plansza[i][9 - k] = klocuszek;
			}
			ciag = 1;
			jeszczeRaz = 1;
		}
		else
		{
			ciag = 1;
		}
	}
}

void Plansza::SzukajPoziomychCiagow(bool &jeszczeRaz)
{
	srand((int)time(0));
	int ciag = 0;
	for (int i = 0; i < 10; i++) //10 to rozmiar planszy
	{

		kolor::KolorKlocuszka tmpKolor = this->plansza[0][i].getKolorKlocuszka();
		for (int j = 1; j < 10; j++) //10 to rozmiar planszy
		{
			if (tmpKolor == this->plansza[j][i].getKolorKlocuszka()) //Je�eli dochodzimy do dolnej �ciany, to i tak ko�czymy ci�g
			{
				ciag++;
			}
			else
			{
				if (ciag > 2)
				{
					for (int k = 0; k < ciag; k++)
					{
						Klocuszek klocuszek((j - k), i, static_cast<kolor::KolorKlocuszka>(rand() % 4), rodzaj::zwyk�y);
						this->plansza[j - k][i] = klocuszek;
					}
					ciag = 1;
					jeszczeRaz = 1;
				}
				else
				{
					tmpKolor = this->plansza[j][i].getKolorKlocuszka();
					ciag = 1;
				}
			}
		}
		if (ciag > 2)
		{
			for (int k = 0; k < ciag; k++)
			{
				Klocuszek klocuszek((9 - k), i, static_cast<kolor::KolorKlocuszka>(rand() % 4), rodzaj::zwyk�y);
				this->plansza[9 - k][i] = klocuszek;
			}
			ciag = 1;
			jeszczeRaz = 1;
		}
		else
		{
			ciag = 1;
		}
	}
}

Plansza::~Plansza()
{
}


// Funkcja sprawdza czy istnieje jakikolwiek prawid�owy ruch na planszy. Jest wywo�ywana r�cznie przez gracza, wi�c nie spowolni gry swoj� z�o�ono�ci�
bool Plansza::Czy_jest_ruch_na_planszy()
{
	kolor::KolorKlocuszka kolorSekwencji;
	int dlugoscSekwencji = 0;
	//Najprierw szukamy poziomych sekwencji
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//this->plansza[i][j] 
			//ALE TU B�DZIE SZALONY ALGORYTM , ZOSTAWIAM TO NA KONIEC
		}
	}
	return false;
}


// Zbiera informacje jakie 2 klocuszki gracz chce zamieni� i wywo�uje metod� sprawd� poprawno��.
// Zwraca false je�li �adne klocuszki nie uformowa�y ci�gu
bool Plansza::Wykonaj_ruch(int x1, int y1, int x2, int y2) //
{
	bool wynik1 = Sprawd�_poprawno��_ruchu(x1, y1);
	bool wynik2 = Sprawd�_poprawno��_ruchu(x2, y2);
	if (wynik1 || wynik2) {
		return 1;
	}
	else {
		return 0;
	}

}




// Sprawdza, czy ruch wykonany przez gracza jest prawid�owy
bool Plansza::Sprawd�_poprawno��_ruchu(int x, int y)
{
	bool czyRuchMialSens = false;
	int ciag = 1;
	for (int i = x + 1; i < 10; i++) //szukamy najpierw w pionie
	{
		if (plansza[x][y].getKolorKlocuszka() == plansza[i][y].getKolorKlocuszka())
		{
			ciag++;
		}
		else { break; }
	}
	for (int i = x - 1; i > -1; i--)
	{
		if (plansza[x][y].getKolorKlocuszka() == plansza[i][y].getKolorKlocuszka())
		{
			ciag++;
		}
		else {
			if (ciag > 2)
			{
				for (int j = 0; j < ciag; j++) {
					plansza[i + 1 + j][y].stanKlocuszka = stanyKlocuszka::do_zniszczenia;
				}
				czyRuchMialSens = true;
			}
			break;
		}
	}
	ciag = 1;
	for (int i = y + 1; i < 10; i++) ////potem w poziomie
	{
		if (plansza[x][y].getKolorKlocuszka() == plansza[x][i].getKolorKlocuszka())
		{
			ciag++;
		}
		else { break; }
	}
	for (int i = y - 1; i > -1; i--)
	{
		if (plansza[x][y].getKolorKlocuszka() == plansza[x][i].getKolorKlocuszka())
		{
			ciag++;
		}
		else {
			if (ciag > 2)
			{
				for (int j = 0; j < ciag; j++) {
					plansza[x][i + 1 + j].stanKlocuszka = stanyKlocuszka::do_zniszczenia;
				}
				return 1;
			}
			break;
		}
	}
	if (czyRuchMialSens) return 1;
	return 0;
}


//uzupe�nia luki w planszy po zniszczonych klocuszkach
bool Plansza::Uzupe�nij_plansze()
{
	bool jeszczeRaz = 0;

	srand((int)time(0));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (this->plansza[i][j].stanKlocuszka == stanyKlocuszka::do_zniszczenia)
			{
				for (int k = j; k < 9; k++)
				{
					plansza[i][k].zmienKolorKlocuszka(plansza[i][k + 1].kolorKlocuszka);
				}
				plansza[i][j].stanKlocuszka = stanyKlocuszka::domyslny;
				Klocuszek klocuszek(i, 9, static_cast<kolor::KolorKlocuszka>(rand() % 4), rodzaj::zwyk�y);
				plansza[i][9] = klocuszek;
			}
		}
	}

	int ciag = 0;
	for (int i = 0; i < 10; i++) //10 to rozmiar planszy
	{
		kolor::KolorKlocuszka tmpKolor = this->plansza[i][0].getKolorKlocuszka();
		for (int j = 0; j < 10; j++) //10 to rozmiar planszy
		{
			if (tmpKolor == this->plansza[i][j].getKolorKlocuszka()) //Je�eli dochodzimy do prawej �ciany, to i tak ko�czymy ci�g
			{
				ciag++;
			}
			else
			{
				if (ciag > 2)
				{
					for (int k = 0; k < ciag; k++)
					{
						this->plansza[i][j - k].stanKlocuszka = stanyKlocuszka::do_zniszczenia;
					}
					ciag = 1;
					jeszczeRaz = 1;
				}
				else
				{
					tmpKolor = this->plansza[i][j].getKolorKlocuszka();
					ciag = 1;
				}
			}
		}
		if (ciag > 2)
		{
			for (int k = 0; k < ciag; k++)
			{
				this->plansza[i][9 - k].stanKlocuszka = stanyKlocuszka::do_zniszczenia;
			}
			ciag = 1;
			jeszczeRaz = 1;
		}
		else
		{
			ciag = 1;
		}
	}

	ciag = 0;
	for (int i = 0; i < 10; i++) //10 to rozmiar planszy
	{

		kolor::KolorKlocuszka tmpKolor = this->plansza[0][i].getKolorKlocuszka();
		for (int j = 1; j < 10; j++) //10 to rozmiar planszy
		{
			if (tmpKolor == this->plansza[j][i].getKolorKlocuszka()) //Je�eli dochodzimy do dolnej �ciany, to i tak ko�czymy ci�g
			{
				ciag++;
			}
			else
			{
				if (ciag > 2)
				{
					for (int k = 0; k < ciag; k++)
					{
						this->plansza[j - k][i].stanKlocuszka = stanyKlocuszka::do_zniszczenia;
					}
					ciag = 1;
					jeszczeRaz = 1;
				}
				else
				{
					tmpKolor = this->plansza[j][i].getKolorKlocuszka();
					ciag = 1;
				}
			}
		}
		if (ciag > 2)
		{
			for (int k = 0; k < ciag; k++)
			{
				this->plansza[9 - k][i].stanKlocuszka = stanyKlocuszka::do_zniszczenia;
			}
			ciag = 1;
			jeszczeRaz = 1;
		}
		else
		{
			ciag = 1;
		}
	}
	return jeszczeRaz;
}


