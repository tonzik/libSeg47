/*
Seg47.cpp - Kirjasto 4-osaisen segmenttinäytön (common anode) ohjaamiseen käyttäen SN74LS47N-piiriä.
*/

#include "Arduino.h"
#include "Seg47.h"

/*Konstruktori - Funktio joka luo uuden ilmentymän Seg47-luokasta.
Täällä alustetaan kaikki toiminnot.
*/

Seg47::Seg47(int segVirta1, int segVirta2, int segVirta3, int segVirta4, int segBitti1, int segBitti2, int segBitti3, int segBitti4) {
	
	_segVirta1 = segVirta1;
	_segVirta2 = segVirta2;
	_segVirta3 = segVirta3;
	_segVirta4 = segVirta4;
	_segBitti1 = segBitti1;
	_segBitti2 = segBitti2;
	_segBitti3 = segBitti3;
	_segBitti4 = segBitti4;
	
	// Tuttuun tapaan määritetään pinni lähdöksi
	pinMode(_segVirta1, OUTPUT);
	pinMode(_segVirta2, OUTPUT);
	pinMode(_segVirta3, OUTPUT);
	pinMode(_segVirta4, OUTPUT);
	pinMode(_segBitti1, OUTPUT);
	pinMode(_segBitti2, OUTPUT);
	pinMode(_segBitti3, OUTPUT);
	pinMode(_segBitti4, OUTPUT);
}

void Seg47::showNro(int numero) {
	int segOsa1 = ((numero / 1000) % 10);
	int segOsa2 = ((numero /  100) % 10);
	int segOsa3 = ((numero /   10) % 10);
	int segOsa4 = ((numero /    1) % 10);
	
	//Näytetään numero segmenttinäytöllä, sytyttäen ja sammuttaen segmenttiosioita vuorotellen
	digitalWrite(_segVirta4, HIGH);
	getNro(segOsa4);
	delay(segViive);
	
	digitalWrite(_segVirta4, LOW);
	digitalWrite(_segVirta3, HIGH);
	getNro(segOsa3);
	delay(segViive);
	
	digitalWrite(_segVirta3, LOW);
	digitalWrite(_segVirta2, HIGH);
	getNro(segOsa2);
	delay(segViive);
	
	digitalWrite(_segVirta2, LOW);
	digitalWrite(_segVirta1, HIGH);
	getNro(segOsa1);
	delay(segViive);
	
	digitalWrite(_segVirta1, LOW);
}

void Seg47::getNro(int numero) {
  digitalWrite(_segBitti1, numero & 1); // esim 4 & 1 => 0100 & 0001 > 0
  numero = numero >> 1;                 // 0100 >> 1 => 0100 > 0010
  digitalWrite(_segBitti2, numero & 1); // 0010 & 0001 > 0
  numero = numero >> 1;                 // 0010 => 0001  
  digitalWrite(_segBitti3, numero & 1); // 0001 & 0001 => 1
  numero = numero >> 1;                 // 0001 => 0000
  digitalWrite(_segBitti4, numero & 1); // 0000 & 0001 => 0 
}
