#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

struct Person {
   string name;
   int age;

   bool operator<(const Person& other) const {
      return age < other.age;
   }

   bool operator>(const Person& other) const {
      return age > other.age;
   }
};

int main() {
   // 1. ���������� ������
   list<Person> people = { {"Ivan", 30}, {"Maria", 20}, {"Oleh", 25}, {"Anna", 22} };

   // 2. ���������� �� ��������
   people.sort(greater<>());

   // 3. ��������
   cout << "Sorted (desc):\n";
   for (auto& p : people) cout << p.name << " " << p.age << endl;

   // 4. ����� age < 25
   auto found = find_if(people.begin(), people.end(), [](Person p) { return p.age < 25; });
   if (found != people.end())
      cout << "Found age < 25: " << found->name << " " << found->age << endl;

   // 5. ���������� ����� ����� � set
   set<Person> young;
   copy_if(people.begin(), people.end(), inserter(young, young.end()), [](Person p) { return p.age < 25; });

   // 6. ��������
   cout << "Young people:\n";
   for (auto& p : young) cout << p.name << " " << p.age << endl;

   // 7. ���������� � set ��� �������������, people ��������� �� ���������
   people.sort();

   // 8. ��������
   cout << "People (asc):\n";
   for (auto& p : people) cout << p.name << " " << p.age << endl;

   // 9. ������
   list<Person> merged(people);
   merged.insert(merged.end(), young.begin(), young.end());
   merged.sort();

   // 10. ��������
   cout << "Merged list:\n";
   for (auto& p : merged) cout << p.name << " " << p.age << endl;

   // 11. ϳ�������� age < 25
   int count = count_if(merged.begin(), merged.end(), [](Person p) { return p.age < 25; });
   cout << "Count of people with age < 25: " << count << endl;

   // 12. �������� �������� ���� � ������ age == 22
   bool any22 = any_of(merged.begin(), merged.end(), [](Person p) { return p.age == 22; });
   cout << "Is there anyone with age == 22? " << (any22 ? "Yes" : "No") << endl;

   return 0;
}
