#include <iostream>

class Data {
private:
	int moksleiviu_kiekis = 0,
		pagirimo_rasta_gaus = 0;
	int* pazymiai = NULL;
public:
	void run();
};

int main() {
	int moksleiviu_kiekis = 0,
		pagirimo_rasta_gaus = 0;
	int* pazymiai = NULL;

	std::cin >> moksleiviu_kiekis;
	for (int i = 0; i < moksleiviu_kiekis; i++) {
		int pazymiu_kiekis = 0,
			pazymiu_suma = 0;
		double vidurkis;
		bool maziau_8 = false;
		std::cin >> pazymiu_kiekis;
		pazymiai = new int[pazymiu_kiekis];
		for (int j = 0; j < pazymiu_kiekis; j++) {
			std::cin >> pazymiai[j];
			pazymiu_suma += pazymiai[j];
			if (pazymiai[j] < 8) maziau_8 = true;
		}
		vidurkis = (double)pazymiu_suma / pazymiu_kiekis;
		if (vidurkis > 8.5 && !maziau_8) pagirimo_rasta_gaus++;
		delete[] pazymiai;
		pazymiai = NULL;
	}

	if (pagirimo_rasta_gaus == 0) printf("visi looseriai");
	else if (pagirimo_rasta_gaus == 1) printf("Pagyrimo raštą gaus %i moksleivis", pagirimo_rasta_gaus);
	else if (pagirimo_rasta_gaus < 10 || pagirimo_rasta_gaus > 21 && pagirimo_rasta_gaus < 31) printf("Pagyrimo raštą gaus %i moksleiviai", pagirimo_rasta_gaus);
	else if ((pagirimo_rasta_gaus % 10) == 1 && pagirimo_rasta_gaus != 11) printf("Pagyrimo raštą gaus %i moksleivis", pagirimo_rasta_gaus);
	else printf("Pagyrimo raštą gaus %i moksleivių", pagirimo_rasta_gaus);

	return 0;
}

void Data::run() {
	std::cin >> moksleiviu_kiekis;
	for (int i = 0; i < moksleiviu_kiekis; i++) {
		int pazymiu_kiekis = 0,
			pazymiu_suma = 0;
		double vidurkis;
		bool maziau_8 = false;
		std::cin >> pazymiu_kiekis;
		pazymiai = new int[pazymiu_kiekis];
		for (int j = 0; j < pazymiu_kiekis; j++) {
			std::cin >> pazymiai[j];
			pazymiu_suma += pazymiai[j];
			if (pazymiai[j] < 8) maziau_8 = true;
		}
		vidurkis = (double)pazymiu_suma / pazymiu_kiekis;
		if (vidurkis > 8.5 && !maziau_8) pagirimo_rasta_gaus++;
		delete[] pazymiai;
		pazymiai = NULL;
	}
}
