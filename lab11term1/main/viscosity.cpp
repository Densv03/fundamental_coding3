#include "viscosity.h"

elements::elements() {

}
elements::elements(string name1, int num1, int temperature1, float viscosity1) {

	this->name = name1;
	this->num = num1;
	this->temperature = temperature1;
	this->viscosity = viscosity1;
}
elements::elements(const elements& a) {
	this->name = a.name;
	this->num = a.num;
	this->temperature = a.temperature;
	this->viscosity = a.viscosity;
}

void elements::setter(string name1, int num1, int temperature1, float viscosity1) {

	this->name = name;
	this->num = num;
	this->temperature = temperature;
	this->viscosity = viscosity;
}

int elements::random_number() {
	srand(time(NULL));
	int arr[7]{};
	bool already;

	for (int i = 0; i < 7; ) {

		already = false;
		int newrand = rand() % 7;

		for (int j = 0; j < i; j++) {
			if (*(arr + i) == newrand) {
				already = true;
			}
		}

		if (already == false) {
			*(arr + i) = newrand;
			i++;
		}
	}
	int k = 0;
	return *(arr + k++);
}
void elements::random() {
	string elements[8] = { "Медь","Золото","Вольфрам","Серебро","Ртуть","Алюминий","Свинец","Висмут" };
	int nums[8] = { 29,79,74,47,80,13,82,83 };
	int temperatures[8] = { 1085,1064,3422,962,-39,660,328,271 };
	float viscosities[8] = { 1.2,0.8,4.0,3.2,3.3,2.9,2.1,1.7 };
	int arr[8]{};
	bool already;
	for (int i = 0; i < 8; ) {
		already = false;
		int newrand = rand() % 8;
		for (int j = 0; j < i; j++) {
			if (*(arr + i) == newrand) {
				already = true;
			}
		}
		if (already == false) {
			*(arr + i) = newrand;
			i++;
		}
	}
	int k = 0;
	int randnum = *(arr + k++);
	name = *(elements + randnum);
	num = *(nums + randnum);
	temperature = *(temperatures + randnum);
	viscosity = *(viscosities + randnum);
}

void elements::show() {

	cout << "| " << setw(12) << name << " | " << setw(16) << num << " | " << setw(12) << temperature << " | " << setw(13) << viscosity << " | \n";
	cout << "|--------------|------------------|--------------|---------------|\n";
}

elements:: ~elements() {

}