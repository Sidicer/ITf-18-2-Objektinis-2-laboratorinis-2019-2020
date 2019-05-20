#include <iostream>
#include <algorithm>

class Dalyvis {
private:
	int seiminko_amzius,
		augintinio_amzius,
		ivertinimu_kiekis;
	int* ivertinimai;
	double ivertinimu_vidurkis;
public:
	Dalyvis();
	~Dalyvis();

	void inputDalyvisData();

	bool disqualify();
	int getVoteCount();

	double getAverage();
	int getOwnerAge();
	int getPetAge();
};

int main() {

	int winner = 0,
		maziausiai_vertinanciu = -1;
	double biggestAverage = -1;

	Dalyvis* dalyviai = NULL;
	int dalyviu_kiekis = 0;
	std::cin >> dalyviu_kiekis;

	dalyviai = new Dalyvis[dalyviu_kiekis];
	int diskvalifikuotu = dalyviu_kiekis;

	for (int i = 0; i < dalyviu_kiekis; i++) {
		dalyviai[i].inputDalyvisData();
		
		if (dalyviai[i].getAverage() > biggestAverage && !dalyviai[i].disqualify()) {
			biggestAverage = dalyviai[i].getAverage();
			winner = i;
		}
		printf("%i dalyvio galutinis vidurkis yra %0.3f\n", i + 1, dalyviai[i].getAverage());

		if (dalyviai[i].disqualify()) diskvalifikuotu--;
		if (dalyviai[i].getVoteCount() > maziausiai_vertinanciu) maziausiai_vertinanciu = dalyviai[i].getVoteCount();
	}

	if (diskvalifikuotu) printf("Nugalėtojo ir jo šeimininko amžiai: %i ir %i\n", dalyviai[winner].getPetAge(), dalyviai[winner].getOwnerAge());
	else printf("visi looseriai\n");

	printf("Mažiausias galimas žiūrovų skaičius: %i", maziausiai_vertinanciu);

	delete[] dalyviai;
	dalyviai = NULL;
	return 0;
}

Dalyvis::Dalyvis() {
	this->seiminko_amzius = 0;
	this->augintinio_amzius = 0;
	this->ivertinimu_kiekis = 0;
	this->ivertinimai = NULL;
	this->ivertinimu_vidurkis = 0;
}

Dalyvis::~Dalyvis() {
	delete[] this->ivertinimai;
	this->ivertinimai = NULL;
}

void Dalyvis::inputDalyvisData() {
	std::cin >> this->seiminko_amzius >> this->augintinio_amzius >> this->ivertinimu_kiekis;
	ivertinimai = new int[ivertinimu_kiekis];
	for (int i = 0; i < ivertinimu_kiekis; i++) {
		std::cin >> this->ivertinimai[i];
		this->ivertinimu_vidurkis += this->ivertinimai[i];
	}

	std::sort(this->ivertinimai, this->ivertinimai + this->ivertinimu_kiekis);
	this->ivertinimu_vidurkis = this->ivertinimu_vidurkis - this->ivertinimai[0] - this->ivertinimai[this->ivertinimu_kiekis - 1];
}

bool Dalyvis::disqualify()
{
	if (this->augintinio_amzius > this->seiminko_amzius) return true;
	else return false;
}

int Dalyvis::getVoteCount()
{
	return this->ivertinimu_kiekis;
}

double Dalyvis::getAverage() { return this->ivertinimu_vidurkis / static_cast<double>(this->ivertinimu_kiekis-2); }

int Dalyvis::getOwnerAge(){	return this->seiminko_amzius; }

int Dalyvis::getPetAge(){ return this->augintinio_amzius; }
