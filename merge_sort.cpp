#include <iostream>
#include <cstring>

using namespace std;

int Merge(int * L, int Lsize, int * R, int Rsize, int * A);


void Mergesort(int * A,int Asize)
{
    int i;
    if(Asize<2)
        {
        return;
        }

    int mid;

    mid=Asize/2;
    int Lsize = mid;
    int Rsize = Asize-mid;

    int L[Lsize],R[Rsize];

    for(i=0;i<mid;i++)
    {
        L[i] = *(A+i);
    }

    for(i=mid;i<Asize;i++)
    {
        R[i-mid] = *(A+i);
    }


    Mergesort(L,Lsize);
    Mergesort(R,Rsize);

    Merge(L,Lsize,R,Rsize,A);


}

int Merge(int * L, int Lsize, int * R, int Rsize, int * A)
{
    int i,j,k;
    i=j=k=0;

    while(i<Lsize && j<Rsize)
    {
        if(*(L+i)<=*(R+j))
        {
            *(A+k) = *(L+i);
            i++;
        }

        else
        {
            *(A+k) = * (R+j);
            j++;
        }
        k++;
    }

    while(i<Lsize)
    {
        *(A+k) = *(L+i);
        k++;
        i++;
    }

    while(j<Rsize)
    {
        *(A+k) = *(R+j);
        j++;
        k++;
    }
}


int main()
{
    int i;
    int arra[]={5,2,3,7,1,8,6,4};
    int arrasize = sizeof(arra)/sizeof(int);



    Mergesort(arra,arrasize);


   for(i=0;i<8;i++)
    {
        cout << arra[i];
    }


}
