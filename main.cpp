#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string SolveTask(int n) {

  // Считаем сумму арифметической прогрессии от 1 до n
  int s = n*(1 + n) / 2;

  // Если s не кратно 2, то невозможно получить в итоге одинаковые веса порций
  if (s % 2 != 0) {
    string res = "NO\n";
    return res;
  }

  ostringstream oss;
  oss << "YES\n";

  int l = n / 2;
  int k = n - l;
  oss << l << "\n";

  // Если s кратно 2, то либо n кратно 4, либо (n+1) кратно 4
  if (n % 4 == 0) {
    // Пример: n = 12
    // У 1-го человека порции: 1 12 2 11 3 10
    // У 2-го человека порции: 4 9 5 8 6 7
    for (int i = 1; i <= n / 4; i++) {
      // Считаем порции 1-го
      oss << i << " " << n - i + 1 << " ";
    }
    oss << "\n" << k << "\n";
    for (int i = n / 4 + 1; i <= n / 2; i++) {
      // Считаем порции 2-го
      oss << i << " " << n - i + 1 << " ";
    }
    oss << "\n";
    return oss.str();
  }


  // Пример: n = 11
  // У 1-го человека порции: 11 1 10 2 9
  // У 2-го человека порции: 3 8 4 7 5 6
  oss << n << " ";
  for (int i = 1; i <= n / 4; i++) {
    // Считаем порции 1-го
    oss << i << " " << n - i << " ";
  }
  oss << "\n" << k << "\n";
  for (int i = n / 4 + 1; i <= n / 2; i++) {
    // Считаем порции 2-го
    oss << i << " " << n - i << " ";
  }
  oss << "\n";
  return oss.str();
}

int main() {
  int n;
  cin >> n;
  cout << SolveTask(n);
}
