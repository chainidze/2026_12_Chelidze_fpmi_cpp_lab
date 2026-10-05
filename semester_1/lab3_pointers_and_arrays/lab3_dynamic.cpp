#include <iostream>
#include <cmath>
#include <random>
#include <string>
const int maxv = 10000;

void ruchkami(int* a,int n){
for(int i = 0 ; i < n ; i++){
std::cin >> a[i];
}
}
int main()
{
setlocale(LC_ALL,".1251");
int n = 0;

std::cout << "Введите n до " << maxv << std::endl;
std::cin >> n;
if( (n <= 0) || (n > maxv)){
std::cout << "error" << std::endl;
return -1;
}
int* a = new int[n];
int* answ = new int[n];
std::string t;
std::cout << "выберете тип работы , если хотить вводить элементы вручную , введите \"ruchki\", если рандомные , то \"random\" ](или что угодно другое\)" << std::endl;
std::cin >> t;
if( (t) == "ruchki"){
std::cout << "Введите все элементы массива" << std::endl;
ruchkami(a , n);
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
for(int i = 0 ; i < n ; i++){
a[i] = (distrib(gen));
std::cout << a[i] << " ";
}
std::cout << std::endl;
}
int pointer = 0;
int r = 0;
for(int l = 0 ;l < n ; ){
while(r < n && (a[r] == a[l]) ){ // ()
r++;
}
answ[pointer] = a[l];
pointer++;
l = r;
}
while(pointer < n){answ[pointer] = 0; pointer++; }
for(int i = 0 ; i < n ; i ++){
std::cout << answ[i] << " ";
}
delete[] a;
delete[] answ;
return 0;
}
