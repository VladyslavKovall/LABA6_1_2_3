#include <iostream>
#include <list>
using namespace std;

struct Person {
   string name;
   int age;
};

int main() {
   list<Person> container1 = { {"Anna", 20}, {"Bohdan", 25}, {"Ira", 22} };

   // ��������
   cout << "container1:\n";
   for (auto& p : container1) cout << p.name << " " << p.age << endl;

   // ����: �������� Anna, ������ Bohdan ? age = 30
   container1.remove_if([](Person p) { return p.name == "Anna"; });
   for (auto& p : container1)
      if (p.name == "Bohdan") p.age = 30;

   // ������ ���������
   list<Person> container2 = { {"Olena", 19}, {"Taras", 28} };

   // �������� ������� ���� �������
   auto it = container1.begin();
   advance(it, 1);
   container1.erase(it);

   // ������ �� � �������
   container1.insert(container1.end(), container2.begin(), container2.end());

   // ��������
   cout << "container1 changed:\n";
   for (auto& p : container1) cout << p.name << " " << p.age << endl;

   cout << "container2:\n";
   for (auto& p : container2) cout << p.name << " " << p.age << endl;

   return 0;
}
