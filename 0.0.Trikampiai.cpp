#include <iostream>

class staciakampiai {
	private:
		int ds_mat[2],
			is_mat[2];
	public:
		staciakampiai();
		~staciakampiai();

		int calculate_area();
		int calculate_peri();
};

int main() {
	int param; std::cin >> param;
	staciakampiai Stac;
	switch (param) {
		case 1: std::cout << Stac.calculate_area();
		break;
		case 2: std::cout << Stac.calculate_peri();
		break;
	}
	return 0;
}

staciakampiai::staciakampiai() {
	ds_mat[0] = 6;
	ds_mat[1] = 9;
}

staciakampiai::~staciakampiai()
{
}

int staciakampiai::calculate_area() {
	std::cin >> is_mat[0] >> is_mat[1];
	return is_mat[0] * is_mat[1] + ds_mat[0] * ds_mat[1];
}

int staciakampiai::calculate_peri() {
	std::cin >> is_mat[0] >> is_mat[1];
	return 2*(is_mat[0] + is_mat[1]) + 2*(ds_mat[0] + ds_mat[1]);
}
