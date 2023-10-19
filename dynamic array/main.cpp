#include <iostream>
using namespace std;


void FillArray(int* const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;
    }
    cout << endl;
}

void ShowArray(const int* const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void PushBack(int*& arr, int& size, int value)
{
    int* NewArr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        NewArr[i] = arr[i];

    }
    NewArr[size] = value;
    size++;
    delete[] arr;
    arr = NewArr;
}

void PopBack(int*& arr, int& size) {
    size--;
    int* NewArr = new int[size];

    for (int i = 0; i < size; i++)
    {
        NewArr[i] = arr[i];

    }

    delete[] arr;
    arr = NewArr;
}

void PushForward(int*& arr, int& size, int value)
{
    int* NewArr = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        NewArr[i + 1] = arr[i];

    }
    NewArr[0] = value;
    size++;
    delete[] arr;
    arr = NewArr;
}

void AnyNumber(int*& arr, int& size, int value, int Index)
{
    int* NewArr = new int[size + 1];

    for (int i = 0, j = 0; i < size; i++, j++)
    {
        if (i == Index)
        {
            NewArr[j] = value;
            j++;
        }
        NewArr[j] = arr[i];
    }
    size++;
    delete[] arr;
    arr = NewArr;

}

void AnyNumber1(int*& arr, int& size, int value, int Index)
{
    int* NewArr = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        NewArr[i] = arr[i];

    }
    NewArr[Index] = value;


    delete[] arr;
    arr = NewArr;

}

void AnyNumber3(int*& arr, int& size, int Index)
{
    size--;
    int* NewArr = new int[size];

    for (int i = 0, j = 0; i < size; i++, j++)
    {

        if (i == Index)
        {

            j++;
        }
        NewArr[i] = arr[j];
    }

    delete[] arr;
    arr = NewArr;

}

int main() {

    setlocale(LC_ALL, "Russian");

    int size,
        index,
        number;

    cout << "Введите длину массива: " << endl;
    cin >> size;
    int* arr = new int[size];
    cout << endl << "Массив без изменений: " << endl;
    FillArray(arr, size);
    ShowArray(arr, size);


    cout << "Введите Число что бы добавить в конец массива: " << endl;
    cin >> number;
    PushBack(arr, size, number);
    ShowArray(arr, size);


    cout << "Введите Число что бы добавить в начало массива: " << endl;
    cin >> number;
    PushForward(arr, size, number);
    ShowArray(arr, size);


    cout << "Введите индекс масива что бы заменить число: " << endl;
    cin >> index;
    cout << "Введите Число: " << endl;
    cin >> number;
    AnyNumber1(arr, size, number, index);
    ShowArray(arr, size);

    cout << "Введите индекс масива что бы добавить число: " << endl;
    cin >> index;
    cout << "Введите Число: " << endl;
    cin >> number;
    AnyNumber(arr, size, number, index);
    ShowArray(arr, size);

    cout << "Введите индекс масива что бы удалить число: " << endl;
    cin >> index;
    AnyNumber3(arr, size, index);
    ShowArray(arr, size);




    delete[] arr;

    return 0;
}