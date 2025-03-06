#include <iostream>
#include <vector>
#include <cmath>

//vec.at(1); == vec[2] 
//at sahmanic dirs chi galis vectory  //out of french
// vec.reserv(100)    100 zise of vector
/// std::vector<int> myvec(5, 3)   == { 3,3,3,3,3};
// vec.empty()
// vec.resize(11,98) == { 98,98,98,....};
//vec.erase(8)  delete 8 elem in vec 
// std::vector<int>::reversiterator  it = vec.rbegin(); it != vec.rend() i++   revers vector
//   *(it + 2)   ~=  advance(it , 2 )  print (*(it));
// vec[0].insert(33); added thr value in vec not delete old value 

 int matrx [3][3] = { {1,1,1},
                      {2,2,2},
                      {3,3,3}
    };

double** allocateMatrix(int m) {
    double** arr = new double*[m];
    for (int i = 0; i < m; ++i) {
        arr[i] = new double[m];
        for (int j = 0 ; j < m ; j++)
        {
           std::cin >> arr[i][j];// = std::rand() % 10;
         //   arr[i][j] = std::rand() % 100;
            std::cout << arr[i][j] <<" ";
        }
        std::cout << "\n";
    }
    return arr;
}

int  r_433 ( int**  matrx, int sum = 0,int count = 0 )
{

    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j <= i;  j++ )
        {
            if (matrx[i][j] % 2 == 0)
            {
                sum += matrx[i][j] * matrx[i][j];
                count++;
            }

        }
    }
     delete[] matrx;
     return  sum / count ;

}

int r_437(int** mat,int size , int k, int product )
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0 ; j < size - i; j++ )
        {
            if ( mat[i][j] % k != 0 ) 
            {
                std::cout <<  mat[i][j] << " - ";
                product *= mat[i][j];
            }
        }
        std::cout  << std::endl;
    }
    return product;

}
int r_441 (int** mat,int size )
{
    int count = 0;
    for (int i = 0; i < size; i++ )
    {
        for (int j = 0 ; j <= i ; j++)
        {
            if (( i + (  size -1 - j  )) % 2 != 0 )
            {
                count ++;
                std::cout << mat[i][ size -1- j ]<<" ";
            }
        }
    }
    std::cout << std::endl;
    return count;
}

double r_447 ( double** mat , int size )
{
    double dubleScr = 1;
    double  count = 0.0;
    for ( int i = 0; i <  size ; i++ )
    {
        for ( int j = 0; j <= i ; j ++ )
        {
            if ( static_cast<int>(mat[i][j])  == mat[i][j] ) // 1.2 3.4 5.6
                                                             //  2  3.9  8
                                                             //  9  90   6 
            {
                std::cout <<  mat[i][j]<< " ";// 2 9 90 6 
                count ++;
                dubleScr += mat[i][j] * mat[i][j]; // 
            }
        }
        std::cout <<std::endl;
    }
    return dubleScr / count;// 8221 / 4 == 2055.5 

}



int r_453 (double** mat,int  size)
{
    int count = 0;  // mat 1 0 0 1 3 4 5 6 7 0
    for (int i = 0 ; i < size; i++ )
    {
        for ( int j = 0; j <size; j++ ) 
        {
            if ( i <= j )// 
            {
                if(mat[i][j]  == 0 ) 
                {
                    std::cout <<mat[i][j]<<" ";//idex   1 2 
                    count++;// 2
                }
            }
        }
        std::cout << std::endl;
    }
    return count;
}


double r_458 ( double** mat , int size )
{
    int count = 0;
    int sumelem = 0;
    for (int i = 0; i < size; i ++ )
    {
        for(int j = 0; j < size; j++ )
        {
            if(i <= j && ( j + i) % 2 == 0 )// 1 2 3 4 5 6 7 8 9
            {
                 sumelem += mat[i][j];// 1 + 3 + 5 + 9 =18 / 4 = 4 
                 std::cout << mat[i][j]<<" ";
                 count ++;
            }
        }
    }
    if (count == 0 )
        return 0.0;
    return sumelem / count;
}

using namespace std;


void r_462 ( double** mat , int size )
{
    vector<int> B ;
    int firstelem = 0;
    int lastElement = 0;
    for (int i =0; i < size; i++ )
    {
        firstelem = mat[i][0]; // 1 4 7  
        lastElement = mat[i][size-1]; // 3 6 9 
        B.push_back(((firstelem * firstelem )+ (lastElement * lastElement))); // 10 52 130

    }
    for(int elem : B)
    {
        std::cout <<  elem <<" " ;      
    }
}


void r_463 (double** mat ,int size)
{
    int a, b ;
    std::cout << "Enter [a and b] interval: " << std::endl;
    cin >> a >> b;
    vector<double> B;
    //     int size_arr = sizeof(mat) / sizeof(mat[0]);
    for( int i = 0; i < size; i++)//1 2 3 4 5 6 7 8 9
    {
        int sumofelem = 0;
        for (int j = a; j <= b; j++)// a== 0 b ==1
        {
            sumofelem += mat[i][j]; // 1+ 2 | 4+ 5 | 7 + 8
        }
        B.push_back(sumofelem);// 3 9 15 
    }
    for(int elem : B)
    {
        std::cout << elem <<" ";
    }
}
//std::abs(arr[i])

vector<int> r_468 ( double** mat, int size)
{
    vector<int> B;
    std::cout << " Enter the T number: " << std::endl;
    int T;
    cin >> T;
    for(int i = 0 ; i < size; i ++)
    {
        int count = 0;
        for(int j = 0; j < size; j++)
        {
            if(abs(mat[i][j] ) > T)
            {
                count ++;
            }
        }
        B.push_back(count);
    }
    return B;
}

void r_472(double** mat ,int size)
{
    vector<double> B;
    int count = 0;
    for(int i = 0; i < size; i++)//1 2 3 4 0 6 7 8 9
    {
        if (count != 0)
        {
            std::cout << "The matrix has more than one row containing 0 " << std::endl;
            break;
        }
        if( mat[i][i] == 0 && count == 0)
        {
            for(int j = 0 ; j < size; ++j)
            {
                count++;
                B.push_back(mat[i][j]);// 4 0 6 
            }
        }
    }
    for(double elem : B)
    {
        std::cout << elem <<" ";
    }
}
void r_476 (double** mat, int size )
{
    vector<double> X(size, -3);
    bool smol_to_biger = false;
    for(int i = 0; i < size; i++ )
    {
        for(int j = 0; j < size-1 ; j++)
        {
            if (mat[i][j] < mat[i][j + 1])
            {
                smol_to_biger =  true;
                break;
            }
        } 
        if (smol_to_biger)
            X[i] = 3;
    }
    for(int elem : X)
    {
        std::cout <<elem<< " ";// << std::endl;
    }
}
void r_480 (double** mat,int size )
{
    vector<double> X (size, 0);
    if(mat[0][0] == mat [0][size -1])// 1 2 1 4 5 6 7 8 1
    {
       for(int i = 0; i < size; i++)
       {
            if (mat[0][i] == mat[i][i])// 1 5 1
            {
                X[i] = mat[0][i];// 101
            }
       }
    }
    for(double elem : X)
    {
        std::cout << elem <<" ";// << std::endl;
    }
}
void r_483(double** mat , int size)
{
    int big_elem_index_sum = 0;
    double bigelem = mat[0][0];
    for(int i = 0; i < size; i++ ) // 1 2 1 4 5 6 7 8 1
    {
        for(int j = 0; j <= i; j++ )
        {
            if(mat[i][j] > bigelem)
            {
                bigelem = mat[i][j];
                big_elem_index_sum = i + j;// mat [2] [1] == 8  bigelem == 8   2+1 == 4
            }
        }
        std::cout <<  std::endl;
    }
    std::cout << " big_elem_index_sum \t" << big_elem_index_sum << std::endl;
}


void r_486 (double** mat,int size )
{
    int t;
    cin >> t;
    if(t > size -1)
    {
        std::cout << "The number T must not be larger than the size of the matrix." << std::endl;
        return;
    }
    double bing_elem = mat[t][0];
    for(int i = 0 ; i < size; i++)
    {
        for(int j = 0; j < size; j++ )
        {
            if(mat[t][j] > bing_elem)
            {
                bing_elem = mat[t][j];
            }
        }
    }
    std::cout << " bing_elem  " << bing_elem<< std::endl;
}

void r_490 (double** mat , int size )
{
    int  max_value = mat[0][size-1]; 
    int  max_row = 0;

    for ( int i = 0; i < size ; i++ )//1 2 45 3 4 5 6 7 8 9
    {
        if(mat[i][size - i - 1] > max_value)
        {
            max_value = mat[i][size - i - 1];//45
            max_row = i; // 0
        }
    }
    std::cout << " max_row\t "<< max_row << std::endl;
}
//1 2 3
//4 5 6
//7 8 9
//
//[0][size-1] 0 1 2
//[1][size-2] 0 1
//[2][size-3] 0 
void r_493 (double** mat , int size)
{
    int count = 0;
    double sum_gen_elem = 0;
    double sum_else_elem = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j <= i; j++)// 1 2 3 4 5 6 7 8 9
        {
            if( i == j && mat[i][i] > 0)
            {
                sum_gen_elem += mat[i][i];// 1 5 9 
                count ++;
            }
        }
            if ( mat[i][size - i - 1] > 0 )
            {
                sum_gen_elem += mat[i][size - i - 1];//3 5 7
                count++;
            }
    }
    std::cout << sum_gen_elem / count << std::endl; // 1+5+9+3+5+7 = 30 | 30 / 6 == 5
}
void r_497 (double** mat , int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++ )
    {
        for (int j = 0; j < size; j++)
        {
            if (mat[i][j] == mat[j][i] &&  mat[i][j] > 0)
            {
               sum += mat[i][j]; 
            }
            else 
            {
                std::cout << " OS " << std::endl;
            }

        }
    }
    std::cout << " sum \t"<< sum  << std::endl;
}


void r_500 (double** mat, int size )
{
    vector<int> X;//(size, 0);

    for (int i = 0; i < size; ++i) {
        int sum = 0;
        int min_val_index = 0;
        //         1  2 -3  // 0 
        //         4 -5  6  // -1
        //        -1 -2 -3  // -6
        for (int j = 0; j < size; j++) {
            if (mat[i][j] < 0) {
                min_val_index = j;
            }
        }
        for(int f = 0; f <= min_val_index; f++)
        {
            sum += mat[i][f];
        }

        X.push_back(sum);/// = sum;
    }
    for(double el : X)
    {
        std::cout << " elem "<< el << std::endl;
    }
}

double** mat(int m, int n) {
    double** arr = new double*[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new double[n];
        for (int j = 0; j < n; j++) {
            //arr[i][j] = std::rand() % 10;
            cin >> arr[i][j];
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    return arr;
}

void r_501(double** mat, int m, int n) {
    int bigValue = mat[0][0];
    int line = 0, elem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] > bigValue) {
                bigValue = mat[i][j];
                line = i;
                elem = j;
            }
        }
    }

    std::swap(mat[0][0], mat[line][elem]);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void deallocate(double** arr, int m) {
    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void r_509 (double** mat , int m ,int n)
{
    double bigvalue  = mat[0][0];
    double smolvalue = mat[0][0];
    for(int i = 0; i < m ; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] > bigvalue )
            {
                bigvalue =  mat[i][j];
            }
            if(mat[i][j] < smolvalue )
            {
                smolvalue = mat[i][j];
            }
        } 
    }
    double sum_gen_elem = 0;
    double averag_numb = (smolvalue + bigvalue) / 2.0;
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++ )
        {
            if (mat[i][j] > averag_numb && static_cast<int>(mat[i][j]) % 2 == 0 )
                sum_gen_elem += mat[i][j];
        }
    }
    std::cout << " sum_gen_elem\t "<< sum_gen_elem << std::endl;

}
void r_512(double** mat , int m , int n )
{
    vector<double> X;
    double bigvalue = mat[0][0];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)//1 2 3 4 5 6 7 8 9
        {
            if (mat[i][j] > bigvalue && static_cast<int>(mat[i][j]) % 2 != 0 )
            {
                bigvalue = (mat[i][j]);// 3 5 9
            }
        }
        X.push_back(bigvalue);
    }
    for(double el : X)
    {
        std::cout << el << std::endl;
    }
}
int main() {
    int m = 3, n = 3;
    int size_of_arr = 3;
    double** matrix = mat(m, n);
    std::cout << "--------------------------\n";
//    r_462(allocateMatrix(size_of_arr),m);
//    r_463(allocateMatrix(size_of_arr),m);
//    vector<int> B = r_468(matrix,size_of_arr);
//    r_472(allocateMatrix(size_of_arr),m);
//    r_476(allocateMatrix(size_of_arr),m);
//    r_480(allocateMatrix(size_of_arr),m);
//    r_483(allocateMatrix(size_of_arr),m);
//    r_486(allocateMatrix(size_of_arr),m);
//    r_490(allocateMatrix(size_of_arr),m);
//    r_493(allocateMatrix(size_of_arr),m);
//    r_497(allocateMatrix(size_of_arr),m);
//    r_500(allocateMatrix(size_of_arr),m);
//    r_501(matrix, m, n);
//    r_509(matrix, m, n);
//    r_512(matrix, m, n);
//    deallocate(matrix, m);// deleted dynamic memory 
    return 0;
}
