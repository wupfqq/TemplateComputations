#include <iostream>

//Вычисление суммы ряда чисел Фибоначчи из N элементов
template <int N>
struct Fibb{
     static const long long  value=Fibb<N-1>::value+Fibb<N-2>::value;
};
template<>
struct Fibb<1>{
     static const int value=1;
};
template<>
struct Fibb<0>{
     static const int value=0;
};

//Проверка, является ли число простым(если да - 1, нет -0)

template<int K,int D>
struct HPrNum{
    static const bool val=K%D==0?false:HPrNum<K,D-1>::val;
};
template <int K>
struct HPrNum<K,1>{
    static const bool val=true;
};


template <int K>
struct PrimeNum{
    static const bool val=HPrNum<K,K/2>::val;
};


int main(){
    std::cout<<PrimeNum<18>::val;
    std::cout<<'\n'<<Fibb<25>::value;
}
