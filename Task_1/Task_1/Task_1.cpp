#include <iostream>
#include <set>
#include <map>
#include <string>

void letter_count(std::string& text) {
    std::multiset<char> char_set(text.begin(), text.end());
    std::cout << "[IN]: "<< text<< std::endl;
    std::cout << "[OUT]: " << std::endl;
    std::multimap<int, char> frequency;
    for (auto it = char_set.begin(); it != char_set.end(); it=char_set.upper_bound(*it)) 
    {
        frequency.emplace(char_set.count(*it), *it);
    }

   for(auto it=frequency.rbegin();it!=frequency.rend();++it){
        std::cout << it->second << ": " << it->first << std::endl;
    }

}


int main()
{
    
    std::string text = "Hello world!!";  
    letter_count(text);
    

}

