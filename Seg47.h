/*
Seg47.h - Kirjasto 4-osaisen segmenttinäytön (common anode) ohjaamiseen käyttäen SN74LS47N-piiriä.
*/

#ifndef Seg47_h
#define Seg47_h

#include "Arduino.h"

const int segLed_On = HIGH;
const int segLed_Off = LOW;
const int segViive = 1;

/*
Luodaan luokka joka muodostuu metodeista näytön käsittelyä varten,
sekä muuttujuat joita tarvitaan
*/

class Seg47 {
	// Julkinen tieto
	public:
		
		// Konstruktori joka liittää metodit valituille tuloille
		Seg47(int, int, int, int, int, int, int, int);
		
		void showNro(int);
		void getNro(int);
		void binNro0();
		void binNro1();
		void binNro2();
		void binNro3();
		void binNro4();
		void binNro5();
		void binNro6();
		void binNro7();
		void binNro8();
		void binNro9();
	
	//Yksityinen tieto
	private:
	
		//Mihin tuloon painike liitetään
		int _segVirta1; // Segmenttiosio 1:n virtapinni
		int _segVirta2; // Segmenttiosio 2:n virtapinni
		int _segVirta3; // Segmenttiosio 3:n virtapinni
		int _segVirta4; // Segmenttiosio 4:n virtapinni
		int _segBitti1; // A (A0 74LS47N ohjain)
		int _segBitti2; // B (A1 74LS47N ohjain)
		int _segBitti3; // C (A2 74LS47N ohjain)
		int _segBitti4; // D (A3 74LS47N ohjain)
};

#endif