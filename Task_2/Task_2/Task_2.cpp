

#include <iostream>
#include <vector>
#include<set>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size{};   
    std::cout << "[IN]:\n";
    std::cin >> size;
    std::vector<int> arr1(size);
    for (int i = 0; i < size; ++i) {
       std::cin>> arr1[i]; 
    }
    std::cout << "OUT: \n";
  
    std::set<int> my_set;
    for (int i = 0; i < size; ++i) { // перекладываем вектор в set что бы убрать дубли и отсортировать по позрастанию
       my_set.insert(arr1[i]);
    }
   
    for (auto it = my_set.rbegin(); it != my_set.rend(); ++it) { // вывод в обратном направлении, в условиях задачи не написано, что бы они внутри были отсортированы
        std::cout << *it << "\n";
    }
    std::cout << std::endl;

}
