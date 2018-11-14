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
	if		(numero == 0) { binNro0(); } // Näytetään numero 0
	else if	(numero == 1) { binNro1(); } // Näytetään numero 1
	else if	(numero == 2) { binNro2(); } // Näytetään numero 2
	else if	(numero == 3) { binNro3(); } // Näytetään numero 3
	else if	(numero == 4) { binNro4(); } // Näytetään numero 4
	else if	(numero == 5) { binNro5(); } // Näytetään numero 5
	else if	(numero == 6) { binNro6(); } // Näytetään numero 6
	else if	(numero == 7) { binNro7(); } // Näytetään numero 7
	else if	(numero == 8) { binNro8(); } // Näytetään numero 8
	else if	(numero == 9) { binNro9(); } // Näytetään numero 9
}

// Numero 0
void Seg47::binNro0() {
	digitalWrite(_segBitti1, segLed_Off);
	digitalWrite(_segBitti2, segLed_Off);
	digitalWrite(_segBitti3, segLed_Off);
	digitalWrite(_segBitti4, segLed_Off);
}

// Numero 1
void Seg47::binNro1() {
	digitalWrite(_segBitti1, segLed_On);
	digitalWrite(_segBitti2, segLed_Off);
	digitalWrite(_segBitti3, segLed_Off);
	digitalWrite(_segBitti4, segLed_Off);
}

// Numero 2
void Seg47::binNro2() {
	digitalWrite(_segBitti1, segLed_Off);
	digitalWrite(_segBitti2, segLed_On);
	digitalWrite(_segBitti3, segLed_Off);
	digitalWrite(_segBitti4, segLed_Off);
}

// Numero 3
void Seg47::binNro3() {
	digitalWrite(_segBitti1, segLed_On);
	digitalWrite(_segBitti2, segLed_On);
	digitalWrite(_segBitti3, segLed_Off);
	digitalWrite(_segBitti4, segLed_Off);
}

// Numero 4
void Seg47::binNro4() {
	digitalWrite(_segBitti1, segLed_Off);
	digitalWrite(_segBitti2, segLed_Off);
	digitalWrite(_segBitti3, segLed_On);
	digitalWrite(_segBitti4, segLed_Off);
}

// Numero 5
void Seg47::binNro5() {
	digitalWrite(_segBitti1, segLed_On);
	digitalWrite(_segBitti2, segLed_Off);
	digitalWrite(_segBitti3, segLed_On);
	digitalWrite(_segBitti4, segLed_Off);
}

// Numero 6
void Seg47::binNro6() {
	digitalWrite(_segBitti1, segLed_Off);
	digitalWrite(_segBitti2, segLed_On);
	digitalWrite(_segBitti3, segLed_On);
	digitalWrite(_segBitti4, segLed_Off);
}

// Numero 7
void Seg47::binNro7() {
	digitalWrite(_segBitti1, segLed_On);
	digitalWrite(_segBitti2, segLed_On);
	digitalWrite(_segBitti3, segLed_On);
	digitalWrite(_segBitti4, segLed_Off);
}

// Numero 8
void Seg47::binNro8() {
	digitalWrite(_segBitti1, segLed_Off);
	digitalWrite(_segBitti2, segLed_Off);
	digitalWrite(_segBitti3, segLed_Off);
	digitalWrite(_segBitti4, segLed_On);
}

// Numero 9
void Seg47::binNro9() {
	digitalWrite(_segBitti1, segLed_On);
	digitalWrite(_segBitti2, segLed_Off);
	digitalWrite(_segBitti3, segLed_Off);
	digitalWrite(_segBitti4, segLed_On);
}