#include <iostream>
#include <string>

//khoor zruog
int main()
{
    std::string s;
    int n;
    setlocale(LC_ALL,"RUS");
//    cout << "¬ведите длинну строки в символах" << endl;
//    cin >> n;
//    cin.ignore();
    std::cout << "¬ведите строку состо€щую из слов зашифрованых шифром цезар€ и разделенных знаками-разделител€ми(только знаки \' \', \',\' )" << std::endl;
    getline(std::cin,s);
    for(int k = 0; k < 26 ; k++){
        std::cout << "k=" << k << " ";
        for(int i = 0 ; i < s.size();i++){
            if((s[i] >= 65 && s[i] <= 90)){
                std::cout << static_cast<char>((s[i]-'A' - k + 26)%26 + 'A') ;
            }
            else if((s[i] >= 97 && s[i] <= 122)){
                std::cout << static_cast<char>((s[i]-'a' - k + 26)%26 +'a');
            }
            else std::cout << s[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
