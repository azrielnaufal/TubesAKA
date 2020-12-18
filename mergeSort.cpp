// C++ program untuk algoritma merge sorting && ascending

#include <chrono> 
#include <iostream>
using namespace std;
 
// menggabungkan 2 subarray yang terurut dari arr[]
// subarray pertama adalah arr[kiri...mid]
// subarray kedua adalah arr[tengah+1....kanan]
void merge(int arr[], int kiri, int tengah, int kanan){
    int n1 = tengah - kiri + 1; //size dari subarray pertama
    int n2 = kanan - tengah; //size dari subarray kedua
 
    // membuat array sementara
    int Left[n1], Right[n2];
 
    // memindahkan isi subarray ke array Left[] & Right[]
    for (int i = 0; i < n1; i++)
        Left[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[tengah + 1 + j];
 
    //menggabungkan 2 array sementara (Left[] & Right[]) kembali ke arr[1..kanan]
 
    // index untuk subarray pertama
    int i = 0;
 
    // index untuk subarray kedua
    int j = 0;
 
    // index di array pengggabungan
    int k = kiri;
 
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            //Left[i] akan ditaruh terlebih dahulu ke arr[k]
            arr[k] = Left[i];
            i++;
        }
        else {
            //right[j] akan ditaruh terlebih dahulu ke arr[k]
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
 
    // untuk memasukkan array yang tersisa. program akan menjalankan salah satu dari loop dibawah.
    // jika terdapat sisa di Left[]
    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }
 
    // jika terdapat sisa di Right[]
    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
 
//Prosedur ini secara rekursif akan melakukan proses divide
void mergeSort(int arr[],int left,int right){
    if(left>=right){
        return;//returns recursively
    }
    int m = (left + right-1)/2;
    mergeSort(arr,left,m);
    mergeSort(arr,m+1,right);
    merge(arr,left,m,right);
}
 
void printArray(int A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
int main(){
    int n;
    cin>>n;
    int arr[n];

    auto t1 = std::chrono::steady_clock::now();
    for(int i = 0; i < n; i++){
        arr[i] = rand()%50;
    }
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);
    
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    auto t2 = std::chrono::steady_clock::now();
    double duration = double(std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count());
    cout<<endl;
    std::cout <<"Elapsed Time (s) :"<< duration/1e9 << std::endl;
    system("pause;");
    return 0;
}