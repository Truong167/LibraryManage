#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <math.h>

using namespace std;

#define MAXDAUSACH 10000

//struct Date {
//	int ngay;
//	int thang;
//	int nam;
//};
//
//Date GetDate() {//lay ngay-thang-nam hien tai
//	Date resDate;
//	time_t now = time(0);
//	tm *ltm = localtime(&now);
//	resDate.nam=1900 + ltm->tm_year;
//	resDate.thang=1 + ltm->tm_mon;
//	resDate.ngay=ltm->tm_mday;
//	return resDate;
//}
// khai báo struct sach


struct book {
	char maSach[15];
	int trangThai;
	char viTri[20];
};
typedef struct book BOOK;

struct node_danh_muc_sach {
	BOOK data;
	struct node_danh_muc_sach* pNext;
};
typedef struct node_danh_muc_sach NODE_DANH_MUC_SACH;

struct list_danh_muc {
	NODE_DANH_MUC_SACH* pHead;
	NODE_DANH_MUC_SACH* pTail;
};
typedef struct list_danh_muc LIST_DANH_MUC;
// khai báo struct dau sach
struct dausach {
	char isbn[10];
	char tenSach[50];
	int soTrang;
	char tacGia[50];
	int namXuatBan;
	char theLoai[50];
	LIST_DANH_MUC listSach;
	int soLuong; //so luong sach trong danh muc sach
	int luotMuon;//so luot muon cho tung dau sach
};
typedef struct dausach DAUSACH;
struct ds_dausach{
	DAUSACH *nodes[MAXDAUSACH];
	int sl;
};
typedef struct ds_dausach DS_DAU_SACH;
// khai bao struct muon tra
struct Date1 {
	int day;
	int month;
	int year;
};
typedef struct Date1 DATE1;

struct MuonTra {
	char ma_sach[15];
	DATE1 ngay_muon;
	DATE1 ngay_tra;
	int trang_thai;
};
typedef struct MuonTra MUONTRA;

struct node_muon_tra {
	MUONTRA data;
	struct node_muon_tra *pNext;
};
typedef struct node_muon_tra NODE_MUON_TRA;

struct list_muon_tra {
	NODE_MUON_TRA* pHead; //Node qu?n lí d?u danh sách
	NODE_MUON_TRA* pTail; //Node qu?n lí cu?i danh sách
};
typedef struct list_muon_tra LIST_MUON_TRA;
// khai bao struct doc gia
struct TheDocGia {
	unsigned int MATHE;
	string Ho;
	string Ten;
	int Phai; /// 0: nu, 1 nam
	int TrangThai;
	int soLuongDangMuon;
	int tongSoLuong;
	LIST_MUON_TRA listMuonTra;
};

struct nodeTheDocGia {
	TheDocGia data;
	struct nodeTheDocGia* pLeft;
	struct nodeTheDocGia* pRight;
};

typedef struct nodeTheDocGia NODETHEDOCGIA;
typedef NODETHEDOCGIA* TREE;

struct CTQH{
	unsigned int MATHE;
	char maSach[10];
	string HoTen;
	DATE1 ngaymuon;
	int SoNgayQuaHan;
};
void loadMATHE();
void Luu_mt();
// Handle Dau Sach
int ThemDauSach(DS_DAU_SACH &listDauSach, string state, int check);
void ClearRemainDauSach(int total, int pointX, int pointY);
void DrawTableSach();
void CountHeaderSachTable(int pointX, int pointY);
void DrawBoderThemDauSach();
void PrintDataDauSach(DS_DAU_SACH &ds, int tab, string state);
void CoutNodeDauSach(DAUSACH *ds, int stt, int pointX, int pointY);
void Traverse_DauSach(DS_DAU_SACH listDauSach, int &pointX, int pointY, int currentPage, int &stt, string keyword, int &total);
void CountHeaderDauSachTable(int pointX, int pointY);
DAUSACH* Search_DauSach_By_STT(DS_DAU_SACH dsds, string keyword, int currentPage, int select);
int Search_Info_DauSach_By_STT(DS_DAU_SACH dsds, int currentPage, int select);
int Search_DauSach_By_STT_Plus(DS_DAU_SACH dsds, string keyword, int currentPage, int select);
void Traverse_Sach(LIST_DANH_MUC list, int &pointX, int pointY, int currentPage, int &stt, string keyword, int &total,int sl);
void SaveDauSach(DS_DAU_SACH ds);
void PrintDataTop10(DS_DAU_SACH ds);
void Traverse_Top10DauSach(DS_DAU_SACH listDauSach, int &pointX, int pointY, int &stt);
void DrawTableTop10DauSach(int is_draw_title, int tab);
void  XoaDauSach(DS_DAU_SACH &dsds, int pos);
// Ham xu ly dau sach
int Insert_DauSach(DS_DAU_SACH& listDauSach, DAUSACH *ds);
void xuatSach(DS_DAU_SACH listDauSach);
void  Delete_Item_DauSach(DS_DAU_SACH &dsds, int pos);
DS_DAU_SACH Search_DauSach(DS_DAU_SACH &dsds, string input);
void menu();
bool isISBN(char isbn[10], DS_DAU_SACH listDauSach);
int CompareDS(DAUSACH *a, DAUSACH *b, int type);
void SortDS(DS_DAU_SACH &dsds);
void Load_DauSach(DS_DAU_SACH &ds);
void LoadAllDataFromFile();
void traverse(DS_DAU_SACH dsds, char *isbn);
// handle danh muc sach
LIST_DANH_MUC taoList(char isbn[10], char vitri[20], int sl);
NODE_DANH_MUC_SACH* KhoiTaoNode(BOOK b);
void themVaoCuoi(LIST_DANH_MUC& l, NODE_DANH_MUC_SACH* p);
void KhoiTao(LIST_DANH_MUC& l);
void xuat(BOOK b);
void XuatDS(LIST_DANH_MUC l);
void PrintDataSach(DAUSACH *ds, int tab, string state);
void Doc_ds_danh_muc(ifstream& file, LIST_DANH_MUC& l, BOOK b, int sl);
void ClearRemainSach(int total, int pointX, int pointY);
BOOK SearchDMS(LIST_DANH_MUC list, string keyword, int currentPage, int select, int sl, int st);
void DrawBoderSuaSach(string title);
void SuaNodeBatKi(LIST_DANH_MUC& l, BOOK b);
int SuaSach(LIST_DANH_MUC &list, NODE_DANH_MUC_SACH* p);
void Doc_tat_ca_danh_muc(LIST_DANH_MUC& l);
void Luu_danh_muc_tam(LIST_DANH_MUC& l);
BOOK SearchDMSByMS(LIST_DANH_MUC list,char ms[15]);
NODE_DANH_MUC_SACH* SearchNodeDMS(LIST_DANH_MUC list, string keyword, int currentPage, int select, int sl,int st);
NODE_DANH_MUC_SACH* SearchNodeDMSByMS(LIST_DANH_MUC list,char ms[15]);
// handle Doc gia
unsigned int Random();
void KhoiTaoCay(TREE& t);
void DocDuLieuDocGia(TREE &t);
int ThemNodeVaoCay(TREE& t, TheDocGia x);
void DrawTableDocGia();
void PrintDataDocGia(int tab, string state, TREE &tree, int type);
void ClearRemainDocGia(int total, int pointX, int pointY, int currentPage);
int DemSoDocGia(TREE t);
void Traverse_DocGia(TREE DSDG, int &stt, int &pointX, int pointY, int currentPage);
void CoutNodeDG(TheDocGia dg, int stt, int pointX, int pointY);
void Inorder(TREE p, TREE &DSDG);
void Insert_Last_DSDG(TREE &DSDG, TheDocGia x);
void DrawBoderThemDocGia(string title);
int ThemDocGia(TREE &tree, string state, TheDocGia p);
bool checkExitMaThe(TREE t, unsigned int mathe);
void LuuDuLieuDocGia(TREE t);
TheDocGia Search_By_STT_DSDG(TREE DSDG, int select, int currentPage);
void InDanhSachDocGiaTheoTenHo(TREE t, TREE& temp);
NODETHEDOCGIA* TimKiemDocGia(TREE t, int x);
int XoaDocGia(TREE& t, int maDocGia);
int DeleteDG_DSDG(TREE &DSDG, int maThe);
void DiTimNodeTheMang(TREE& x, TREE& y);
void DrawNhapMaDocGia(TREE &tree, DS_DAU_SACH ds, int check);
//xu ly muon tra
void KhoiTaoMuonTra(LIST_MUON_TRA& l);
NODE_MUON_TRA* KhoiTaoNodeMuonTra(MUONTRA mt);
void themVaoCuoiMT(LIST_MUON_TRA& l, NODE_MUON_TRA* p);
void XoaDauMT(LIST_MUON_TRA& l);
void XoaCuoiMT(LIST_MUON_TRA& l);
void XoaNodeBatKiMT(LIST_MUON_TRA& l, string x);
void PrintDataSachMT(DAUSACH *ds, int tab, string state, TREE &tree);
int ShowMTconfirm(LIST_MUON_TRA &list, NODE_DANH_MUC_SACH* p, DAUSACH *ds, TREE &tree);
void PrintDataMT(DAUSACH *ds,TREE &tree, int tab, string state);
void Traverse_MT(LIST_MUON_TRA list, int &pointX, int pointY, int currentPage, int &stt, string keyword, int &total);
void CoutNodeMT(MUONTRA mt, int stt, int pointX, int pointY);
void DrawTableDanhSachMuon();
int TraSach(LIST_MUON_TRA &list, NODE_MUON_TRA* mt, NODE_DANH_MUC_SACH* b, DAUSACH *ds, TREE &tree);
void SuaTraSach(LIST_MUON_TRA& l, MUONTRA mt);
MUONTRA SearchMT(LIST_MUON_TRA list, string keyword, int currentPage, int select, int sl,int stt);
void DrawBoderTraSach();
void DrawInputStatusTraSach(int pointX, int pointY, int status);
int DuyetDSDaMuon(LIST_MUON_TRA& l, char masach[10]);
void DrawTableQuaHan(int is_draw_title, int tab);
NODE_MUON_TRA* SearchNodeMT(LIST_MUON_TRA list, string keyword, int currentPage, int select, int sl,int st);
//Ngay
Date1 GetDate();
int DemNgay(Date1 date);
Date1 inputDate(int day, int month, int year);
string ShowNgay(Date1 date);
bool checkQuaHan(LIST_MUON_TRA l);
void AddListQuaHan2(TREE t, CTQH *arr);
void QuickSortQuaHan2(CTQH *arr, int q, int r);
void DuyetDG(TREE DSDG, CTQH *arr);
void PrintDataQH(TREE tree, DS_DAU_SACH ds);
void Traverse_QH(CTQH *arr, DS_DAU_SACH ds,int &pointX, int pointY, int currentPage, int &stt);
//freee
void ClearList_DauSach(DS_DAU_SACH &ds);
void GiaiPhongDMS(LIST_DANH_MUC& l);
void GiaiPhongMT(LIST_MUON_TRA& l);
void deleteTree (TREE &t);
void freeArrMT();
