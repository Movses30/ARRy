// ա յն տ ա րրերի ա րտ ա դրյա լը որոնք բա ցա րձա կ ա րժեքով փ ոքր են t տ վից
#include<iostream>
#include <cmath> // abs() ֆունկցիա ի հա մա ր    std::abs(arr[i]) return the absolute value   |3| == |-3|

void r_222 ()
{//222  calculateRMS 

    int size;
    std::cout << "Eter size of arry: " << std::endl;
    std::cin >> size;

    int*  arry = new int[size];
    std::cout << "Enter number of arry :" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arry[i];
    }

    float sum_positive = 1;
    int cout_positiv = 0;

    for (int i = 0; i < size ; ++i )
    {
        if ( arry [i] > 0 )
        {
            sum_positive = arry[i] * arry[i];
            cout_positiv += 1;
        }
    }

    if(cout_positiv > 0 )
    {
        float average = sum_positive / cout_positiv ;
        std::cout << " average is : "<< average << std::endl;
    }
}

void r_232 ()
{ /// +
    int size;
    std::cout << "Enter size of arry:" << std::endl;  //
    std::cin >> size;
    int* arr = new int[size];

    std::cout << " Enter the element of arry:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cin >> arr[i]; // 1 2 3
    }
    int c, d;
    std::cout << " enter the reang:" << std::endl;
    std::cin >> c >> d; // 0 3 
    int product = 1;

    for( int i = 0; i < size; i++ )
    {  
        if(i >= c  && i <= d )
        {
            product *= arr[i];  // C D  the product of the elements belonging to the range
        }
    }
    std::cout << "The product of range is -> :"<< product << std::endl;//  1 * 2 * 3 = 6 
    delete arr; 

}



void absalute_value ()
{//235  +
    int n;
    std::cout << "Enter size of arry: ";//5
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Enter the elements of arry: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i]; // 10 20 30 40 50 
    }

    int t; // 100
    std::cout << "Enter the T value ";
    std::cin >> t;

    int product = 1;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        if (std::abs(arr[i]) < t) {
            product *= arr[i];
        std::cout << " product :\t"<< product << std::endl;// 10 200 6000  240000 12000000
        }
    } 
    delete arr;
}

void numbe_T ()
{//238
    int n;
    std::cout << "Enter size of arry: "; // 5
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Enter the elements of arry: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];// 1 2 3 4 5
    }

    int K;
    std::cout << "Enter the K value ";
    std::cin >> K; // 3

    int product = 0;
    bool found = false;

    for (int i = 0; i < n; ++i)
    {
        if( i % K == 0)
        {
            product += arr[i]; // 0  3 
            std::cout << " arrr  " << product << std::endl; // 5  
        }
    }
      delete arr;
}
// Կա զմել բլոկ-սխ եմա և ծրա գիր, որոնք կհաշվեն և կտ պ են ո հա տ ա մբողջ տ իպ ի տ ա րրեր պ ա րունա կող միա չա փ զա նգվա ծի
void even_value ()
{//241
    int arr [4] = {1,2,3,4};
    int product = 0;
    int scuer = 1;
    for(int i = 0; i < 4; i++)
    {
        if( arr[i] % 2 == 0 )
        {
            scuer =  arr[i] * arr[i];// 1*1 + 3 * 3  == 10  
            product += scuer;
        }
    }
    std::cout << " resault  :"<< product << std::endl;
}

void kent_value ()
{//246

    int arr [9] = {1,2,3,4,5,6,7,8,9};
    int product = 1;
    int count = 0;
    for(int i = 0; i < 9; i++)
    {
        if( arr[i] % 2 != 0 )
        {
            product *=  arr[i];// 1*3*5*7*9 == 945;
            count++;   // indexes 0 2 4 6 8 
        }
    }
    std::cout << " product is :"<< product << std::endl;
    std::cout << " count++   " << count << std::endl;
}
void  multiple_of_7()
{//250

    int arr [9] = {1,2,21,4,5,6,7,8,9};
    int product = 1;
    int count = 0;
    for(int i = 0; i < 9; i++)
    {
        if( arr[i] % 7 == 0 )//  7 and 21 
        {
            count++; //1 
        }
    }
    std::cout << " Moltiple of 7 is \t"<< count << std::endl;
}

void division_5()
{//254

    int arr [9] = {1,2,3,4,5,6,7,8,9};
    int product = 1;
    for(int i = 0; i < 9; i++)
    {
        if( arr[i] % 5 == 2 )
        {
            product *= arr[i]; // 2 * 7 == 14
        }
    }
    std::cout << " division 5  is \t"<< product << std::endl;
}

void scuer_sum ()
{//255
    
    int arr [9] = {1,2,3,4,5,6,7,8,9};
    int product = 0;
    int scuer = 1;
    for(int i = 0; i < 9; i++)
    {
        if( (arr[i] + i) % 3 == 0 )//  index  1 4 7   value 2 5 8   1 + 2  |   4 + 5 | 8 + 7   
        {
            std::cout << " i \t"<< i << std::endl;
            product += arr[i] * arr[i] ; // 2 * 2 + 5 * 5 + 8 * 8 == 93
        }
    }
    std::cout << " scuer sum \t"<< product << std::endl;
}


void r_259 ()
{//259             0    1  2  3   4    5    6   7   8
    int  arr[9] = {10, 20,30, 40, 56, 666, 76, 86, 96};
   //              10  19 28  37  52  661  70  79  86 
    int k = 70; 
    int count = 0;

    for (int i = 0; i < 9; ++i)
    {
        if (std::abs(arr[i] - i) > k)// 79 > 70  | 661 > 70 | 86 > 70 
        {
            count++;
        }
    }
    std::cout << " count "<<count << std::endl;
}


void  r_261 ()
{
    int  arr[9] = {10, 20,30, 40, 56, 666, 76, 86, 96}; 
     
    int big_value = arr[0];

    for (int i = 0; i < 9; ++i)
    {
        // 
        if (arr[i] > big_value ) // Erik jan you are need to use this functio as well r_263 ();
        {
            big_value = arr[i];
        }
    }
    std::cout << " big_value "<<big_value << std::endl;

}

void r_263 ()
{//263
     int arr[8] = {22, 222, 2222, 1, 2, 3, 4, 9};
    int smallest_value = arr[0]; 
    int largest_value  = arr[0];

    for (int i = 1; i < 8; ++i) {
        if (arr[i] < smallest_value) {
            smallest_value = arr[i];
        }
        if (arr[i] > largest_value) {
            largest_value = arr[i];
        }
    }

    std::cout << "Sum : " <<smallest_value + largest_value << std::endl;
}

void r_267 ()
{//267
    int arr[8] = {22, 222, 2222, 1, 2, 3, 4, 9};
    int big_value = arr[0];
    int number_of_value = 0;
    for (int i = 0; i < 8; i++ )
    {
        if (arr[i] >big_value)
        {
            big_value = arr[i];
            number_of_value = i; // 2
        }
    }
    std::cout << " number of value "<< number_of_value << std::endl;
}

int r_270 ()
{
    int arr[8] = {22, 222, 2222, 1, 2, 3, 0, 9};
    int smol_number = arr[0];
    int number_of_value = 0;
    for (int i = 0; i < 8; i++ )
    {
        if (arr[i] < smol_number)
        {
            smol_number = arr[i]; // 0
            number_of_value = i;// 6
        }
    }
    return number_of_value;
}

double  r_271 ()
{
    int X[8] = {1,2,3,4,5,6,7,8};
    double averageX = 0;
    double averageY = 0;
    int Y[8] = {1,2,3,4,5,6,7,8};
    for (int i = 0; i < 8; i++ )
    {
        averageX += X[i];
        averageY += Y[i];
    }
//    double arithmetic_mean = ( (averageX / 8) * ( averageY / 8));
    return  ( (averageX / 8) * ( averageY / 8));
}


double r_275 ()
{
    int X[8] = {1,2,3,4,5,6,7,800};
    int Y[8] = {1,2,2,2,2,2,2,2};
    double sumX = 0;
    double maltipleY = 1;
    for (int i = 0; i < 8 ; i++)
    {
        sumX += X[i];  // 828
        if( Y[i] != 0 )
            maltipleY *= Y[i]; // 128
    }
    // double ratio = static_cast<double>(sumX) / maltipleY;  chat GTP solvade
    return sumX / maltipleY; // 828 / 128 == 6.46875
}

double r_277 ()
{
    int X[8] = {1,2,3,4,5,6,7,8};
    int Y[8] = {1,2,3,4,5,6,7,8};
    double sum_X_and_Y = 0;
    for (int i = 0; i < 8 ; i++ )
    {
        if (X[i] % 7 == 0)
        {
            sum_X_and_Y += X[i];// 7 
        }
        if (Y[i] % 7 == 0)
        {
            sum_X_and_Y += Y[i];// 7
        }
    }
    return sum_X_and_Y; // 14

}

int r_279 ()
{//             0 1 2 3 4 5 6 7 
    int X[8] = {1,2,3,4,5,6,7,8};
    int Y[8] = {1,2,3,4,5,6,7,8};
    double sum  = 0;
    for (int i = 0; i < 8 ; i++ )
    {
        if ( i % 2 == 0) //1 3 5 7
        {
            sum += X[i];
        }
        if (i % 2 != 0 ) // 2 4 6 8
        {
            sum += Y[i];
        }
    }
    return sum;// 36 

}
int main()
{
//254
 //  std::cout << " number_of_value \t" <<r_279() << std::endl;
//        absalute_value();
    numbe_T();
    return 0;
}
