#ifndef MENU_H
#define MENU_H

#include <windows.h>
#include <string.h>
#include <conio.h>
#include "Structs.h"
#include "constant.h"

using namespace std;

char FrameTitle[4][50] = {
	"CHUC NANG",
	"HUONG DAN CHUNG",
	"THONG BAO",
	"MAN HINH CHINH"
};

char MenuPhimTat[NUMBER_LINE_ITEM][50] = {
	"UP: Len",
	"DOWN: Xuong",
	"LEFT: Trai",
	"RIGHT: Phai",
	"PgUp: Keo Len",
	"PgDn: Keo Xuong",
	"Enter: Chon/ Xac Nhan",
	"ESC: Thoat"
};

char MenuText[NUMBER_MENU_ITEM][MENU_TEXT_LENGTH] = {
		"         DAU SACH        ",
		"         DOC GIA         ",
		"         MUON TRA        ",
		"          THOAT          "
};

char SubMenuText[NUMBER_MENU_ITEM - 1][4][MENU_TEXT_LENGTH] = {
	{
		"In Danh Sach Dau Sach",
		"Top 10 Sach Muon Nhieu",
		"Them Dau Sach",
//		"Xoa Dau Sach",
//		"In DS Lop TC"
	},
	{
		"In DSDG Theo Ho + Ten",
		"In DSDG Theo Ma Doc Gia",
		"Them Doc Gia",
		//"In DSSV Theo LopTC",
	},
	{
		"Muon sach",
		"In danh sach dang muon",
		"Danh sach qua han"
	},
};

void PrintFrameText(int color, const char* text) {
	SetColor(color);
	cout << text;
	SetColor(DARK_BLUE);
}

void ColorText(int color, const char* text) {
	SetBGColor(color);
	SetColor(WHITE);
	printf("%-25s", text);
	SetColor(BLACK);
	SetBGColor(WHITE);
}

void DrawBorder() {
	int index = 0;
	HideTyping();
	GoToXY(0, 0);
	SetColor(DARK_BLUE);
	for (int i = 0; i < HEIGHT_BORDER; i++) {
		if (i == 0) {
			cout << " " << char(TOP_LEFT_CORNER);
			index = (WIDTH_FRAME_MENU - strlen(FrameTitle[0])) / 2;

			for (int j = 0; j < index; j++) {
				cout << char(DOUBLE_HORIZONTAL_LINE);
			}

			PrintFrameText(GREEN, FrameTitle[0]);

			for (int j = WIDTH_FRAME_MENU - index; j < WIDTH_BORDER - 1; j++) {
				if (j == WIDTH_FRAME_MENU) cout << char(TOP_CENTER);
				else cout << char(DOUBLE_HORIZONTAL_LINE);
			}
			cout << char(TOP_RIGHT_CORNER) << endl;
		}
		else if (i == HEIGHT_BORDER - 1) {
			cout << " " << char(BOTTOM_LEFT_CORNER);
			for (int j = 1; j < WIDTH_BORDER - 1; j++) {
				if (j == WIDTH_FRAME_MENU) cout << char(BOTTOM_CENTER);
				else cout << char(DOUBLE_HORIZONTAL_LINE);
			}
			cout << char(BOTTOM_RIGHT_CORNER) << endl;
		}
		else if (i == HEIGHT_FRAME_MENU) {
			cout << " " << char(LEFT_CENTER);

			index = (WIDTH_FRAME_MENU - strlen(FrameTitle[1])) / 2;
			for (int j = 0; j < index; j++) {
				cout << char(DOUBLE_HORIZONTAL_LINE);
			}

			PrintFrameText(GREEN, FrameTitle[1]);

			for (int j = WIDTH_FRAME_MENU - index; j < WIDTH_FRAME_MENU; j++) {
				cout << char(DOUBLE_HORIZONTAL_LINE);
			}
			cout << char(RIGHT_CENTER);
			GoToXY(WIDTH_BORDER, i);
			cout << char(DOUBLE_VERTICAL_LINE) << endl;

		}
		else if (i == HEIGHT_FRAME_MAIN) {
			cout << " " << char(DOUBLE_VERTICAL_LINE);
			GoToXY(WIDTH_FRAME_MENU + 1, i);
			cout << char(LEFT_CENTER);

			index = (WIDTH_BORDER - WIDTH_FRAME_MENU - strlen(FrameTitle[2])) / 2;
			for (int j = 0; j < index; j++) {
				cout << char(DOUBLE_HORIZONTAL_LINE);
			}

			PrintFrameText(RED, FrameTitle[2]);

			for (int j = WIDTH_BORDER - WIDTH_FRAME_MENU - index; j < WIDTH_BORDER - WIDTH_FRAME_MENU - 1; j++) {
				cout << char(DOUBLE_HORIZONTAL_LINE);
			}
			GoToXY(WIDTH_BORDER, i);
			cout << char(RIGHT_CENTER) << endl;
		}
		else {
			cout << " " << char(DOUBLE_VERTICAL_LINE);
			GoToXY(WIDTH_FRAME_MENU + 1, i);
			cout << char(DOUBLE_VERTICAL_LINE);
			GoToXY(WIDTH_BORDER, i);
			cout << char(DOUBLE_VERTICAL_LINE) << endl;
		}
	}

}

void ShowHuongDan() {
	SetColor(BLACK);
	for (int i = 0; i < NUMBER_LINE_ITEM; i++) {
		GoToXY(3, HEIGHT_FRAME_MENU + 3 + i);
		cout << MenuPhimTat[i];
	}
}

void ClearBorderSubMenu() {
	for (int i = 0; i < 30; i++) {
		GoToXY(BUTTON_PADDING_LEFT + WIDTH_FRAME_MENU, i + 3);
		printf("%-27s", " ");
	}
}

int DrawSubMenu(int i, int select) {
	int j = 0,
		pointX = BUTTON_PADDING_LEFT + WIDTH_FRAME_MENU + 1,
		pointY = i * BUTTON_PADDING_LEFT + 5;

	for (int k = 0; k < 3 * 2 - 1; k++) {
		if (k % 2 == 0) {
			GoToXY(pointX, pointY + k);
			if (select - 1 == j) {
				ColorText(LIGHT_BLUE, SubMenuText[i][j++]);
			}
			else {
				SetColor(BLACK);
				printf("%-25s", SubMenuText[i][j++]);
			}
			GoToXY(pointX, pointY + 1 + k);
			if (k < 4) cout << "-------------------------";
		}
	}

	return 0;
}

void DrawBorderSubMenu(int i, int selectSubMenu = 0) {
	ClearBorderSubMenu();
	int k = 0;

	int pointX = BUTTON_PADDING_LEFT + WIDTH_FRAME_MENU;
	int pointY = i * BUTTON_PADDING_LEFT + 5;

	SetColor(BLACK);
	GoToXY(pointX, pointY - 1);
	cout << char(TOP_LEFT_CORNER_SIMPLE);
	for (k = 1; k < MENU_TEXT_LENGTH - 5; k++)
		cout << char(HORIZONTAL_LINE);

	cout << char(TOP_RIGHT_CORNER_SIMPLE);

	int j = 0;
	for (k = 0; k < 5; k++) {
		GoToXY(pointX, pointY + k);
		cout << char(VERTICAL_LINE);
		GoToXY(WIDTH_FRAME_MENU + MENU_TEXT_LENGTH - 2, pointY + k);
		cout << char(VERTICAL_LINE);
	}

	GoToXY(pointX, pointY + k);
	cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
	for (k = 1; k < MENU_TEXT_LENGTH - 5; k++)
		cout << char(HORIZONTAL_LINE);

	cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
	DrawSubMenu(i, selectSubMenu);
}

void DrawButton(int i) {
	int pointX = BUTTON_PADDING_LEFT;
	int pointY = i * BUTTON_PADDING_LEFT + 4;

	SetColor(BLACK);
	GoToXY(pointX, pointY);
	cout << char(TOP_LEFT_CORNER_SIMPLE);
	for (int k = 1; k < MENU_TEXT_LENGTH - 5; k++)
		cout << char(HORIZONTAL_LINE);

	cout << char(TOP_RIGHT_CORNER_SIMPLE);
	GoToXY(BUTTON_PADDING_LEFT, pointY + 1);
	cout << char(VERTICAL_LINE);


	for (int k = 0; k < MENU_TEXT_LENGTH - 6; k++)
		cout << char(SPACE);

	cout << char(VERTICAL_LINE);
	GoToXY(pointX, pointY + 2);
	cout << char(BOTTOM_LEFT_CORNER_SIMPLE);

	for (int k = 1; k < MENU_TEXT_LENGTH - 5; k++)
		cout << char(HORIZONTAL_LINE);

	cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);

}

void PrintMenuText(int& select) {
	int pointX = BUTTON_PADDING_LEFT + 1, pointY = 0;
	for (int i = 0; i < NUMBER_MENU_ITEM; i++) {
		pointY = i * BUTTON_PADDING_LEFT + 5;
		GoToXY(pointX, pointY);
		if (i == select)
			ColorText(LIGHT_BLUE, MenuText[i]);
		else cout << MenuText[i];
	}
}

void DrawMenu(int& select) {
	int pointX = BUTTON_PADDING_LEFT + 1, pointY = 0;
	for (int i = 0; i < NUMBER_MENU_ITEM; i++) {
		DrawButton(i);
		pointY = i * BUTTON_PADDING_LEFT + 5;
		GoToXY(pointX, pointY);
	}
	PrintMenuText(select);
}

int SubMenu(int index) {
	char action;
	int selectSubMenu = 0;
	DrawBorderSubMenu(index, selectSubMenu + 1);
	do {
		SetColor(BLACK);
		DrawSubMenu(index, selectSubMenu + 1);
		action = _getch();
		if (action == 0) action = _getch();
		switch (action) {
		case UP:
			if (selectSubMenu + 1 > 1) {
				selectSubMenu--;
			}
			break;
		case DOWN:
			if (selectSubMenu + 1 < NUMBER_SUB_MENU_ITEM) {
				selectSubMenu++;
			}
			break;
		case ENTER:
			return selectSubMenu;
		case ESC:
			selectSubMenu = -1;
			return selectSubMenu;
		case LEFT:
			selectSubMenu = -1;
			return selectSubMenu;
		}
	} while (1);
}

void ShowSubMenu(int& select, DS_DAU_SACH &ds, TREE t) {
	int selectSubMenu = 0;
	do {
		selectSubMenu = SubMenu(select);
		ClearBorderSubMenu();
		switch (selectSubMenu) {
		case -1:
			return;
		case 0:
			if (select == 0) {
				PrintDataDauSach(ds, 1, "TEST");
			}
			else if (select == 1) {
				PrintDataDocGia(1, "TEST", t, 0);
			}
			else if (select == 2) {
				DrawNhapMaDocGia(t, ds,1);
			}
			break;
		case 1:
			if (select == 0) {
				PrintDataTop10(ds);
			}
			else if (select == 1) {
				PrintDataDocGia(1, "TEST", t, 1);
			}
			else if (select == 2) {
				DrawNhapMaDocGia(t, ds, 2);

			}
			else if (select == 3) {

			
			}

			break;
		case 2:
			if (select == 0) {
				PrintDataDauSach(ds, 2, "NEW");
			}
			else if (select == 1) {
				PrintDataDocGia(2, "NEW", t, 1);
			}
			else if (select == 2) {
				PrintDataQH(t, ds);
			}
			break;
		}
	} while (1);
}

int ShowMenu(DS_DAU_SACH &ds, TREE t) {
	HideTyping();
	char action;
	int select = 0;
	DrawMenu(select);
	do {
		PrintMenuText(select);
		action = _getch();
		if (action == 0) action = _getch();
		switch (action) {
		case UP:
			if (select + 1 > 1) {
				select--;
			}
			break;
		case DOWN:
			if (select + 1 < NUMBER_MENU_ITEM) {
				select++;
			}
			break;
		case RIGHT:
			if (select < NUMBER_MENU_ITEM - 1)
				ShowSubMenu(select, ds, t);
			break;
		case ENTER:
			if (select < NUMBER_MENU_ITEM - 1)
				ShowSubMenu(select, ds, t);
			else {
				SaveDauSach(ds);
				LuuDuLieuDocGia(t);
				Luu_mt();
				system("cls");
				ClearList_DauSach(ds);
				deleteTree(t);
				exit(0);
			}
			break;
		}
	} while (1);
}
#endif

