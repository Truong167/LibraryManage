#include "Structs.h"
#include "console.h"
#include "menu.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	system("cls");
	SetConsoleTitle("Library Management");
	DS_DAU_SACH listDauSach;
	TREE tree = NULL;
	ResizeConsole(1353, 800);
	RemoveScrollbar();
	SetTitleAndBgColor("color F0");
	DrawBorder();
	ShowHuongDan();
	Load_DauSach(listDauSach);
	DocDuLieuDocGia(tree);
	loadMATHE();
	ShowMenu(listDauSach, tree);
//	menu();
	system("pause");
	return 0;
}
