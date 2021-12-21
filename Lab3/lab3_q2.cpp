#include<iostream>
using namespace std;
#define MAX 100

class spm
{
            int row,col,val;
            public:
            void read(spm a[],int m,int n);
            void fast(spm a[],spm b[]);
};


void spm:: read(spm a[], int m, int n)
{
            int i, j, k, item, p;
            a[0].row = m;
            a[0].col = n;
            k = 1;

            cout<<"\nEnter the elements:\n";
            for(i=0; i<m; i++)
            {
                        for(j=0; j<n; j++)
                        {
                                    cin>>item;
                                    if(item == 0)
                                                continue;
                                    a[k].row = i;
                                    a[k].col = j;
                                    a[k].val = item;
                                    k++;
                        }
            }
            a[0].val = k-1;

            cout<<"\nThe entered sparse matrix is:\n";
            cout<<"\nRow\tColumn\tValue\n";
            for(p=0;  p<=a[0].val;  p++)
            {
                       cout<< a[p].row<<"\t";
                        cout<<a[p].col<<"\t";
                        cout<<a[p].val<<"\n";
            }
}

void spm:: fast(spm a[],  spm b[])
{
            int row_terms[100],  start_pos[100];
            int i,  j,  p;       

            int numTerms = a[0].val;
            int numCols = a[0].col;
             
            b[0].row = numCols;
            b[0].col = a[0].row;
            b[0].val = numTerms;
            if(numTerms>0)
            {
                        for(i =0; i<numCols;  i++)
                                                row_terms[i] = 0;

                        for(i=1; i<=numTerms; i++)
                                                row_terms[a[i].col]++;

                        start_pos[0]=1;

                        for(i=1; i<numCols; i++)
                                                start_pos[i] = start_pos[i-1] + row_terms[i-1];

                        for(i=1; i<=numTerms; i++)
                        {
                                             j = start_pos[a[i].col]++;
                                    b[j].row = a[i].col;
                                                b[j].col = a[i].row;
                                                b[j].val = a[i].val;
                        }
             }
            cout<<"\nThe Fast Transpose sparse matrix is:\n";
            cout<<"\nRow\tColumn\tValue\n";
            for(p=0; p<=a[0].val; p++)
            {
                        cout<< b[p].row<<"\t";
                        cout<<b[p].col<<"\t";
                        cout<<b[p].val<<"\n";
            }
}
int main()
{
            int m, n, key;
            spm a[MAX], b[MAX],o;
            cout<<"\nEnter  the no of rows and columns:\t";
            cin>>m>>n;

            o.read(a, m, n);
             o.fast(a, b);
             return 0;
}
