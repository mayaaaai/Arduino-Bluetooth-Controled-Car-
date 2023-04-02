# Arduino-Bluetooth-Controled-Car-
Arduino Bluetooth Controled Car - Team Project ( Physics - 1st year, semester I)



Proiect Fizica
Arduino Bluetooth Controled Car
By Oana Laza & Maia Incer

 In acest proiect avem urmatoarea cerinta: crearea unei masinute controlate prin bluetooth cu ajutorul placutei de dezvoltare Arduino. Pentru a indeplini aceasta cerinta vom face si partea HARDWARE si partea SOFTWARE.
I.	PARTEA HARDWARE
   Aceasta parte are si ea la randul ei mai multe etape: etapa de proiectare, etapa de asamblare a sasiului si etapa de conectare.
1.	Proiectarea masinutei 
    O simpla cautare pe internet a unei masini controlate bluetooth prin arduino ne arata o multitudine de variante pentru sasiu, unele variante printate 3D, unele kit-uri sau unele facute din carton sau lemn.
   Pentru acest proiect am decis sa folosim kitul de sasiu cu 4 motoare de pe siteul  https://www.emag.ro/masina-inteligenta-lunga-4wd-dubla-cl135/pd/DPQZ5JBBM/. Am ales acest kit deoarece pretul sau era relativ scazut si din faptul ca contine cele 4 motoare necesare. Kitul contine: 2 placute de plexiglass de 26x15x0,2cm(spatiul suficient pentru componente), suruburile de montare, piulite, 4 motoare DC 6V cu angrenaje, niste piloni si un suport pentru 4 baterii AA.
     Pentru controlul motoareler avem nevoie de un modul de tip BRIDGE. Acest modul ne permite sa controlam directia motoarelor(prin inversare de polaritate) si sa controlam turatia motorului(cu ajuturul functie pulse-width-modulation). In acest proiect vom folosi modulul H-Bridge L298N. Modulul este folosit pentru a controla 2 motoare. Pentru a putea controla mai multe motoare vom grupa in paralel motoarele. Dimensiunile modulului sunt de 43x43x27 mm ceea ce il fac ideal pentru acest proiect. Modulul a fost achizitionat de pe https://cleste.ro/modul-l298n-cu-punte-h-dubla.html.
      Pentru controlul modulului H-Brige vom folosi o placuta de dezvoltare Arduino UNO. Acesta placuta foloseste limbajul de programare C++ si este folosita in majoritatea proiectelor de robotica de tip hobby, o alternativa la aceasta fiind placuta Raspberry Pi. Am decis sa folosim modelul UNO deoarece este cea mai folosita placuta, iar in caz de probleme gasesti usor rezolvare pe forumuri. Acesta placuta a fost achizitionata de pe https://cleste.ro/placa-de-dezvoltare-arduino-uno.html. 
       Pentru a transmite informatii la placuta Arduino vom folosi un modul Bluetooth HC-05. Acest modul este foarte utilizat in proiecte de tip RC, existand astfel o gramada de aplicatii pe android care permit stabilirea unei conexiuni intre un smartphone si modul. Pentru a comunica cu placuta Arduino vom folosi pini digital 0 si 1, numiti si pini serial. Acesti pini sunt folositi pentru comunicare cu sistemul de calcul. Stiind acest lucru vom simula o conexiune cu sistemul de calcul daca se poate conecta modulul bluetooth. Modulul bluetooth va fi conectat dupa ce uploadam codul pe placuta de dezvoltare deoarece pinii 0 si 1 sunt folositi in timpul uploadarii programului. Acest modul a fost achizitionat de pe https://cleste.ro/modul-bluetooth-hc-05.html.
    Pentru alimentarea “masinutei” vom folosi un acumulator Ni-MH de 7.2V 650mAh, acumulator pe care l-am luat dintr-o drona defecta. Am folosit initial 4 baterii AA dar performantele au fost scazute comparativ cu acumulatorul. O imbunatatire a alimentarii ar fi adaugarea unui acumulator LiPo 3C de 11.4V de 1200mAh. Acumulatoarele LiPo sunt cunoscute pentru performantele ridicate in domeniul jucariilor de tip RC si pentru modul de incarcare relativ usor. Acumulatoarele Ni-MH ca cel folosit in proiect, sunt mai sensibile, acestea necesitand o descarcare completa inainte de reincarcare si o incarcare neintrerupta. 
       Pe langa aceste componente am mai folosit fire conectoare “tata-tata”, o placuta breadboard, niste rezistente de 1kΩ si banda izolatoare.
 Dupa ce am stabilit lista cu componentele necesare am facut o schema tip breadboard in programul Fritzing. Acest program are o librarie vasta de componente necesare roboticii.
 
 
 ![image](https://user-images.githubusercontent.com/102360393/229363283-37e535e1-9425-4699-9a33-59ec5f93830c.png)

     
 In schema am pus o baterie de 9V, dar in masinuta vom folosi un acumulator.
Pentru a executa viraje, masinuta noastra se aseamana mai mult cu un tank deoarece nu avem un mecanism de directie(steering). Motoarele pot executa doar doua miscari(FATA sau SPATE). Pentru a executa un viraj la stanga motoarele din partea dreapta vor merge in fata in timp ce motoarele din partea stanga vor fi oprite, iar pentru un viraj la dreapta motoarele din stanga vor merge in fata, si cele din dreapta vor fi oprite. Pentru a intelege mai usor acest concept am pregatit o schema a miscarii la dreapta.

![image](https://user-images.githubusercontent.com/102360393/229363308-9abc6b25-e16c-445e-97af-81b609f17c84.png)

 
2.	Etapa de asamblare
In aceasta etapa vom asambla sasiu si vom lipi coomponentele pe masinuta. Piesele pe care le vom folosi:

      ![image](https://user-images.githubusercontent.com/102360393/229363361-68f77653-ff9c-4c1c-a6c9-79c1b2e9153e.png)
      ![image](https://user-images.githubusercontent.com/102360393/229363367-b77028e9-01d8-4091-a2a9-02e5e6bfedcc.png)
      ![image](https://user-images.githubusercontent.com/102360393/229363376-6101f076-e292-422e-aef6-833cbe1ff01d.png)

     
                              Suport baterii, Modul Bridge si Placuta Arduino
                              
   ![image](https://user-images.githubusercontent.com/102360393/229363391-5407cc32-c4f0-47ab-b8a4-646857b02308.png)
   ![image](https://user-images.githubusercontent.com/102360393/229363400-2af70e04-f80d-49aa-862e-9f3ea1037a03.png)
   ![image](https://user-images.githubusercontent.com/102360393/229363407-c2a885a2-a538-4357-bd14-5f596c5a2ca8.png)

   
                                Motor DC, modul Bluetooth, Acumulator NiMh
                                
                                
   Motoarele DC nu au fire atasate la conectori asa ca vom folosi un ciocan de lipit cu niste cositor pentru a le suda.
  
   Dupa atasarea firelor vom monta motoarele pe sasiu folosind suruburile din kit.
   
   
      ![image](https://user-images.githubusercontent.com/102360393/229363433-087bcbbc-1e1b-4c64-89c4-186bd6cdfaa0.png)

    
   Dupa montarea motoarelor, vom lipi cu niste banda izolatoare modulul H-Bridge de sasiu. La fel vom face si cu suportul de bateri si cu placuta Arduino.
   
  ![image](https://user-images.githubusercontent.com/102360393/229363522-682875ab-e097-4be1-87d5-07fe43c1154d.png)
  ![image](https://user-images.githubusercontent.com/102360393/229363529-1bdda588-2d9d-48d6-8449-564a26716150.png)


  
3.	Etapa de conectare.

   Pentru a conecta modulul Bluetooth la placuta Arduino avem nevoie de un semnal de 3.3V la pinul RX, dar placuta arduino ne ofera din pini 0 si 1 doar un semnal de 5V. Pentru a rezolva aceasta problema vom folosi un divizor de tensiune. 
  ![image](https://user-images.githubusercontent.com/102360393/229363539-a7044f43-2a39-4ad3-8744-fd97b2edd05a.png)

   Folosindu-ne de formula:  unde  Vout = Tensiune Iesire(3.3V) si Vin=Tensiune Intrare(5V),  am calculat ca avem nevoie de o rezistenta R1=1kΩ si o rezistenta R2= 2kΩ.  Deoarece nu aveam o rezistenta de 2kΩ am grupat in serie 2 rezistente de 1kΩ folosindune de formula rezistentei in gruparea in serie:
  ![image](https://user-images.githubusercontent.com/102360393/229363552-1ecb9180-925f-426e-999a-bd1621263e37.png)

  
    Am construit pe o placuta breadboard divizorul de tensiune folosindu-ne de cele 3 rezistente de 1k Ω si niste fire conectoare.
 ![image](https://user-images.githubusercontent.com/102360393/229363575-15d0578d-9d02-4dff-98e0-cfd1f4991872.png)

 
In urmatorul pas am facut conexiunile dintre placa Arduino, Modulul H-Bridge,modulul Bluetooth motoare si alimentare. Pentru a intelege mai usor conxiunile am facut un tabel cu pini care vor fi conectati. Am notat cu DT- divizorul de tensiune,  cu gri alimentarea – si cu rosu alimentarea +.

![image](https://user-images.githubusercontent.com/102360393/229363612-c283fef0-0ee8-47d9-ad38-71b8408fe264.png)

  Dupa finalizarea conexiunilor avem urmatorul rezultat:
  
 ![image](https://user-images.githubusercontent.com/102360393/229363634-46ff2083-f8fc-4b59-841d-82211d092a26.png)
 ![image](https://user-images.githubusercontent.com/102360393/229363639-d500b44f-0648-46ac-ae45-af45e4e4804f.png)


  
   Pentru a mari performantele am atasat o baterie de 9V pentru alimentarea placutei Arduino. 
   
II.	 PARTEA SOFTWARE
    Pentru a programa placa Arduino Uno avem nevoie de urmatoarele: un sistem de calcul(laptop sau PC), un cablu USB 2.0 si programul Arduino IDE(https://www.arduino.cc/en/software). Deoarce folosim o placa Arduino originala nu avem nevoie de driver pentru a conecta placa. Inainte de a conecta placa la PC, scoate firele din pini 0 si 1(sunt pini seriali, vitali in comunicarea cu PC) pentru a nu avea errori de uploadare.
    In programul Arduino IDE vom coda in C++, folosindu-ne si de functile specifice arduinoIDE “digitalWrite”, “Serial.print()”, “Serial.begin()”, “pinMode”. Pentru a intelege codul urmarim schema logica a programului.  
    
    
    ![image](https://user-images.githubusercontent.com/102360393/229363733-5bf2e727-49fb-433a-8c62-dfb9ea383b01.png)

    
    In Arduino avem doua functii marii: void setup() si void loop(). In functia void setup definim parametrii de functionare(pini,serial,valori etc). Functia void setup ruleaza o singura data, atunci cand alimentam placa arduino. Functia void loop este o functie care se repeta pe tot parcursul alimentari placii si se folosese pentru actiuni care se schimba pe parcursul functionarii robotului.
 Inainte de functia void setup() am definit o variabila x de tip int si i-am dat valoarea 0.
 In functia void setup() am pornit functia serial de comunicare folosind comanda Serial.begin si I-am dat valoarea baud rate de 38400 (biti pe secunda) care este aceeasi valoare de comunicare cu cea a modulului bluetooth. Astfel am asigurat o comunicare intre acestia la acelasi baud rate, deci nu o sa avem probleme de interpretare a semnalului. Folosindu-ne de functia pinMode am definit pinii digitali care vor controla modulul H-Bridge. 
 In functia void loop() am dat o functie if care are rolul de a verifica daca avem comunicare de tip serial, adica modulul bluetooth este conectat. Daca avem comunicare seriala, programul va interpreta cu ajutorul functie Serial.read() valoarea lui x(variabila de tip int). Folosindu-ne de o serie de functii if care au rolul de a verifica daca x are valoarea un numar de la 1 la 5. Pentru fiecare valoare de la 1 la 5 a lui x, atribuim o comanda. De exemplu if(x ==  1) robotul va intelege sa execute seria de comenzi digitalWrite necesare miscarii in fata. In functile if mai intalnim pe langa digitalWrite(care au rol in controlul motoarelor) si functia Serial.print() care are rolul de a returna o valoare string la smartphone care sa confirme directia dorita. Dupa cum spuneam, functia void loop() se repeta in continuu, deci cata vreme valoarea lui x nu se schimba, masinuta va executa o singura miscare(FATA, SPATE, STANGA, DREAPTA, STOP).
  Folosindu-ne de schema logica si de cunostintele noastre in C++ am alcatuit urmatorul cod:
  
  ![image](https://user-images.githubusercontent.com/102360393/229363749-739a2918-40f0-4f31-b65f-96f398206d04.png)
  ![image](https://user-images.githubusercontent.com/102360393/229363754-7cbbab95-65c7-42a1-83eb-dc7cb415c6c0.png)


  
Uploadam codul pe placuta UNO si conectam pinii modulului bluetooth in pini serial 0 si 1.
Pentru a ne conecta la modulul bluetooth vom folosi aplicatia  Bluetooth Terminal HC-05. (https://play.google.com/store/apps/details?id=project.bluetoothterminal&hl=en_US&gl=US )

![image](https://user-images.githubusercontent.com/102360393/229363762-4b12ca45-4b7e-48fc-b970-763a775547bf.png)

 
Dupa cum puteti vedea si in imagine, noi transmitem placutei arduino valori intregi de la 1 la 5 si ea ne raspunde cu o confirmare a directiei.


