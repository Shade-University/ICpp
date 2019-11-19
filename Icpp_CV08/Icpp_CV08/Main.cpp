#include "Matrix.h"


int main()
{
	Matrix<int> m{ 3,3 };
	int jednodpole[] = { 0,1,2,3,4,5,6,7,8 };
	m.SetZ(jednodpole);
	std::cout << "Defaultni pole" << std::endl;
	m.Print();
	Matrix<int> mt = m.Transposition();
	std::cout << "Po tranzpozici" << std::endl;
	mt.Print();
	Matrix<int> mmt = m.Multiply(mt);
	std::cout << "Vynasobene pole" << std::endl;
	mmt.Print();
	Matrix<double> mmt_d = mmt.TypeCast<double>();
	std::cout << "Prevod na double" << std::endl;
	mmt_d.Print();
	Matrix<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.SetZ(jednodpole_d);
	std::cout << "Nove double pole" << std::endl;
	n_d.Print();
	Matrix<double> mmtn_d = mmt_d.Multiply(n_d);
	std::cout << "Vynasobene pole" << std::endl;
	mmtn_d.Print();
	Matrix<int> r = mmtn_d.TypeCast<int>();
	std::cout << "Prevod na int pole" << std::endl;
	r.Print();
	Matrix<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.SetZ(tpole);
	std::cout << "Nove int pole" << std::endl;
	t.Print();
	std::cout << "r==t ? " << (r.IsEqual(t) ? "true" : "false") << std::endl;

	std::cin.get();
	return 0;
}