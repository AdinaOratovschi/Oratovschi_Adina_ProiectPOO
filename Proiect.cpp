#include <iostream>
#include <string>
using namespace std;

//domeniul e Aprozar
//clasele sunt: Suc, Chips, Vanzator


class Suc
{
private:
    int nrIngrediente;
    
    const string nume;
    float pret;
    string* ingrediente;
    static int cantitate;

    friend void marestePret(Suc& suc, float marire);
    friend void scaderePret(Suc& suc, float scadere);

public:
    Suc() : nume("Coca Cola")
    {
        pret = 5.1;
        ingrediente = new string[3];
        ingrediente[0] = "Apa";
        ingrediente[1] = "Zahar";
        ingrediente[2] = "Aroma";
        nrIngrediente = 3;
        cantitate++;
    }

    Suc(string numeSuc, float pretSuc) : nume(numeSuc), pret(pretSuc)
    {
        ingrediente = new string[3];
        ingrediente[0] = "Apa";
        ingrediente[1] = "Zahar";
        ingrediente[2] = "Aroma";
        nrIngrediente = 3;
        cantitate++;
    }

    Suc(string numeSuc, float pretSuc, string* ingredienteSuc, int totalIngrediente) : nume(numeSuc)
    {
        pret = pretSuc;
        ingrediente = ingredienteSuc;
        nrIngrediente = totalIngrediente;
        cantitate++;
    }

    Suc(const Suc& sucOriginal): nume(sucOriginal.nume)
    {
        nrIngrediente = sucOriginal.nrIngrediente;
        pret = sucOriginal.pret;
        ingrediente = new string[nrIngrediente];
        for (int i = 0; i < nrIngrediente; i++)
        {
            ingrediente[i] = sucOriginal.ingrediente[i];
        }
    }

    Suc operator=(const Suc& suc)
    {
        this->nrIngrediente = suc.nrIngrediente;
        this->pret = suc.pret;
        if (ingrediente != NULL)
        {
            delete[] ingrediente;
        }
        ingrediente = new string[nrIngrediente];
        for (int i = 0; i < nrIngrediente; i++)
        {
            ingrediente[i] = suc.ingrediente[i];
        }
        return *this;
    }

    bool operator>(const Suc& suc)
    {
        return pret > suc.pret;
    }

    bool operator<(const Suc& suc)
    {
        return pret < suc.pret;
    }

    ~Suc()
    {
        if (ingrediente != NULL)
        {
            delete[] ingrediente;
        }
    }

    void afisare()
    {
        cout << endl << "Suc " << nume << " are pretul de " << pret << " si contine:" << endl;
        for (int i = 0; i < nrIngrediente; i++)
        {
            cout << ingrediente[i] << endl;
        }
        cout << "Cantitate sucuri: " << cantitate << endl;
    }

    string getNume()
    {
        return nume;
    }

    float getPret()
    {
        return pret;
    }

    void setPret(float noulPret)
    {
        pret = noulPret;
    }

    string* getIngrediente()
    {
        return ingrediente;
    }

    void setIngrediente(string* noileIngrediente)
    {
        ingrediente = noileIngrediente;
    }

    int getNrIngrediente()
    {
        return nrIngrediente;
    }

    static int getCantitate()
    {
        return cantitate;
    }

    static void setCantitate(int nouaCantitate)
    {
        cantitate = nouaCantitate;
    }

    friend ostream& operator<<(ostream& consola, const Suc& suc);
};

int Suc::cantitate = 0;

void marestePret(Suc& suc, float marire)
{
    suc.pret = suc.pret + marire;
}

void scaderePret(Suc& suc, float scadere)
{
    suc.pret = suc.pret - scadere;
}

ostream& operator<<(ostream& consola, const Suc& suc)
{
    consola << endl << "Suc " << suc.nume << " are pretul de " << suc.pret << " si contine:" << endl;
    for (int i = 0; i < suc.nrIngrediente; i++)
    {
        consola << suc.ingrediente[i] << endl;
    }
    consola << "Cantitate sucuri: " << suc.cantitate << endl;
    return consola;
}

class Chips
{
private:
    int nrIngrediente;

    const string nume;
    float calorii;
    string* ingrediente;
    static int vandute;

    friend void maresteCalorii(Chips& chips, float marire);
    friend void scadereCalorii(Chips & chips, float scadere);

public:
    Chips() : nume("Lays")
    {
        calorii = 536.1;
        ingrediente = new string[2];
        ingrediente[0] = "Cartofi";
        ingrediente[1] = "Ulei";
        nrIngrediente = 2;
        vandute++;
    }

    Chips(string numeChips, float caloriiChips) : nume(numeChips), calorii(caloriiChips)
    {
        ingrediente = new string[2];
        ingrediente[0] = "Cartofi";
        ingrediente[1] = "Ulei";
        nrIngrediente = 2;
        vandute++;
    }

    Chips(string numeChips, float caloriiChips, string* ingredienteChips, int totalIngrediente) : nume(numeChips)
    {
        calorii = caloriiChips;
        ingrediente = ingredienteChips;
        nrIngrediente = totalIngrediente;
        vandute++;
    }

    Chips(const Chips & chipsOriginal) : nume(chipsOriginal.nume)
    {
        nrIngrediente = chipsOriginal.nrIngrediente;
        calorii = chipsOriginal.calorii;
        ingrediente = new string[nrIngrediente];
        for (int i = 0; i < nrIngrediente; i++)
        {
            ingrediente[i] = chipsOriginal.ingrediente[i];
        }
    }

    Chips operator=(const Chips& chips)
    {
        this->nrIngrediente = chips.nrIngrediente;
        this->calorii = chips.calorii;
        if (ingrediente != NULL)
        {
            delete[] ingrediente;
        }
        ingrediente = new string[nrIngrediente];
        for (int i = 0; i < nrIngrediente; i++)
        {
            ingrediente[i] = chips.ingrediente[i];
        }
        return *this;
    }

    bool operator==(const Chips& chips)
    {
        return this->nume == chips.nume && this->calorii == chips.calorii;
    }

    bool operator!=(const Chips& chips)
    {
        return this->nume!=chips.nume || this->calorii != chips.calorii;
    }

    string& operator[](int i)
    {
        string eroare = "Depaseste nr de ingrediente";
        if (i < nrIngrediente)
        {
            return this->ingrediente[i];
        }
        else
        {
            return eroare; 
        }
    }

    ~Chips()
    {
        delete[] ingrediente;
    }

    void afisare()
    {
        cout << endl << "Chips-urile " << nume << " au un numare de " << calorii <<" calorii si contine: " << endl;
        for (int i = 0; i < nrIngrediente; i++)
        {
            cout << ingrediente[i] << endl;
        }
        cout << "Cantitate chips-uri vandute: " << vandute << endl;
    }

    string getNume()
    {
        return nume;
    }

    float getCalorii()
    {
        return calorii;
    }

    void setCalorii(float noileCalorii)
    {
        calorii = noileCalorii;
    }

    string* getIngrediente()
    {
        return ingrediente;
    }

    void setIngrediente(string* noileIngrediente)
    {
        ingrediente = noileIngrediente;
    }

    int getNrIngrediente()
    {
        return nrIngrediente;
    }

    static int getVandute()
    {
        return vandute;
    }

    static void setVandute(int noileVandute)
    {
        vandute = noileVandute;
    }
};

int Chips::vandute = 0;

void maresteCalorii(Chips& chips, float marire)
{
    chips.calorii = chips.calorii + marire;
}

void scadereCalorii(Chips& chips, float scadere)
{
    chips.calorii = chips.calorii - scadere;
}

class Vanzator
{
private:
    int totalProdVandute;

    const string nume;
    float valVanzari;
    string* produseVandute;
    static int totalVanzariAprozar;

    friend void maresteValVanzari(Vanzator& vanzator, float marire);
    friend void scadereValVanzari(Vanzator& vanzator, float scadere);

public:
    Vanzator() : nume("Popescu Ion")
    {
        valVanzari = 25;
        produseVandute = new string[2];
        produseVandute[0] = "Ceapa";
        produseVandute[1] = "Dulciuri";
        totalProdVandute = 2;
        totalVanzariAprozar++;
    }

    Vanzator(string numeVanzator, float valVanzariVanzator) : nume(numeVanzator), valVanzari(valVanzariVanzator)
    {
        produseVandute = new string[2];
        produseVandute[0] = "Ceapa";
        produseVandute[1] = "Dulciuri";
        totalProdVandute = 2;
        totalVanzariAprozar++;
    }

    Vanzator(string numeVanzator, float valVanzariVanzator, string* produseVanduteVanzator, int totalProdVanduteVanzator) : nume(numeVanzator)
    {
        valVanzari = valVanzariVanzator;
        produseVandute = produseVanduteVanzator;
        totalProdVandute = totalProdVanduteVanzator;
        totalVanzariAprozar++;
    }

    Vanzator(const Vanzator& vanzatorOriginal) : nume(vanzatorOriginal.nume)
    {
        totalProdVandute = vanzatorOriginal.totalProdVandute;
        valVanzari = vanzatorOriginal.valVanzari;
        produseVandute = new string[totalProdVandute];
        for (int i = 0; i < totalProdVandute; i++)
        {
            produseVandute[i] = vanzatorOriginal.produseVandute[i];
        }
    }

    Vanzator operator=(const Vanzator& vanzator)
    {
        this->totalProdVandute = vanzator.totalProdVandute;
        this->valVanzari = vanzator.valVanzari;
        if (produseVandute != NULL)
        {
            delete[] produseVandute;
        }
        produseVandute = new string[totalProdVandute];
        for (int i = 0; i < totalProdVandute; i++)
        {
            produseVandute[i] = vanzator.produseVandute[i];
        }
        return *this;
    }

    bool operator==(const Vanzator& vanzator)
    {
        return this->nume == vanzator.nume;
    }

    bool operator!=(const Vanzator& vanzator)
    {
        return this->nume!= vanzator.nume;
    }

    string& operator[](int i)
    {
        string eroare = "Produs necunoscut.";
        if (i < totalProdVandute)
        {
            return this->produseVandute[i];
        }
        else
        {
            return eroare;
        }
    }

    ~Vanzator()
    {
        delete[] produseVandute;
    }

    void afisare()
    {
        cout << endl << "Vanzatorul " << nume << " a avut un numare de " << valVanzari << " vanzari si anume: " << endl;
        for (int i = 0; i < totalProdVandute; i++)
        {
            cout << produseVandute[i] << endl;
        }
        cout << "Cantitate vanzari totale in magazin: " << totalVanzariAprozar << endl;
    }

    string getNume()
    {
        return nume;
    }

    float getValVanzari()
    {
        return valVanzari;
    }

    void setValVanzari(float noileValVanzari)
    {
        valVanzari = noileValVanzari;
    }

    string* getProduseVandute()
    {
        return produseVandute;
    }

    void setProduseVandute(string* noileProduseVandute)
    {
        produseVandute = noileProduseVandute;
    }

    int getTotalProdVandute()
    {
        return totalProdVandute;
    }

    static int getTotalVanzariAprozar()
    {
        return totalVanzariAprozar;
    }

    static void setTotalVanzariAprozar(int noulTotalVanzariAprozar)
    {
        totalVanzariAprozar = noulTotalVanzariAprozar;
    }
};

int Vanzator::totalVanzariAprozar = 500;

void maresteValVanzari(Vanzator& vanzator, float marire)
{
    vanzator.valVanzari = vanzator.valVanzari + marire;
}

void scadereValVanzari(Vanzator& vanzator, float scadere)
{
    vanzator.valVanzari = vanzator.valVanzari - scadere;
}

void main()
{
    Suc unSuc;
    unSuc.afisare();
    Suc altSuc("Fanta", 4.5);
    altSuc.afisare();
    Suc sprite("Sprite", 3.9, new string[4]{ "Apa", "Zahar", "Lamaie", "Aroma" }, 4);
    sprite.afisare();
    cout << endl;
    marestePret(unSuc, 0.4);
    unSuc.afisare();
    scaderePret(sprite, 0.2);
    sprite.afisare();
    cout << endl;
    cout << "Cel mai mare pret al unui suc este: " << unSuc.getPret() << endl;
    cout << "Cel mai acru suc este: " << sprite.getNume() << endl;
    cout << "Avem in stoc: " << Suc::getCantitate() << endl;
    cout << "Ingredientele din sprite sunt: " << endl;
    for (int i = 0; i < sprite.getNrIngrediente(); i++)
    {
        cout << sprite.getIngrediente()[i] << endl;
    }
    Suc sucNou;
    sucNou = sprite;
    cout<<sucNou;
    if (unSuc < altSuc)
    {
        cout << "unSuc < altSuc"<<endl;
    }
    else
    {
        cout << "unSuc > altSuc"<<endl;
    }
    if (altSuc > sprite)
    {
        cout << "altSuc > sprite"<<endl;
    }
    else
    {
        cout << "altSuc < sprite"<<endl;
    }

    Vanzator unVanzator;
    unVanzator.afisare();
    Vanzator altVanzator("Ionescu David", 68);
    altVanzator.afisare();
    Vanzator altiVanzator("Dumitru Adela", 34, new string[4]{ "Apa", "Suc", "Faina", "Legume"}, 4);
    altiVanzator.afisare();
    cout << endl;
    maresteValVanzari(altVanzator, 3);
    unVanzator.afisare();
    scadereValVanzari(altiVanzator, 7);
    altiVanzator.afisare();
    cout << endl;
    cout << "Cele mai multe vanzari sunt de: " << altVanzator.getValVanzari() << endl;
    cout << "Cele mai multe produse vandute sunt facute de: " << altiVanzator.getNume() << endl;
    cout << "S-au vandut pana acum in aprozar: " << Vanzator::getTotalVanzariAprozar() <<" produse."<< endl;
    cout << "Produsele vandute de Dumitru Adela sunt: " << endl;
    for (int i = 0; i < altiVanzator.getTotalProdVandute(); i++)
    {
        cout << altiVanzator.getProduseVandute()[i] << endl;
    }
    Vanzator nouVanzator;
    nouVanzator = altiVanzator;
    nouVanzator.afisare();
    Vanzator novice;
    if (novice == unVanzator)
    {
        cout << "novice == unVanzator" << endl;
    }
    else
    {
        cout << "novice != unVanzator" << endl;
    }
    if (novice != unVanzator)
    {
        cout << "novice != unVanzator" << endl;
    }
    else
    {
        cout << "novice == unVanzator"<<endl;
    }
    cout << "Primul produs vandut este: " << novice[0];

    Chips unChips;
    unChips.afisare();
    Chips altChips("Chio", 601.4);
    altChips.afisare();
    Chips alteChips("Takis", 589.9, new string[3]{ "Cartofi", "Ulei", "Faina" }, 3);
    alteChips.afisare();
    cout << endl;
    maresteCalorii(altChips, 0.16);
    unChips.afisare();
    scadereCalorii(alteChips, 1.24);
    alteChips.afisare();
    cout << endl;
    cout << "Cele mai multe calorii sunt in chips-urile: " << altChips.getCalorii() << endl;
    cout << "Cele mai multe ingrediente se regasesc in chips-urile: " << alteChips.getNume() << endl;
    cout << "S-au vandut pana acum: " << Chips::getVandute() << endl;
    cout << "Ingredientele din Takis sunt: " << endl;
    for (int i = 0; i < alteChips.getNrIngrediente(); i++)
    {
        cout << alteChips.getIngrediente()[i] << endl;
    }
    Chips nouChips;
    nouChips = alteChips;
    nouChips.afisare();
    Chips unChips2;
    if (unChips2 == unChips)
    {
        cout << "unChips2 == unChips"<<endl;
    }
    if (unChips != nouChips)
    {
        cout << "unChips != nouChips"<<endl;
    }
    cout << "Primul ingredient este: " << nouChips[0];
    
}
