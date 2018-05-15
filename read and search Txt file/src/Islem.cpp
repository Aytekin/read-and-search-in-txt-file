/**
* @file.......: Islem.cpp
* @description: Islem s�n�f�n�n degiskenleri uzerinde islem yap�ld�g�.methodlar�n govdelerinin yaz�ld�g� dosya
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale
*/


#include "Islem.h"
#include "Liste.h"
#include<dirent.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

Islem::Islem()
{
}

//girilecek dizindeki dosyalara ula�mak icin yap�lan tan�mlamalar
ifstream fin;
string dir;
int num;
DIR *dp;
struct dirent *dirp;

void Islem::YoluAl()
{
	cout << "Klasor..: ";
	cin >> dir;
}


bool Islem::hataKontrol()
{
	//eger dizin ismi hatal�ysa hata no ilke birlikte bir yazi bastiracak ekrana ve fok false d�necek
	//eger dizin mevcutsa true d�necek ve i�lem devam edecektir
	if ((dp = opendir(dir.c_str())) == NULL) {
		cout << "Hata NO(" << errno << ")" << dir << endl;
		system("pause");

		return false;
	}
	return true;
}


void Islem::DosyalariBulEkle()
{
	//eger dizin isminde bir hata yoksa fonksiyon calisacak
	if (hataKontrol())
	{
		Liste * list = new Liste();
		//verilen dizindeki dosyalar� okuyoruz
		while (dirp = readdir(dp)) {
			
			fin.open(dirp->d_name);
			fin >> num;
			//burdaki for d�ng�s� olu�turdu�umuz kontrol ile 
			//uzant�s� .txt olan dosyalar� i�leme girdirecek

			for (int i = 0; dirp->d_name[i] != '\0'; i++)
			{
				if (dirp->d_name[i] == '.' && dirp->d_name[i + 1] == 't' &&dirp->d_name[i + 2] == 'x' &&dirp->d_name[i + 3] == 't')
				{
					//burada bagl� listeye agac ekleyecegiz
					string ara_deger = "";

					//ifstream nesnesiyle okuma islemini baslatiyoruz
					ifstream DosyayiOku;
					//istemilen klas�rdeki dosyay� a��yoruz
					DosyayiOku.open(dir + "\\" + dirp->d_name);
					//dosyadaki degerleri okuyoruz
					DosyayiOku >> ara_deger;
					//heap b�lgesinde agac ad�nda bir Agac nesnesi olusturuyoruz
					Agac * agac = new Agac(ara_deger);
					//dosyan�n sonuna gelene kadar okuma i�lemine devam ediyoruz
					while (!DosyayiOku.eof()) {

						DosyayiOku >> ara_deger;
						//dosyadan okudu�umuz her de�eri a�aca ekliyoruz
						agac->AgacaEkle(ara_deger);
					}
					//dosyada okunacak ba�ka de�er kalmay�nca dosyay� kapat�yoruz
					DosyayiOku.close();
					//dosyadan okudu�umuz de�erlerle olu�turdu�umuz agac� dosya ismiyle beraber 
					//ba�l� listedeki d���mlere ekliyoruz
					list->ListeyeEkle(agac, dirp->d_name);
				}
			}
		}
		closedir(dp);
	}
	//eger dizin isminde hata al�nd�ysa fonksiyon bitecek
	else
		return;
	
}









