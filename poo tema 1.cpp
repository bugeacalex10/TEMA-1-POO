/*
    Problema la acest proiect este calcularea profitului dupa punerea pariurilor ale
    fiecarui client.
    Datele de intrare sunt preluate din fiesierul "date.in.txt".
    Pe primul rand am un nr n care reprezinta numarul de meciuri.
    pe urmatoarele n randuri am date despre meciuri, pe fiecare rand am 2 echipe 3 cote
    si rezultatul final.
    Dupa pe urmatorul rand sunt este un m numar care reprezinta numarul de clienti.
    Fiecare client are un rand pe care scrie numele, prenumele, bugetul initial si un 
    numar k care reprezinta numarul de pariuri puse de acel client.
    Pe urmatoarele k randuri dupa fiecare client sunt pariurile sale pe un anumit meci dat de 
    un index la final.
    Numarul k la finalul fiecarui client poate fi diferit adica nu toti clientii au acelasi
    numar de pariuri.
    Programul face operatii pe vector si de atribuire si de asemenea cateva operatii simple
    matematice pentru calcularea bugetului final.
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
//declarare biblioteci necesare

class meci{
    private:
        std::string echipa1;
        std::string echipa2;
        float cota_echipa1;
        float cota_egal;
        float cota_echipa2;
        std::string rezultat;
        //variabile private pentru clasa meci
    public:
        meci () : echipa1(""), echipa2(""), cota_echipa1(0), cota_egal(0), cota_echipa2(0),
        rezultat("") {}
        //constructor default
        meci (const std::string& e1, const std::string& e2, float c1, float eg, float c2)
        {
            echipa1 = e1;
            echipa2 = e2;
            cota_echipa1 = c1;
            cota_egal = eg;
            cota_echipa2 = c2;
            rezultat = "";
        }
        //constructor cu parametri
        meci (const meci& m)
        {
            echipa1 = m.echipa1;
            echipa2 = m.echipa2;
            cota_echipa1 = m.cota_echipa1;
            cota_egal = m.cota_egal;
            cota_echipa2 = m.cota_echipa2;
            rezultat = m.rezultat;
        }
        //constructor de copiere
        meci& operator= (const meci& m)
        {
            if (this != &m)
            {
                echipa1 = m.echipa1;
                echipa2 = m.echipa2;
                cota_echipa1 = m.cota_echipa1;
                cota_egal = m.cota_egal;
                cota_echipa2 = m.cota_echipa2;
                rezultat = m.rezultat;
            }
            return *this;
        }
        //operator de asignare
        void rezultat_meci(const std::string& rez)
        {
            rezultat = rez;
        }
        //functie pentru a seta rezultatul meciului
        float verificare_sum_castigata(const std::string& alegere)
        {
            if (alegere == "echipa1" && rezultat == echipa1)
            {
                return cota_echipa1;
            }
            else if (alegere == "egal" && rezultat == "egal")
            {
                return cota_egal;
            }
            else if (alegere == "echipa2" && rezultat == echipa2)
            {
                return cota_echipa2;
            }
            else
            {
                return 0;
            }
        }
        //functie de verificare a alegerii clientului si returnarea cotei corespunzatoare
        ~meci(){}
        //destructor
};
//clasa pentru meciuri


class pariu{
    private:
        float suma;
        std::string echipa_aleasa;
        int index_meci;
        //variabile private pentru clasa pariu
    public:
        pariu () : suma(0), echipa_aleasa(""), index_meci(0) {}
        //constructor default
        pariu (float s, const std::string& alegerea, int ind)
        {
            suma = s;
            echipa_aleasa = alegerea;
            index_meci = ind;
        }
        //constructor cu parametri
        pariu (const pariu& p)
        {
            suma = p.suma;
            echipa_aleasa = p.echipa_aleasa;
            index_meci = p.index_meci;
        }
        //constructor de copiere
        pariu& operator= (const pariu& p)
        {
            if (this != &p)
            {
                suma = p.suma;
                echipa_aleasa = p.echipa_aleasa;
                index_meci = p.index_meci;
            }
            return *this;
        }
        //operator de asignare
        float get_suma() const
        {
            return suma;
        }
        //getter pentru suma pariului
        float ret_suma(std::vector<meci>& meciuri)
        {
            float cota_castig = meciuri[index_meci].verificare_sum_castigata(echipa_aleasa);
            return suma * cota_castig - suma;
        }
        //functia pentru returnarea sumei castigate sau pierdute in functie de alegerea
        //clientului si rezultatul meciului
        ~pariu(){}
        //destructot
};
//clasa pentru pariuri


class client{
    private:
        std::string nume;
        std::string prenume;
        std::vector<pariu> pariuri;
        float buget;
        float suma_castigata = 0;
        //variabile private pentru clasa client
    public:
        client () : nume(""), prenume(""), buget(0), pariuri({}) {}
        //constructor default
        client (const std::string& n, const std::string& p, float b, std::vector<pariu> gamble)
        {
            nume = n;
            prenume = p;
            buget = b;
            pariuri = gamble;
        }
        //constructor cu parametri
        client (const client& c)
        {
            nume = c.nume;
            prenume = c.prenume;
            buget = c.buget;
            pariuri = c.pariuri;
        }
        //constructor de copiere
        client& operator= (const client& c)
        {
            if (this != &c)
            {
                nume = c.nume;
                prenume = c.prenume;
                buget = c.buget;
                pariuri = c.pariuri;
            }
            return *this;
        }
        //operator de asignare
        void adauga_pariu (const pariu& p)
        {
            pariuri.push_back(p);
        }
        //functie de adaugare a unui pariu intr-un vector pentru pariurile clientului
        void calculare_castiguri(std::vector<meci>& meciuri)
        {
            for(int ind = 0; ind < pariuri.size(); ind++)
            {
                buget += pariuri[ind].ret_suma(meciuri);
            }
        }
        //functie pentru calcularea bugetului final al clientului dupa toate pariurile puse
        std::string get_nume() const
        {
            return nume;
        }
        //getter pentru numele clientului
        std::string get_prenume() const
        {
            return prenume;
        }
        //getter pentru prenumele clientului
        float get_buget() const
        {
            return buget;
        }
        //getter pentru bugetul final al clientului
        friend std::ostream& operator<< (std::ostream&out ,const client& c) 
        {
            out << c.nume << " " << c.prenume << " " << c.buget;
            return out;
        }
        //operator de afisare al numelui, prenumelui si bugetului final al clientului
        ~client(){}
        //destructor
};
//clasa pentru clienti


int main()
{
    std::ifstream fin("date.in.txt");
    std::ofstream fout("date.out.txt");
    //deschidere fisiere intrare si iesire

    int nrmeciuri;
    fin >> nrmeciuri;
    //declarare si citire numar de meciuri
    std::vector<meci> meciuri;
    //declarare vector pentru meciuri

    for(int ind = 0; ind < nrmeciuri; ind++)
    {
        std::string e1 , e2;
        //declarare variabile pentru echipe
        float c1, eg, c2;
        //declarare variabile pentru cote
        std::string rez;
        //declarare variabila pentru rezultat
        fin >> e1 >> e2 >> c1 >> eg >> c2 >> rez;
        //citire date pentru fiecare meci din fisierul de intrare
        meci m(e1, e2, c1, eg, c2);
        //creare obiect de tip meci cu datele citite
        m.rezultat_meci(rez);
        //setare rezultat pentru meciul curent
        meciuri.push_back(m);
        //adaugare obiect meci in vectorul de meciuri
    }
    //for folosit pentru citirea datelor despre meciuri si adaugarea acestora intr-un vector


    int nrclienti;
    fin >> nrclienti;
    //declarare si citire numar de clienti
    std::vector<float> buget_initial;
    //vector pentru stocarea bugetului initial al clientilor
    std::vector<client> clienti;
    //declarare vector clienti
    for(int ind = 0; ind < nrclienti; ind++)
    {
        std::string nume,prenume;
        //declarare variabile pentru numele si prenumele clientului
        float buget;
        //declarare variabila pentru bugetul initial al clientului
        int nrpariuri;
        //declarare variabila pentru numarul de pariuri ale clientului
        fin >> nume >> prenume >> buget >> nrpariuri;
        //citire date pentru fiecare client din fisierul de intrare
        buget_initial.push_back(buget);
        //stocare buget initial al clientului
        std::vector<pariu> pariuri;
        //declarare vector pentru pariurile clientului curent
        for(int ind_pariu = 0; ind_pariu < nrpariuri; ind_pariu++)
        {
            float suma;
            std::string alegere;
            int index_meci;
            //variabile pentru datele unui pariu pus de client
            fin >> suma >> alegere >> index_meci;
            //citire date
            pariu p(suma, alegere, index_meci);
            //creare obiect de tip pariu cu datele citite
            pariuri.push_back(p);
            //adaugare obiect pariu in vectorul de pariuri al clientului curent
        }
        client c(nume, prenume, buget, pariuri);
        //creare obiect de tip client cu datele citite si vectorul de pariuri
        clienti.push_back(c);
        //adaugare obiect client in vectorul de clienti
    }
    //for folosit pentru citirea datelor despre clienti si stocarea acestora intr-un vector, 
    //dar si pentru stocharea bugetului initial intr-un vector separat

    for(int ind = 0; ind < clienti.size(); ind++)
    {
        clienti[ind].calculare_castiguri(meciuri);
        //apelare functie de calculare a castigurilor sau a pierderilor
        if (clienti[ind].get_buget() > buget_initial[ind])
        {
            fout << "📈 "; 
        }
        else
        {
            fout << "📉 ";
        }
        //if pentru verificare daca clientul a facut profit sau nu
        if(ind != clienti.size() - 1)
        {
            fout << clienti[ind] << std::endl;
        }
        else
        {
            fout << clienti[ind];
        }
        //if pentru afisare cu endl mai putin daca e ultimul client
    }
    //for pentru afisare nume si prenume al clientilor dar si daca au facut profit sau nu si 
    //bugetul final


    fin.close();
    fout.close();
    //inchidere fisiere de intrare si iesire
    return 0;
    //returneaza 0 ca sa indice faptul ca programul s-a incheiat cu succes
}
//int main