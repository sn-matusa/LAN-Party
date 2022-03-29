	Această temă m-a ajutat mult în ințelegerea structurilor de date și implementarea
acestora în clase. Am încercat pe cât mai putut să lucrez cât mai modularizat, deși cred
că era loc de mult mai bine.

	Cerinta 1.
	Pentru prima cerinta m-am folosit de 3 clase (lista, Team si Player). Clasa Player am 
agregat-o din Team, iar pe aceasta din lista. Am creat o functie in main in care citeam din
fisiere datele corespunzatoare (nume echipa, nr. jucatori, date jucatori) si folosindu-ma de
constructorii cu parametrii (Player si Team) am creat nodul respectiv de tip Team pe care l-am
adaugat in lista prin metoda ”void AddTeam(const Team&);”. Acest procedeu se desfasoara intr-un for
care itireaza pana la numatorul de echipe. Cu metoda ”void afisare(ofstream &)const;” am afisat
intreaga lista in fisier. Pentru aceasta cerinta m-am mai folosit de diverse metode prin care
setam adresa urmatorului nod, returnam adresa urmatorul nod etc.
	Pentru ca am lucrat cu pointeri, am implementat in clasa lista si constuctor de copiere,
destructor si operator = .
	Cerinta 2.
	Pentru cerinta 2 am realizat o functie care parcurge lista si imi calculeaza punctajul
de echipa pentru fiecare nod in parte. Dupa care cu metoda void stergere(); am sters nodurile cu
cel mai mic puntaj de echipa astfel incat sa ajung la numarul de echipe cerut. Dupa care am afisat
lista.
	Cerinta 3.
	Aici am ales sa implementez mai multe clase pentru a modulariza mai mult procesul. Asadar,
am creat clasele coada, meci si stiva. In functia din main task3, am incercat pe cat posibil
sa fac cat mai eficient acest procedeu. Algoritmul incepe prin a inseara lista in coada, astfel
formandu-se meciurile. Dupa care introduc echipele in stive, corespunzatoare rezultatului lor.
Dupa ce am terminat cu prima runda de castigatori , folosesc un while pentru restul procesului
pana ajung la echipa castigatoare. In momentul cand in stiva de echipe castigatoare am 8 echipe, 
intruduc respectivele echipe intr-o noua lista, dupa care procesul se reia, echipele fiind 
introduse in coada de meciuri , dupa care in stive. Pe parcurs, afisez in fisierele txt continutul
cozii si a stivei de castigatori.
	Cerinta 4.
	La urmatoare cerinta am ales sa creez inca o clasa, numita de mine nod_bts. Din lista creata la
cerinta anterioara, am introdus pe rand nodurile in arborele meu cu ajutorul metodei 
nod_bst* insert(nod_bst*, const Team &); . Aceasta primeste ca parametru o echipa pe care o
insereaza mai departe in arbore astfel incat la final cand fac afisarea cu void inorder(nod_bst*,ofstream &);
arborele sa fie ordonat descrescator. Iau in considerare si cand echipele au acelasi puntaj, si
compar numele echipelor. Agoritmul este unul de tip recursiv. Mai folosesc mici metode pentru a seta
sau a returna echipa dintr-un nod.

	Cele mai mari dificultati pe care le-am gasit au fost la alocarea nodurilor in diversele structuri de date,
pentru ca uneori nu reuseam sa salvez acele noduri, ele fiind pastrate doar in interiorul functiei din
care faceau parte. Dar cu multa munca am reusit sa rezolv toate problemele de genul acesta. Un lucru interesant
a fost spatiu pe care unele nume de echipa il aveau in fisiere din Date. Am reusit sa caut si sa sterg acel spatiu
cu functiile string back() si pop_back() (specifice c++11).
