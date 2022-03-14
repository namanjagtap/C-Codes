#include<iostream>
using namespace std;

int main(){
    int a[10][10], b[10][10], multi[10][10], r1, c1, r2, c2, i, j, k;
    
    cout<<"Enter row and column of first matrix: ";
    cin>>r1>>c1;
    
    cout<<"Enter row and column of second matrix: ";
    cin>>r2>>c2;
    
    while(c1!=r2)
    {
        cout<<"Error! Column of first matrix is not equal to row of second matrix!"<<endl;
        
        cout<<"Enter row and column of first matrix: ";
        cin>>r1>>c1;
        
        cout<<"Enter row and column of second matrix: ";
        cin>>r2>>c2;
    }

    cout<< endl <<"Enter element of first matrix."<< endl;

    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
        {
            cout<<"Enter element a"<<i+1<<j+1<<" : ";
            cin>>a[i][j];
        }


    cout<<"Enter element of second matrix."<<endl;

    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
        {
            cout<<"Enter element b"<<i+1<<j+1<<" : ";
            cin>>b[i][j];
        }

    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
        {
            multi[i][j]=0;
        }

    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            for(k=0;k<c1;k++)
            {
                multi[i][j] += a[i][k]*b[k][j];
            }
    
    cout<<endl<<"Output Matrix: "<<endl;
    int sum=0;
    for(i=0;i<r1;i++)
    for(j=0;j<c2;j++)
    {
        sum+=multi[i][j];
        cout<< " " <<multi[i][j];
        if(j == c2-1)
            cout<<endl;
    }
    cout<<sum<<endl;

    return 0;

}