#include "Structs.h"
#include "constant.h"
#include "console.h"
#include "helper.h"

int arrmt[10000];
int smt = 0;
int indexQH = 0;

/*
* — Tieu De Cho Chuc Nang Mon Hoc —
*/
const int NUMBER_ITEM_MONHOCTEXT = 4;

/*
* === END ===

/*
* — Tieu De Cho Chuc Nang Sach —
*/
const int NUMBER_ITEM_SACHTEXT = 3;
const int NUMBER_ITEM_SACH_FUNCTION_TEXT = 5;

char ThemSachText[NUMBER_ITEM_SACHTEXT][MENU_TEXT_LENGTH] = {
		"MA SACH: ",
		"TRANG THAI: ",
		"VI TRI:"
};
char MUONTRATXT[NUMBER_ITEM_SACHTEXT][MENU_TEXT_LENGTH] = {
		"MA SACH: ",
		"TEN SACH: ",
		"NGAY MUON: "
};

char SachFunctionText[2][NUMBER_ITEM_SACH_FUNCTION_TEXT][30] = {
		{
			"UP",
			"DOWN",
			"ENTER"
		},
		{
			": Len",
			": Xuong",
			": Xac Nhan"
		}
};
/*
* === END ===
Doc gia
*/

const int NUMBER_ITEM_DOCGIA_TEXT = 6;
const int NUMBER_ITEM_DOCGIA_FUNCTION_TEXT = 5;

char TitleText[10][MENU_TEXT_LENGTH+ 10] = {
		"BANG DANH SACH DAU SACH",
		"BANG DANH SACH SACH",
		"TOP 10 SACH MUON NHIEU NHAT",
		"BANG DANH SACH CAC DOC GIA",
		"DANH SACH SACH DA MUON",
		"DANH SACH DOC GIA MUON SACH QUA HAN"
};

char EditText[10][MENU_TEXT_LENGTH] = {
		"NHAP THONG TIN DAU SACH",
		"SUA THONG TIN DAU SACH",
		"XOA DAU SACH",
		"SUA THONG TIN SACH",
		"NHAP THONG TIN DOC GIA",
		"SUA THONG TIN DOC GIA",
		"XOA DOC GIA",
		"XAC NHAN MUON SACH",
		"XAC NHAN TRA SACH"
		
};

char ThemDocGiaText[NUMBER_ITEM_DOCGIA_TEXT-1][MENU_TEXT_LENGTH] = {
		"MA THE: ",
		"HO: ",
		"TEN:",
		"PHAI: ",
		"TRANG THAI: "
};

char DocGiaFunctionText[2][NUMBER_ITEM_DOCGIA_FUNCTION_TEXT][30] = {
		{
			"CTR+F",
			"DEL",
			"ENTER"
		},
		{
			": Tim Kiem",
			": Xoa",
			": Xac Nhan"
		}
};
/*============================================================Dau sach
*/
const int NUMBER_ITEM_DAUSACHTEXT = 6;
char ThemDauSachText[NUMBER_ITEM_DAUSACHTEXT+2][MENU_TEXT_LENGTH] = {
		"ISBN: ",
		"TEN SACH: ",
		"SO TRANG: ",
		"TEN TAC GIA: ",
		"NAM XUAT BAN: ",
		"THE LOAI: ",
		"SO LUONG",
		"VI TRI"
};

const int NUMBER_ITEM_DAUSACH_FUNCTION_TEXT = 5;
char DauSachFunctionText[2][NUMBER_ITEM_DAUSACH_FUNCTION_TEXT][30] = {
		{
			"EX_INSERT",
			"CTR+F",
			"DEL",
			"ENTER"
		},
		{
			": Sua",
			": Tim Kiem",
			": Xoa",
			": Xac Nhan"
		}
};

char EditFunctionText[2][NUMBER_ITEM_DAUSACH_FUNCTION_TEXT][30] = {
		{
			"Tab",
			"Up",
			"ENTER"
		},
		{
			": Ve trang truoc",
			": Len",
			": Xac Nhan"
		}
};

char TraSachTxt[4][MENU_TEXT_LENGTH] = {
		"MA SACH: ",
		"TEN SACH: ",
		"NGAY TRA: ",
		"TRANG THAI: "
};
/*
* === END ===
*/
// ==== end ====


void loadMATHE(){
	ifstream filein;

	filein.open("data\\maThe.txt", ios::in);
	int i = 0;
	if (filein.is_open()){
		while (!filein.eof()){
			filein >> arrmt[i];
			i++;
		}	
	
	}
}

void Luu_mt(){
	ofstream fileout;
	fileout.open("data\\maThe.txt", ios::out);
	for (int i = smt; i < sizeof arrmt / sizeof(int); i++) {
				fileout << arrmt[i] << endl;
			}
	fileout.close();

}

//Dau sach
void DrawBoderThemDauSach() {
	int pointX = 55, pointY = 5, width = 90, height = 36;

	for (int i = 0; i < height; i++) {
		GoToXY(pointX, pointY + i);
		if (i == 0 || i == height - 1) {
			for (int j = 0; j < width; j++) {
				if (j == 0)
					if (i == height - 1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if (j == width - 1)
					if (i == height - 1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else {
			cout << char(VERTICAL_LINE);
			GoToXY(pointX + width - 1, pointY + i);
			cout << char(VERTICAL_LINE);
		}
	}

//	strcpy(DauSachFunctionText[1][1], ": Tim Kiem");
	DrawTitleFunction(pointX + 20, pointY + 35,EditFunctionText, NUMBER_ITEM_DAUSACH_FUNCTION_TEXT, 0);

	for (int i = 0; i < NUMBER_ITEM_DAUSACHTEXT+2; i++) {
		GoToXY(pointX + 5, pointY + 2 + i * 4);
		printf("%-30s", ThemDauSachText[i]);
		DrawInput(85, pointY + 1 + i * 4);
	}


	GoToXY(87, 8);
	Typing();

}
void ClearRemainDauSach(int total, int pointX, int pointY){
	int row2 = 15-total;
	pointY = total*2+pointY;
	for(int i = 0; i < row2;i++){
		GoToXY(pointX, pointY+=2); printf("%-7s", " ");
		GoToXY(pointX + 10, pointY); printf("%-10s", " ");
		GoToXY(pointX + 23, pointY); printf("%-20s", " ");
		GoToXY(pointX + 48, pointY); printf("%-8s", " ");
		GoToXY(pointX + 59, pointY); printf("%-16s", " ");
		GoToXY(pointX + 79, pointY); printf("%-7s", " ");	
		GoToXY(pointX + 94, pointY); printf("%-15s", " ");
	}
}

void CountHeaderDauSachTable(int pointX, int pointY){
	GoToXY(pointX, pointY); cout << "STT";
	GoToXY(pointX + 10, pointY); cout << "ISBN";
	GoToXY(pointX + 23, pointY); cout << "Ten Sach";
	GoToXY(pointX + 48, pointY); cout << "So Trang";
	GoToXY(pointX + 59, pointY); cout << "Ten Tac Gia";
	GoToXY(pointX + 79, pointY); cout << "Nam Xuat Ban";
	GoToXY(pointX + 94, pointY); cout << "The Loai";
}

void CountHeaderTop10DauSachTable(int pointX, int pointY){
	GoToXY(pointX, pointY); cout << "STT";
	GoToXY(pointX + 10, pointY); cout << "ISBN";
	GoToXY(pointX + 23, pointY); cout << "Ten Sach";
	GoToXY(pointX + 60, pointY); cout << "So Luot Muon";

}

void CoutNodeTop10DauSach(DAUSACH *ds, int stt, int pointX, int pointY){
	HideTyping();
	GoToXY(pointX, pointY); printf("%-7d", stt);
	GoToXY(pointX + 10, pointY); printf("%-10s", ds->isbn);
	GoToXY(pointX + 23, pointY); printf("%-14s", ds->tenSach);
	GoToXY(pointX + 60, pointY); printf("%-8d", ds->luotMuon);
	SetColor(BLACK);
}

void CoutNodeDauSach(DAUSACH *ds, int stt, int pointX, int pointY){
	HideTyping();
	GoToXY(pointX, pointY); printf("%-7d", stt);
	GoToXY(pointX + 10, pointY); printf("%-10s", ds->isbn);
	GoToXY(pointX + 23, pointY); printf("%-20s", ds->tenSach);
	GoToXY(pointX + 48, pointY); printf("%-8d", ds->soTrang);
	GoToXY(pointX + 59, pointY); printf("%-16s", ds->tacGia);
	GoToXY(pointX + 79, pointY); printf("%-7d", ds->namXuatBan);	
	GoToXY(pointX + 94, pointY); printf("%-15s", ds->theLoai);
	SetColor(BLACK);
}


void DrawTableDauSach(int is_draw_title, int tab){
	int pointX = 40, pointY = 5, width = 115, height = 37;
	int col1 = 10, col2 = 24, col3 = 48, col4 = 59, col6 = 79, col7 = 94;
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3 || j == col4 || j == col6 || j == col7)
					if(i > 0 && i < height-2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-2)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(HORIZONTAL_LINE);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else if(i%2 == 0){
			for(int j = 0; j < width; j++){
				if(j == 0)
					cout << char(LEFT_CENTER_SIMPLE);
				else if(j == width-1)
					cout << char(RIGHT_CENTER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3 || j == col4 || j == col6 || j == col7)
					if(i == 2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-3)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(PLUS_CENTER);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else {
			cout << char(VERTICAL_LINE);
			
			if(i > 2 && i < height - 2){
				GoToXY(pointX+col1, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col2, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col3, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col4, pointY+i);
				cout << char(VERTICAL_LINE);
				
				
				GoToXY(pointX+col6, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col7, pointY+i);
				cout << char(VERTICAL_LINE);
				
			}
			
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	CountHeaderDauSachTable(pointX+2, pointY+3);
	
	if(is_draw_title == 0) return;
	DrawHuongDanTable(70, 40, DauSachFunctionText, NUMBER_ITEM_DAUSACH_FUNCTION_TEXT);
	
	DrawTitle(TitleText[0], 89);
}

void DrawTableTop10DauSach(){
	int pointX = 60, pointY = 5, width = 80, height = 37;
	int col1 = 10, col2 = 23, col3 = 60;
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3)
					if(i > 0 && i < height-2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-2)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(HORIZONTAL_LINE);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else if(i%2 == 0){
			for(int j = 0; j < width; j++){
				if(j == 0)
					cout << char(LEFT_CENTER_SIMPLE);
				else if(j == width-1)
					cout << char(RIGHT_CENTER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3)
					if(i == 2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-3)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(PLUS_CENTER);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else {
			cout << char(VERTICAL_LINE);
			
			if(i > 2 && i < height - 2){
				GoToXY(pointX+col1, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col2, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col3, pointY+i);
				cout << char(VERTICAL_LINE);
			}
			
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	CountHeaderTop10DauSachTable(pointX+2, pointY+3);
	
	DrawTitle(TitleText[2], 87);
}

void  XoaDauSach(DS_DAU_SACH &dsds, int pos) {
	DAUSACH *pNode=dsds.nodes[pos];
	GiaiPhongDMS(pNode->listSach);
	free(pNode);
//	delete  (dsds.dsDauSach[pos]);
	for(int i = pos; i <dsds.sl; i++) {
		dsds.nodes[i] = dsds.nodes[i + 1];
	}
	dsds.sl--;
	return;
}

int ThemDauSach(DS_DAU_SACH &listDauSach, string state, int check){
	HideTyping();
	int x = 87, y = 7;
	string temp = "";
	int c, type = 2, index = 0, is_delete = 0, length = 10, soTrang = 0, soLuong = 0, namXuatBan = 0, soLuongTmp;
	char isbn[10];
	char tenSach[50];
	char tacGia[50];
	char theLoai[50];
	char viTri[50];
	
	if(state == "NEW"){
		DrawTitle(EditText[0], 90);		
	} else if(state == "EDIT"){
		DrawTitle(EditText[1], 90);	
		DrawBoderThemDauSach();
		if(check != -1){
			DrawButtonYesNo(37, state);
			
			GoToXY(x, y);
			SetColor(PURPLE);
			printf("%-50s", listDauSach.nodes[check]->isbn);
			strcpy(isbn, listDauSach.nodes[check]->isbn);
	
			SetColor(BLACK);				
			GoToXY(x, y+=4);
			printf("%-50s", listDauSach.nodes[check]->tenSach);
			strcpy(tenSach, listDauSach.nodes[check]->tenSach);
						
			GoToXY(x, y+=4);
			printf("%-50d", listDauSach.nodes[check]->soTrang);
			soTrang = listDauSach.nodes[check]->soTrang;

			GoToXY(x, y+=4);
			printf("%-50s", listDauSach.nodes[check]->tacGia);
			strcpy(tacGia, listDauSach.nodes[check]->tacGia);
						
			GoToXY(x, y+=4);
			printf("%-50d", listDauSach.nodes[check]->namXuatBan);
			namXuatBan = listDauSach.nodes[check]->namXuatBan;
						
			GoToXY(x, y+=4);
			printf("%-50s", listDauSach.nodes[check]->theLoai);
			strcpy(theLoai, listDauSach.nodes[check]->theLoai);
					
			GoToXY(x, y+=4);
			printf("%-50d", listDauSach.nodes[check]->soLuong);
			soLuong = listDauSach.nodes[check]->soLuong;
			
			GoToXY(x, y+=4);
			printf("%-50s", listDauSach.nodes[check]->listSach.pHead->data.viTri);
			strcpy(viTri, listDauSach.nodes[check]->listSach.pHead->data.viTri);			
			y = y-4, type = 3, index++, length = 3;;
			temp = ConvertIntToString(soLuong);
			soLuongTmp = soLuong;
			length = 15;
		}
	}
	
	else if(state == "DELETE"){
		DrawTitle(EditText[2], 93);	
		DrawBoderThemDauSach();
		if(check != -1){
			DrawButtonYesNo(37, state);
			
			GoToXY(x, y);
			SetColor(PURPLE);
			printf("%-50s", listDauSach.nodes[check]->isbn);
			strcpy(isbn, listDauSach.nodes[check]->isbn);
	
			SetColor(BLACK);				
			GoToXY(x, y+=4);
			printf("%-50s", listDauSach.nodes[check]->tenSach);
			strcpy(tenSach, listDauSach.nodes[check]->tenSach);
						
			GoToXY(x, y+=4);
			printf("%-50d", listDauSach.nodes[check]->soTrang);
			soTrang = listDauSach.nodes[check]->soTrang;

			GoToXY(x, y+=4);
			printf("%-50s", listDauSach.nodes[check]->tacGia);
			strcpy(tacGia, listDauSach.nodes[check]->tacGia);
						
			GoToXY(x, y+=4);
			printf("%-50d", listDauSach.nodes[check]->namXuatBan);
			namXuatBan = listDauSach.nodes[check]->namXuatBan;
						
			GoToXY(x, y+=4);
			printf("%-50s", listDauSach.nodes[check]->theLoai);
			strcpy(theLoai, listDauSach.nodes[check]->theLoai);
					
			GoToXY(x, y+=4);
			printf("%-50d", listDauSach.nodes[check]->soLuong);
			soLuong = listDauSach.nodes[check]->soLuong;
			
			GoToXY(x, y+=4);
			printf("%-50s", listDauSach.nodes[check]->listSach.pHead->data.viTri);
			strcpy(viTri, listDauSach.nodes[check]->listSach.pHead->data.viTri);	
					
			y = y+3, type = 4, index = 7;
			DrawTitleYesNo(38, is_delete, state);
		}
	}
	
	if(state == "NEW"){
		DrawBoderThemDauSach();
		type = 0;
		do{
			c = InputValue(length, temp, x, y, type);
			switch (c) {
				case EX_UP:
					if(index == 0) break;
					
					if(index == 1){
						temp = convertToString(isbn, strlen(isbn));
						GoToXY(x+temp.length(), y -= 4);
						index --;
						type = 0; length = 10;
					}else if(index == 2){
						temp = convertToString(tenSach, strlen(tenSach));
						GoToXY(x+temp.length(), y -= 4);
						index --;	
						type = 1, length = 50;
					}else if(index == 3){
						temp = ConvertIntToString(soTrang);
						GoToXY(x+temp.length(), y -= 4);
						index --;
						type = 3, length = 4;
					}else if(index == 4){
						
						temp = convertToString(tacGia, strlen(tacGia));
						GoToXY(x+temp.length(), y -= 4);
						index --;
						type = 2, length = 50 ;
					}else if(index == 5){
						temp = ConvertIntToString(namXuatBan);		
						if(namXuatBan > GetDate().year){
							Message("ERROR:", "Nam Xuat Ban Khong Duoc Lon Hon Nam Hien Tai", 0, 1000);
							GoToXY(x+temp.length(), y);
							break;
						}
						GoToXY(x+temp.length(), y -= 4);
						index --;
						type = 3, length = 4;
					}else if(index == 6){
						temp = convertToString(theLoai, strlen(theLoai));
						GoToXY(x+temp.length(), y -= 4);
						index --;
						type = 2, length = 50;
					}
					else if(index == 7){
						temp = ConvertIntToString(soLuong);
						GoToXY(x+temp.length(), y -= 4);
						index --;
						type = 3, length = 3;
					}
					break;
			    case EX_DEL:
			    case CTRL_F:
			    	DrawBoderThemDauSach();
			    	break;
			    case ENTER:
			    	if(temp[temp.length()-1] == SPACE) temp = temp.substr(0, temp.length()-1);
			    	if(temp.length() == 0 ) {
						Message("ERROR:", "Vui long khong de trong! ", 0, 1000);
						GoToXY(x+temp.length(), y);
						break;
					}
					
					if(index == 0){
						strcpy(isbn, temp.c_str());
						if(isISBN(isbn, listDauSach)){
							Message("ERROR:", "ISBN Da Ton Tai!", 0, 1000);
							GoToXY(x+temp.length(), y);
							break;
						}
						temp = convertToString(tenSach, strlen(tenSach));
						
						y+=4, type = 1, length = 50;
						
					}else if(index == 1){
						y+=4;
						strcpy(tenSach, temp.c_str());
						type = 3, length = 4;
						temp = ConvertIntToString(soTrang);
					}else if(index == 2){
						y+=4;
						sscanf(temp.c_str(), "%d", &soTrang);
						type = 2, length = 50 ;
						temp = convertToString(tacGia, strlen(tacGia));
					}else if(index == 3){
						y+=4;
						strcpy(tacGia, temp.c_str());
						type = 3, length = 4;
						temp = ConvertIntToString(namXuatBan);
					}else if(index == 4){
						
						sscanf(temp.c_str(), "%d", &namXuatBan);
						
						if(namXuatBan > GetDate().year){
							Message("ERROR:", "Nam Xuat Ban Khong Duoc Lon Hon Nam Hien Tai", 0, 1000);
							GoToXY(x+temp.length(), y);
							break;
						}
						y+=4;
						type = 2, length = 50;
						temp = convertToString(theLoai, strlen(theLoai));
					}else if(index == 5){
						y+=4;
						strcpy(theLoai, temp.c_str());
						type = 3, length = 3;
						temp = ConvertIntToString(soLuong);
					}else if(index == 6){
						y+=4;
						sscanf(temp.c_str(), "%d", &soLuong);
						type = 1, length = 20;
						temp = convertToString(viTri, strlen(viTri));
					}
					else if(index == 7){
						y+=4;
						strcpy(viTri, temp.c_str());
					}
					index++;
//					temp = "";
					if(index == 8){
						DAUSACH *ds = new DAUSACH;
						strcpy(ds->isbn, isbn);
						strcpy(ds->tenSach, tenSach);
						ds->soTrang = soTrang;
						strcpy(ds->tacGia, tacGia);
						ds->namXuatBan = namXuatBan;
						strcpy(ds->theLoai, theLoai);
						ds->soLuong = soLuong;
						ds->luotMuon = 0;
						ds->listSach = taoList(isbn, viTri, soLuong);
						listDauSach.nodes[listDauSach.sl] = ds;
						listDauSach.sl++;
		  				Message("SUCCESS:", "Them Moi Dau Sach Thanh Cong!", 1, 1000);
						y = 7, index = 0;
						ClearInput(x, 3, 8);
						length = 50;
						temp = "";
						strcpy(tacGia, temp.c_str());
				    	strcpy(tenSach, temp.c_str());
				    	strcpy(theLoai, temp.c_str());
				    	strcpy(viTri, temp.c_str());
					}
			    	break;
			    case ESC:
			    	temp = "";
			    	strcpy(tacGia, temp.c_str());
			    	strcpy(tenSach, temp.c_str());
			    	strcpy(theLoai, temp.c_str());
			    	strcpy(viTri, temp.c_str());
			        return c;
			}
		}while(1);
	} else if(state == "EDIT"){
		
		do{
			c = InputValue(length, temp, x, y, type);
			switch (c) {				
			    case EX_INSERT:
			    case EX_DEL:
			    	ClearButtonYesNo(22);
			        return c;
				case TAB:
					temp = "";
					strcpy(tacGia, temp.c_str());
				    strcpy(tenSach, temp.c_str());
				    strcpy(theLoai, temp.c_str());
				    strcpy(viTri, temp.c_str());
			        return c;
			    case EX_LEFT:
			    case EX_RIGHT:
					if(index < 2) break;
					is_delete = is_delete == 1 ? 0 : 1;
			    	DrawTitleYesNo(38, is_delete, state);
			        break;
			    case ENTER:
			    	if(temp[temp.length()-1] == SPACE) temp = temp.substr(0, temp.length()-1);
			    	if(temp.length() == 0 ) {
						Message("ERROR:", "Vui long khong de trong!", 0, 1000);
						GoToXY(x+temp.length(), y);
						break;
					}
					
					if(index == 1){
						sscanf(temp.c_str(), "%d", &soLuong);
						if(soLuong < soLuongTmp){
							Message("ERROR:", "Chi Duoc Tang So Luong", 0, 1000);
							GoToXY(x+temp.length(), y);
							break;
						}
				    	index++;
				    	y+= 4;
				    	temp = convertToString(viTri, strlen(viTri));
				    	type = 1; length = 20;
				    	
					}
					else if (index == 2) {
						
						strcpy(viTri, temp.c_str());						
						index ++;
						type = 4;
						DrawTitleYesNo(38, is_delete, state);
					}
					else if (index == 3) {
						if(is_delete == 0) {
							BOOK b;
							char isbnTmp[20];
							char maSachTmp[20];
							listDauSach.nodes[check]->soLuong = soLuong;
							for (int i = soLuongTmp + 1; i <= soLuong; i++) {
								itoa(i, isbnTmp, 10);
								strcpy(maSachTmp, isbn);
								strcat(maSachTmp, "-");
								strcat(maSachTmp, isbnTmp);
								strcpy(b.maSach, maSachTmp);
								b.trangThai = 0;
								strcpy(b.viTri, listDauSach.nodes[check]->listSach.pHead->data.viTri);
						
								NODE_DANH_MUC_SACH* p = KhoiTaoNode(b);
						
								themVaoCuoi(listDauSach.nodes[check]->listSach, p);
							
															
							}
							if(strcmp(listDauSach.nodes[check]->listSach.pHead->data.viTri, viTri) != 0){
									for (NODE_DANH_MUC_SACH* k = listDauSach.nodes[check]->listSach.pHead; k != NULL; k = k->pNext) {
											strcpy(k->data.viTri, viTri);
									}
							}
							Message("SUCCESS:", "Da Luu Thay Doi Dau Sach!", 1, 1000);
						}
						return TAB;
					}
			    	break;
			    case ESC:
			        return c;
			}
		}while(1);
	}
	else if(state == "DELETE"){
		do{
			type = 4;
			c = InputValue(50, temp, x, y, type);
			switch (c) {				
			    case EX_INSERT:
			    case EX_DEL:
			    	ClearButtonYesNo(22);
			    	
			        return c;
				case TAB:
					temp = "";
					strcpy(tacGia, temp.c_str());
				    strcpy(tenSach, temp.c_str());
				    strcpy(theLoai, temp.c_str());
				    strcpy(viTri, temp.c_str());
			        return c;
			    case EX_LEFT:
			    case EX_RIGHT:
					if(index < 7) break;
					is_delete = is_delete == 1 ? 0 : 1;
			    	DrawTitleYesNo(38, is_delete, state);
			        break;
			    case ENTER:
					if (index == 7) {
						if(is_delete == 0 && listDauSach.nodes[check]->luotMuon == 0) {
							XoaDauSach(listDauSach, check);
							Message("SUCCESS:", "Xoa Thanh Cong", 1, 1000);
						} else if(is_delete == 0 && listDauSach.nodes[check]->luotMuon > 0){
							Message("ERROR:", "Khong The Xoa. Dau Sach Nay Da Co Du Lieu Muon Tra!", 0, 1000);
						}
						return TAB;
					}
			    	break;
			    case ESC:
			        return c;
			}
		}while(1);
	}
	
	
}

bool CheckTrungMax(DS_DAU_SACH temp, int lenArr, char isbn[]) {//Neu dau sach da ton tai trong mang tra ve false
	for(int i=0; i<lenArr; i++) {
		if(strcmp(temp.nodes[i]->isbn, isbn)==0) {
			return false;
		}
	}
	return true;
}

void getTop10(DS_DAU_SACH ds, DS_DAU_SACH &temp){
	DAUSACH *max;
	temp.sl = 0;
	for(int i = 0; i < ds.sl; i++){
		temp.nodes[i] = ds.nodes[i];
		temp.sl++;
	}
	
	for (int i = 0; i < temp.sl - 1; i++) {
		for (int j = i + 1; j < temp.sl; j++) {
			if(temp.nodes[i]->luotMuon < temp.nodes[j]->luotMuon){
				max = temp.nodes[i];
				temp.nodes[i] = temp.nodes[j];
				temp.nodes[j] = max;
			}
		}
	}

}

void PrintDataTop10(DS_DAU_SACH ds){
	int c, a, b = -1;
	DS_DAU_SACH temp;
	getTop10(ds, temp);
	if(temp.sl == 0){
		Message("ERROR:", "Danh Sach Dau Sach Rong!", 0, 1000);
		ClearTable(1);
		return;
	}
	
	int stt = 0, pointX = 62, pointY = 8, x = 57, y = 6;
	int select = 0;
	string keyword = "";
	DAUSACH *d;
	Message("SUCCESS:", "Load Du Lieu Dau Sach Thanh Cong!", 1, 500);
	DrawTableTop10DauSach();
	Traverse_Top10DauSach(temp, pointX, pointY, stt);
	DrawArrowTable(62, 8, select, 0, stt);
	PrintSearchInput(62, keyword);
	do {
	    c = InputSearch(keyword, x, y, 50);
	    switch (c) {
	    	case EX_UP:
	    	case EX_DOWN:
	    		if (c == EX_UP &&select + 1 > 1) select--; 
		        else if (c == EX_DOWN && select + 1 < stt) select++;
		        
	    		DrawArrowTable(62, 8, select, 0, stt);
	    		PrintSearchInput(62, keyword);
	    		break;
			case ENTER:{
				break;
			}
			case ESC:
				HideTyping();
				ClearTable(1);
				return;
		}	
	} while(1);
}

void PrintDataDauSach(DS_DAU_SACH &ds,  int tab, string state){
	int c, a, b = -1;
	SortDS(ds);
	if(ds.sl == 0){
		Message("ERROR:", "Danh Sach Rong!", 0, 1000);
		ClearTable(1);
		return;
	}
	
	if(tab == 2){
		ClearTable(0);
		do{
			a = ThemDauSach(ds, "NEW", b);
			if(a == TAB){
				tab = 1;
				ClearTable(0);
				break;
			}else if(a == ESC) {
				ClearTable(1);
				return;
			}else if(a == EX_F3 || a == EX_DEL){
				Message("ERROR:", "Ban Dang Tao Moi Khong The Xoa Sua!", 0, 1500);
			}
		}while(1);
	}
	
	int stt = 0, pointX = 42, pointY = 8, x = 52, y = 6;
	int total = ds.sl;

	int n = (int)ceil((double)total/15);
	int currentPage = 0, select = 0;
	string keyword = "";
	DS_DAU_SACH search;
	DAUSACH *d;
	
	Message("SUCCESS:", "Load Du Lieu Dau Sach Thanh Cong!", 1, 500);
	PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
	DrawTableDauSach(1, tab);
	Traverse_DauSach(ds, pointX, pointY, currentPage, stt, keyword, total);
	DrawArrowTable(42, 8, select, currentPage, stt);
	PrintSearchInput(42, keyword);
	do {
	    c = InputSearch(keyword, x, y, 50);
	    switch (c) {
	    	case EX_UP:
	    	case EX_DOWN:
	    		if (c == EX_UP &&select + 1 > 1) select--; 
		        else if (c == EX_DOWN && select + 1 < stt) select++;
		        
	    		DrawArrowTable(42, 8, select, currentPage, stt);
	    		PrintSearchInput(42, keyword);
	    		break;
		    case EX_PAGEUP:
		    case EX_PAGEDOWN:
		    	if(tab > 1) break;
		    	
		    	if (c == EX_PAGEUP &&currentPage + 1 > 1) currentPage--; 
		        else if (c == EX_PAGEDOWN && currentPage + 1 < n) currentPage++;
		        
		        HideTyping();
		        Traverse_DauSach(ds, pointX, pointY, currentPage, stt, keyword, total);
		        n = (int)ceil((double)total/15);
				PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
				
				if(currentPage == n-1)
						ClearRemainDauSach(stt, pointX, pointY);
						
				DrawArrowTable(42, 8, select = 0, currentPage, stt);
				PrintSearchInput(42, keyword);
				break;
			case CTRL_F:
					Traverse_DauSach(ds, pointX, pointY, currentPage = 0, stt = 0, keyword, total);
					ClearRemainDauSach(stt, pointX, pointY = 8);
					n = (int)ceil((double)total/15);
					PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
					DrawArrowTable(pointX, 8, select = 0, currentPage, stt);
					PrintSearchInput(42, keyword);
		    	break;
			case ENTER:{
				
				b = Search_DauSach_By_STT_Plus(ds, keyword, currentPage, select);
				if(ds.nodes[b]->soLuong == 0){
					Message("ERROR:", "So luong bang 0", 0, 1000);
					SetColor(GREEN);
					GoToXY(34, 43);
					break;
				}
				ClearTable(1);
				PrintDataSach(ds.nodes[b], 1, "NEW");
				PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
				DrawTableDauSach(1, tab);
				Traverse_DauSach(ds, pointX, pointY, currentPage, stt, keyword, total);
				DrawArrowTable(42, 8, select, currentPage, stt);
				PrintSearchInput(42, keyword);
				break;
			}
			case EX_INSERT: {
				b = Search_Info_DauSach_By_STT(ds, currentPage, select);
				select = 0;
				ClearTable(1);
				do {
					a = ThemDauSach(ds, "EDIT", b);
					if(a == TAB){
							x = 57, y = 6;
							tab = 1;
							ClearTable(0);
						    PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
							DrawTableDauSach(1, tab);
							SortDS(ds);
							Traverse_DauSach(ds, pointX, pointY = 8, currentPage, stt, keyword, total);
							DrawArrowTable(42, 8, select = 0, currentPage, stt);
							PrintSearchInput(42, keyword);
							break;
						}else if(a == ESC) {
							ClearTable(1);
							return;
						}else if(a == EX_F3 || a == EX_DEL){
							Message("ERROR:", "Ban Dang Tao Moi Khong The Xoa Sua!", 0, 1500);
						}
				} while(1);
				break;
			}
			case EX_DEL:{
				
				b = Search_Info_DauSach_By_STT(ds, currentPage, select);
				select = 0;
				ClearTable(1);
				do {
					a = ThemDauSach(ds, "DELETE", b);
					if(a == TAB){
							x = 57, y = 6;
							tab = 1;
							ClearTable(0);
						    PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
							DrawTableDauSach(1, tab);
							SortDS(ds);
							Traverse_DauSach(ds, pointX, pointY = 8, currentPage, stt, keyword, total);
							DrawArrowTable(42, 8, select = 0, currentPage, stt);
							PrintSearchInput(42, keyword);
							break;
						}else if(a == ESC) {
							ClearTable(1);
							return;
						}else if(a == EX_F3 || a == EX_DEL){
							Message("ERROR:", "Ban Dang Tao Moi Khong The Xoa Sua!", 0, 1500);
						}
				} while(1);
				break;
			}
			case ESC:
				HideTyping();
				ClearTable(1);
				return;
		}	
	} while(1);
}

void Traverse_DauSach(DS_DAU_SACH listDauSach, int &pointX, int pointY, int currentPage, int &stt, string keyword, int &total){
	int n = (currentPage)*15; 
	int m = (currentPage+1)*15;
	if(m > listDauSach.sl) m = listDauSach.sl; 
	stt = 0;
	if(keyword.length() == 0){
		total = listDauSach.sl;
		for(int i = n ; i < m ; i++){
			stt++;
			CoutNodeDauSach(listDauSach.nodes[i], (i+1), pointX, pointY+=2);
		}
		return;
	}
	int index = -1;
	int stt2 = 0;
	for(int i = 0 ; i < listDauSach.sl; i++){
		string tenSach = convertToString(listDauSach.nodes[i]->tenSach, strlen(listDauSach.nodes[i]->tenSach));
		if(tenSach.find(keyword) != string::npos){
			stt++;
			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1) {
				stt2++;
				CoutNodeDauSach(listDauSach.nodes[i], (i+1), pointX, pointY+=2);
			}
		}
	}	
	total = stt;
	stt = stt2;
}

void Traverse_Top10DauSach(DS_DAU_SACH listDauSach, int &pointX, int pointY, int &stt){
	stt = 0;
	int sl = listDauSach.sl;
	int j = sl > 10 ? 10 : sl;
	for(int i = 0 ; i < j ; i++){
		if(listDauSach.nodes[i]->luotMuon > 0){
		stt++;
		CoutNodeTop10DauSach(listDauSach.nodes[i], (i+1), pointX, pointY+=2);
		}
	}
}


int Search_DauSach_By_STT1(DS_DAU_SACH dsds, string keyword, int currentPage, int select){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > dsds.sl) m = dsds.sl; 
	
	int  j = 0;
	for ( int i = n ; i < m ; i++){
		string tenSach = convertToString(dsds.nodes[i]->tenSach, strlen(dsds.nodes[i]->tenSach));
	   	if(tenSach.find(keyword) != string::npos){
		   	if (j == select) return i;
			j++;
		}
	}
	return -1;
}

DAUSACH* Search_DauSach_By_STT(DS_DAU_SACH dsds, string keyword, int currentPage, int select){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > dsds.sl) m = dsds.sl; 
	
	DAUSACH *ds;
	ds = new DAUSACH;
	int  j = 0;
	for ( int i = n ; i < m ; i++){
		string tenSach = convertToString(dsds.nodes[i]->tenSach, strlen(dsds.nodes[i]->tenSach));
	   	if(tenSach.find(keyword) != string::npos){
		   	if (j == select) {
		   		return dsds.nodes[i];	
			}
			j++;
		}
	}
	return ds;
}

int Search_Info_DauSach_By_STT(DS_DAU_SACH dsds, int currentPage, int select){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > dsds.sl) m = dsds.sl; 
	
	int  j = 0;
	for ( int i = n ; i < m ; i++){
		if (j == select) return i;
		j++;
	}
	return -1;
}

int Search_DauSach_By_STT_Plus(DS_DAU_SACH dsds, string keyword, int currentPage, int select){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > dsds.sl) m = dsds.sl; 
	
	int  j = 0;
	for ( int i = n ; i < m ; i++){
		string tenSach = convertToString(dsds.nodes[i]->tenSach, strlen(dsds.nodes[i]->tenSach));
	   	if(tenSach.find(keyword) != string::npos){
		   	if (j == select) return i;
			j++;
		}
	}
	return -1;
}

DAUSACH* Search_DauSach_By_ISBN(DS_DAU_SACH dsds, char isbn[10]){
	
	DAUSACH *ds;
	ds = new DAUSACH;
	
	for ( int i = 0 ; i < dsds.sl ; i++){
	   	if(strcmp(isbn,dsds.nodes[i]->isbn) == 0){
		   		return dsds.nodes[i];	
			}
		}
	
	return ds;
}

DS_DAU_SACH Search_DauSach(DS_DAU_SACH &dsds, string input){
	int i, j=-1;
	DS_DAU_SACH temp;
	temp.sl = 0;
	for(i = 0; i < dsds.sl; i++) {
		string tenSach = convertToString(dsds.nodes[i]->tenSach, strlen(dsds.nodes[i]->tenSach));
		int search = tenSach.find(input);
		if(search != -1) {
			temp.nodes[++j] = dsds.nodes[i];
			temp.sl++;
		}
	}
	return temp;
}

int CompareDS(DAUSACH *a, DAUSACH *b, int type) {//type=0: so sanh theo the loai; else: so sanh theo ten
	if(type == 0) {
		return strcmp(a->theLoai, b->theLoai);
	}
	return strcmp(a->tenSach, b->tenSach);
}

void SortDS(DS_DAU_SACH &dsds) {
	DAUSACH* temp;
	int type;
	type=0;//sort theo the loai
	for (int i = 0; i < dsds.sl - 1; i++) {
		for (int j = i + 1; j < dsds.sl; j++) {
			if (CompareDS(dsds.nodes[i], dsds.nodes[j], type)>0) {
				temp = dsds.nodes[i];
				dsds.nodes[i] = dsds.nodes[j];
				dsds.nodes[j] = temp;
			} else if(CompareDS(dsds.nodes[i], dsds.nodes[j], type)==0) {
				type=1;
				if (CompareDS(dsds.nodes[i], dsds.nodes[j], type)>0) {
					temp = dsds.nodes[i];
					dsds.nodes[i] = dsds.nodes[j];
					dsds.nodes[j] = temp;
				}
			}
			type=0;
		}
	}
}

void Load_DauSach(DS_DAU_SACH &ds){ 
	char filename[50] = "data\\dauSach.txt";
	char fileSach[50] = "data\\Sach.txt";
	
	ifstream file1(fileSach);
  	ifstream file(filename);
	
	if (!file.is_open() || !file1.is_open())
	{
		cout<<"file khong ton tai";
		return;
	}
	BOOK b;
	ds.sl = 0;
	string temp;
	DAUSACH *dauSach;
	int i = -1;
	while (!file.eof())
	{
		
		getline(file, temp, ',');
		if(temp == "\n" || temp == "") break;
		
		dauSach = new DAUSACH;
		strcpy(dauSach->isbn, temp.c_str());
		
		getline(file, temp, ',');
		strcpy(dauSach->tenSach, temp.c_str());

		getline(file, temp, ',');
		sscanf(temp.c_str(), "%d", &dauSach->soTrang);
		
		getline(file, temp, ',');
		strcpy(dauSach->tacGia, temp.c_str());
		
		getline(file, temp, ',');
		sscanf(temp.c_str(), "%d", &dauSach->namXuatBan);
		
		getline(file, temp, ',');
		strcpy(dauSach->theLoai, temp.c_str());
		
		getline(file, temp, ',');
		sscanf(temp.c_str(), "%d", &dauSach->soLuong);
		KhoiTao(dauSach->listSach);
		Doc_ds_danh_muc(file1, dauSach->listSach, b, dauSach->soLuong);
		
		getline(file, temp);
		sscanf(temp.c_str(), "%d", &dauSach->luotMuon);
		
		
		if (ds.sl == MAXDAUSACH - 1) {
			cout<<"Danh sach dau sach day";
			return;
		}
	
		ds.nodes[++i] = dauSach;
		ds.sl++;
	}
	file1.close();
	file.close();
}

void SaveDauSach(DS_DAU_SACH ds){	
    ofstream file;
    ofstream fileout;
	file.open("data\\dauSach.txt", ios::out);
	fileout.open("data\\sach.txt", ios::out);
    if(ds.sl == 0) return;
    for(int i = 0; i < ds.sl; i++){
    	file << ds.nodes[i]->isbn << ","; 
		file << ds.nodes[i]->tenSach << ",";
		file << ds.nodes[i]->soTrang << ","; 
		file << ds.nodes[i]->tacGia << "," ;
		file << ds.nodes[i]->namXuatBan << ",";
		file << ds.nodes[i]->theLoai << ",";
		file << ds.nodes[i]->soLuong << ",";
		file << ds.nodes[i]->luotMuon << "\n";
		for (NODE_DANH_MUC_SACH* k = ds.nodes[i]->listSach.pHead; k != NULL; k = k->pNext) {
				fileout << k->data.maSach << ",";
				fileout << k->data.trangThai << ",";
				fileout << k->data.viTri;
				if (k->pNext == NULL) {
					fileout << endl;
					break;
				}
				fileout << endl;
			}
	}
	fileout.close();
	file.close();
}


void GetTopTenDauSach(DS_DAU_SACH ds, DS_DAU_SACH temp) {
	int i, j, n=ds.sl;
	DAUSACH *max;
	int sl = 0;
	for(i=0; i<10; i++) {
		max = new DAUSACH;
		max = ds.nodes[0];
		for(j=1; j<n; j++) {
			if(max->luotMuon<=ds.nodes[j]->luotMuon) {
					max=ds.nodes[j];
			}
		}
		temp.nodes[sl] = max;
		sl++;
	}
}

int Insert_DauSach(DS_DAU_SACH& listDauSach, DAUSACH *ds) {
	if(listDauSach.sl + 1 <= MAXDAUSACH){
		listDauSach.sl++;
		listDauSach.nodes[listDauSach.sl - 1] = ds;
		return 1;
	}
	return 0;
}

void traverse(DS_DAU_SACH dsds, char *isbn){
	for(int i = 0; i < dsds.sl; i++){
		if(strcmp(dsds.nodes[i]->isbn, isbn) == 0){
			XuatDS(dsds.nodes[i]->listSach);
		}
	}
}
bool isISBN(char isbn[10], DS_DAU_SACH listDauSach){
	for(int i = 0; i < listDauSach.sl; i++){
		if(strcmp(isbn, listDauSach.nodes[i]->isbn) == 0){
			return true;
		}
	}
	return false;
}


void  Delete_Item_DauSach(DS_DAU_SACH &dsds, int pos) {
	for(int i = pos; i <dsds.sl; i++) {
		dsds.nodes[i-1] = dsds.nodes[i];
	}
	dsds.sl--;
}




// ===================================================================end dau sach========================================================================
// ===================================================================danh muc sach=======================================================================
void DrawBoderSuaSach(string title){
	int pointX = 55, pointY = 5, width = 90, height = 25;
	
	SetColor(RED);
	GoToXY(pointX+30, pointY+2);
	printf("%-50s", title.c_str());
	SetColor(BLACK);
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else cout << char(HORIZONTAL_LINE);
			}
		}else {
			cout << char(VERTICAL_LINE);
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	
	for(int i = 0; i < NUMBER_ITEM_SACHTEXT; i++){
		GoToXY(pointX+5, pointY+6+i*4);
		printf("%-30s", ThemSachText[i]);
		DrawInput(85, pointY+5+i*4);
	}
	
	
	GoToXY(87, 8);
	Typing();

}

void DrawInputStatusSach(int pointX, int pointY, int status, int type){
	HideTyping();
	GoToXY(pointX, pointY);
	
	SetColor(BLACK);
	
	if(status == 0){
		SetColor(WHITE);
		SetBGColor(GREEN);
	}
	cout << "     Cho Muon Duoc     ";
	
	SetColor(BLACK);
	SetBGColor(WHITE);
	cout << char(219);
	SetColor(BLACK);
	SetBGColor(WHITE);
	
	if(status == 2){
		SetColor(WHITE);
		SetBGColor(GREEN);
	}
	if(type == 1){
		cout << "       Da Thanh Ly        ";	
	} else if(type == 0){
		cout << "         Thanh Ly         ";
	}
	
	SetBGColor(WHITE);
	SetColor(BLACK);
}

int SuaSach(LIST_DANH_MUC &list, NODE_DANH_MUC_SACH* p){
	HideTyping();
	int x = 87, y = 11;
	string temp = "";
	string status;
	int c, type = 2, index = 0, is_delete = 0, length = 50, status1 = 1;
	char maSach[15];
	int trangThai;
	char viTri[20];

			DrawBoderSuaSach("");
			DrawButtonYesNo(23, "EDIT");
	
			GoToXY(x, y);
			SetColor(RED);
			printf("%-50s", p->data.maSach);	
			SetColor(BLACK);
							
			GoToXY(x, y+=4);
			DrawInputStatusSach(x, y, p->data.trangThai, 0);
						
			GoToXY(x, y+=4);
			printf("%-50s", p->data.viTri);

			y = y-4, type = 4, index++;
			temp = p->data.maSach;
			length = 15;
			GoToXY(x+temp.length(), y);
			
			do{
				c = InputValue(50, temp, x, y, type);
				switch (c) {				
			    case EX_INSERT:
			    case EX_DEL:
			    	ClearButtonYesNo(22);
			       
				case TAB:
			        
			    case EX_LEFT:
			    case EX_RIGHT:
			    	if(index == 1){
						status1 = status1 == 2 ? 0 : 2;
						DrawInputStatusSach(x, y, status1, 0);
						
					} else if(index == 3){
						is_delete = is_delete == 1 ? 0 : 1;
			    		DrawTitleYesNo(24, is_delete, "EDIT");
					}
			        break;
			    case ENTER:
			    	if(temp[temp.length()-1] == SPACE) temp = temp.substr(0, temp.length()-1);
			    	if(!(index == 3 || index == 4) && temp.length() == 0 ) {
						Message("ERROR:", "Vui long khong de trong!", 0, 1000);
						GoToXY(x+temp.length(), y);
						break;
					}

					if(index == 1){
//						b.trangThai = status1;
						length = 10;
						index+=2;
						DrawTitleYesNo(24, is_delete, "EDIT");
					}else if(index == 3){
						GoToXY(x, y-4);
						printf("%-50s"," ");
						p->data.trangThai = status1;
						if(is_delete == 0) {
							Message("SUCCESS:", "Luu Doc Gia Thanh Cong!", 1, 1000);
						}
//						SuaNodeBatKi(list, b);
						status1 = 0;
						return 0;
					}
					break;
				case ESC:
					ClearTable(0);
					return c;
			}
			
		}while(1);
//	}
}

BOOK SearchDMS(LIST_DANH_MUC list, string keyword, int currentPage, int select, int sl,int st){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > sl) m = sl; 
	int stt = 0;
	int stt2 = 0;
	
	for (NODE_DANH_MUC_SACH* k = list.pHead; k != NULL; k = k->pNext){
			stt++;
			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1 && stt - 1 == (select + currentPage*15))  {
			stt2++;
			return k->data;	
			}	
		}
	stt = stt2;
	
}

void SuaNodeBatKi(LIST_DANH_MUC& l, BOOK b) {
	//N?u node n?m d?u danh sách
	if (strcmp(l.pHead->data.maSach, b.maSach) == 0) {
		l.pHead->data.trangThai = b.trangThai;
		return;
	}
	//N?u node n?m cu?i danh sách
	if (strcmp(l.pTail->data.maSach, b.maSach) == 0) {
		l.pTail->data.trangThai = b.trangThai;
		return;
	}
	//Duy?t danh sách d? tìm
	for (NODE_DANH_MUC_SACH* k = l.pHead; k != NULL; k = k->pNext) {
		//Phát hi?n
		if (strcmp(k->data.maSach, b.maSach) == 0) {
			k->data.trangThai = b.trangThai;
			return;
		}
	}

}

void PrintDataSach(DAUSACH *ds, int tab, string state){
	int c, a;
	
	int stt = 0, pointX = 47, pointY = 8, x = 57, y = 6;
	int total = ds->soLuong;

	int n = (int)ceil((double)total/15);
	int currentPage = 0, select = 0;
	int currentPage1 = 0;
	string keyword = "";
	DAUSACH *d;
	
	Message("SUCCESS:", "Load Du Lieu Sach Thanh Cong!", 1, 500);
	PrintPageTable(n > 0 ? currentPage1+1 : 0, n, 140);
	DrawTableSach();
	Traverse_Sach(ds->listSach, pointX, pointY, currentPage, stt, keyword, total, ds->soLuong);
	DrawArrowTable(47, 8, select, currentPage1, stt);
	PrintSearchInput(47, keyword);

	do {
	    c = InputSearch(keyword, x, y, 50);
	    switch (c) {
	    	case EX_UP:
	    	case EX_DOWN:
	    		if (c == EX_UP &&select + 1 > 1) select--; 
		        else if (c == EX_DOWN && select + 1 < stt) select++;
		        
	    		DrawArrowTable(47, 8, select, currentPage, stt);
	    		PrintSearchInput(47, keyword);
	    		break;
		    case EX_PAGEUP:
		    case EX_PAGEDOWN:
		    	if(tab > 1) break;
		    	
		    	if (c == EX_PAGEUP &&currentPage + 1 > 1) currentPage--; 
		        else if (c == EX_PAGEDOWN && currentPage + 1 < n) currentPage++;
		        
		        HideTyping();
		        Traverse_Sach(ds->listSach, pointX, pointY, currentPage, stt, keyword, total, ds->soLuong);
		        n = (int)ceil((double)total/15);
				PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
				
				if(currentPage == n-1)
						ClearRemainSach(stt, pointX, pointY);
						
				DrawArrowTable(47, 8, select = 0, currentPage, stt);
				PrintSearchInput(47, keyword);
				break;
			case CTRL_F:
		    	break;
			case ENTER:{
//				BOOK b;
				NODE_DANH_MUC_SACH* h;
//				b = SearchDMS(ds->listSach, keyword, currentPage, select, ds->soLuong, n);
				h= SearchNodeDMS(ds->listSach, keyword, currentPage, select, ds->soLuong, n);
				
				if(h->data.trangThai == 2){
					Message("ERROR", "Sach Da Thanh Ly. Khong The Sua Hoac Cho Muon !!!", 0, 1000);
					PrintSearchInput(47, keyword);
					break;
				} else if(h->data.trangThai == 1){
					Message("ERROR", "Sach Dang Muon. Khong The Sua !!!", 0, 1000);
					PrintSearchInput(47, keyword);
					break;
				}
				
				ClearTable(1);
				DrawTitle(EditText[3], 92);
				do{
								
				 			a = SuaSach(ds->listSach, h);
							if(a == 0){
							x = 57, y = 6;
							tab = 1;
							ClearTable(0);
					    	PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
							DrawTableSach();
		        			Traverse_Sach(ds->listSach, pointX, pointY, currentPage, stt, keyword, total, ds->soLuong);
							DrawArrowTable(47, 8, select, currentPage, stt);
							PrintSearchInput(47, keyword);
							//p = NULL;
							break;
							}else if(a == ESC) {
								ClearTable(1);
								return;
							}
				}while(1);
			}
			case EX_INSERT:
			case TAB:
			case ESC:
				ClearTable(1);
				return;
		}	
	} while(1);
}

void DrawTableSach(){
	int pointX = 45, pointY = 5, width = 106, height = 37;
	int col1 = 8, col2 = 34, col3 = 63;
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3)
					if(i > 0 && i < height-2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-2)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(HORIZONTAL_LINE);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else if(i%2 == 0){
			for(int j = 0; j < width; j++){
				if(j == 0)
					cout << char(LEFT_CENTER_SIMPLE);
				else if(j == width-1)
					cout << char(RIGHT_CENTER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3)
					if(i == 2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-3)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(PLUS_CENTER);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else {
			cout << char(VERTICAL_LINE);
			
			if(i > 2 && i < height - 2){
				GoToXY(pointX+col1, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col2, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col3, pointY+i);
				cout << char(VERTICAL_LINE);
			}
			
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	CountHeaderSachTable(pointX+2, pointY+3);
	
	DrawHuongDanTable(70, 40, SachFunctionText, NUMBER_ITEM_SACH_FUNCTION_TEXT);
		
	DrawTitle(TitleText[1], 90);
}



void CountHeaderSachTable(int pointX, int pointY){
	GoToXY(pointX, pointY); cout << "STT";
	GoToXY(pointX + 8, pointY); cout << "MA SACH";
	GoToXY(pointX + 34, pointY); cout << "TRANG THAI";
	GoToXY(pointX + 63, pointY); cout << "VI TRI";
}

void CoutNodeSach(BOOK s, int stt, int pointX, int pointY){
	HideTyping();
	char trangThai [20];
	if(s.trangThai == 0){
		strcpy(trangThai, "Cho muon duoc");
	} else if(s.trangThai == 1){
		strcpy(trangThai, "Da co doc gia muon");
	} else {
		strcpy(trangThai, "Da thanh ly");
	}
	GoToXY(pointX, pointY); printf("%-6d", stt);
	GoToXY(pointX + 8, pointY); printf("%-11s", s.maSach);
	GoToXY(pointX + 34, pointY); printf("%-20s", trangThai);
	GoToXY(pointX + 63, pointY); printf("%-10s", s.viTri);
	
}

void ClearRemainSach(int total, int pointX, int pointY){
	int row2 = 15-total;
	pointY = total*2+pointY;
	for(int i = 0; i < row2;i++){
	GoToXY(pointX, pointY+=2); printf("%-6s", " ");
	GoToXY(pointX + 8, pointY); printf("%-11s", " ");
	GoToXY(pointX + 34, pointY); printf("%-20s", " ");
	GoToXY(pointX + 63, pointY); printf("%-10s", " ");
	}
}


void Traverse_Sach(LIST_DANH_MUC list, int &pointX, int pointY, int currentPage, int &stt, string keyword, int &total,int sl){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > sl) m = sl; 
	stt = 0;
	int stt2 = 0;
		total = sl;
		for (NODE_DANH_MUC_SACH* k = list.pHead; k != NULL; k = k->pNext){
			stt++;
			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1) {
			stt2++;
			CoutNodeSach(k->data, stt ,pointX, pointY+=2);	
			}
	}
	total = stt;
	stt = stt2;
}

void Luu_danh_muc_tam(LIST_DANH_MUC& l){
	ofstream fileout;
	fileout.open("data\\Sach.txt", ios::out);
	for (NODE_DANH_MUC_SACH* k = l.pHead; k != NULL; k = k->pNext) {
				fileout << k->data.maSach << ",";
				fileout << k->data.trangThai << ",";
				fileout << k->data.viTri;
				if (k->pNext == NULL) {
					fileout << endl;
					break;
				}
				fileout << endl;
			}
	fileout.close();

}

void Doc_tat_ca_danh_muc(LIST_DANH_MUC& l) {
	string temp;
	BOOK b;
	ifstream file;
	
	file.open("data\\Sach.txt", ios::in);

	if (!file.is_open()) {
		cout << "undone";
		system("pause");
		return;
	}
	
	while (!file.eof()) {
		//Doc thong tin
		getline(file, temp, ',');
		if(temp == "\n" || temp == "") break;
		
		strcpy(b.maSach, temp.c_str());
		
		getline(file, temp, ',');
		sscanf(temp.c_str(), "%d", &b.trangThai);
		
		getline(file, temp);
		strcpy(b.viTri, temp.c_str());
		//Khoi tao 1 node
		NODE_DANH_MUC_SACH* p = KhoiTaoNode(b);
		//Them vao ds lien ket
		themVaoCuoi(l, p);

	
	}
	file.close();
}

void Doc_ds_danh_muc(ifstream& file, LIST_DANH_MUC& l, BOOK b, int sl) {
	if (!file.is_open()) {
		cout << "undone";
		system("pause");
		return;
	}
	int dem = 0;
	string temp;

	while (dem != sl) {
		
		getline(file, temp, ',');
		if(temp == "\n" || temp == "") break;
		
		strcpy(b.maSach, temp.c_str());
		
		getline(file, temp, ',');
		sscanf(temp.c_str(), "%d", &b.trangThai);
		
		getline(file, temp);
		strcpy(b.viTri, temp.c_str());
		//Khoi tao 1 node
		NODE_DANH_MUC_SACH* p = KhoiTaoNode(b);
		//Them vao ds lien ket
		themVaoCuoi(l, p);
		dem++;
	}
}

LIST_DANH_MUC taoList(char isbn[10], char vitri[20], int sl) {
	LIST_DANH_MUC listDM;
	KhoiTao(listDM);
	BOOK b;
	char c[20];
	char temp[20];
	for (int i = 1; i <= sl; i++) {
		itoa(i, c, 10);
		strcpy(temp, isbn);
		strcat(temp, "-");
		strcat(temp, c);
		strcpy(b.maSach, temp);
		b.trangThai = 0;
		strcpy(b.viTri,vitri);

		NODE_DANH_MUC_SACH* p = KhoiTaoNode(b);

		themVaoCuoi(listDM, p);
	}
	return listDM;
}

//Hàm khoi tao 1 node
NODE_DANH_MUC_SACH* KhoiTaoNode(BOOK b) {
	NODE_DANH_MUC_SACH* p = new NODE_DANH_MUC_SACH; //Cap phat vung nho cho NODE p
	if (p == NULL)
	{
		cout << "\nKhong du bo nho!";
		return NULL;
	}
	p->data = b;//Truyen giá tri x vào cho data
	p->pNext = NULL;
	return p; 
}


void themVaoCuoi(LIST_DANH_MUC& l, NODE_DANH_MUC_SACH* p) {
	// neu danh sach rong
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p; //Node dau cung là node cuoi và là p
	}
	else {
		l.pTail->pNext = p; 
		l.pTail = p; 
	}
}

void KhoiTao(LIST_DANH_MUC& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

//Xuat
void xuat(BOOK b) {
	cout << "Ma sach: " << b.maSach;
	cout << "\t\tTrang thai: " << b.trangThai;
	cout << "\t\tVi tri: " << b.viTri;
	cout << "\n"; 
}
//Hàm xu?t danh sách liên k?t ??n
void XuatDS(LIST_DANH_MUC l) {
	int dem = 0; 
	for (NODE_DANH_MUC_SACH* k = l.pHead; k != NULL; k = k->pNext) {
		dem++;
		cout << dem <<". ";
		xuat(k->data);
	}
}
// =======================================================end========================================
// ==================================================================doc gia
void KhoiTaoCay(TREE& t) {
	t = NULL;
}

void DocDuLieuDocGia(TREE &t){
	MUONTRA m;

	KhoiTaoCay(t);

	fstream filein;
	TheDocGia tdg;
	int soDocGia;
	int soSach;
	int index;
	filein.open("data\\docGia.txt", ios::in);

	if (filein.is_open()){
		string temp;
		filein >> soDocGia;
		for (int i = 0; i < soDocGia; i++)
		{
			NODETHEDOCGIA *p = new NODETHEDOCGIA;
			
			filein >> tdg.MATHE;
			getline(filein, temp);
			getline(filein, tdg.Ho);
			getline(filein, tdg.Ten);
			filein >> tdg.Phai;
			filein >> tdg.TrangThai;
			filein >> tdg.soLuongDangMuon;
			filein >> tdg.tongSoLuong;
		//	ThemNodeVaoCay(t, tdg);

			if(tdg.tongSoLuong != 0){
			
			KhoiTaoMuonTra(tdg.listMuonTra);
			for(int i = 0; i < tdg.tongSoLuong; i++){
				//Doc thong tin
				getline(filein, temp);
				getline(filein, temp);
				strcpy(m.ma_sach, temp.c_str()); // d?c d?n d?u ','
				filein >> m.ngay_muon.day ;
				filein >> m.ngay_muon.month;
				filein >> m.ngay_muon.year;
				filein >> m.ngay_tra.day;
				filein >> m.ngay_tra.month;
				filein >> m.ngay_tra.year;
				filein >> m.trang_thai;
				
				NODE_MUON_TRA* q = KhoiTaoNodeMuonTra(m);
				themVaoCuoiMT(tdg.listMuonTra, q);
			}
		}
			ThemNodeVaoCay(t, tdg);

		}
	}
	else cout << "Loi ket noi file! ";
	filein.close();
}

int ThemNodeVaoCay(TREE& t, TheDocGia x) {

	//neu cay rong
	if (t == NULL) {
		NODETHEDOCGIA* p = new NODETHEDOCGIA;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;//node p chinh la goc
	//	KhoiTaoMuonTra(p->data.listMuonTra);

		return 1;
	}
	else {

		//cay co ton tai phan tu
		if (t->data.MATHE > x.MATHE) {
			ThemNodeVaoCay(t->pLeft, x);
				//	KhoiTaoMuonTra(t->data.listMuonTra);

			return 1;
		}
		else if (t->data.MATHE < x.MATHE) {
			ThemNodeVaoCay(t->pRight, x);
				//	KhoiTaoMuonTra(t->data.listMuonTra);

			return 1;
		}

	}
	return 0;
}

unsigned int Random()
{
	srand(time(0));
	int x = rand();
	return x;
}

void PrintDataDocGia(int tab, string state, TREE &tree, int type){
	
	TREE docGia = NULL, temp = NULL;
	TheDocGia p;
	int c, a;
	
	if(state !="NEW" && tree == NULL){
		Message("ERROR:", "Danh Sach Doc Gia Rong!", 0, 1000);
		return;
	}
	
	if(type == 1){
		Inorder(tree, docGia);	
	} else {
		InDanhSachDocGiaTheoTenHo(tree, temp);
		Inorder(temp, docGia);
	}
	
	
	
	if(tab == 2){
		ClearTable(1);
		DrawTitle(EditText[1], 87);
		do{
			a = ThemDocGia(tree, state, p);
			HideTyping();
			
			switch(a){
				case 0:
					break;				
				case EX_DEL:
					Message("ERROR:", "Dang Tao Moi Khong The Xoa Sua!", 0, 1000);
					break;
				case ESC:
					ClearTable(1);
		        	return;
				}
			if(a==0) break;
		} while (1);
		ClearTable(1);
		tab = 1;
	}
	
	if(tree == NULL){
		Message("ERROR:", "Danh Sach Doc Gia Rong!", 0, 1000);
		ClearTable(1);
		return;
	}
	
	int stt = 0, pointX = 47, pointY = 8, x = 57, y = 6;
	int total = DemSoDocGia(tree);
	int n = (int)ceil((double)total/15);
	int currentPage = 0, select = 0;
	string keyword = "";
	
	TREE *pages = new TREE[n];
	
	
	Message("SUCCESS:", "Load Du Lieu Doc Gia  Thanh Cong!", 1, 500);
	PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
	DrawTableDocGia();
	Traverse_DocGia(docGia, stt, pointX, pointY, currentPage);
	DrawArrowTable(47, 8, select, currentPage, stt);
	PrintSearchInput(47, keyword);
	
	do {
	    c = InputSearch(keyword, x, y, 50);
	    switch (c) {
	    	case EX_UP:
	    	case EX_DOWN:
	    		if (c == EX_UP &&select + 1 > 1) select--; 
		        else if (c == EX_DOWN && select + 1 < stt) select++;
		        
	    		DrawArrowTable(47, 8, select, currentPage, stt);
	    		PrintSearchInput(47, keyword);
	    		break;
		    case EX_PAGEUP:
		    case EX_PAGEDOWN:
		    	if(tab ==  2) break;
		    	
		    	if (c == EX_PAGEUP &&currentPage + 1 > 1) currentPage--; 
		        else if (c == EX_PAGEDOWN && currentPage + 1 < n) currentPage++;
		        
		        HideTyping();
				Traverse_DocGia(docGia, stt = 0, pointX, pointY, currentPage);
				PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
				
				if(currentPage == n-1)
						ClearRemainDocGia(stt, pointX, pointY, currentPage);
				DrawArrowTable(47, 8, select = 0, currentPage, stt);
				PrintSearchInput(47, keyword);
				
		        break;
//		    case EX_INSERT: 
//		    case TAB: 
//		    	tab = (tab == 1) ? 2 : 1;
//		    	DrawTitleTable(87, 1, tab, DocGiaText);
//		    	if(tab == 1){
//		    		x = 57, y = 6;
//		    		ClearTable(0);
//		    		PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
//					DrawTableDocGia(1);
//					Traverse_DocGia(docGia, stt = 0, pointX, pointY, currentPage);
//					DrawArrowTable(47, 8, select, currentPage, stt);
//					PrintSearchInput(47, keyword);
//				}else{
//					ClearTable(0);
//					do{
//						a = ThemDocGia(tree, docGia, "NEW", p);
//						if(a == 0){
//							x = 57, y = 6;
//							tab = 1;
//							ClearTable(0);
//				    		PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
//							DrawTableDocGia(1);
//							Traverse_DocGia(docGia, stt = 0, pointX, pointY = 8, currentPage);
//							DrawArrowTable(47, 8, select, currentPage, stt);
//							PrintSearchInput(47, keyword);
//							break;
//						}else if(a == ESC) {
//							ClearTable(1);
//							return;
//						}else if(a == EX_F3 || a == EX_DEL){
//							Message("ERROR:", "Ban Dang Tao Moi Khong The Xoa Sua!", 0, 1500);
//						} 
//					}while(1);
//				}
//		    	break;
			case CTRL_F:
		    	
				break;			
			case EX_DEL:
			case ENTER:
				{
					if(stt == 0){
						Message("ERROR:", "Doc Gia Khong Hop Le!", 0, 500);
						GoToXY(x+keyword.length(), y);
						break;
					}
					
					tab = 2;
			    	if(select > -1){
			    		p = Search_By_STT_DSDG(docGia, select, currentPage);
			    		select = 0;
					}
					
					ClearTable(1);
//					DrawTitleTable(87, 1, tab, DocGiaText);
					string state2 = c == EX_DEL ? "DELETE" : "EDIT";
					do{
						a = ThemDocGia(tree, state2, p);
						if(a == 0){
							docGia = NULL;
							temp = NULL;
							
							if(type == 1){
									Inorder(tree, docGia);	
							} else {
									InDanhSachDocGiaTheoTenHo(tree, temp);
									Inorder(temp, docGia);
							}
							x = 57, y = 6;
							tab = 1;
							ClearTable(1);
							
					    	PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
							DrawTableDocGia();
							Traverse_DocGia(docGia, stt = 0, pointX, pointY = 8, currentPage);
							DrawArrowTable(47, 8, select, currentPage, stt);
							PrintSearchInput(47, keyword);
							break;
						}else if(a == ESC) {
							ClearTable(1);
							return;
						}else {
							if(state2 == "NEW"){
								Message("ERROR:", "Ban Dang Tao Moi Khong The Xoa Sua!", 0, 1500);
							}else{
								HideTyping();
								state2 = a == EX_INSERT ? "NEW" : ( a == EX_F3 ? "EDIT" : "DELETE");
							}
							
						} 
					}while(1);
					break;
				}
		    case ESC:		    	
		    	ClearTable(1);
		        return;
	    }
	} while (1);
}


void Traverse_DocGia(TREE DSDG, int &stt, int &pointX, int pointY, int currentPage){

   	
   	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	stt = 0;
	int stt2 = 0;
	
	NODETHEDOCGIA *p;
	while(DSDG){
		if(DSDG->pLeft == NULL){
			stt++;

			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1) {
				stt2++;
				CoutNodeDG(DSDG->data, stt ,pointX, pointY+=2);
			}
				DSDG = DSDG->pRight;
		}
		else{
			p = DSDG->pLeft;
			while(p->pRight && p->pRight != DSDG){
				p = p->pRight;
			}
			if(p->pRight == NULL){
				p->pRight = DSDG;
				DSDG = DSDG->pLeft;
			}
			else{
				p->pRight == NULL;
				if(currentPage*15 < stt && stt < (currentPage+1)*15 +1) {
				stt2++;
				CoutNodeDG(DSDG->data, stt ,pointX, pointY+=2);
				}
				DSDG = DSDG->pRight;
			}
		}
	}
//	total = stt;
	stt = stt2;
}

void CountHeaderDocGiaTable(int pointX, int pointY){	
	GoToXY(pointX, pointY); cout << "STT";
	GoToXY(pointX + 8, pointY); cout << "MA THE";
	GoToXY(pointX + 26, pointY); cout << "Ho";
	GoToXY(pointX + 40, pointY); cout << "Ten";
	GoToXY(pointX + 59, pointY); cout << "Phai";
	GoToXY(pointX + 75, pointY); cout << "Trang Thai";	
}

void CoutNodeDG(TheDocGia dg, int stt, int pointX, int pointY){
	HideTyping();
	string phai;
	string trangThai;
	if(dg.Phai == 1){
		phai = "Nam";
	} else {
		phai = "Nu";
	}
	
	if(dg.TrangThai == 0){
		trangThai = "Khoa";
	} else {
		trangThai = "Dang hoat dong";
	}
	GoToXY(pointX, pointY); printf("%-6d", stt);
	GoToXY(pointX + 8, pointY); printf("%-11d", dg.MATHE);
	GoToXY(pointX + 26, pointY); printf("%-10s", dg.Ho.c_str());
	GoToXY(pointX + 40, pointY); printf("%-16s", dg.Ten.c_str());
	GoToXY(pointX + 59, pointY); printf("%-5s", phai.c_str());
	GoToXY(pointX + 75, pointY); printf("%-20s", trangThai.c_str());	
}

void ClearRemainDocGia(int total, int pointX, int pointY, int currentPage){
	int row2 = 15-total;
	pointY = total*2+pointY;
	for(int i = 0; i < row2;i++){
		GoToXY(pointX, pointY+=2); printf("%-6s", " ");
		GoToXY(pointX + 8, pointY); printf("%-11s", " ");
		GoToXY(pointX + 26, pointY); printf("%-10s"," ");
		GoToXY(pointX + 40, pointY); printf("%-16s", " ");
		GoToXY(pointX + 59, pointY); printf("%-5s", " ");
		GoToXY(pointX + 75, pointY); printf("%-20s", " ");	
	}
}

void DrawTableDocGia(){
	int pointX = 45, pointY = 5, width = 106, height = 37;
	int col1 = 8, col2 = 26, col3 = 40, col4 = 59, col5 = 75;
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3 || j == col4 || j == col5)
					if(i > 0 && i < height-2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-2)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(HORIZONTAL_LINE);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else if(i%2 == 0){
			for(int j = 0; j < width; j++){
				if(j == 0)
					cout << char(LEFT_CENTER_SIMPLE);
				else if(j == width-1)
					cout << char(RIGHT_CENTER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3 || j == col4 || j == col5)
					if(i == 2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-3)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(PLUS_CENTER);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else {
			cout << char(VERTICAL_LINE);
			
			if(i > 2 && i < height - 2){
				GoToXY(pointX+col1, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col2, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col3, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col4, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col5, pointY+i);
				cout << char(VERTICAL_LINE);
			}
			
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	
	CountHeaderDocGiaTable(pointX+2, pointY+3);
	
	DrawHuongDanTable(70, 40, DocGiaFunctionText, NUMBER_ITEM_DOCGIA_FUNCTION_TEXT);
	
	DrawTitle(TitleText[3], 87);
	
}

int DemSoDocGia(TREE t){
	int dem = 1;
	if (t != NULL){
		dem += DemSoDocGia(t->pLeft);
		dem += DemSoDocGia(t->pRight);
		return dem;
	}
	else return 0;
}

void Insert_Last_DSDG(TREE &DSDG, TheDocGia x){
    TREE p = new NODETHEDOCGIA;
    p->data = x;
    p->pRight = NULL;
    p->pLeft = NULL;
    
    if(DSDG == NULL) 
		DSDG = p;
    else{
      	TREE Last = DSDG;
      	for(; Last->pRight != NULL; Last = Last->pRight);
      	Last->pRight = p;
	}
}

void Inorder(TREE p, TREE &DSDG){
    if (p != NULL)
    {
        Inorder(p->pLeft, DSDG);
        Insert_Last_DSDG(DSDG, p->data);
        Inorder(p->pRight, DSDG);
    }
}

void DrawBoderThemDocGia(){
	int pointX = 55, pointY = 5, width = 90, height = 31;
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else cout << char(HORIZONTAL_LINE);
			}
		}else {
			cout << char(VERTICAL_LINE);
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	
	DrawTitleFunction(pointX+20, pointY+30, EditFunctionText, NUMBER_ITEM_DOCGIA_FUNCTION_TEXT, 0);
	
	
	for(int i = 0; i < NUMBER_ITEM_DOCGIA_TEXT-1; i++){
		GoToXY(pointX+5, pointY+3+i*4);
		cout << ThemDocGiaText[i];
		DrawInput(85, pointY+2+i*4);
	}
	
	GoToXY(87, 20);
	SetColor(PURPLE);
	SetColor(BLACK);
	
	GoToXY(87, 8);
	Typing();
}

void DrawInputGender(int pointX, int pointY, int gender){
	HideTyping();
	GoToXY(pointX, pointY);
	
	SetColor(BLACK);
	
	if(gender == 1){
		SetColor(WHITE);
		SetBGColor(GREEN);
	}
	cout << "          NAM           ";
	
	SetColor(BLACK);
	SetBGColor(WHITE);
	cout << char(219);
	SetColor(BLACK);
	SetBGColor(WHITE);
	
	if(gender == 0){
		SetColor(WHITE);
		SetBGColor(GREEN);
	}
	cout << "           NU            ";
	
	SetBGColor(WHITE);
	SetColor(BLACK);
}

void DrawInputStatus(int pointX, int pointY, int status){
	HideTyping();
	GoToXY(pointX, pointY);
	
	SetColor(BLACK);
	
	if(status == 1){
		SetColor(WHITE);
		SetBGColor(GREEN);
	}
	cout << "       Hoat Dong        ";
	
	SetColor(BLACK);
	SetBGColor(WHITE);
	cout << char(219);
	SetColor(BLACK);
	SetBGColor(WHITE);
	
	if(status == 0){
		SetColor(WHITE);
		SetBGColor(GREEN);
	}
	cout << "         Khoa           ";
	
	SetBGColor(WHITE);
	SetColor(BLACK);
}

int ThemDocGia(TREE &tree, string state, TheDocGia p){
	TheDocGia tdg;
	unsigned int maThe;
	int x = 87, y = 12, c, type = 1, is_delete = 0, length = 10, index = 1, gender = 1, status = 1;
	string temp = "";
	
	if(state == "NEW"){
		ClearTable(1);
		DrawTitle(EditText[4], 90);
		DrawBoderThemDocGia();
		length = 25;
	}
	else if(state == "EDIT"){
		ClearTable(1);
		DrawTitle(EditText[5], 90);
		DrawBoderThemDocGia();
			DrawButtonYesNo(28, state);
								
			GoToXY(x, y-=4);
			SetColor(RED);
			printf("%-50d", p.MATHE);
			SetColor(BLACK);
								
			GoToXY(x, y+=4);
			printf("%-50s", p.Ho.c_str());
								
			GoToXY(x, y+=4);
			printf("%-50s", p.Ten.c_str());
								
			DrawInputGender(x, y+=4, p.Phai);
			
			DrawInputStatus(x, y+=4, p.TrangThai);
								
			y = y-12;
			type = 1;
			temp = p.Ho;
			tdg.MATHE = p.MATHE;
	}
	else if(state == "DELETE"){
		ClearTable(1);
		DrawTitle(EditText[6], 95);
		DrawBoderThemDocGia();
			GoToXY(x, y-=4);
			SetColor(RED);
			printf("%-50d", p.MATHE);
			SetColor(BLACK);
								
			GoToXY(x, y+=4);
			printf("%-50s", p.Ho.c_str());
								
			GoToXY(x, y+=4);
			printf("%-50s", p.Ten.c_str());
								
			GoToXY(x, y+=4);
			DrawInputGender(x, y, p.Phai);
			
			GoToXY(x, y+=4);
			DrawInputStatus(x, y, p.TrangThai);
			
			index = 5;		
			type = 4;
			GoToXY(x , y);
			is_delete = 0;
			DrawButtonYesNo(28, state);
			DrawTitleYesNo(29, is_delete, state);
	}


	if(state == "NEW"){
		type = 2;
		DrawInputGender(87, 20, -1);
		DrawInputStatus(87, 24, 1);
		NhapLai:
		do {
//			maThe = Random();
			maThe = arrmt[smt];

		} while(checkExitMaThe(tree, maThe));
		GoToXY(x, 8);
		SetColor(PURPLE);
		printf("%-20d", maThe);
		SetColor(BLACK);
		tdg.MATHE = maThe;
		
		do{
			c = InputValue(length, temp, x, y, type);
			switch (c) {		
				
				case EX_UP:
					if(index == 1) break;
					
					if(index == 2){
						temp = tdg.Ho;
						GoToXY(x+temp.length(), y -= 4);
						index --;
					}else if (index == 3){
						temp = tdg.Ten;
						GoToXY(x+temp.length(), y -= 4);
						index --;
						length = 10;
						type =2;
						DrawInputGender(x, y+4, gender);
					}
					break;
							
			    case EX_DEL:
			    	ClearButtonYesNo(22);
			        return c;
			    case EX_LEFT:
			    case EX_RIGHT:
			    	if(index < 3) break;	
					gender = gender == 1 ? 0 : 1;
			    	DrawInputGender(x, y, gender);	
			        break;
			    case ENTER:
			    	if(temp[temp.length()-1] == SPACE) temp = temp.substr(0, temp.length()-1);
			    	if(temp.length() == 0 ) {
						Message("ERROR:", "Vui long khong de trong!", 0, 1000);
						GoToXY(x+temp.length(), y);
						break;
					}
					if(index == 1){
						tdg.Ho = temp;
						length = 10;
						temp = tdg.Ten;
					}else if(index == 2){
				
						tdg.Ten = temp;
						type = 4;
						DrawInputGender(x, y+4, gender);
					}else if(index == 3){
						temp = gender == 1 ? "Nam" : "Nu";
						tdg.Phai = gender;
					}
//					temp = "";
				    index++;
				    if(index == 4) {
				    	GoToXY(x, y);
						printf("%-50s"," ");
						gender = 0;
						status = 0;
						DrawInputGender(87, 20, -1);
						DrawInputStatus(87, 24, 1);
						type = 1, y = 4, length = 10, index = 1;
						tdg.TrangThai = 1;
						tdg.soLuongDangMuon = 0;
				    	tdg.tongSoLuong = 0;
						ThemNodeVaoCay(tree, tdg);
						smt++;
						
				    	ClearInput(x, y, 3);
				    	Message("SUCCESS:", "Them Doc Gia Thanh Cong!", 1, 1000);
				    	y = 12;
				    	goto NhapLai;						
					}
					GoToXY(x+temp.length(), y+=4);
			    	break;
			    case ESC:
			        return c;
			}
		}while(1);
	}
	else if(state == "EDIT"){
		type = 2;
		do{
			c = InputValue(50, temp, x, y, type);
			switch (c) {			
				case EX_UP:
					if(index == 1) break;
					
					if(index == 2){
						temp = p.Ho;
						GoToXY(x+temp.length(), y -= 4);
						index --;
					}else if (index == 3){
						temp = p.Ten;
						GoToXY(x+temp.length(), y -= 4);
						index --;
						length = 10;
						type =2;
					}else if (index == 4){
						DrawInputGender(x, y-=4, p.Phai);
						index --;
					}
					break;	
			    case EX_INSERT:
			    case EX_DEL:
			    	ClearButtonYesNo(22);
			        return c;
				case TAB:
			        return 0;
			    case EX_LEFT:
			    case EX_RIGHT:
					if(index == 3){
						gender = gender == 1 ? 0 : 1;
						DrawInputGender(x, y, gender);
					} else if(index == 4){
						status = status == 1 ? 0 : 1;
						DrawInputStatus(x, y, status);
					} else if(index == 5){
						is_delete = is_delete == 1 ? 0 : 1;
			    		DrawTitleYesNo(29, is_delete, state);
					}
			        break;
			    case ENTER:
			    	if(temp[temp.length()-1] == SPACE) temp = temp.substr(0, temp.length()-1);
			    	if(!(index == 3 || index == 4) && temp.length() == 0 ) {
						Message("ERROR:", "Vui long khong de trong!", 0, 1000);
						GoToXY(x+temp.length(), y);
						break;
					}
					
			    	if(index == 1){
						tdg.Ho = temp;
						temp = p.Ten;
						length = 10;
						y+=4, index++;
					}else if(index == 2){
						tdg.Ten = temp;
						gender = p.Phai;
						temp = "";
						y+=4, index++, type = 4;
						DrawInputGender(x, y, gender);
					}else if(index == 3){
						tdg.Phai = gender;
						status = p.TrangThai;
						temp = p.TrangThai;
						y+=4, index++;
						DrawInputStatus(x, y, status);
					}else if(index == 4){
						tdg.TrangThai = status;
						index++;
						DrawTitleYesNo(29, is_delete, state);
					}else if(index == 5) {
				    	GoToXY(x, y-4);
						printf("%-50s"," ");
						gender = 0;
						status = 0;
						DrawInputGender(x, 20, gender-1);
						DrawInputStatus(x, 24, status -1);
						if(is_delete == 0) {
							
							p = tdg;
							TREE t = TimKiemDocGia(tree, tdg.MATHE);
							if(t->data.soLuongDangMuon > 0 && tdg.TrangThai == 0){
								Message("ERROR:", "Khong The Khoa The. Doc Gia Con Sach Chua Tra", 0, 1000);
								break;
							}
							t->data.Ho = tdg.Ho;
					    	t->data.Ten = tdg.Ten;
					    	t->data.Phai = tdg.Phai;
					    	t->data.TrangThai = tdg.TrangThai;
							Message("SUCCESS:", "Luu Doc Gia Thanh Cong!", 1, 1000);
						}
				    	return 0;
					}
			    	break;
			    case ESC:
			        return c;
			}
		}while(1);
	}
	else if(state == "DELETE"){
		type = 4;
		do{
			c = InputValue(50, temp, x, y, type);
			switch (c) {				
			    case EX_INSERT:
			    case EX_DEL:
			    	ClearButtonYesNo(22);
			    	return c;
				case TAB:
			        return 0;
			    case EX_LEFT:
			    case EX_RIGHT:
			    	if(index < 3) break;
			    	is_delete = is_delete == 1 ? 0 : 1;
			    	DrawTitleYesNo(29, is_delete, state);
			        break;
			    case ENTER:
					if(index == 5){
						if(is_delete == 0 && p.tongSoLuong == 0 ) {
							XoaDocGia(tree, p.MATHE);
							Message("SUCCESS:", "Xoa Doc Gia Thanh Cong!", 1, 800);
						} else if(is_delete == 0 && p.soLuongDangMuon > 0) {
							Message("ERROR:", "Xoa That Bai. Doc Gia Con Sach Chua Tra!", 0, 800);
							break;
						}
						return 0;
					}
			    	break;
			    case ESC:
			        return c;
			}
		}while(1);
	}
}

bool checkExitMaThe(TREE t, unsigned int mathe){
	if (t == NULL) return false;
	else if (t->data.MATHE == mathe) return true;
	else if (mathe < t->data.MATHE) return checkExitMaThe(t->pLeft, mathe);
	else return checkExitMaThe(t->pRight, mathe);
}


void GhiThongTin1DocGia(TREE t, ofstream &fileout){
	
	fileout << t->data.MATHE << endl;
	fileout << t->data.Ho << endl;
	fileout << t->data.Ten << endl;
	fileout << t->data.Phai << endl;
	fileout << t->data.TrangThai << endl;
	fileout << t->data.soLuongDangMuon << endl;
	fileout << t->data.tongSoLuong << endl;
	if(t->data.tongSoLuong != 0){
		for (NODE_MUON_TRA* k = t->data.listMuonTra.pHead; k != NULL; k = k->pNext){
			fileout << k->data.ma_sach <<endl;
			fileout << k->data.ngay_muon.day << " " << k->data.ngay_muon.month << " " << k->data.ngay_muon.year << endl;
			fileout << k->data.ngay_tra.day << " " << k->data.ngay_tra.month << " " << k->data.ngay_tra.year << endl;
			fileout << k->data.trang_thai << endl;
		}
	}
}

void GhiThongTinDanhSachDocGia(TREE t, ofstream &fileout){
	if (t != NULL)
	{
		GhiThongTin1DocGia(t, fileout);
		GhiThongTinDanhSachDocGia(t->pLeft, fileout);
		GhiThongTinDanhSachDocGia(t->pRight, fileout);
	}
}

void LuuDuLieuDocGia(TREE t){
	ofstream fileout;
	fileout.open("data\\docGia.txt", ios::out);
	if (fileout.is_open())
	{
		fileout << DemSoDocGia(t) << endl;
		GhiThongTinDanhSachDocGia(t, fileout);
	}
	else cout << "Loi ket noi file! ";
	fileout.close();
}

TheDocGia Search_By_STT_DSDG(TREE DSDG, int select, int currentPage){

int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	int stt = 0;
	int stt2 = 0;
	
	NODETHEDOCGIA *p;
	while(DSDG){
		if(DSDG->pLeft == NULL){
			stt++;

			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1 && stt - 1 == (select + currentPage*15) ) {
				stt2++;
				return DSDG->data;
			}
				DSDG = DSDG->pRight;
		}
		else{
			p = DSDG->pLeft;
			while(p->pRight && p->pRight != DSDG){
				p = p->pRight;
			}
			if(p->pRight == NULL){
				p->pRight = DSDG;
				DSDG = DSDG->pLeft;
			}
			else{
				p->pRight == NULL;
				if(currentPage*15 < stt && stt < (currentPage+1)*15 +1 && stt - 1 == (select + currentPage*15)) {
				stt2++;
				return DSDG->data;
				}
				DSDG = DSDG->pRight;
			}
		}
	}
	stt = stt2;
}

void ThemNodeVaoCayTheoTenHo(TREE& t, TheDocGia x) {

	//neu cay rong
	if (t == NULL) {
		NODETHEDOCGIA* p = new NODETHEDOCGIA;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;//node p chinh la goc
	}
	else {
		//cay co ton tai phan tu
		if (t->data.Ten > x.Ten) {
			ThemNodeVaoCayTheoTenHo(t->pLeft, x);
		}
		else if (t->data.Ten < x.Ten) {
			ThemNodeVaoCayTheoTenHo(t->pRight, x);
		}
		else {
			if (t->data.Ho > x.Ho) {
				ThemNodeVaoCayTheoTenHo(t->pLeft, x);
			}
			else if (t->data.Ho < x.Ho) {
				ThemNodeVaoCayTheoTenHo(t->pRight, x);
			}
			else {
				ThemNodeVaoCayTheoTenHo(t->pLeft, x);
			}
		}
	}
}

void InDanhSachDocGiaTheoTenHo(TREE t, TREE& temp) {
	if (t != NULL) {
		InDanhSachDocGiaTheoTenHo(t->pLeft, temp);
		ThemNodeVaoCayTheoTenHo(temp, t->data);
		InDanhSachDocGiaTheoTenHo(t->pRight, temp);
	}
}

NODETHEDOCGIA* TimKiemDocGia(TREE t, int x){

	if (t == NULL) return NULL;
	else{
		if (x < t->data.MATHE) TimKiemDocGia(t->pLeft, x);
		else if (x > t->data.MATHE) TimKiemDocGia(t->pRight, x);
		else return t;
	}
}

int XoaDocGia(TREE& t, int maDocGia) {
	//Neu cay dang rong
	if (t == NULL) {
		return 0;
	}
	else {
		//neu data nho hon node goc
		if (maDocGia < t->data.MATHE) {
			XoaDocGia(t->pLeft, maDocGia);
		}
		else if (maDocGia > t->data.MATHE) {
			XoaDocGia(t->pRight, maDocGia);
		}
		else if (maDocGia == t->data.MATHE) {
			NODETHEDOCGIA* x = t; // node x la node the mang - ti nua se xoa no
			//neu nhanh trai = NULL <=> day la cay co 1 con chinh la con phai
			if (t->pLeft == NULL) {
				t = t->pRight; //duyet sang phai cua node can xoa de cap nhat moi lien ket giua node cha 
								//cua node can xoa voi node con cua node can xoa
			}
			else if (t->pRight == NULL) {
				t = t->pLeft; //duyet sang trai cua node can xoa de cap nhat moi lien ket giua node cha 
								//cua node can xoa voi node con cua node can xoa
			}
			else //node can xoa la node co 2 con
			{
				//C1: Tim node trai nhat cua cay con phai( cay con phai cua node can xoa)	
				DiTimNodeTheMang(x, t->pRight);
			}
			delete x; //xoa node can xoa
			return 1;
		}
		else return 0;
	}
}

int DeleteDG_DSDG(TREE &DSDG, int maThe){  
	TREE p = DSDG, q;
  	if (DSDG == NULL ) return 0;
  	if (DSDG->data.MATHE == maThe ) {
	    p = DSDG;
		DSDG = p->pRight;
		delete p;
		
		return 1;
	}
    
	for ( p = DSDG; p->pRight!=NULL && p->pRight->data.MATHE != maThe; p = p->pRight);
	if (p->pRight!= NULL ) {
		q = p->pRight; 
		p->pRight = q->pRight;
		delete q; 
		return 1;
	}
	return 0;
}

void DiTimNodeTheMang(TREE& x, TREE& y) {
	//duyet sang ben trai nhat
	if (y->pLeft != NULL) {
		DiTimNodeTheMang(x, y->pLeft);
	}
	else { //tim duoc node trai nhat
		x->data = y->data; //cap nhat data cua node can xoa la data cua node the mang	
		x = y; //cho node X =y
		y = y->pRight; //ban chat cho nay chinh la cap nhat lai moi lien ket cho node cha cua node the mang
	}
}

// handle Muon Tra

void DrawInfoDocGia(int pointX, int pointY, TheDocGia tdg){
	HideTyping();
	int width = 40, height = 4;
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else cout << char(HORIZONTAL_LINE);
			}
		}else {
			cout << char(VERTICAL_LINE);
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	
	GoToXY(45, 2);
	cout << tdg.Ho << " " <<  tdg.Ten << " ( "  <<  tdg.MATHE  << " ) ";
	GoToXY(37, 3);
	printf("PHAI: %-5sTRANG THAI: %-10s", tdg.Phai == 0 ? "Nu" : "Nam", tdg.TrangThai == 0 ? "Khoa" : "Hoat Dong" );

}

void DrawBorderNhap(int pointX, int pointY){
	int width = 90, height = 8;
	SetColor(RED);
	GoToXY(pointX+34, pointY+1);
	printf("%-50s", "NHAP THONG TIN DOC GIA!");
	SetColor(BLACK);
	
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else cout << char(HORIZONTAL_LINE);
			}
		}else {
			cout << char(VERTICAL_LINE);
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	
	int index = 0;
	GoToXY(pointX+5, pointY+3+index*4);
	printf("%-30s", ThemDocGiaText[index]);
	DrawInput(85, pointY+2+index*4);
	
	GoToXY(87, 8);
	HideTyping();

}


void DrawNhapMaDocGia(TREE &tree, DS_DAU_SACH ds, int check){
	int nodes = -1;
	int x = 75, y = 10, type = 3, length = 7;
	DrawBorderNhap(x-20, y);
	string temp = "";
	x = x+12, y = y+3;
	int c, stt, a;
	
	TheDocGia tdg;
	TREE t;
	do{
		tdg.MATHE = -1;
		c = InputValue(length, temp, x, y, type);
			switch (c) {
			    case ENTER:
			    	{
			    		if(temp[temp.length()-1] == SPACE) temp = temp.substr(0, temp.length()-1);
			    		if(temp.length() == 0){
			    			Message("ERROR:", "Vui long khong de trong!", 0, 1000);
			    			break;
						}
			    		
			    		sscanf(temp.c_str(), "%d", &tdg.MATHE);
			    		
			    		t = TimKiemDocGia(tree, tdg.MATHE);
			    		if(t == NULL) {
			    			Message("ERROR:", "Ma The Khong Ton Tai!", 0, 1000);
			    			GoToXY(x+temp.length(), y);
			    			break;
						}
						
						
						int tab = 1;
						int stt = 0, pointX = 47, pointY = 8, x = 52, y = 6, pointXds = 42, x1 = 52;
						int total = ds.sl;
						
						
						int n = (int)ceil((double)total/15);
						int currentPage = 0, select = 0;
						string keyword = "";
						if(check == 1){
							if(t->data.TrangThai == 0){
								Message("ERROR:", "DOC GIA DA BI KHOA!", 0, 1000);
				    			break;	
							}
							if (t->data.tongSoLuong != 0){
								if(checkQuaHan(t->data.listMuonTra) == true){
									Message("ERROR:", "DOC GIA CO SACH DANG QUA HAN!", 0, 1000);
									break;
								}
							}
							if (t->data.soLuongDangMuon >= 3){
								Message("ERROR:", "DOC GIA DA MUON DU 3 QUYEN SACH ROI!", 0, 1000);
			    				GoToXY(34, 43);
			    				break;
							}
						}
						if(check == 2){
							if(t->data.tongSoLuong == 0){
								Message("ERROR:", "DOC GIA CHUA TUNG MUON SACH!", 0, 1000);
								break;
							}
							
						}
						DAUSACH *d;
						ClearTable(1);
						DrawInfoDocGia(35, 1, t->data);
						if(check == 1){
							x = 52;	
							PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
							DrawTableDauSach(1, tab);
							Traverse_DauSach(ds, pointXds, pointY, currentPage, stt, keyword, total);
							DrawArrowTable(42, 8, select, currentPage, stt);
							PrintSearchInput(42, keyword);
						}	
						else if(check == 2){
							x = 57;
							DrawTableDanhSachMuon();
							Traverse_MT(t->data.listMuonTra,pointX, pointY, currentPage, stt, keyword, total);
							DrawArrowTable(47, 8, select, currentPage, stt);
							PrintSearchInput(47, keyword);
						}
						do{
							type = 1, length = 30;
							Quaylai:
							c = InputValue(length, keyword, x, y, type);
							if(c == ENTER){
								if(check == 1){
								
								nodes = Search_DauSach_By_STT_Plus(ds, keyword, currentPage, select);
								
								if(ds.nodes[nodes]->soLuong == 0){
									Message("ERROR:", "So luong bang 0", 0, 1000);
									break;
								}
								if(t->data.soLuongDangMuon > 0 && DuyetDSDaMuon(t->data.listMuonTra, ds.nodes[nodes]->isbn) == 0){
									Message("ERROR:", "Ban da muon sach nay roi!", 0, 1000);
									goto Quaylai;
								}
								ClearTable(1);
								DrawInfoDocGia(35, 1, t->data);
								PrintDataSachMT(ds.nodes[nodes], 1, "NEW", t);
								PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
								DrawTableDauSach(1, tab);
								Traverse_DauSach(ds, pointXds, pointY, currentPage, stt, keyword, total);
								DrawArrowTable(42, 8, select, currentPage, stt);
								PrintSearchInput(42, keyword);
								}
							if (check == 2){
								d = new DAUSACH;
								
								
//								MUONTRA mt;
//								BOOK b;
//								mt = SearchMT(t->data.listMuonTra,keyword, currentPage, select,1,n);
								
								NODE_DANH_MUC_SACH* b;
								NODE_MUON_TRA* mt;
								
								mt = SearchNodeMT(t->data.listMuonTra,keyword, currentPage, select,1,n);
								
								string temp = convertToString(mt->data.ma_sach, strlen(mt->data.ma_sach));
								for (int i = 0 ; i < temp.length(); i++){
									if ( temp[i] == '-') 
									{
										temp = temp.substr(0, i);
										break;
									}
						
								}
								char isbn1[10];
								strcpy(isbn1, temp.c_str());
								d = Search_DauSach_By_ISBN(ds, isbn1);
								b = SearchNodeDMSByMS(d->listSach, mt->data.ma_sach);
								
								if(mt->data.trang_thai == 1 || mt->data.trang_thai == 2){
									Message("ERROR", "Sach Da Tra Hoac Lam Mat Roi!!!", 0, 1000);
									goto Quaylai;
								}
									ClearTable(1);
				
								do{
											
							 			a = TraSach(t->data.listMuonTra, mt,b, d, t);
										if(a == 0){
										x = 57, y = 6;
										tab = 1;
										ClearTable(0);
										DrawInfoDocGia(35, 1, t->data);
										DrawTableDanhSachMuon();
										Traverse_MT(t->data.listMuonTra,pointX, pointY, currentPage, stt, keyword, total);
										DrawArrowTable(47, 8, select, currentPage, stt);
										PrintSearchInput(47, keyword);
										break;
										}else if(a == ESC) {
											ClearTable(1);
											return;
										}
							}while(1);
								
							}
						
							
							} else if(c == EX_UP || c == EX_DOWN){
								if (c == EX_UP &&select + 1 > 1) select--; 
						        else if (c == EX_DOWN && select + 1 < stt) select++;
						        if(check == 1){
						        	DrawArrowTable(42, 8, select, currentPage, stt);
					    			PrintSearchInput(42, keyword);
								}
					    		if(check == 2){
						        	DrawArrowTable(47, 8, select, currentPage, stt);
					    			PrintSearchInput(47, keyword);
								}
							}
							else if (c == EX_PAGEUP || c == EX_PAGEDOWN){
								if (check == 1){
								
								if (c == EX_PAGEUP &&currentPage + 1 > 1) currentPage--; 
						        else if (c == EX_PAGEDOWN && currentPage + 1 < n) currentPage++;
						        
						        HideTyping();
						        Traverse_DauSach(ds, pointXds, pointY, currentPage, stt, keyword, total);
						        n = (int)ceil((double)total/15);
								PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
								
								if(currentPage == n-1)
								ClearRemainDauSach(stt, pointXds, pointY);
										
								DrawArrowTable(42, 8, select = 0, currentPage, stt);
								PrintSearchInput(42, keyword);
								
								}
							}
							else if(c == CTRL_F){
								if(check == 1){
									Traverse_DauSach(ds, pointXds, pointY, currentPage = 0, stt = 0, keyword, total);
									ClearRemainDauSach(stt, pointXds, pointY = 8);
									n = (int)ceil((double)total/15);
									PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
									DrawArrowTable(pointXds, 8, select = 0, currentPage, stt);
									PrintSearchInput(42, keyword);
								}
							}
							else if(c == ESC){
								ClearTable(1);
								return;
							}
						}while(1);
						
						ClearTable(0);
						return;
					}
			    case ESC:
			    	ClearTable(1);
			    	
			        return;
			}
	}while(1);
}
// =====================================================end=====================================================

//=================================================muon tr========================

void KhoiTaoMuonTra(LIST_MUON_TRA& l) {
	//Cho 2 node tr? d?n NULL vì danh sách chua có ph?n t?
	l.pHead = NULL;
	l.pTail = NULL;
}

//Hàm kh?i t?o 1 node
NODE_MUON_TRA* KhoiTaoNodeMuonTra(MUONTRA mt) {
	NODE_MUON_TRA* p = new NODE_MUON_TRA; //C?p phát vùng nh? cho NODE p
	if (p == NULL)
	{
		cout << "\nKhong du bo nho!";
		return NULL;
	}
	p->data = mt;//Truy?n giá tr? x vào cho data
	p->pNext = NULL;//node v?a du?c khai báo nên chua có liên k?t d?n node nào h?t => con tr? c?a nó s? tr? d?n NULL
	return p; //Tr? v? NODE p v?a kh?i t?o
}

void themVaoCuoiMT(LIST_MUON_TRA& l, NODE_MUON_TRA* p) {
	//N?u danh sách dang r?ng
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p; //Node d?u cung là node cu?i và là p
	}
	else {
		l.pTail->pNext = p; //Cho con tr? c?a pTail liên k?t v?i node p
		l.pTail = p; //C?p nh?t l?i p chính là node pTail
	}
}

void XoaDauMT(LIST_MUON_TRA& l) {
	//N?u danh sách r?ng
	if (l.pHead == NULL) {
		return;
	}
	NODE_MUON_TRA* p = l.pHead; //Node p là node s? xóa
	l.pHead = l.pHead->pNext; //C?p nh?t l?i l.pHead là ph?n t? k? ti?p trong danh sách
	delete p;
}

//Hàm xóa cu?i
void XoaCuoiMT(LIST_MUON_TRA& l) {
	//N?u danh sách r?ng
	if (l.pHead == NULL) {
		return;
	}
	//Tru?ng h?p danh sách có 1 ph?n t?
	if (l.pHead->pNext == NULL) {
		XoaDauMT(l);
		return;
	}
	//Duy?t t? dâu danh sách d?n node k? cu?i
	for (NODE_MUON_TRA* k = l.pHead; k != NULL; k = k->pNext) {
		//Phát hi?n node k? cu?i
		if (k->pNext == l.pTail) {
			delete l.pTail; //Xóa ph?n t? cu?i
			k->pNext = NULL; //Cho con tr? c?a node k? cu?i tr? d?n NULL
			l.pTail = k; //C?p nh?t l?i pTail là node k? cu?i
			return;
		}
	}
}

//Xóa node b?t kì
void XoaNodeBatKiMT(LIST_MUON_TRA& l, string x) {
	//N?u node n?m d?u danh sách
	if (l.pHead->data.ma_sach == x) {
		XoaDauMT(l);
		return;
	}
	//N?u node n?m cu?i danh sách
	if (l.pHead->data.ma_sach == x) {
		XoaCuoiMT(l);
		return;
	}
	NODE_MUON_TRA* g = new NODE_MUON_TRA; //Node tr? d?n node n?m tru?c node c?n xóa
	//Duy?t danh sách d? tìm
	for (NODE_MUON_TRA* k = l.pHead; k != NULL; k = k->pNext) {
		//Phát hi?n
		if (k->data.ma_sach == x) {
			g->pNext = k->pNext; //C?p nh?t m?i liên k?t gi?a node k ( node q) v?i node sau node g
			delete k; //Xóa node n?m sau node q
			return;
		}
		g = k; //Cho node g tr? d?n node k
	}

}

void DrawBoderMT(){
	int pointX = 55, pointY = 5, width = 90, height = 25;
	
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else cout << char(HORIZONTAL_LINE);
			}
		}else {
			cout << char(VERTICAL_LINE);
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	
	DrawTitleFunction(pointX+25, pointY+24, SachFunctionText, NUMBER_ITEM_SACH_FUNCTION_TEXT, 0);
	
	for(int i = 0; i < NUMBER_ITEM_SACHTEXT; i++){
		GoToXY(pointX+5, pointY+6+i*4);
		printf("%-30s", MUONTRATXT[i]);
		DrawInput(85, pointY+5+i*4);
	}
	
	
	GoToXY(87, 8);
	Typing();

}

MUONTRA SearchMT(LIST_MUON_TRA list, string keyword, int currentPage, int select, int sl,int st){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > sl) m = sl; 
	int stt = 0;
	int stt2 = 0;
	
	for (NODE_MUON_TRA* k = list.pHead; k != NULL; k = k->pNext){
			stt++;
			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1 && stt - 1 == (select + currentPage*15))  {
			stt2++;
			return k->data;	
			}	
		}
	stt = stt2;
	
}
NODE_MUON_TRA* SearchNodeMT(LIST_MUON_TRA list, string keyword, int currentPage, int select, int sl,int st){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > sl) m = sl; 
	int stt = 0;
	int stt2 = 0;
	
	for (NODE_MUON_TRA* k = list.pHead; k != NULL; k = k->pNext){
			stt++;
			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1 && stt - 1 == (select + currentPage*15))  {
			stt2++;
			return k;	
			}	
		}
	stt = stt2;
	
}

void CoutNodeMT(MUONTRA mt, int stt, int pointX, int pointY){
	HideTyping();
	char trangThai [20];
	if(mt.trang_thai == 0){
		strcpy(trangThai, "Dang muon");
	} else if(mt.trang_thai == 1){
		strcpy(trangThai, "Da tra");
	} else {
		strcpy(trangThai, "Da mat");
	}
	GoToXY(pointX, pointY); printf("%-6d", stt);
	GoToXY(pointX + 10, pointY); printf("%-11s", mt.ma_sach);
	GoToXY(pointX + 25, pointY); printf("%-20s", ShowNgay(mt.ngay_muon).c_str());
	GoToXY(pointX + 50, pointY); printf("%-10s", ShowNgay(mt.ngay_tra).c_str());
	GoToXY(pointX + 75, pointY); printf("%-10s", trangThai);

	
	
}

void PrintDataSachMT(DAUSACH *ds, int tab, string state, TREE &tree){
	int c, a;
	
	int stt = 0, pointX = 47, pointY = 8, x = 57, y = 6;
	int total = ds->soLuong;

	int n = (int)ceil((double)total/15);
	int currentPage = 0, select = 0;
	int currentPage1 = 0;
	string keyword = "";
	DAUSACH *d;
	
	Message("SUCCESS:", "Load Du Lieu Thanh Cong!", 1, 500);
	PrintPageTable(n > 0 ? currentPage1+1 : 0, n, 140);
	DrawTableSach();
	Traverse_Sach(ds->listSach, pointX, pointY, currentPage, stt, keyword, total, ds->soLuong);
	DrawArrowTable(47, 8, select, currentPage1, stt);
	PrintSearchInput(47, keyword);
	do {
	    c = InputSearch(keyword, x, y, 50);
	    switch (c) {
	    	case EX_UP:
	    	case EX_DOWN:
	    		if (c == EX_UP &&select + 1 > 1) select--; 
		        else if (c == EX_DOWN && select + 1 < stt) select++;
		        
	    		DrawArrowTable(47, 8, select, currentPage, stt);
	    		PrintSearchInput(47, keyword);
	    		break;
		    case EX_PAGEUP:
		    case EX_PAGEDOWN:
		    	if(tab > 1) break;
		    	
		    	if (c == EX_PAGEUP &&currentPage + 1 > 1) currentPage--; 
		        else if (c == EX_PAGEDOWN && currentPage + 1 < n) currentPage++;
		        
		        HideTyping();
		        Traverse_Sach(ds->listSach, pointX, pointY, currentPage, stt, keyword, total, ds->soLuong);
		        n = (int)ceil((double)total/15);
				PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
				
				if(currentPage == n-1)
						ClearRemainSach(stt, pointX, pointY);
						
				DrawArrowTable(47, 8, select = 0, currentPage, stt);
				PrintSearchInput(47, keyword);
				break;
			case CTRL_F:
		    	break;
			case ENTER:{
//				BOOK b;
//				b = SearchDMS(ds->listSach, keyword, currentPage, select, ds->soLuong, n);
				NODE_DANH_MUC_SACH* h;
				h = SearchNodeDMS(ds->listSach, keyword, currentPage, select, ds->soLuong, n);
				
				if(h->data.trangThai == 2){
					Message("ERROR", ": Sach Da Thanh Ly. Khong The Sua Hoac Cho Muon !!!", 0, 1000);
					PrintSearchInput(47, keyword);
					break;
				}
				if(h->data.trangThai == 1){
					Message("ERROR", ": Da co doc gia muon !!!", 0, 1000);
					PrintSearchInput(47, keyword);
					break;
				}
				
				
				ClearTable(1);
				do{
					a = ShowMTconfirm(tree->data.listMuonTra,h, ds, tree);
					
					
					break;
					if(a == ESC) {
						ClearTable(1);
						return;
						}
				}while(1);
					return;
			}
			case EX_INSERT:
			case TAB:
				break;
			case ESC:
				ClearTable(1);
				return;
		}	
	} while(1);
}

int DuyetDSDaMuon(LIST_MUON_TRA& l, char masach[10]) {
	for (NODE_MUON_TRA* k = l.pHead; k != NULL; k = k->pNext) {
		//Phát hi?n
		string temp = convertToString(k->data.ma_sach, strlen(k->data.ma_sach));
		for (int i = 0 ; i < temp.length(); i++){
			if ( temp[i] == '-') 
			{
				temp = temp.substr(0, i);
				break;
			}		
		}
		char isbn1[10];
		strcpy(isbn1, temp.c_str());
	
		
		if (strcmp(isbn1, masach) == 0 && k->data.trang_thai == 0) {
			return 0;
		}
	}
	return 1;
}

void CountHeaderMTTable(int pointX, int pointY){
	GoToXY(pointX, pointY); cout << "STT";
	GoToXY(pointX + 10, pointY); cout << "Ma sach";
	GoToXY(pointX + 25, pointY); cout << "Ngay muon";
	GoToXY(pointX + 50, pointY); cout << "Ngay tra";
	GoToXY(pointX + 75, pointY); cout << "Trang thai";
	
}

void DrawTableDanhSachMuon(){
	int pointX = 45, pointY = 5, width = 106, height = 37;
	int col1 = 10, col2 = 25, col3 = 50, col4 = 75;
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3 || j == col4)
					if(i > 0 && i < height-2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-2)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(HORIZONTAL_LINE);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else if(i%2 == 0){
			for(int j = 0; j < width; j++){
				if(j == 0)
					cout << char(LEFT_CENTER_SIMPLE);
				else if(j == width-1)
					cout << char(RIGHT_CENTER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3 || j == col4)
					if(i == 2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-3)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(PLUS_CENTER);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else {
			cout << char(VERTICAL_LINE);
			
			if(i > 2 && i < height - 2){
				GoToXY(pointX+col1, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col2, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col3, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col4, pointY+i);
				cout << char(VERTICAL_LINE);	
			}
			
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	CountHeaderMTTable(pointX+2, pointY+3);
	
	DrawHuongDanTable(48, 40, DauSachFunctionText, NUMBER_ITEM_DAUSACH_FUNCTION_TEXT);
	
	DrawTitle(TitleText[4], 87);
}


int ShowMTconfirm(LIST_MUON_TRA &list, NODE_DANH_MUC_SACH *p, DAUSACH *ds, TREE &tree){
	HideTyping();
	int x = 87, y = 11;
	string temp = "";
	string status;
	int c, type = 2, index = 0, is_delete = 0, length = 50, status1 = 1;
	char maSach[15];
	Date1 ngaymuon;
	char tenSach[50];
	LIST_MUON_TRA listTemp;
	
			DrawTitle(EditText[7], 90);
			DrawBoderMT();
			DrawButtonYesNo(23, "EDIT");
			DrawTitleYesNo(24, is_delete, "EDIT");
	
			GoToXY(x, y);
			SetColor(RED);
			printf("%-50s",p->data.maSach);	
			SetColor(BLACK);
							
			GoToXY(x, y+=4);
			printf("%-50s", ds->tenSach);	
						
			GoToXY(x, y+=4);
			printf("%-50s", ShowNgay(GetDate()).c_str());

			y = y+4, type = 4;
			length = 15;
			
			do{
				c = InputValue(50, temp, x, y, type);
				switch (c) {				
			    case EX_INSERT:
			    case EX_DEL:
			    	ClearButtonYesNo(22);
			       
				case TAB:
			        
			    case EX_LEFT:
			    case EX_RIGHT:
			    	if(index == 0){
						is_delete = is_delete == 1 ? 0 : 1;
			    		DrawTitleYesNo(24, is_delete, "EDIT");
					}
			        break;
			    case ENTER:
			    	
					if(index == 0){
						GoToXY(x, y-4);
						printf("%-50s"," ");
						DrawTitleYesNo(24, is_delete, "EDIT");
						
//						b.trangThai = 1;
						 
						MUONTRA mt;
						if(tree->data.tongSoLuong == 0) KhoiTaoMuonTra(tree->data.listMuonTra);
						
						strcpy(mt.ma_sach, p->data.maSach);
						mt.ngay_muon = GetDate();
						mt.ngay_tra.day = 0;
						mt.ngay_tra.month = 0;
						mt.ngay_tra.year = 0;
						mt.trang_thai = 0;
	
						
						if(is_delete == 0) {
							if(tree->data.soLuongDangMuon == 3){
								Message("ERROR:", "MUON THAT BAI. DOC GIA DANG MUON 3 CUON", 0, 1000);
								break;
							}
						NODE_MUON_TRA* q = KhoiTaoNodeMuonTra(mt);
				
						themVaoCuoiMT(tree->data.listMuonTra, q);
						
						tree->data.soLuongDangMuon++;
						tree->data.tongSoLuong++;	
						ds->luotMuon ++;
						p->data.trangThai = 1;
						Message("SUCCESS:", "MUON THANH CONG", 1, 1000);
					}
						
						
						ClearTable(0);
						return 0;
					}
					break;
				case ESC:
					ClearTable(0);
					return c;
			}
			
		}while(1);

}

void TaoListMT(char masach[15], MUONTRA mt){
	
		strcpy(mt.ma_sach, masach);
		mt.ngay_muon = GetDate();
		mt.ngay_tra = inputDate(0,0,0);
		mt.trang_thai = 0;
	
}

int TraSach(LIST_MUON_TRA &list, NODE_MUON_TRA* mt, NODE_DANH_MUC_SACH* b, DAUSACH *ds, TREE &tree){
	int x = 87, y = 11;
	string temp = "";
	string status;
	int c, type = 4, index = 0, is_delete = 0, length = 50, status1 = 1;
	int tt;

			DrawTitle(EditText[8], 90);
			DrawBoderTraSach();
			DrawButtonYesNo(27, "EDIT");
	
			GoToXY(x, y);
			SetColor(RED);
			printf("%-50s",mt->data.ma_sach);	
			SetColor(BLACK);
							
			GoToXY(x, y+=4);
			printf("%-50s", ds->tenSach);	
						
			GoToXY(x, y+=4);
			printf("%-50s", ShowNgay(GetDate()).c_str());

			DrawInputStatusTraSach(x, y+=4, 1);

			length = 15;
			
			do{
				c = InputValue(50, temp, x, y, type);
				switch (c) {				
			    case EX_INSERT:
			    case EX_DEL:
			    	ClearButtonYesNo(22);
			       
				case TAB:
			        
			    case EX_LEFT:
			    case EX_RIGHT:
			    	if(index == 0){
						status1 = status1 == 1 ? 2 : 1;
						DrawInputStatusTraSach(x, y, status1);
						
					} else if(index == 1){
						is_delete = is_delete == 1 ? 0 : 1;
			    		DrawTitleYesNo(28, is_delete, "EDIT");
					}
			        break;
			    case ENTER:
					if(index == 0){
						GoToXY(x, y);
						printf("%-50s"," ");
						
						DrawInputStatusTraSach(x, y, status1);
//						status1 = 1;
						
						index++;
						DrawTitleYesNo(28, is_delete, "EDIT");
					}
					else if(index == 1){
						GoToXY(x, y);
						printf("%-50s"," ");
						if(is_delete == 0) {
//							SuaNodeBatKi(ds->listSach, b);
							if(status1 == 2){
								b->data.trangThai = 2;
							} else if(status1 == 1){
								b->data.trangThai = 0;

							}

		
										
							mt->data.ngay_tra = GetDate();
							mt->data.trang_thai = status1;
//							SuaTraSach(tree->data.listMuonTra, mt);				
							tree->data.soLuongDangMuon --;
							Message("SUCCESS:", "TRA THANH CONG", 1, 1000);
							status1 = 1;
						}
							return 0;
					}	
				
					break;
				case ESC:
					ClearTable(0);
					return c;
			}
		
		}while(1);

}


//void PrintDataMT(DAUSACH *ds,TREE &tree, int tab, string state){
//	int c, a;
//	
//	int stt = 0, pointX = 47, pointY = 8, x = 57, y = 6;
//	int total = ds->soLuong;
//
//	int n = (int)ceil((double)total/15);
//	int currentPage = 0, select = 0;
//	int currentPage1 = 0;
//	string keyword = "";
//	DAUSACH *d;
//	
//	Message("SUCCESS:", "Load Du Lieu Lop Tin Chi Thanh Cong!", 1, 500);
//	PrintPageTable(n > 0 ? currentPage1+1 : 0, n, 140);
//	DrawTableDanhSachMuon();
//	Traverse_MT(tree->data.listMuonTra,pointX, pointY, currentPage, stt, keyword, total);
//	Traverse_Sach(ds->listSach, pointX, pointY, currentPage, stt, keyword, total, ds->soLuong);
//	DrawArrowTable(47, 8, select, currentPage1, stt);
//	do {
//	    c = InputSearch(keyword, x, y, 50);
//	    switch (c) {
//	    	case EX_UP:
//	    	case EX_DOWN:
//	    		if (c == EX_UP &&select + 1 > 1) select--; 
//		        else if (c == EX_DOWN && select + 1 < stt) select++;
//		        
//	    		DrawArrowTable(47, 8, select, currentPage, stt);
//	    		PrintSearchInput(47, keyword);
//	    		break;
//		    case EX_PAGEUP:
//		    case EX_PAGEDOWN:
//		    	if(tab > 1) break;
//		    	
//		    	if (c == EX_PAGEUP &&currentPage + 1 > 1) currentPage--; 
//		        else if (c == EX_PAGEDOWN && currentPage + 1 < n) currentPage++;
//		        
//		        HideTyping();
//		        Traverse_Sach(ds->listSach, pointX, pointY, currentPage, stt, keyword, total, ds->soLuong);
//		        n = (int)ceil((double)total/15);
//				PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
//				
//				if(currentPage == n-1)
//						ClearRemainSach(stt, pointX, pointY);
//						
//				DrawArrowTable(47, 8, select = 0, currentPage, stt);
//				PrintSearchInput(47, keyword);
//				break;
//			case CTRL_F:
//		    	break;
//			case ENTER:{
//				MUONTRA mt;
//				BOOK b;
//				b = SearchDMS(ds->listSach, keyword, currentPage, select, ds->soLuong, n);
//				mt = SearchMT(tree->data.listMuonTra,keyword, currentPage, select,1,n);
//				if(mt.trang_thai == 1 || mt.trang_thai == 2){
//					Message("ERROR", "Sach Da Tra Hoac Lam Mat Roi!!!", 0, 1000);
//					PrintSearchInput(47, keyword);
//					break;
//				}
//					ClearTable(0);
//
//				do{
//								
//				 			a = TraSach(tree->data.listMuonTra, mt,b, ds, tree);
//							if(a == 0){
//							x = 57, y = 6;
//							tab = 1;
//							ClearTable(0);
//					    	PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
//							DrawTableSach();
//		        			Traverse_Sach(ds->listSach, pointX, pointY, currentPage, stt, keyword, total, ds->soLuong);
//							DrawArrowTable(47, 8, select, currentPage, stt);
//							PrintSearchInput(47, keyword);
//							break;
//							}else if(a == ESC) {
//								ClearTable(1);
//								return;
//							}
//				}while(1);
//			}
//							
//			
//			case EX_INSERT:
//			case TAB:
//
//			break;
//			case ESC:
//				ClearTable(1);
//				return;
//		}	
//	} while(1);
//}
void Traverse_MT(LIST_MUON_TRA list, int &pointX, int pointY, int currentPage, int &stt, string keyword, int &total){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;

	stt = 0;
	int stt2 = 0;

		for (NODE_MUON_TRA* k = list.pHead; k != NULL; k = k->pNext){
			stt++;
			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1) {
			stt2++;
			CoutNodeMT(k->data, stt ,pointX, pointY+=2);	
			}
	}

	stt = stt2;
}

void SuaTraSach(LIST_MUON_TRA& l, MUONTRA mt) {
	//N?u node n?m d?u danh sách
	if (strcmp(l.pHead->data.ma_sach, mt.ma_sach) == 0 && l.pHead->data.trang_thai == 0) {
		l.pHead->data.ngay_tra = mt.ngay_tra;
		l.pHead->data.trang_thai = mt.trang_thai;

		return;
	}

	if (strcmp(l.pTail->data.ma_sach, mt.ma_sach) == 0 && l.pTail->data.trang_thai == 0) {
		l.pTail->data.ngay_tra = mt.ngay_tra;
		l.pTail->data.trang_thai = mt.trang_thai;

		return;
	}

	for (NODE_MUON_TRA* k = l.pHead; k != NULL; k = k->pNext) {

		if (strcmp(k->data.ma_sach, mt.ma_sach) == 0 && k->data.trang_thai == 0) {
			
			k->data.ngay_tra = mt.ngay_tra;
			k->data.trang_thai = mt.trang_thai;

			return;
		}
	}

}

void DrawBoderTraSach() {
	Typing();
	int pointX = 55, pointY = 5, width = 90, height = 30;

	for (int i = 0; i < height; i++) {
		GoToXY(pointX, pointY + i);
		if (i == 0 || i == height - 1) {
			for (int j = 0; j < width; j++) {
				if (j == 0)
					if (i == height - 1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if (j == width - 1)
					if (i == height - 1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else {
			cout << char(VERTICAL_LINE);
			GoToXY(pointX + width - 1, pointY + i);
			cout << char(VERTICAL_LINE);
		}
	}

	DrawTitleFunction(pointX + 5, pointY + 29, DauSachFunctionText, NUMBER_ITEM_DAUSACH_FUNCTION_TEXT, 0);

	for (int i = 0; i < 4; i++) {
		GoToXY(pointX + 5, pointY + 6 + i * 4);
		printf("%-30s", TraSachTxt[i]);
		DrawInput(85, pointY + 5 + i * 4);
	}


	GoToXY(87, 8);
	Typing();

}

void CountHeaderQuaHanTable(int pointX, int pointY){
	GoToXY(pointX, pointY); cout << "STT";
	GoToXY(pointX + 10, pointY); cout << "Ma The";
	GoToXY(pointX + 23, pointY); cout << "Ho Ten";
	GoToXY(pointX + 43, pointY); cout << "Ma Sach";
	GoToXY(pointX + 57, pointY); cout << "Ten Sach";
	GoToXY(pointX + 80, pointY); cout << "Ngay Muon";
	GoToXY(pointX + 98, pointY); cout << "Ngay Qua Han";
}
void CoutQuaHanTable(CTQH qh,DS_DAU_SACH ds ,int stt,int pointX, int pointY){
	HideTyping();
	DAUSACH *d;
	string temp = convertToString(qh.maSach, strlen(qh.maSach));
		for (int i = 0 ; i < temp.length(); i++){
			if ( temp[i] == '-'){
				temp = temp.substr(0, i);
				break;
				}
			}
	char isbn1[10];
	strcpy(isbn1, temp.c_str());
	d = Search_DauSach_By_ISBN(ds,isbn1);
		
//	GoToXY(pointX, pointY); cout << stt;
//	GoToXY(pointX + 10, pointY); cout << qh.MATHE;
//	GoToXY(pointX + 23, pointY); cout << qh.HoTen;
//	GoToXY(pointX + 43, pointY); cout << qh.maSach;
//	GoToXY(pointX + 57, pointY); cout << d->tenSach;
//	GoToXY(pointX + 80, pointY); cout << ShowNgay(qh.ngaymuon);
//	GoToXY(pointX + 98, pointY); cout << qh.SoNgayQuaHan;
	
		GoToXY(pointX, pointY); printf("%-8d", stt);
		GoToXY(pointX + 10, pointY); printf("%-11d", qh.MATHE);
		GoToXY(pointX + 23, pointY); printf("%-18s", qh.HoTen.c_str());
		GoToXY(pointX + 43, pointY); printf("%-12s", qh.maSach);
		GoToXY(pointX + 57, pointY); printf("%-20s", d->tenSach);
		GoToXY(pointX + 80, pointY); printf("%-15s", ShowNgay(qh.ngaymuon).c_str());
		GoToXY(pointX + 98, pointY); printf("%-5d", qh.SoNgayQuaHan);
}

void ClearRemainQH(int total, int pointX, int pointY, int currentPage){
	int row2 = 15-total;
	pointY = total*2+pointY;
	string blank = " ";
	for(int i = 0; i < row2;i++){
		GoToXY(pointX, pointY+=2); printf("%-8s", " ");
		GoToXY(pointX + 10, pointY); printf("%-11s", " ");
		GoToXY(pointX + 23, pointY); printf("%-18s", " ");
		GoToXY(pointX + 43, pointY); printf("%-12s", " ");
		GoToXY(pointX + 57, pointY); printf("%-20s", " ");
		GoToXY(pointX + 80, pointY); printf("%-15s", " ");
		GoToXY(pointX + 98, pointY); printf("%-5s", " ");
	}
}


void DrawTableQuaHan(){
	int pointX = 40, pointY = 5, width = 115, height = 37;
	int col1 = 10, col2 = 23, col3 = 43, col4 = 57, col6 = 80, col7 = 98;
	
	for(int i = 0; i < height; i++){
		GoToXY(pointX, pointY+i);
		if(i == 0 || i == height-1){
			for(int j = 0; j < width; j++){
				if(j == 0)
					if(i == height-1)
						cout << char(BOTTOM_LEFT_CORNER_SIMPLE);
					else 
						cout << char(TOP_LEFT_CORNER_SIMPLE);
				else if(j == width-1)
					if(i == height-1)
						cout << char(BOTTOM_RIGHT_CORNER_SIMPLE);
					else 
						cout << char(TOP_RIGHT_CORNER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3 || j == col4 || j == col6 || j == col7)
					if(i > 0 && i < height-2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-2)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(HORIZONTAL_LINE);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else if(i%2 == 0){
			for(int j = 0; j < width; j++){
				if(j == 0)
					cout << char(LEFT_CENTER_SIMPLE);
				else if(j == width-1)
					cout << char(RIGHT_CENTER_SIMPLE);
				else if(j == col1 || j == col2 || j == col3 || j == col4 || j == col6 || j == col7)
					if(i == 2)
						cout << char(TOP_CENTER_SIMPLE);
					else if(i == height-3)
						cout << char(BOTTOM_CENTER_SIMPLE);
					else cout << char(PLUS_CENTER);
				else cout << char(HORIZONTAL_LINE);
			}
		}
		else {
			cout << char(VERTICAL_LINE);
			
			if(i > 2 && i < height - 2){
				GoToXY(pointX+col1, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col2, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col3, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col4, pointY+i);
				cout << char(VERTICAL_LINE);
				
				
				GoToXY(pointX+col6, pointY+i);
				cout << char(VERTICAL_LINE);
				
				GoToXY(pointX+col7, pointY+i);
				cout << char(VERTICAL_LINE);
				
			}
			
			GoToXY(pointX+width-1, pointY+i);
			cout << char(VERTICAL_LINE);
		}
	}
	CountHeaderQuaHanTable(pointX+2, pointY+3);
	
	
	DrawTitle(TitleText[5], 83);
}

void DrawInputStatusTraSach(int pointX, int pointY, int status){
	HideTyping();
	GoToXY(pointX, pointY);
	
	SetColor(BLACK);
	
	if(status == 1){
		SetColor(WHITE);
		SetBGColor(GREEN);
	}
	cout << "      TRA SACH         ";
	
	SetColor(BLACK);
	SetBGColor(WHITE);
	cout << char(219);
	SetColor(BLACK);
	SetBGColor(WHITE);
	
	if(status == 2){
		SetColor(WHITE);
		SetBGColor(GREEN);
	}

	cout << "      LAM MAT SACH       ";	
		
	SetBGColor(WHITE);
	SetColor(BLACK);
}

NODE_DANH_MUC_SACH* SearchNodeDMS(LIST_DANH_MUC list, string keyword, int currentPage, int select, int sl,int st){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > sl) m = sl; 
	int stt = 0;
	int stt2 = 0;
	
	for (NODE_DANH_MUC_SACH* k = list.pHead; k != NULL; k = k->pNext){
			stt++;
			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1 && stt - 1 == (select + currentPage*15))  {
			stt2++;
			return k ;	
			}	
		}
	stt = stt2;
}

BOOK SearchDMSByMS(LIST_DANH_MUC list,char ms[15]){
	for (NODE_DANH_MUC_SACH* k = list.pHead; k != NULL; k = k->pNext){
			if(strcmp(k->data.maSach, ms) == 0)  {
			return k->data;	
			}	
		}	
}
NODE_DANH_MUC_SACH* SearchNodeDMSByMS(LIST_DANH_MUC list,char ms[15]){
	for (NODE_DANH_MUC_SACH* k = list.pHead; k != NULL; k = k->pNext){
			if(strcmp(k->data.maSach, ms) == 0)  {
			return k;	
			}	
		}	
}
//=========================================================end===============================
// xu ly ngay
string ShowNgay(Date1 date){
	return ConvertIntToString(date.day) + "/" + ConvertIntToString(date.month) + "/" + ConvertIntToString(date.year);
}

bool checkLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	}
	return false;
}

// Tao doi tuong ngay gio
Date1 inputDate(int day, int month, int year) {
	Date1 date1;
	date1.day = day;
	date1.month = month;
	date1.year = year;
	return date1;
}
Date1 GetDate() {//lay ngay-thang-nam hien tai
	Date1 resDate;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	resDate.year=1900 + ltm->tm_year;
	resDate.month=1 + ltm->tm_mon;
	resDate.day=ltm->tm_mday;
	return resDate;
}

int DemNgay(Date1 date){
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int dateOfYear=0,dateOfMonth=0, datecount=0;
	
	for(int i = date.year; i < GetDate().year; i++ ){
		if(checkLeapYear(i)) dateOfYear += 366;
		else dateOfYear += 365;
	}
	
	if(checkLeapYear(GetDate().year)) a[1] = 29;
	if(date.month > GetDate().month){
		for (int i = GetDate().month; i < date.month; i++ ){
			dateOfMonth -=a [i-1];
		}
	}
	else {
		for (int i = date.month; i < GetDate().month; i++ ){
			dateOfMonth +=a [i-1];
	}
	datecount = GetDate().day - date.day;
	return dateOfYear + dateOfMonth + datecount;
}
}
bool checkQuaHan(LIST_MUON_TRA l){
	
	for (NODE_MUON_TRA *k = l.pHead; k != NULL; k = k->pNext){
	
		if (DemNgay(k->data.ngay_muon) > 7 && k->data.ngay_tra.year == 0) return true;
	
	}
	
	return false;
	
}

void AddListQuaHan2(TREE t, CTQH *arr){
	if(t->data.tongSoLuong > 0){
		for (NODE_MUON_TRA *p = t->data.listMuonTra.pHead; p != NULL; p = p->pNext){
			if (p->data.trang_thai == 0 && t->data.soLuongDangMuon > 0 && DemNgay(p->data.ngay_muon) > 7){
				arr[indexQH].MATHE = t->data.MATHE;
				strcpy(arr[indexQH].maSach, p->data.ma_sach);
				arr[indexQH].HoTen = t->data.Ho + " " + t->data.Ten;
				arr[indexQH].ngaymuon = p->data.ngay_muon;
				arr[indexQH].SoNgayQuaHan = DemNgay(p->data.ngay_muon);
				++indexQH;
			}
		}
	}
}
void QuickSortQuaHan2(CTQH *arr, int q, int r){
	CTQH temp;
	int i = q;
	int j = r ;
	//L?y ph?n t? gi?a c?a dãy c?n s?p th? t? làm ch?t
	int x = arr[(q + r ) / 2].SoNgayQuaHan;
	do
	{  // Phân do?n dãy con a[q],..., a[r]
		while (arr[i].SoNgayQuaHan > x)
			i++; //Tìm ph?n t? d?u tiên có tr? nh? hon hay b?ng x
		while (arr[j].SoNgayQuaHan < x)
			j--;   //Tìm ph?n t? d?u tiên có tr? l?n hon hay b?ng x

		if (i <= j)   // Hoan vi
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (q<j) 	// ph?n th? nh?t có t? 2 ph?n t? tr? lên
		QuickSortQuaHan2(arr, q, j);
	if (i < r )   	// ph?n th? ba có t? 2 ph?n t? tr? lên
		QuickSortQuaHan2(arr, i, r);
}

void DuyetDG(TREE DSDG, CTQH *arr){
	NODETHEDOCGIA *p;
	while(DSDG){
		if(DSDG->pLeft == NULL){
			AddListQuaHan2(DSDG, arr);
			DSDG = DSDG->pRight;
		}
		else{
			p = DSDG->pLeft;
			while(p->pRight && p->pRight != DSDG){
				p = p->pRight;
			}
			if(p->pRight == NULL){
				p->pRight = DSDG;
				DSDG = DSDG->pLeft;
			}
			else{
				p->pRight == NULL;
				AddListQuaHan2(DSDG, arr);
				DSDG = DSDG->pRight;
			}
		}
	}
}
void PrintDataQH(TREE tree, DS_DAU_SACH ds){
	int c, a;
	TREE t = NULL;
	int stt = 0, pointX = 42, pointY = 8, x = 57, y = 6;
	string keyword="";

	int currentPage = 0, select = 0;
	int currentPage1 = 0;
	Inorder(tree, t);
	
	int sodocgia = DemSoDocGia(tree);
	CTQH *arr = new CTQH[sodocgia*3];
	DuyetDG(t, arr);
	if(indexQH == 0){
		Message("ERROR:", "Khong co doc gia muon sach qua han", 0, 500);
		return;
	}
	QuickSortQuaHan2(arr, 0 , indexQH - 1);
	int n = (int)ceil((double)indexQH/15);
	Message("SUCCESS:", "Load Du Lieu Thanh Cong!", 1, 500);
	PrintPageTable(n > 0 ? currentPage1+1 : 0, n, 140);
	DrawTableQuaHan();
	Traverse_QH(arr, ds, pointX, pointY,currentPage, stt);
	DrawArrowTable(42, 8, select, currentPage1, stt);
	PrintSearchInput(42, keyword);
	do {
	    c = InputSearch(keyword, x, y, 50);
	    switch (c) {
	    	case EX_UP:
	    	case EX_DOWN:
	    		if (c == EX_UP &&select + 1 > 1) select--; 
		        else if (c == EX_DOWN && select + 1 < stt) select++;
		    	Traverse_QH(arr, ds, pointX, pointY,currentPage, stt);
	    		DrawArrowTable(42, 8, select, currentPage, stt);
	    		PrintSearchInput(42, keyword);
	    		break;
		    case EX_PAGEUP:
		    case EX_PAGEDOWN:
		    	if (c == EX_PAGEUP &&currentPage + 1 > 1) currentPage--; 
		        else if (c == EX_PAGEDOWN && currentPage + 1 < n) currentPage++;
		        
		        HideTyping();
				Traverse_QH(arr, ds, pointX, pointY,currentPage, stt);
				PrintPageTable(n > 0 ? currentPage+1 : 0, n, 140);
				
				if(currentPage == n-1)
				ClearRemainQH(stt, pointX, pointY, currentPage);
				break;
			case ESC:
				ClearTable(1);
//				deleteTree(t);
//				delete [] arr;
				indexQH = 0;
				return;
		}	
	} while(1);
}
void Traverse_QH(CTQH *arr, DS_DAU_SACH ds,int &pointX, int pointY, int currentPage, int &stt){
	int n = (currentPage)*15;
	int m = (currentPage+1)*15;
	if(m > indexQH ) m = indexQH ; 
	stt = 0;
	int stt2 = 0;
		for (int i = 0; i < indexQH; i++){
			stt++;
			if(currentPage*15 < stt && stt < (currentPage+1)*15 +1) {
			stt2++;	
			CoutQuaHanTable(arr[i], ds, stt, pointX, pointY+=2);
			}
	}
	stt = stt2;
}

//Free
void ClearList_DauSach(DS_DAU_SACH &ds){
	for(int i = 0; i < ds.sl; i++){
		XoaDauSach(ds, i);
	}
	ds.sl = 0;
}

void GiaiPhongDMS(LIST_DANH_MUC& l) {
	NODE_DANH_MUC_SACH* k = NULL;
	while (l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}

void GiaiPhongMT(LIST_MUON_TRA& l) {
	NODE_MUON_TRA* k = NULL;
	while (l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}

void deleteTree (TREE &t)
{
	if(t == NULL) return;
		deleteTree(t->pLeft);
		deleteTree(t->pRight);
	if(t->data.tongSoLuong > 0) {
		GiaiPhongMT(t->data.listMuonTra);
		free(t);	
	}
//	t = NULL;
}


