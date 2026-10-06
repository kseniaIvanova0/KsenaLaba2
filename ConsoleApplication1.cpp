/*************************
 * Автор: Иванова Ксения *
 * Вариант: 7            *
 * Название: Лаба 2      *
 *************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  // Ввод данных
  double initialPressure, chamberVolume, pumpVolume;
  cout << "vvedite nachalnoe davlenie p0: ";
  cin >> initialPressure;
  cout << "vvedite obiom kameri V (л): ";
  cin >> chamberVolume;
  cout << "vvedite rabochii obiom nasosa V0 (л): ";
  cin >> pumpVolume;

  // Вычисление константы (отношение объемов)
  double ratio = chamberVolume / (chamberVolume + pumpVolume);

  int strokeCount;
  double residualPressure;

  // Вывод заголовка таблицы
  cout << "\nTablica znachenii p = f(n)\n";
  cout << "n\tp\n";
  cout << fixed << setprecision(3); // Округление до 3 знаков

  // --- ПЕРВЫЙ УЧАСТОК: цикл с постусловием do while (n = 10..50, шаг 10) ---
  strokeCount = 10;
  do {
      residualPressure = initialPressure * pow(ratio, strokeCount);
      cout << strokeCount << "\t" << residualPressure << "\n";
      strokeCount += 10;
  } while (strokeCount <= 50);

  // --- ВТОРОЙ УЧАСТОК: цикл с предусловием while (n = 100..250, шаг 50) ---
  strokeCount = 100;
  while (strokeCount <= 250) {
      residualPressure = initialPressure * pow(ratio, strokeCount);
      cout << strokeCount << "\t" << residualPressure << "\n";
      strokeCount += 50;
  }

  return 0;
}