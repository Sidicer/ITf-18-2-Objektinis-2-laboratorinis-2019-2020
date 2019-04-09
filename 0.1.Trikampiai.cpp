#include <iostream>

class trikampiai {
	private:
		int krastine_a,
			krastine_b,
			krascine_c;
	public:
		trikampiai();
		trikampiai(int, int, int);
		~trikampiai();
		double plotas();
};

int main() {
	trikampiai trikampis_antras;
	int a, b, c;
	std::cin >> a >> b >> c;
	trikampiai trikampis_pirmas(a, b, c);
	if (trikampis_pirmas.plotas() > trikampis_antras.plotas())
		printf("Pirmas\n");
	else if (trikampis_antras.plotas() > trikampis_pirmas.plotas())
		printf("Antras\n");
	else
		printf("Lygūs\n");
	return 0;
}

trikampiai::trikampiai()
{
	this->krastine_a = 6;
	this->krastine_b = 6;
	this->krascine_c = 6;
}

trikampiai::trikampiai(int krastine_a, int krastine_b, int krastine_c)
{
	this->krastine_a = krastine_a;
	this->krastine_b = krastine_b;
	this->krascine_c = krastine_c;
}

trikampiai::~trikampiai()
{
	printf("Išnyk\n");
}

double trikampiai::plotas() {
	long double p = (this->krastine_a + this->krastine_b + this->krascine_c) / 2.0;
	return sqrt(p*(p- this->krastine_a)*(p- this->krastine_b)*(p-krascine_c));
}
