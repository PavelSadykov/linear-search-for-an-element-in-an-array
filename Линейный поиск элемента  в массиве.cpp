//
//  main.cpp
//  С++ Линейный поиск элемента  в массиве
//
//  Created by Павел on 31.08.2022.
//

#include <iostream>
using namespace std;

template <typename T>
void show_arr(T arr[], const int length) {
    cout<<"[";
    for (int i=0; i<length;i++)
        cout << arr[i]<<" ";
    cout<<"]\n";
    
}

//поиск первого вхождения
template <typename T>
int search_index(T arr[],const int length, T value, int begin=0){//T value позиция, которую мы хотим найти. int begin=0 откуда ищем
    for(int i=begin; i < length; i++)
        if(arr[i] == value)
            return i;
    return -1;// элемент не обнаружен
}

//последнее вхождение
template <typename T>
int search_last_index(T arr[],const int length, T value){
    
    for(int i=length-1; i >=0; i--)
        if(arr[i] == value)
            return i;
    return -1;
}
template <typename T>
int search_last_index(T arr[],const int length, T value, int begin){
    
    for(int i=begin; i >=0; i--)
        if(arr[i] == value)
            return i;
    return -1;
}



//вывод подслова
void subword(char arr[], const int length, char sym){
    int index = search_index(arr,length,sym);
    if(index==-1)//если симовла нет в массиве
        cout<<"Error\n";
    else{
        for(int i = index; i<length;i++)
            cout<<arr[i];
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
setlocale(LC_ALL, "Rus");
    int n;

    // линейный поиск
    const int size = 6;
    int arr[size]={4,7,-1,8,7,0};
    cout<<"Массив: \n";
    show_arr(arr,size);
    cout<<"Введите число : ";
    cin>>n;
  
 
    //поиск первого вхождения
    
    if(search_index(arr, size, n, 2 )==-1)
        cout <<"Такого числа нет  в массиве\n\n";
    else
    cout<<"Позиция числа в массиве: "<<search_index(arr, size,
                                                     n, 2 )<<"\n\n";
    
    
    
    //Последнее вхождение - все тоже самое но с конца массива
    if(search_last_index(arr, size, n, 3)==-1)
        cout <<"Такого числа нет  в массиве\n\n";
    else
    cout<<"Позиция последнего  вхождения числа в массив: "<<search_last_index(arr, size,n, 3 )<<"\n\n";
     
     
    //Задание "Подслово"/ пользователь передает символ, а программа выводит оставшееся слово
    const int word_size=8;
    char word[word_size]{'f','u','n','c','t','i','o','n'};
    cout<<"Введите символ : ";
    char sym;
    cin>>sym;
    cout<<"Подслово :\n";
    subword(word,word_size, sym);
    cout<<endl;
    
    
     return 0;
}
