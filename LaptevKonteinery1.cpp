// LaptevKonteinery1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

class array
{
public:
    array();
    array(int k);
    ~array();
    int n = 0;
    double sum = 0, avr = 0, firstNegNum = 0;;
    double* Array;
    double* Array2;


    void FormArray();
    void FormArray(double* arr, double num);
    void FormArray(double* arr);
    void PrintArray();
    void PrintArray2();
    void Transform();

private:
    void Sum();
    void Average();
    void FirstNeg();
};

array::array()
{
    if (n)
    {
        n += 2;
    }
    else
    {
        std::cin >> n;
    }
    Array = new double[n];
    Array2 = new double[n+2];
}

array::array(int k)
{
    n = k;
    if (n)
    {
        n += 2;
    }
    else
    {
        std::cin >> n;
    }
    Array = new double[n];
    Array2 = new double[n + 2];
}

array::~array()
{
    delete[] Array;
    Array = nullptr;
    delete[] Array2;
    Array2 = nullptr;
}

void array::FormArray()
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> Array[i];
        Array2[i] = Array[i];
    }
    Sum();
    Average();
    Array2[n] = sum;
    Array2[n + 1] = avr;
    FirstNeg();
}

void array::FormArray(double arr[100], double num)
{
    for (int i = 0; i < n-1; i++)
    {
        Array[i] = arr[i];
        Array2[i] = Array[i];
    }
    Array[n-1] = num;
    Array2[n-1] = num;
    Sum();
    Average();
    Array2[n] = sum;
    Array2[n + 1] = avr;
    FirstNeg();
}

void array::FormArray(double* arr)
{
    for (int i = 0; i < n; i++)
    {
        Array[i] = arr[i];
        Array2[i] = Array[i];
    }
    Sum();
    Average();
    Array2[n] = sum;
    Array2[n + 1] = avr;
    FirstNeg();
}

//сумма
void array::Sum()
{
    for (int i = 0; i < n; i++)
    {
        sum += Array[i];
    }
}

//среднее арифметическое
void array::Average()
{
    avr = sum / n;
}

void array::FirstNeg()
{
    for (int i = 0; i < n; i++)
    {
        if (firstNegNum > Array[i])
        {
            firstNegNum = Array[i];
            break;
        }
    }
}

void array::Transform()
{
    double temp;
    temp = (firstNegNum + Array2[5]) / 2;
    for (int i = 0; i < n+2; i++)
    {
        Array2[i] /= temp;
    }
}

void array::PrintArray()
{
    std::cout << std::fixed << std::setprecision(3);
    for (int i = 0; i < n; i++)
    {
        std::cout << Array[i] << "\t";
    }
    std::cout << std::endl;
}

void array::PrintArray2()
{
    for (int i = 0; i < n+2; i++)
    {
        std::cout << Array2[i] << "\t";
    }
    std::cout << std::endl;
}


int main()
{
    array arr;
    int size = arr.n;
    double num = 0;

    int switch_on = -1;

    arr.FormArray();
    std::cout << arr.n << std::endl;
    arr.PrintArray();
    arr.PrintArray2();
    arr.Transform();
    arr.PrintArray2();
    
    double temp[100];


    for (int i = 0; i < size + 2; i++)
    {
        temp[i] = arr.Array2[i];
    }

    while (switch_on)
    {
        std::cin >> switch_on;
        switch (switch_on)
        {
        case 1://добавить элемент
        {
            array arrAdd(++size);            
            std::cout << "+: " << arrAdd.n << std::endl;
            std::cin >> num;
            arrAdd.FormArray(temp, num);
            arrAdd.PrintArray();
            arrAdd.PrintArray2();
            arrAdd.Transform();
            arrAdd.PrintArray2();

            for (int i = 0; i < size+4; i++)
            {
                temp[i] = arrAdd.Array2[i];
            }

            size += 2;
            break;
        }
        case 2://удалить элемент
        {
            array arrSub(--size);
            std::cout << "-: " << arrSub.n << std::endl;
            arrSub.FormArray(temp);
            arrSub.PrintArray();
            arrSub.PrintArray2();
            arrSub.Transform();
            arrSub.PrintArray2();

            for (int i = 0; i < size + 4; i++)
            {
                temp[i] = arrSub.Array2[i];
            }

            size += 2;
            break;
        }
        default:
            break;
        }
    }
}