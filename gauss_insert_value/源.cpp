#include <iostream>
using namespace std;
#define ERROR 10e-4
void scanf_data(double ** &A, double ** &temp_a, double &x, int &n);
void solution(double ** &A, double ** &temp_a, double x, int n);
void diff_value(double **A,double **temp_a, double x,int n);
int main()
{
	double **A = NULL,**temp_a = NULL;
	int n = 0;
	double x = 0;

	//double temp_a[2][5] = {{-2,-1,0,1,3},{-56,-16,-2,-2,4}};
	//double temp_a[2][n] = { { 0.4,0.55,0.65,0.80,0.9,1.05 },{ 0.41075,0.57815,0.69675,0.88811,1.02652,1.25382 } };

	//double temp_x = 0.596;


	scanf_data(A,temp_a ,x, n);

	solution(A, temp_a,x, n);

	diff_value(A,temp_a,x,n);

	system("PAUSE");
	return 0;
}
void scanf_data(double ** &A, double ** &temp_a, double &x, int &n)
{
	cout << "********请输入数值的个数:**********\n";
	cin >> n;

	A = new double *[n];
	temp_a = new double *[2];

	cout << "********请先输入"<<n<<"个x,然后输入"<<n<<"个f(x):**********\n";
	for (size_t i = 0; i < n; i++)
	{
		A[i] = new double[n];
		if(i <2)
			temp_a[i] = new double[n];
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp_a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				A[j][i] = temp_a[1][j];

			}
			else
			{
				A[j][i] = 0;
			}
		}
	}
	cout << "********需要计算的x的值**********\n";
	cin >> x;
}


void solution(double ** &A, double ** &temp_a, double x, int n)
{
	
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			double temp1 = A[j][i - 1] - A[j - 1][i - 1];
			double temp2 = temp_a[0][j] - temp_a[0][j - i];
				//cout<<temp1 <<" "<<temp2<<endl;
			A[j][i] = temp1 / temp2;
		}
	}
	cout << "\n\n**********差商表********\n";
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

}
void diff_value(double **A, double **temp_a,double x, int n)
{
	double ** n_table = NULL;
	int i, j;

	int k = 0;
	double sum1,sum2 = 0;
	for (k = 1; k <=n; k++)
	{
		sum1 = sum2;
		sum2 = 0;
		for (i = 0; i<k; i++)
		{
			double temp_sum = 1;
			for (j = 0; j < i; j++)
			{
				temp_sum *= (x - temp_a[0][j]);

			}
			sum2 += temp_sum * A[i][i];
		}
		//cout <<sum1 <<" "<< sum2 << endl;
		if (fabs(sum1 - sum2) <= ERROR)
		{
			//cout << "第"<<k << endl;
			break;
		}
	}
	cout << "\n****************计算结果为************\n\n";
	cout <<"\t"<<k-1<<"次的方程满足条件\n" << endl;
	cout << "\t" << "插值结果y为：" << sum2 << "\n\n";
}