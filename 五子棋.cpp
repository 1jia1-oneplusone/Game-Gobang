#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
using namespace std;
char a[16][16],p='*';
int x,y,i,fx[8]={1,0,-1,0,1,1,-1,-1},fy[8]={0,1,0,-1,1,-1,1,-1},qx[5],qy[5];
void dg1();
void ss(char b,int xx,int yy)
{
	int x1=xx,y1=yy;
	qx[0]=xx,qy[0]=yy;
	for(int k=0;k<8;k++)
	{
		x1=xx,y1=yy;
		for(int u=1;u<5;u++)
		{
			if(a[x1+fx[k]][y1+fy[k]]==b)
			{
				x1+=fx[k],y1+=fy[k],qx[u]=x1,qy[u]=y1;
			}
			else break;
			if(u==4&&a[x1][y1]==b)p=b;
		}
		if(p!='*')break;
	}
	return;
}
void pd()
{
	for(i=1;i<=15;i++)for(int j=1;j<=15;j++)
	{
		if(a[i][j]=='@')
		{
			ss('@',i,j);
		}
		if(a[i][j]=='O')
		{
			ss('O',i,j);
		}
	}
	return;
}
void pr()
{
	system("cls");
	for(i=1;i<=15;i++)
	{
		if(i>5)cout<<' ';
		cout<<15-i+1<<'>'<<' ';
		for(int j=1;j<=15;j++)cout<<a[i][j]<<' ';
		cout<<endl;
		
	}
	cout<<"    ";
	for(i=1;i<=15;i++)
	{
		cout<<"! ";
	}
	cout<<endl;
	cout<<"    ";
	for(i=1;i<=15;i++)
	{
		cout<<i;
		if(i<10)cout<<' ';
	}
	cout<<endl;
}
void pr2()
{
	system("cls");
	for(i=1;i<=15;i++)
	{
		//if(i<10)cout<<' ';
		//cout<<i<<'>'<<' ';
		cout<<"    ";
		for(int j=1;j<=15;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
		
	}
	/*cout<<"    ";
	for(i=1;i<=15;i++)
	{
		cout<<"! ";
	}
	cout<<endl;
	cout<<"    ";
	for(i=1;i<=15;i++)
	{
		cout<<i;
		if(i<10)cout<<' ';
	}
	cout<<endl;*/
}
void dg2()
{
	cout<<"O White go! O"<<endl;
	cin>>y>>x;
	if(a[x][y]=='O'||a[x][y]=='@'){cout<<"No there!"<<endl;Sleep(2000);pr();dg2();return;}
	a[x][y]='O';
	pr();
	pd();
	if(p=='O'){pr2();cout<<"White win!"<<endl;Sleep(2000);return;}
	dg1();
	return;
}
void dg1()
{
	cout<<"@ Black go! @"<<endl;
	cin>>y>>x;
	if(a[x][y]=='O'||a[x][y]=='@'){cout<<"No there!"<<endl;Sleep(2000);pr();dg1();return;}
	a[x][y]='@';
	pr();
	pd();
	if(p=='@'){pr2();cout<<"Black win!"<<endl;Sleep(2000);return;}
	dg2();
	return;
}
void dg()
{
	cout<<"Are you ready?"<<endl;
	Sleep(1200);
	system("cls");
	cout<<"3!"<<endl;
	Sleep(800);
	system("cls");
	cout<<"2!"<<endl;
	Sleep(800);
	system("cls");
	cout<<"1!"<<endl;
	Sleep(800);
	system("cls");
	cout<<"Game start!"<<endl;
	Sleep(1000);
	pr();
	dg1();
	return;
}
int main()
{
	for(i=1;i<=15;i++)for(int j=1;j<=15;j++)a[i][j]='+';
	dg();
	return 0;
}
