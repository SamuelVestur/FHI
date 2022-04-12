#include "triedy.h"

/*********** definicie clenskych funkcii triedy 'RodneCislo' ************/
//definicia parametrickeho konstruktora triedy 'RodneCislo'
RodneCislo::RodneCislo(char *r)
{
	strcpy(rodcis, r);
	pohlavie = VratPohlavie();
}

char *RodneCislo::VratRC()
{
	char *pom;
	pom = new char[12];
	strcpy(pom, rodcis);
	return pom;
}

int RodneCislo::VratDen()
{
	char pom[3];
	pom[0] = rodcis[4];
	pom[1] = rodcis[5];
	pom[2] = '\0';
	return (atoi(pom));
}

int RodneCislo::VratMesiac()
{
	char pom[3];
	pom[0] = rodcis[2];
	pom[1] = rodcis[3];
	pom[2] = '\0';
	return (VratPohlavie() == 0) ? (atoi(pom) - 50) : atoi(pom);
}

int RodneCislo::VratRok()
{
	char pom[3];
	int int_pom;

	pom[0] = rodcis[0];
	pom[1] = rodcis[1];
	pom[2] = '\0';
	int_pom = atoi(pom);
	if (int_pom < 15)
		return int_pom + 2000;	//2000 - 2014
	else
		return int_pom + 1900;	//1915 - 1999
}

int RodneCislo::VratPohlavie()
{
	char pom[3];
	pom[0] = rodcis[2];
	pom[1] = rodcis[3];
	pom[2] = '\0';
	return (atoi(pom) > 50) ? 0 : 1;
}

void RodneCislo::ZmenRC(char *r)
{
	strcpy(rodcis, r);
	pohlavie = VratPohlavie();
}

/*********** definicie clenskych funkcii triedy 'Osoba' **********************/
//definicia parametrickeho konstruktora triedy 'Osoba'
Osoba::Osoba(char *m, char *p, char *r) :rc(r)
{
	strcpy(meno, m);
	strcpy(priezvisko, p);
}

char *Osoba::VratMeno()
{
	char *pom;
	pom = new char[20];
	strcpy(pom, meno);
	return pom;
}

char *Osoba::VratPriezvisko()
{
	char *pom;
	pom = new char[20];
	strcpy(pom, priezvisko);
	return pom;
}

void Osoba::ZmenMeno(char *m)
{
	strcpy(meno, m);
}

void Osoba::ZmenPriezvisko(char *p)
{
	strcpy(priezvisko, p);
}

/*********** definicie clenskych funkcii triedy 'Zamestnanec' ************/
//definicia parametrickeho konstruktora triedy 'Zamestnanec'
Zamestnanec::Zamestnanec(char *m, char *p, char *r, long int osob_cis, char *prac_zarad,
	char *nazov_prevadz, int cis_pr, long int mz) : Osoba(m, p, r)
{
	osobne_cislo = osob_cis;
	strcpy(prac_zaradenie, prac_zarad);
	strcpy(nazov_prevadzky, nazov_prevadz);
	cis_prevadzky = cis_pr;
	mzda = mz;
}

long int Zamestnanec::VratOsobneCislo()
{
	return osobne_cislo;
}

char *Zamestnanec::VratPracZaradenie()
{
	char *pom;
	pom = new char[30];
	strcpy(pom, prac_zaradenie);
	return pom;
}

char *Zamestnanec::VratNazovPrevadzky()
{
	char *pom;
	pom = new char[30];
	strcpy(pom, nazov_prevadzky);
	return pom;
}

int Zamestnanec::VratCis_prevadzky()
{
	return cis_prevadzky;
}

long int Zamestnanec::VratMzdu()
{
	return mzda;
}

void Zamestnanec::ZmenCis_prevadzky( long int cis_p)
{
	cis_prevadzky = cis_p;
}
void Zamestnanec::ZmenMzdu(long int m)
{
	mzda = m;
}
void Zamestnanec::ZmenPracZaradenie(char *m)
{
	strcpy(prac_zaradenie, m);


}
void Zamestnanec::ZmenNazovPrevadzky(char *m)
{
	strcpy(nazov_prevadzky, m);
}
void Zamestnanec::ZmenOsobnecislo(long int m)
{
	osobne_cislo = m;


}
//defin. neclensk. spriatelenej operatorovej funkcie prepisaneho operatora << pre obj. tr. 'RodneCislo'
ostream& operator<<(ostream &vyst_prud, RodneCislo r)
{
	vyst_prud << "datum narodenia: " << r.VratDen() << '.' << r.VratMesiac() << '.'
		<< r.VratRok();
	return vyst_prud;
}

//definicia neclensk. spriatelenej operatorovej funkcie prepisaneho operatora << pre objekt tr. 'Osoba'
ostream& operator<<(ostream &vyst_prud, Osoba o)
{
	vyst_prud << "meno           : " << o.VratMeno() << endl
		<< "priezvisko     : " << o.VratPriezvisko() << endl
		<< "rodne cislo    : " << o.rc.VratRC() << endl;
	//pre vypisanie objektu 'rc' do vystupneho prudu sa zavola operatorova funkcia prepisaneho 
	//operatora << pre objekt triedy 'RodneCislo'
	vyst_prud << o.rc << endl
		<< "pohlavie       : ";
	char pom[5];
	(o.rc.VratPohlavie() == 0) ? strcpy(pom, "zena") : strcpy(pom, "muz");
	vyst_prud << pom << endl;
	return vyst_prud;
}

//defin. neclensk. spriatelenej operatorovej funkcie prepisaneho operat. << pre obj. tr. 'Zamestnanec'
ostream& operator<<(ostream &vyst_prud, Zamestnanec z)
{
	vyst_prud << "meno           : " << z.VratMeno() << endl
		<< "priezvisko     : " << z.VratPriezvisko() << endl
		<< "rodne cislo    : " << z.rc.VratRC() << endl;
	//pre vypisanie objektu 'rc' do vystupneho prudu sa zavola operatorova funkcia prepisaneho operatora //<< pre objekt triedy 'RodneCislo'
	vyst_prud << z.rc << endl
		<< "pohlavie       : ";
	char pom[5];
	(z.rc.VratPohlavie() == 0) ? strcpy(pom, "zena") : strcpy(pom, "muz");
	vyst_prud << pom << endl
		<< "osobne cislo   	 : " << z.VratOsobneCislo() << endl		//pridane
		<< "prac. zaradenie	 : " << z.VratPracZaradenie() << endl		//pridane
		<< "nazov prevadzky: " << z.VratNazovPrevadzky() << endl		//pridane
		<< "cislo prevadzky	 : " << z.VratCis_prevadzky() << endl
		<< "mzda [Eur]     	 : " << z.VratMzdu() << endl;
	return vyst_prud;
}