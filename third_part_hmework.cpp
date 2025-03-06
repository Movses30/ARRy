#include<iostream>
#include <cmath> // abs() ֆունկցիա ի հա մա ր    std::abs(arr[i]) return the absolute value   |3| == |-3|

void r_222(int* arr , int size)
{
//    int size;
//    std::cout << " Enter the zise of arry " << std::endl;
//    cin >> size;
//    int* arr = new arr[size];
    int scuer = 1;
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if ( arr[i] >  0)// 2,4,6,8
        {
            scuer += arr[i] * arr[i];
            std::cout << " "<<scuer << std::endl;
            count++;
        }
    }
    double   averageSquare = scuer / count ; 
    std::cout << " avarage " << averageSquare<< std::endl;
}


int  r_227 ( int* arr , int size  )
{
    int maltiple = 1;
    for(int i = 0; i < size; i++ )//1,2,2,2,2,2,2,2,2,2 
    {
        if( i % 2 != 0 )
        {
            maltiple *= arr[i];//2 2 2 2 2
        }
    }
    return maltiple;
}

void r_230 (int* arr , int size )
{
    int    countminus = 0 ;
    int    count = 0;
    for (int i = 0; i < size; i++ )
    {
        if(arr[i] > 0 )
            count++;
        else if (arr[i])
            countminus++;
    }
    std::cout << " big of zero count is \t"<<count <<"\nsmol of zero count is \t"<< countminus << std::endl;
}

void r_233 (int* arr , int size )
{
    int    a = 3;
    int    b = 9;
    std::cout << " (a;b) numbers is " ;
    for (int i = 0; i < size; i++ )
    {
        if(arr[i] > a && arr[i] < b )
            std::cout << arr[i]<<" ";// << std::endl;
    }
}

void r_236 (int* arr , int size )
{
    int    K = 3;
    for (int i = 0; i < size; i++ )//1,2,3,4,-5,6,7,8,9,11
    {
        if(abs(arr[i]) > K )
            std::cout << arr[i]<<" ";// 4 -5 6 7 8 9 11 
    }
}

void r_239 (int* arr , int size )
{
    int maltiple  = 1;

    for (int i = 0; i < size; i++ )//1,2,3,4,-5,6,5,3,3,2
    {
        if(arr[i] - i > 0 )
        {
            maltiple *= arr[i];// 1*2*3*4*6 == 144 
        }
    }
    std::cout << " maltiple "<< maltiple << std::endl;
}

void r_242 (int* arr , int size )
{
    int count = 0;
    for (int i = 0; i < size; i++ )//1,2,3,4,-5,6,5,3,3,2
    {
        if(arr[i] % 2 == 0 )
        {
            count++;
        }
    }
    std::cout << " count of even numbers "<< count  << std::endl;
}


void r_247 (int* arr , int size )
{
    int count = 0;
    for (int i = 0; i < size; i++ )//1,2,3,4,-5,6,5,3,3,2
    {
        if(arr[i]  == 0 )
        {
            count++;
        }
    }
    std::cout << " count of even numbers "<< count  << std::endl;
}


#include <vector>
using namespace std;

void r_251 (const vector<int>* vec)
{
    std::cout << " enter the M number :" << std::endl;
    int m;
    int sum = 0;
    cin >> m;//2
   for( vector<int>::const_iterator it = vec->begin() ; it != vec->end(); )// {1,2,3,4,-33,-2,0,67,11,67};
   {
       if ( *it % m == 0)//2 4 -2 0 
       {
           sum += *it;
       }   
       it++;
   }
   std::cout << " sum "<< sum  << std::endl; // 4
}


void r_256 (vector<int>& vec)
{
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        int count = 0;
        int sum = 0;
        int index = std::distance(vec.begin(), it);
        int root = static_cast<int>(sqrt(index));
        if (index * index == root )
        {
            std::cout << " it " << *it<< std::endl;
            sum += *it;
            count++;
        }
        if(count != 0)
        std::cout << " it "<< (sum / count)   << std::endl;
    }
}

void r_260()
{

}
int main ()
{
    int size = 10;
    int arr[size] = { 1,2,3,4,-5,0,5,0,3,2};
    vector<int> vec = {1,2,3,4,-33,-2,0,67,11,67};
//    r_222(arr, size);
//    std::cout << r_227(arr, size )<< std::endl;
//    r_230(arr,size);
//    r_233(arr,size);
//    r_236(arr,size);
//    r_239(arr,size);
//    r_242(arr,size);
//    r_247(arr,size);
//    r_251(&vec);
    r_256(vec);
    return 0;
}
