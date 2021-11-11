#include<iostream>
#include<cstring>


using namespace std;
class Substance
{
private:
	string name;
	char type;
	string humidity;
	float coefficient;
public:
	Substance() { coefficient = 0; }
	Substance(string _name, char _type, string _humidity, float _coefficient)
	{
		name = _name;
		type = _type;
		humidity = _humidity;
		coefficient = _coefficient;
	}
	void set(string _name, char _type, string _humidity, float _coefficient)
	{
		name = _name;
		type = _type;
		humidity = _humidity;
		coefficient = _coefficient;
	}
	string getName()
	{
		return name;
	}
	char getType()
	{
		return type;
	}
	string getHumidity()
	{
		return humidity;
	}
	float getCoefficient()
	{
		return coefficient;
	}
	void setName(string n)
	{
		name = n;
	}
	void setType(char n)
	{
		type = n;
	}
	void setHumidity(string n)
	{
		humidity = n;
	}
	void setCoefficient(float n)
	{
		coefficient = n;
	}
	void show()
	{
		cout << name << ": ";
		cout << type << ", ";
		cout << humidity << ", ";
		cout << coefficient;
	}
	Substance& operator= (const Substance& sub)
	{
		name = sub.name;
		type = sub.type;
		humidity = sub.humidity;
		coefficient = sub.coefficient;
		return *this;
	}
	friend Substance operator+ (Substance& sub1, Substance& sub2);
	friend bool operator== (Substance& sub1, Substance& sub2);
	friend ostream& operator<< (ostream& out, const Substance& sub);
	friend istream& operator>> (istream& in, Substance& sub);
};
Substance operator+ (Substance& sub1, Substance& sub2)
{
	Substance sub(sub1.name + sub2.name, sub1.type + sub2.type, sub1.humidity + sub2.humidity, sub1.coefficient + sub2.coefficient);
	return sub;
}
bool operator== (Substance& sub1, Substance& sub2)
{
	bool b = true;
	if (sub1.name != sub2.name) b = false;
	if (sub1.type != sub2.type) b = false;
	if (sub1.humidity != sub2.humidity) b = false;
	if (sub1.coefficient != sub2.coefficient) b = false;
	return b;
}
ostream& operator<< (ostream& out, const Substance& sub)
{
	out << sub.name << ": " << sub.type << ", " << sub.humidity << ", " << sub.coefficient << '\n';
	return out;
}
istream& operator>> (istream& in, Substance& sub)
{
	string _name;
	char _type;
	string _humidity;
	float _coefficient;
	in >> _name >> _type >> _humidity >> _coefficient;
	sub.set(_name, _type, _humidity, _coefficient);
	return in;
}
int main()
{
	Substance sub[3], copy;
	copy = sub[2];
	bool ans = sub[2] == copy;
	sub[0].set("Aluminium", 'M', "0-100", 209.3);
	sub[1].set("Fiberglass", 'T', "0-100", 0.035);
	sub[2].set("Clay", 'D', "15-20", 0.73);
	cout << "sub[0] + sub[1] = " << sub[0] + sub[1] << '\n';
	cout << "sub[2] == copy = " << ans;
}