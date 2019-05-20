#include <iostream>
#include <algorithm>

class Dalyvis {
private:
	int amzius,
		sugautu_zuvu_kiekis;
	int* zuvu_svoriai;
	double svorio_vidurkis;
public:
	Dalyvis();
	~Dalyvis();

	void inputDalyvisData();
	void processDalyvisData();
	bool thrownAway();

	double getAverage();
	int getAge();
};

int main() {
	
	int luckyFishes = 0,
		luckyFisher = 0,
		biggestAverage = -1;

	Dalyvis* dalyviai = NULL;
	int dalyviu_kiekis = 0;
	std::cin >> dalyviu_kiekis;
	dalyviai = new Dalyvis[dalyviu_kiekis];

	for (int i = 0; i < dalyviu_kiekis; i++) {
		dalyviai[i].inputDalyvisData();
		dalyviai[i].processDalyvisData();
		if (dalyviai[i].thrownAway()) luckyFishes++;
		if (dalyviai[i].getAverage() > biggestAverage) {
			biggestAverage = dalyviai[i].getAverage();
			luckyFisher = i;
		}
		printf("%i žvejo galutinis vidurkis yra %0.3f\n", i+1, dalyviai[i].getAverage());
	}

	printf("Nugalėtojo amžius: %i\n", dalyviai[luckyFisher].getAge());
	printf("Antrą gyvenimą gavusių žuvų skaičius: %i\n", luckyFishes);

	delete[] dalyviai;
	dalyviai = NULL;
	return 0;
}

Dalyvis::Dalyvis() {
	this->amzius = 0;
	this->sugautu_zuvu_kiekis = 0;
	this->zuvu_svoriai = NULL;
	this->svorio_vidurkis = 0;
}

Dalyvis::~Dalyvis() {
	delete[] this->zuvu_svoriai;
	this->zuvu_svoriai = NULL;
}

void Dalyvis::inputDalyvisData() {
	std::cin >> this->amzius >> this->sugautu_zuvu_kiekis;
	zuvu_svoriai = new int[sugautu_zuvu_kiekis];
	for (int i = 0; i < sugautu_zuvu_kiekis; i++) {
		std::cin >> this->zuvu_svoriai[i];
		this->svorio_vidurkis += this->zuvu_svoriai[i];
	}
	std::sort(this->zuvu_svoriai, this->zuvu_svoriai + this->sugautu_zuvu_kiekis);
}

void Dalyvis::processDalyvisData() {
	if (this->amzius < 18) {
		this->svorio_vidurkis -= this->zuvu_svoriai[0];
		this->sugautu_zuvu_kiekis--;
	}
	else if (this->amzius > 18) {
		this->svorio_vidurkis -= this->zuvu_svoriai[this->sugautu_zuvu_kiekis-1];
		this->sugautu_zuvu_kiekis--;
	}
	this->svorio_vidurkis /= static_cast<double>(this->sugautu_zuvu_kiekis);
}

bool Dalyvis::thrownAway()
{
	if (this->amzius != 18) return true;
	else return false;
}

double Dalyvis::getAverage()
{
	return this->svorio_vidurkis;
}

int Dalyvis::getAge()
{
	return this->amzius;
}
