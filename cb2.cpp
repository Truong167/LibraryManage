#include<iostream>
#include<math.h>
#include<fstream>
#define SL 8
using namespace std;

int demBac(int x, int i){
	x = x/2;
	if(x == 1) return i;
	i++;
	demBac(x, i);
}

void arrscb(int *a){
	int t = SL/2;	
	int y = 1;
	int c = 1;
	a[0] = t; //Gia tri i tri dau tien la sl/2
	
	for ( int i = 1; i <= demBac(SL/2, 1); i ++ ){ // Ung voi vi tri dau la 4096 (2^12) thi se co chieu cao cua ca la 12
		for ( int j = 1 ; j <= pow(2,i); j++){ // Ung voi moi do cao i thi se co 2^i phan tu.
			if( j == 1){// Node trai nhat cua tung do cao se bang SL/(2^i) VD: do cao bang 1 thi node trai nhat se la 4096/2
				a[y] = t/pow(2,i); 
				y++; 
			}	
			else{
				if(a[y - 1] < SL/2){ // Neu gia tri truoc nho hon node dau tien thi dua qua trai nguoc lai dua qua phai
					a[y] = t/pow(2,i) + (pow(2, i) - c) * t/pow(2,i-1);
					y++;
				 }
				else{
					a[y] = t/pow(2,i) + c * t/pow(2,i-1);
					y++;
					c++;
				}		
			}
		}
		c = 1;
	}
}
int main(){
	int *p = new int[SL];
	int i;	
	
	arrscb(p);
	
	ofstream fileout;
	fileout.open("data\\oooo1.txt", ios::out);
	if (fileout.is_open())
	{
		for(int i=0;i<(SL-1);i++){
		fileout<<p[i]<<endl;
		}	
	}
	else cout << "Loi ket noi file! ";
	fileout.close();
	
	delete[] p;
	
	system("pause");
	return 0;
}
