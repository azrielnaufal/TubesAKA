// C++ program untuk algoritma quick sorting && ascending
#include <chrono>
#include <bits/stdc++.h> 
using namespace std;  

void swap(int* a, int* b){  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
// pada fungsi dibawah, elemen pivot dimisalkan sebagai isi array pada index terakhir
// note : pemilihan elemen pivot dapat dilakukan secara bebas
// menempatkan semua nilai yang lebih kecil dari nilai pivot, akan ditempatkan di sebelah kiri elemen pivot
// menempatkan semua nilai yang lebih besar dari nilai pivot, akan ditempatkan di sebelah kanan elemen pivot
int partition (int arr[], int low, int high){  
    int pivot = arr[high]; // elemen pivot dimisalkan nilai array pada index terakhir
    int i = (low - 1); // index dari elemen terkecil
  
    for (int j = low; j <= high - 1; j++){  
        // apabila nilai array pada index ke j lebih kecil dari nilai pivot 
        if (arr[j] < pivot){  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }
    /*memindahkan pivot di tengah array, sehingga semua nilai yang < pivot berada disebelah kiri, 
    >= pivot berada disebelah kanan 
    */
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);  // jumlah nilai yang < pivot atau sebelah kiri
}  
  
/*
arr[] --> array yang ingin di urutkan
low --> index pertama
high --> index terakhir
*/
void quickSort(int arr[], int low, int high){  
    if (low < high){  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
void printArray(int arr[], int size){  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
int main(){  
    int n;
    cout<<"quick sort"<<endl;
    cin>>n;
    int arr[n];
    auto t1 = std::chrono::steady_clock::now();
    for(int i = 0; i < n; i++){
        arr[i] = rand()%50;
    }
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    cout << "Given array is \n";
    printArray(arr, arr_size);
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, arr_size); 

    auto t2 = std::chrono::steady_clock::now();
    auto duration = double(std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count());
    cout<<endl;
    std::cout <<"Elapsed Time (s) :"<< duration/1e9 << std::endl;
    system("pause;");
    return 0;  
}  