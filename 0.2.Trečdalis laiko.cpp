#include <iostream>

class Laikas {
private:
	int hours,
		minutes,
		seconds,
		inSeconds;
public:
	Laikas();
	Laikas(int);
	~Laikas();

	void inputTime();
	void secondsToTime();

	Laikas operator /(const int kiek)const;
};

int main() {
	
	Laikas laikas;
	int kiek_kartu = 0;
	std::cin >> kiek_kartu;
	laikas.inputTime();

	for (int i = 0; i < kiek_kartu; i++) {
		laikas = laikas / 3;
	}
	return 0;
}

Laikas::Laikas() {
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
	this->inSeconds = 0;
}

Laikas::Laikas(int inSeconds) {
	this->inSeconds = inSeconds;
	secondsToTime();
}

Laikas::~Laikas() {}

void Laikas::inputTime() {
	std::cin >> this->hours >> this->minutes >> this->seconds;
	this->inSeconds = this->hours * 3600 + this->minutes * 60 + this->seconds;
}

void Laikas::secondsToTime() {
	int laikinas_hours, laikinas_minutes, laikinas_seconds, laikinas_inSeconds;
	laikinas_inSeconds = this->inSeconds;

	laikinas_minutes = laikinas_inSeconds / 60;
	laikinas_seconds = laikinas_inSeconds % 60;
	laikinas_hours = laikinas_minutes / 60;
	laikinas_minutes = laikinas_minutes % 60;

	printf("%02d:%02d:%02d\n", laikinas_hours, laikinas_minutes, laikinas_seconds);
}

Laikas Laikas::operator/(const int kiek) const
{
	return Laikas(this->inSeconds/kiek);
}
