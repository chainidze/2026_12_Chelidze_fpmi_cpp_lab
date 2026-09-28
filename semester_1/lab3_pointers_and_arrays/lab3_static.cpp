#include <iostream>
#include <cmath>
#include <random>
#include <string>
const int maxv = 10000;

long long scalar(int* a , int* b, int n){
    long long answ = 0;
    for(int i = 0 ; i < n ; i ++){
        answ += static_cast<long long>(*a) * (*b);
        a++;
        b++;
    }
    return answ;
}
void ruchkami(int* a,int n){
    for(int i = 0 ; i < n ;  i++){
        std::cin >> a[i];
    }
}
int main()
{
    setlocale(LC_ALL,".1251");
    int n = 0;
    int a[maxv] = {};
    int b[maxv] = {};
    double z[maxv] = {};
    std::cout << "Введите n до 10 000" << std::endl;
    std::cin >> n;
    if( (n <= 0) || (n > 10000)){
        std::cout << "error" << std::endl;
        return -1;
    }
    std::string t;
    std::cout << "выберете тип работы , если хотить вводить элементы вручную , введите \"ruchki\", если рандомные , то \"random\" ](или что угодно другое\)" << std::endl;
    std::cin >> t;
    if( (t) == "ruchki"){
        std::cout << "Введите все элементы массима а" << std::endl;
        ruchkami(a , n);
        std::cout << "Введите все элементы массима b" << std::endl;
        ruchkami(b , n);
    }
    else{
        std::cout << "границы от а до b" << std::endl;
        int l , r;
        std::cin >> l >> r;
        if(l > r) std::swap(l,r);
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> distrib(l,r);
        std::cout << "элементы a: ";
        for(int i = 0 ; i < n ;  i++){
            a[i] = (distrib(gen));
            std::cout << a[i] << " ";
        }
        std::cout << std::endl << "элементы b: ";
        for(int i = 0 ; i < n ;  i++){
            b[i] = (distrib(gen));
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
    }

    long long sc = scalar(a , b , n);
//    std::cout << sc << std::endl;
    for(int i = 0 ; i < n ; i ++){
        double el = static_cast<double>(std::sqrt(a[i]*a[i] + b[i]*b[i]));
        z[i] = el / sc;
        std::cout << z[i] << " ";
    }
    return 0;
}
