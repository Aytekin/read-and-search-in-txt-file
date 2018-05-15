/**
* @file.......: L�ste.h
* @description: Liste s�n�f�n�n tan�mland�g� h dosyas�
* @course.....: 2.Ogretim B grubu
* @assignment.: 03 Numaral� Odev
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale/O�uzhan Alipek --- aytekin.erlale@Ogr.Sakarya.edu.tr / oguzhan.alipek@Ogr.Sakarya.edu.tr
*/

#pragma once
#include<string>
#include"Agac.h"
class Liste
{
public:
	Liste();
	~Liste();
	std::string dosya_adi;
	Agac * dugumdeki_agac;
	Liste * next;
	void ListeyeEkle(Agac * a1, std::string dosya_adi);
	void dolas();
	void Bul(std::string aranan);
	void DugumleriSil();
};

