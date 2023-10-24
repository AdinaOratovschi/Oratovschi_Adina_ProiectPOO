#include <iostream>
#include <string>
using namespace std;

//domeniul e Aprozar
//clasele sunt: Suc, 

class Suc
{
public:
	
	int volum;
	string* ingrediente;
	float pret;
	const string nume = "Coca-Cola";
	int stoc;
	static int sortimente;
	
	Suc()
	{
		//sortimente++;
		volum = 500;
		ingrediente = new string[2];
		ingrediente[0] = "Apa";
		ingrediente[1] = "Aroma";
		pret = 2.99;
		stoc = 0;
	}

	Suc(int volum, float pret)
	{
		//sortimente++;
		ingrediente = new string[2];
		ingrediente[0] = "Apa";
		ingrediente[1] = "Aroma";
		this->pret = pret;
		this->volum = volum;
		stoc = 0;
	}

	Suc(int volum, float pret, int stoc)
	{
		//sortimente++;
		ingrediente = new string[2];
		ingrediente[0] = "Apa";
		ingrediente[1] = "Aroma";
		this->pret = pret;
		this->volum = volum;
		this->stoc = stoc;
	}



	void afisare()
	{
		cout << "Sucul cu numele " << nume << " are un volum de " << volum << " ml si pretul de " << pret <<" si contine: "<<endl;
		cout << ingrediente[0] << endl << ingrediente[1]<<endl;
	}
};

void main()
{
	Suc cola;
	cola.afisare();

}

