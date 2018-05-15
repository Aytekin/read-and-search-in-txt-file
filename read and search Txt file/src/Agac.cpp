/**
* @file.......: Agac.cpp
* @description: Agac s�n�f�n�n degiskenleri uzerinde islem yap�ld�g�.methodlar�n govdelerinin yaz�ld�g� dosya
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale
*/

#include "Agac.h"
#include<iostream>
#include "Liste.h"
Agac::Agac(std::string kelime)
{
	sol = sag = NULL;
	this->kelime = kelime;
}

void Agac::AgacaEkle(std::string Item)
{

	if (kelime.compare(Item) > 0) {
		if (sol)
			return sol->AgacaEkle(Item);

		Agac * yeni = new Agac(Item);
		sol = yeni;
		
	}
	if (kelime.compare(Item) < 0) {
		//saga ekleme
		if (sag)
			return sag->AgacaEkle(Item);

		Agac * yeni = new Agac(Item);
		sag = yeni;
		
	}
}



//bagli listedeki root->next inden baslay�p her d���mdeki agac� buraya vermeliyiz
//her d���mdeki dosya ismide gelmeli
void Agac::dolas(Agac * agac)
{

	// dola�acak de�er kalmad���nda geriye d�n�yoruz
	if (agac == NULL)
	{
		return;
	}
	// �nce sol alt a�ac�m�za u�ruyoruz
	 dolas(agac->sol);
	// sol alt a�a�taki yaprak d���m�m�z� yazd�r�yoruz
	std::cout << agac->kelime << " ";
	// sonra sa� alt a�aca ge�iyoruz
	 dolas(agac->sag);
}

bool Agac::Varmi(Agac * agac,std::string aranan)
{
	//aranan kelime agactaki kelimeye e�itse 
	if (agac->kelime == aranan)
	{
		return true;
	}	
	//aranan kelimenin alfabetik s�rada agactaki kelimeden �nce gelme durumu
	else if (agac->kelime.compare(aranan) > 0)
	{
		if (agac->sol != NULL) {
			return Varmi(agac->sol, aranan);
		}		
			return false;
	}
	//aranan kelimenin alfabetik s�rada agactaki kelimeden sonra gelme durumu
	else {
		if (agac->sag != NULL) {
			return Varmi(agac->sag, aranan);
		}
			return false;

	}
}

void Agac::sil(Agac * agac)
{
	delete agac;
	agac->kelime = "";
	agac->sag = NULL;
	agac->sol = NULL;
	
}



