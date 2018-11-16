#include "Seg47.h"

// Annetaan 4-osaisen näytön pinnitiedot, yhteensä 8. Muuta oman kytkentäsi mukaisesti, pinnien järjestys oltava kuitenkin sama)
// Seuraavana esimerkkiohjelman pinnien selitys
// disp(   9, = segmenttinäytön 1. osan virta
//         8, = segmenttinäytön 2. osan virta
//         7, = segmenttinäytön 3. osan virta
//         6, = segmenttinäytön 4. osan virta
//        13, = A (A0 74LS47N ohjain)
//        12, = B (A1 74LS47N ohjain)
//        11, = C (A2 74LS47N ohjain)
//        10, = D (A3 74LS47N ohjain)
//		   1, = Näytön 'virkistystaajuus', kokeile sopivaa arvoa näytöllesi väliltä 1-10.
//		   5, = Ajastinpisteen käyttöönotto antamalla pinnin numero. Jos ei haluta käyttöön käytetään lukua -1.
//
Seg47 disp(9,8, 7, 6, 13, 12, 11, 10, 1, 5);

int DSP = 1234;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  // Haetaan kirjastosta haluttu numero/numerosarja näytettäväksi
  disp.showNro(DSP);
}