#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

const int maxv = 100;

void ruchkami(int a[maxv][maxv],int n, int m){
    for(int j = 0 ; j < m ;  j++){
        for(int i = 0 ; i < n ;  i++){
            std::cin >> a[j][i];
        }
    }
}
int input(int a[maxv][maxv], int& n, int& m){
    std::cout << "¬ведите кол во столбцов до " << maxv << std::endl;
    std::cin >> n;
    if( (n <= 0) || (n > maxv)){
        return -1;
    }
    std::cout << "¬ведите кол во строк до " << maxv << std::endl;
    std::cin >> m;
    if( (m <= 0) || (m > maxv)){
        return -1;
    }

    char t = 'a';
    std::cout << "выберете тип работы , если хотить вводить элементы вручную , введите \"v\", если рандомные , то \"r\" ](или любой другой символ\)" << std::endl;
    if(!(std::cin >> t)){
        return -1;
    }
    if( (t) == 'v'){
        std::cout << "¬ведите все элементы массива" << std::endl;
        ruchkami(a , n , m);
    }
    else{
        std::cout << "границы от а до b" << std::endl;
        int l , r;
        std::cin >> l >> r;
        if(l > r) std::swap(l,r);
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> distrib(l,r);
        std::cout << "элементы a: " << std::endl;
        for(int j = 0 ; j < m ;  j++){
            for(int i = 0 ; i < n ;  i++){
                a[j][i] = (distrib(gen));
                std::cout << std::setw(3) << a[j][i] << " ";
            }
        std::cout << std::endl;
        }
    }
    return 0;
}
int main()
{
    setlocale(LC_ALL,".1251");
    int n = 0;
    int m = 0;
    int a[maxv][maxv];
    if( input(a, n, m) == -1){
        std::cout << "eror" << std::endl;
        return -1;
    }
//    for(int j = 0 ; j < n ; j++){
//        for(int i = 0 ; i < n ; i++){
//            std::cout << a[j][i] << " ";
//        }
//        std::cout << std::endl;
//    }
    int pref[maxv][maxv] = {};
    for(int j = 0 ; j < m;  j++){
        int l = 0;
        int r = 0;
        while(r < n){
            while(r < n && a[j][r] > 0){
                r++;
            }
            while(l < r){
                pref[j][l] = r - l;
//                std::cout << a[j][l] << ":";
//                std::cout << pref[j][l] << " ";
                l++;
            }
            l++;
            r++;
//        std::cout << std::endl;
        }

    }
    int AnswPozJ = -1;
    int AnswPozEndJ = 0;
    int AnswPozI = 0;
    int AnswPozEndI = 0;
    int size = 0;
    for(int j = 0 ; j < m; j++){
        for(int i = 0 ; i < n; i++){
            int CurrS = -1;
            int MinS = 1000000;
            for(int check = j ; check < m ; check++){
                MinS = std::min(MinS,pref[check][i]);
                CurrS = MinS*(check - j + 1);
                if(CurrS > size){
                    AnswPozI = i;
                    AnswPozJ = j;
                    AnswPozEndI = i+MinS-1;
                    AnswPozEndJ = check;
                    size = CurrS;
//                  std::cout << "J:" << AnswPozJ << " I:" << AnswPozI << " JE:" << AnswPozEndJ << " IE:" << AnswPozEndI << " size: " << size << " MINS " << MinS<< std::endl;
                }
            }

        }
    }
    if(AnswPozJ == -1){
        std::cout << "такой матрицы нет" << std::endl;
        return -1;
    }
    std::cout << "строка:" << AnswPozJ + 1<< " столбец:" << AnswPozI + 1<< " size: " << size << std::endl;
    std::cout << "матрица:" << std::endl;
    for(int j = AnswPozJ ; j <= AnswPozEndJ ; j++){
        for(int i = AnswPozI ; i <= AnswPozEndI ; i++){
            std::cout << std::setw(3) << a[j][i] << " ";
        }
        std::cout << std::endl;
    }
//    std::cout << std::endl;
//    for(int j = 0 ; j < m ; j++){
//        for(int i = 0 ; i < n ; i++){
//            std::cout << pref[j][i] << " ";
//        }
//        std::cout << std::endl;
//    }
    return 0;
}
