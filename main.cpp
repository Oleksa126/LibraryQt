#include <QCoreApplication>
#include "iostream"
#include "QDate"
#include "menu.h"
using namespace  std;

//template <class ElementType>
//void insertionSort(vector<ElementType> &arr){
//    cout<<"\n before: \n\n";
//    for(int i = 0; i<arr.size(); i++){
//        cout<<arr[i];
//    }

//    for(int i = 0; i<arr.size();i++){
//        for(int j = i; j<arr.size();j++){
//            if(arr[i] < arr[j]){
//                ElementType tmp;
//                tmp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = tmp;
//            }
//        }
//    }

//    cout<<"\n after: \n\n";
//    for(int  i = 0; i<arr.size(); i++){
//        cout<<arr[i];
//    }

//}

int main()
{

    Menu menu;
    menu.meinMenu();



    return 0;
}



