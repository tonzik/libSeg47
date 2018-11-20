/*
Seg47.cpp - Kirjasto 4-osaisen segmenttinäytön (common anode) ohjaamiseen käyttäen SN74LS47N-piiriä.
*/

#include "Arduino.h"
#include "libSeg47.h"

/*Konstruktori - Funktio joka luo uuden ilmentymän Seg47-luokasta.
Täällä alustetaan kaikki toiminnot.
*/

libSeg47::libSeg47(int segVirta1, int segVirta2, int segVirta3, int segVirta4, int segBitti1, int segBitti2, int segBitti3, int segBitti4, int segViive, int segAikaPistePin) {
	
	_segVirta1       = segVirta1;
	_segVirta2       = segVirta2;
	_segVirta3       = segVirta3;
	_segVirta4       = segVirta4;
	_segBitti1       = segBitti1;
	_segBitti2       = segBitti2;
	_segBitti3       = segBitti3;
	_segBitti4       = segBitti4;
	_segViive        = segViive;
	_segAikaPistePin = segAikaPistePin;

	// Tuttuun tapaan määritetään pinni lähdöksi

	pinMode(_segVirta1, OUTPUT);
	pinMode(_segVirta2, OUTPUT);
	pinMode(_segVirta3, OUTPUT);
	pinMode(_segVirta4, OUTPUT);
	pinMode(_segBitti1, OUTPUT);
	pinMode(_segBitti2, OUTPUT);
	pinMode(_segBitti3, OUTPUT);
	pinMode(_segBitti4, OUTPUT);

	if (segAikaPistePin != -1) { // Jos ajastinpiste on käytössä, määritetään tämän pinni lähdöksi.
		pinMode(_segAikaPistePin, OUTPUT);
	}
}

void libSeg47::showNro(int numero) {
	int segOsa1 = ((numero / 1000) % 10);
	int segOsa2 = ((numero /  100) % 10);
	int segOsa3 = ((numero /   10) % 10);
	int segOsa4 = ((numero /    1) % 10);
	
	//Näytetään numero segmenttinäytöllä, sytyttäen ja sammuttaen segmenttiosioita vuorotellen
	digitalWrite(_segVirta4, HIGH);
	getNro(segOsa4);
	delay(_segViive);
	
	digitalWrite(_segVirta4, LOW);
	digitalWrite(_segVirta3, HIGH);
	getNro(segOsa3);
	delay(_segViive);
	
	digitalWrite(_segVirta3, LOW);
	digitalWrite(_segVirta2, HIGH);
	if (_segAikaPistePin != -1) {
		digitalWrite(_segAikaPistePin, LOW); // Jos aikapiste on käytössä laitetaan se tässä päälle
	}
	getNro(segOsa2);
	delay(_segViive);
	
	digitalWrite(_segVirta2, LOW);
	if (_segAikaPistePin != -1) {
		digitalWrite(_segAikaPistePin, HIGH); // Jos aikapiste on käytössä laitetaan se tässä pois päältä
	}
	digitalWrite(_segVirta1, HIGH);
	getNro(segOsa1);
	delay(_segViive);
	
	digitalWrite(_segVirta1, LOW);
}

void libSeg47::getNro(int numero) {
  digitalWrite(_segBitti1, numero & 1); // esim 4 & 1 => 0100 & 0001 > 0
  numero = numero >> 1;                 // 0100 >> 1 => 0100 > 0010
  digitalWrite(_segBitti2, numero & 1); // 0010 & 0001 > 0
  numero = numero >> 1;                 // 0010 => 0001  
  digitalWrite(_segBitti3, numero & 1); // 0001 & 0001 => 1
  numero = numero >> 1;                 // 0001 => 0000
  digitalWrite(_segBitti4, numero & 1); // 0000 & 0001 => 0 
}
