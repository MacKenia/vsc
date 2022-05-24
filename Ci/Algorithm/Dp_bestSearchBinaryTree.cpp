//最优二叉查找树
#include<bits/stdc++.h>

using namespace std;

//const int maxval = 9999;

double BST(int n,double p[],double c[][100],int r[][100])
{
    for(int i=1;i<=n;i++)
    {
        c[i][i-1]=0;   //Ci矩阵初始化
        c[i][i]=p[i];
        r[i][i]=i;      //R根矩阵初始化

    }

    c[n+1][n]=0;
    for(int d=1;d<n;d++)        //安对角线计算，从第二条对角线开始
    {
        for(int i=1;i<=n-d;i++)     //行的取值范围
        {

            int j=i+d;          //j求出在对角线上的i对应的
            double minval=9999;
            int mink=i;         //最小值对应根点
            double sum=0;
            for(int k=i;k<=j;k++)
            {
                sum=sum+p[k];
                if(c[i][k-1]+c[k+1][j]<minval)   //三角形比较法，选最小值
                {
                    minval=c[i][k-1]+c[k+1][j];
                    mink=k;
                }
            }
            c[i][j]=minval+sum;//得到了最小值
            r[i][j]=mink;//记录取得最小值时的根节点
        }
    }

    return c[1][n];
}






int main()
{
    while(1)
    {
        cout<<"input operand :  1  enter   ,2   exit system"<<endl;
        int ch;
        cin>>ch;
        if(ch==2)
            return 0;
        else if(ch==1)
        {
            system("cls");
            int n;
            cout << "input the point number" << endl;
            cin>>n;  //节点个数
            double p[n];  // 概率数组
            memset(p,0,sizeof(p));
            // 将概率数组排序，保证正确
            cout<<"input each point probability" <<endl;
            for(int i=1;i<=n;i++)
            {
                cin>>p[i];
            }
            double c[n+2][100];  //动态ci矩阵
            int r[n+2][100];    //根矩阵
            memset(r,0,sizeof(r));
            memset(c,0,sizeof(c));
            double s=BST(n,p,c,r);

            cout << "the minimum compare times is  " << s<<endl;
            cout << "the minimum probability  matrix is" << endl;
            for(int i=1;i<=n+1;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    cout<<std::setw(3);
                    cout << c[i][j] << "    ";
                }
                cout << endl;
             }

            cout << "the point matrix " << endl;
            for(int i=1;i<=n+1;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    cout << r[i][j] << "   ";
                }
                cout << endl;
             }
        }

    }
}


