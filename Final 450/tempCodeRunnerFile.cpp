#include <iostream>
using namespace std;

int main(){
        int r1, c1;
        cout<<"Enter row and column of first matrix: "<<endl;
        cin>>r1>>c1;
        int r2, c2;
        cout<<"Enter row and column of second matrix: "<<endl;
        cin>>r2>>c2;

        if(c1!=r2){
                cout<<"Can't calculate! Goes against rules."<<endl;
                return 0;
        }

        cout<<"Enter the elements of first matrix:-"<<endl;
        int matrix1[r1][c1];
        for(int i=0;i<r1;i++)
                for(int j=0;j<c1;j++)
                        cin>>matrix1[i][j];

        cout<<"Enter the elements of second matrix:-"<<endl;
        int matrix2[r2][c2];
        for(int i=0;i<r2;i++)
                for(int j=0;j<c2;j++)
                        cin>>matrix2[i][j];

        int resultantMatrix[r1][c2];
        for(int i=0;i<r1;i++)
                for(int j=0;j<c2;j++)
                        resultantMatrix[i][j] = 0;

        for(int i=0;i<r1;i++)
                for(int j=0;j<c2;j++)
                        for(int k=0;k<c1;k++)
                                resultantMatrix[i][j] += matrix1[i][k]*matrix2[k][j];

        cout<<"Resultant Matrix:-"<<endl;
        for(int i=0;i<r1;i++){
                for(int j=0;j<c2;j++)
                        cout<<resultantMatrix[i][j]<<" ";
                cout<<endl;
        }
        cout<<endl;

        return 0;
}