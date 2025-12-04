#include<iostream>

using namespace std;

int interpolationSearch(int* , int, int, int);

int interpolationSearch(int* arr, int low, int high, int nomor) {
    int pos;

    if (low <= high && nomor >= arr[low] && nomor <= arr[high]) {
        pos = low + ((nomor - arr[low])*(high - low))/(arr[high] - arr[low]);

        if (arr[pos] == nomor) {
            return pos;
        } else if (nomor < arr[pos]) {
            interpolationSearch(arr, low, pos - 1, nomor);
        } else {
            interpolationSearch(arr, pos + 1, high, nomor);
        }
    }

    return -1;
}

int main() {
    int n, nomor, pos;

    cout << "Masukkan jumlah nomor yang tersedia (dari 200 nomor): ";
    cin >> n;

    int arr[n];

    cout << "Masukkan nomor nomor yang tersedia: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Masukkan nomor nomor yang dicari: ";
    cin >> nomor;

    cout << endl;
    cout << "Mencari kursi No: " << nomor << endl;

    pos = interpolationSearch(arr, 0, n - 1, nomor);

    if (pos == -1) {
        cout << "Status: TIDAK TERSEDIA" << endl;
    } else {
        cout << "Status: TERSEDIA" << endl;
        cout << "Detail: Kursi No." << nomor << " ditemukan pada index ke-" << pos;
    }
    
    return 0;
}

