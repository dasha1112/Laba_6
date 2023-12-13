#include "TFormula.h"
template <class TString>
int main()
{
  TFormula<int> formula;
  char s[256];
  std::cin >> s;
  TList<TString> r = formula.Partition(s);
  TList<TString> p = formula.ToPolish(r);
  double c = formula.Calculate(p); 
  std::cout << c; 
  return 0;
}
