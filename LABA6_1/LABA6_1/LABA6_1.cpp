#include <iostream>
#include <list>
using namespace std;

int main() {
   list<int> container1 = { 1, 2, 3, 4, 5 };

   // 2. Перегляд
   cout << "container1: ";
   for (int val : container1) cout << val << " ";
   cout << endl;

   // 3. Зміна: видалити 2, замінити 4 на 40
   container1.remove(2);
   for (auto& val : container1)
      if (val == 4) val = 40;

   // 4. Перегляд з ітераторами
   cout << "Changed container1: ";
   for (auto it = container1.begin(); it != container1.end(); ++it)
      cout << *it << " ";
   cout << endl;

   // 5. Другий контейнер
   list<int> container2 = { 6, 7, 8 };

   // 6. Видалити 2 елементи після початку
   auto it = container1.begin();
   advance(it, 1);
   container1.erase(it, next(it, 2));

   // Додати всі з другого контейнера
   container1.insert(container1.end(), container2.begin(), container2.end());

   // 7. Перегляд обох
   cout << "Update container1: ";
   for (int val : container1) cout << val << " ";
   cout << endl;

   cout << "container2: ";
   for (int val : container2) cout << val << " ";
   cout << endl;

   return 0;
}
