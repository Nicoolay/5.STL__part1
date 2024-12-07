#include <iostream>
#include <set>
#include <string>


int main()
{
    
    std::string text = "Hello world!!";  // Исходная строка
    std::multiset<char> char_set(text.begin(), text.end());
    std::cout << "[IN]: Hello world!! ";
  
    std::cout << "\nH: " << char_set.count('H') << std::endl;
    std::cout << "e: " << char_set.count('e') << std::endl;
    std::cout << "l: " << char_set.count('l') << std::endl;
    std::cout << "o: " << char_set.count('o') << std::endl;
    std::cout << " : " << char_set.count(' ') << std::endl;
    std::cout << "w: " << char_set.count('w') << std::endl;
    std::cout << "r: " << char_set.count('r') << std::endl;
    std::cout << "d: " << char_set.count('d') << std::endl;
    std::cout << "!: " << char_set.count('!') << std::endl;
}

