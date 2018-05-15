/**
* @file.......: Test.cpp
* @description: Program�n test edildigi dosya
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale
*/


#include "Islem.h"
#include "Agac.h"
#include "Liste.h"
#include <iostream>
#include <string>

int main() {
	system("cls");
	int secim;
	std::string aranan_kelime;
	Islem * islem = new Islem();
	Liste * list = new Liste();

	islem->YoluAl(); //istenilen dosya yolu al�nacak
	if (!islem->hataKontrol()) //verilen yol hatali ise bir sonraki islemlerin yapilmayacak
		return 0;
	islem->DosyalariBulEkle(); //istenilen yoldaki txtler agaca atanacak agaclar listeye atanacak

	do {


		system("cls");

		std::cout << "1-Arama Yap\n";
		std::cout << "2-Listele\n";
		std::cout << "3-Cikis\n";
		std::cout << ">>>";
		std::cin >> secim;

		switch (secim) {
			case 1: {
				//arama yap�lacak;
				std::cout << "\naranacak kelime..:";
				std::cin >> aranan_kelime;
				list->Bul(aranan_kelime);
				system("pause");

				break;
			}
			case 2: {
				//listeleme yap�lacak

				list->dolas();
				break;
				system("pause");

			}

			default: {
				system("pause");
				break;
			}

		}

		system("pause");
	} while (secim != 3);


}
