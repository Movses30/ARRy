#include <iostream>
#include <vector>
#include <algorithm>

void r281 ()
{
    char  arr[7] = {'q','w','a','r','a','/','='};

    char a = 'a';
    int count = 0;
    for (int i = 0; i < 7; ++i) {
        if (arr[i] == a) {
            count++;
        }
    }
    std::cout << "Տրվա ծ սիմվոլի քա նա կը: " << count << std::endl;
}


void r_284 ()
{  //              113 119  97 104  97   47 
    int  arr[6] = {'q','w','a','h','a','/'};
    char a = 'h';
    int count = 0;
    int sum = 0;
    double average = 1;
    for (int i = 0; i < 6; ++i)
    {
        if ( arr[i] > a )
        {
            sum += i; // 0  1 
            count ++;//  2  
        }
    }
    average = sum / count ;  // 1 / 2 ~ = 0 ;
    std::cout << " average "<< average  << std::endl;
}


void r_288 ()
{//288   
    char X[6] = {'2','w','g','d','h','e'};
    int size = 0;
    char* Y = new char[size];
    for (int i = 0; i < 6; i++ )
    {

        if ( i % 2 != 0 )
        {
            Y[size] = X[i];// w d e 
            size++ ;
        }
    }
    for (int i = 0; i < size; i++ )
    {
        std::cout << "arrnew\t " << Y[i]  << std::endl;
    }
    delete Y;
}


void r_293 ()
{
    int  X[6] = {1,21,11,73,22,82};
    std::vector<int> Y ;

    for (int i = 0; i < 6; i++ )
    {
        if ( X[i]  % 2 != 0 )
        {
            Y.push_back(X[i]);//1 21 11 73
        }
    }

    for (int elem : Y )
    {
        std::cout  << elem << " ";
    }
}

void r_297()
{  
    int  X[6] = {1, 6, 11, 73, 22, 5};
    std::vector<int> Y;

    for (int i = 0; i < 6; i++ )
    {
        if ( X[i] != i  )
        {
            Y.push_back(X[i]);// 1 6 11 73 22
        }
    }
    for(int elem : Y )
    {
        std::cout  << elem << " ";
    }

}

void r_299 ()
{
    int c, d;
    std::cout << " Enter range " << std::endl;
    std::cin >> c >> d;
            //   0  1  2    3   4  5
    int  X[6] = {2, 5, 11, 73, 22, 5};
    std::vector<int> Y;

    for (int i = 0; i < 6; i++ )
    {//                         0                    150
        if (( ( X[i] * X[i]) >= c) &&( (X[i]*X[i]) <= d) )
        {
            Y.push_back(X[i]);  // 5 11 5
        }
    }
    for (int elem : Y )
    {
        std::cout <<elem  <<" ";
    }

}

void r_315 ()
{
    std::vector<int> multiples;  // need to run 

    for (int j = 1000; j <= 9999; ++j)
    {
        if (j % 3  == 0 && j % 5 == 0)
        {
            multiples.push_back(j);
        }
    }

    for (int i = 0; i < multiples.size(); ++i)
    {
        std::cout << " multiples \t "<<multiples[i] << std::endl;
    }

}

void r_318 ()
{
    int k;
    std::cout << " Enter the compres number " << std::endl;
    std::cin >> k;
    std::vector<int> myvector;

    for (int i = 10 ; i <= 999; i++ )
    {
        if (i % k == 0 )
        {
            myvector.push_back(i);
        }
    }
    for (int elem : myvector )
    {
        std::cout << " myvector "<< elem  << std::endl;
    }
}

void r_321 ()
{
    std::vector<int> vecsumelem = {1,14,16,166,6,-22}; 
    std::vector<int> modifayVec;
    int bigvalue = *std::max_element(vecsumelem.begin(), vecsumelem.end());

    for (int i = 0; i < vecsumelem.size(); i++ )
    {
         if (vecsumelem[i] > 0 )
         {
             modifayVec.push_back(vecsumelem[i] + bigvalue);
         }
    }
     for (int i = 0; i < modifayVec.size(); i++ )
     {
         std::cout << " modifayVec.push_back"<< modifayVec[i] << std::endl;
     }
}

void r_324 ()
{
    std::vector<int> vec = {11,101,200,2,3,4};
    std::vector<int> resvec;
    for( int i = 0; i < vec.size(); i++ )
    {
        resvec.push_back(vec[i]);
        if ( vec[i] > 0 )
        {
            resvec.push_back(0);
        }
    }

    for (int i = 0; i < resvec.size(); i++ )
    {
        std::cout << " resvec values"<<resvec[i] << std::endl;
    }

}

void r_327 ()
{
    std::vector<int> myvec = {1,2,3,4,5,6,10};
    std::vector<int> newvec;
    int max_element = myvec[2];

    for (int i = 0; i < myvec.size(); i++ )
    {
        if ( i % 2 == 0 && myvec[i] > max_element )
        {
            max_element = myvec[i];
        }
    }

    for (int i = 0; i < myvec.size(); i++ )
    {
        newvec.push_back(myvec[i] + max_element);
        std::cout << "  newvec. "<< newvec[i] << std::endl;
    }

}

void r_328 ()
{
    std::vector<int> myvec = {1,-2,3,4,5,-6,10};
    std::vector<int> negativvec;
    std::vector<int> positivvec;
    std::vector<int> zerovec; 
    for (int i = 0; i < myvec.size(); i++ )
    {
        if (myvec[i] < 0)
        {
            negativvec.push_back(myvec[i]);
        }
        else if (myvec[i] == 0 )
        {
            zerovec.push_back(myvec[i]);
        }
        else if (myvec[i] > 0 )
        {
            positivvec.push_back(myvec[i]);
        }
    }
    std::vector<int> result;
    result.insert(result.end(), negativvec.begin(), negativvec.end());
    result.insert(result.end(), zerovec.begin(), zerovec.end());
    result.insert(result.end(), positivvec.begin(), positivvec.end());

    for (int elem : result)
        std::cout << " result "<< elem << std::endl;

}

void r_332 ()
{
   std::vector<int> X = {1, 7, 2, 0, 6604,9 };
   std::vector<int> Y;

    for (int element : X)
    {
        Y.push_back(element);
        if (element == 0) {
            Y.push_back(0);
            Y.push_back(0);
        }
    }

    for (int element : Y) 
    {
        std::cout << element << " \n";
    }
}

void r_336()
{
    std::vector<int> X = {1, 0, 2, 0, 3, 4, 0};
    std::vector<int> Y = X;

    int i = 0;
    int j = X.size() - 1;

    while (i < j)
    {
        std::swap(Y[i], Y[j]);
        i++;
        j--;
    }


    for (int elem : Y)
    {
        std::cout << " elem" << elem << std::endl;
    }


}
int recsum ( int n )
{
    if ( n <= 1 | n == 0)
        return 1;
     

    return n + recsum (n - 1);
}
void r_339()
{
    std::vector<int> X = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    std::vector<int> Y ;

    int sumelem = 0;

    for ( int i = 0; i < X.size(); i++ )
    {   
        sumelem += X[i];
        Y.push_back(sumelem);
    }

    for (int elem : Y)
    {
        std::cout << " elem" << elem << std::endl;
    }

}


void r_342 ()
{
    std::vector<int> X = {1,2,3,4,5,6,7,8};
    std::vector<int> Y = X;
    int bigvalue = *std::max_element(X.begin(), X.end());
    int smolvalue = *std::min_element(X.begin(), X.end());
    for (int i = 0; i < X.size(); i++ )
    {
         if (X[i] == bigvalue  )
         {
            Y[i] = smolvalue * smolvalue;
         }
         if (X[i] == smolvalue)
         {
             Y[i] = bigvalue * bigvalue * bigvalue;
         }
    }
    std::cout << " bigvalue "<< bigvalue << std::endl;
    std::cout << " smolvalue "<< smolvalue << std::endl;
     for (int i = 0; i < Y.size(); i++ )
     {
         std::cout << "  Y \t "<< Y[i] << std::endl;
     }

}

int main() 
{
    r_318();
    return 0;
}

