#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

void Time(){
    time_t now = time(0);
    char* dt = ctime(&now);
    cout<<dt<<endl;
}

void timeGuiTietKiem(){
   time_t now = time(0);
   tm *ltm = localtime(&now);
   cout << ltm->tm_mday<<"/"<<1 + ltm->tm_mon<<"/"<< 1901 + ltm->tm_year<< endl;
}

void timeVayTien(){
   time_t now = time(0);
   tm *ltm = localtime(&now);
   cout << ltm->tm_mday<<"/"<<2 + ltm->tm_mon<<"/"<< 1900 + ltm->tm_year<< endl;
}

void TimewriteFileChuyenKhoan(ofstream& file) {

    time_t now = time(0);
    char* timeString = ctime(&now); 


    if (file.is_open()) {
        file << timeString; 
    } else {
        cout << "Khong the mo file!" << endl;
    }
}

void TimewriteFileTietKiem(ofstream& file) {
    // Lấy thời gian hiện tại
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1901 + ltm->tm_year;

    // Định dạng chuỗi thời gian
    string timeString = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

    if (file.is_open()) {
        file << timeString << endl;
    } else {
        cout << "Khong the mo file!" << endl;
    }
}

void TimewriteFileVay(ofstream& file){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = 2 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;

    // Định dạng chuỗi thời gian
    string timeString = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

    if (file.is_open()) {
        file << timeString << endl;
    } else {
        cout << "Khong the mo file!" << endl;
    }
}


// lớp cha tài khoản
class TaiKhoan {
protected:
    string maTaiKhoan;
    string tenTaiKhoan;
    double soDu;
public:
    string getMaTaiKhoan(){
        return this->maTaiKhoan;
    }
    void setMaTaiKhoan(string maTaiKhoan){
        this->maTaiKhoan = maTaiKhoan;
    }

    string getTenTaiKhoan(){
        return this->tenTaiKhoan;
    }

    void setTenTaiKhoan(string tenTaiKhoan){
        this->tenTaiKhoan = tenTaiKhoan;
    }

    double getSoDu(){
        return this->soDu;
    }

    void setSoDu(double soDu){
        this->soDu = soDu;
    }
    TaiKhoan(){}
    TaiKhoan(string ma, string ten, double sodu) : maTaiKhoan(ma), tenTaiKhoan(ten), soDu(sodu) {}
    virtual void hienThiThongTin() {
        cout << "Ma tai khoan: " << maTaiKhoan << endl;
        cout << "Ten tai khoan: " << tenTaiKhoan << endl;
        cout << "So du: " << soDu << endl;
    }
};

// tài khoản thanh toán kế thừa lớp TaiKhoan
class TaiKhoanThanhToan : public TaiKhoan {
    protected:
        double phi;
    public:
        double getPhi(){
            return this->phi;
        }
        void setPhi(double phi){
            this->phi = phi;
        }
        TaiKhoanThanhToan(string ma){
            this->maTaiKhoan = ma;
        }

        TaiKhoanThanhToan(string ma, string ten, double sodu, double phi) : TaiKhoan(ma, ten, sodu), phi(phi) {}
        void hienThiThongTin() override {
            cout << "Tai khoan thanh toan" << endl;
            TaiKhoan::hienThiThongTin();
            cout << "Phi giao dich: " << phi << endl;
        }
};


// tài khoản tiết kiệm kế thừa lớp Tài Khoản
class TaiKhoanTietKiem : public TaiKhoan {
    protected:
        double laiSuat;
        double soTienGui;
        int kyHan;
    public:
        double getLaiSuat(){
            return this->laiSuat;
        }

        void setLaiSuat(double laiSuat){
            this->laiSuat = laiSuat;
        }

        double getSoTienGui(){
            return this->soTienGui;
        }

        void setSoTienGui(double soTienGui){
            this->soTienGui = soTienGui;
        }
        TaiKhoanTietKiem(string ma){
            this->maTaiKhoan = ma;
        }
        TaiKhoanTietKiem(string ma, string ten, double sodu, double soTienGui, double laiSuat,int kyHan) : TaiKhoan(ma, ten, sodu), soTienGui(soTienGui),laiSuat(laiSuat),kyHan(kyHan) {}
        // phương thức hiển thị thông tin tài khoản
        void hienThiThongTin() override {
            cout << "Tai khoan tiet kiem" << endl;
            TaiKhoan::hienThiThongTin();
            cout << "Lai suat: " << laiSuat << "%" << endl;
            cout << "Ngay den han: " ;
            timeGuiTietKiem();
            cout << "So tien gui: " << soTienGui << endl;
        }
        double sotienlai = soDu + soDu * laiSuat;

        void guiTietKiem() {
            soDu -= soTienGui;
            cout << "Giao dich gui tiet kiem thanh cong!" << endl;
            cout << "Ngay Den Han: " ;
            timeGuiTietKiem();
            cout << "So du hien tai: " << soDu << endl;
            cout << "So tien da gui: " << soTienGui << endl;
            cout << "So tien lai sau " << kyHan <<" thang : "<<sotienlai<< endl;
        }

        // write file
        void lichsuGuiTienTietKiem(double soTien) {
            TaiKhoanTietKiem* taiKhoanTietKiem = nullptr;
            
            ofstream file("lichsuguitietkiem.txt", ios::app); 
            if (file.is_open()) {
                file << "Loai giao dich: Gui tien" << endl;
                file << "Ma tai khoan: " << maTaiKhoan << endl;
                file << "So tien: " << soTien << endl;
                file << "Lai suat: " << laiSuat << "%" << endl;
                file << "Ngay den han: " ;
                TimewriteFileTietKiem(file);
                file << endl;

                file.close();
            } else {
                cout << "Khong the mo file!" << endl;
            }

            // Cập nhật số dư tài khoản tiết kiệm
            taiKhoanTietKiem->setSoDu(taiKhoanTietKiem->getSoDu() + soTien);
            cout << "Gui tien thanh cong!" << endl;
        }
        
};

// tài khoản Vay Mượn kế thừa lớp Tài Khoản
class TaiKhoanVayMuon : public TaiKhoan {
    protected:
        double soTienVay;
        double laiSuat;
    public:
        double getSoTienVay(){
            return this->soTienVay;
        }

        void setSoTienVay(double soTienVay){
            this->soTienVay = soTienVay;
        }

        double getLaiSuat(){
            return this->laiSuat;
        }

        void setLaiSuat(double laiSuat){
            this->laiSuat = laiSuat;
        }

        TaiKhoanVayMuon(string ma){
            this->maTaiKhoan = ma;
        }
        double soTienDongHangThang = 0;
        TaiKhoanVayMuon(string ma, string ten, double sodu, double soTienVay, double laiSuat) : TaiKhoan(ma, ten, sodu), soTienVay(soTienVay), laiSuat(laiSuat) {}
        // phương thức hiển thị thông tin tài khoản
        void hienThiThongTin() override {
            cout << "Tai khoan vay muon" << endl;
            TaiKhoan::hienThiThongTin();
            cout << "So tien vay: " << soTienVay << endl;
            cout << "Lai suat: " << laiSuat << "%" << endl;
            cout << "Ky han: " ;
            timeVayTien();
            cout << "So tien dong hang thang: " << soTienDongHangThang << endl;
        }

        // console                  
        void VayTien() {               
            soDu += soTienVay;
            cout<<"So tien da vay: " << soTienVay << endl;
            soTienDongHangThang = soTienVay * laiSuat;
            cout<<"So tien dong hang thang: " << soTienDongHangThang << endl;
            cout<<"Ngay den han: ";
            timeVayTien();
        }

        // write file
        void lichsuVay(double soTien) {
            TaiKhoanVayMuon *TaiKhoanVayMuon = nullptr;
            soDu += soTien;
            soTienVay += soTien;
        
            timeVayTien();


            ofstream file("lichsuvay.txt", ios::app); 
            if (file.is_open()) {
                file <<"So tien da vay: " << soTienVay << endl;
                file <<"So tien dong hang thang: " << soTienDongHangThang << endl;
                file <<"Ngay den han: ";
                TimewriteFileVay(file);
                file << endl;

                file.close(); 
            } else {
                cout << "Khong the mo file!" << endl;
                return; // Exit the function if the file cannot be opened
            }

            // Cập nhật số dư tài khoản tiết kiệm
            if (TaiKhoanVayMuon != nullptr) {
                TaiKhoanVayMuon->setSoDu(TaiKhoanVayMuon->getSoDu() + soTien);
                cout << "Vay tien thanh cong!" << endl;
            }
        }

};

// tài khoản cso thẻ tín dụng kế thừa lớp tài khoản thanh toán, tiết kiệm
class TaiKhoanCoTheTinDung : public TaiKhoanThanhToan, public TaiKhoanTietKiem , public TaiKhoanVayMuon{
    public:
        // TaiKhoanCoTheTinDung(string ma): TaiKhoanThanhToan(ma), TaiKhoanTietKiem(ma),TaiKhoanVayMuon(ma), laiSuat(0), hanMucVay(0), soTienConLai(0) {}
        
        TaiKhoanCoTheTinDung(string ma, string ten, double sodu, double phi) : TaiKhoanThanhToan(ma, ten, sodu, phi),TaiKhoanTietKiem(ma),TaiKhoanVayMuon(ma){}
        // phương thức hiển thị thông tin tài khoản
        TaiKhoanCoTheTinDung(string ma, string ten, double sodu, double soTienGui, double laiSuat,int kyHan) : TaiKhoanTietKiem(ma, ten, sodu, soTienGui, laiSuat, kyHan),TaiKhoanThanhToan(ma),TaiKhoanVayMuon(ma){}
        
        TaiKhoanCoTheTinDung(string ma, string ten, double sodu, double soTienVay, double laiSuat) : TaiKhoanVayMuon(ma, ten, sodu,  soTienVay,  laiSuat),TaiKhoanThanhToan(ma),TaiKhoanTietKiem(ma){}
        
        void hienThiThongTin() override {
            cout << "Tai khoan co the tin dung" << endl;
            TaiKhoanThanhToan::hienThiThongTin();
            TaiKhoanTietKiem::hienThiThongTin();
            TaiKhoanVayMuon::hienThiThongTin();
        }
        
};

struct Transaction {
    string maTaiKhoanGui;
    string maTaiKhoanNhan;
    double soTien;
    string timestamp;
};

class Controller {
private:
    vector<TaiKhoanThanhToan*> danhSachTaiKhoanThanhToan;
    vector<TaiKhoanTietKiem*> danhSachTaiKhoanTietKiem;
    vector<TaiKhoanVayMuon*> danhSachTaiKhoanVayMuon;

    vector<Transaction> transactionHistory;
public:
    Controller(){}
    void themTaiKhoan(TaiKhoan* taiKhoan) {
        if (dynamic_cast<TaiKhoanThanhToan*>(taiKhoan) != nullptr) {
            danhSachTaiKhoanThanhToan.push_back(static_cast<TaiKhoanThanhToan*>(taiKhoan));
        } else if (dynamic_cast<TaiKhoanTietKiem*>(taiKhoan) != nullptr) {
            danhSachTaiKhoanTietKiem.push_back(static_cast<TaiKhoanTietKiem*>(taiKhoan));
        } else if (dynamic_cast<TaiKhoanVayMuon*>(taiKhoan) != nullptr) {
            danhSachTaiKhoanVayMuon.push_back(static_cast<TaiKhoanVayMuon*>(taiKhoan));
        }
    }

    void hienThiDanhSachTaiKhoanThanhToan() {
        for (TaiKhoanThanhToan* taiKhoan : danhSachTaiKhoanThanhToan) {
            taiKhoan->hienThiThongTin();
            cout << "---------------------------" << endl;
        }
    }

    void hienThiDanhSachTaiKhoanTietKiem() {
        for (TaiKhoanTietKiem* taiKhoan : danhSachTaiKhoanTietKiem) {
            taiKhoan->hienThiThongTin();
            cout << "---------------------------" << endl;
        }
    }

    void hienThiDanhSachTaiKhoanVayMuon() {
        for (TaiKhoanVayMuon* taiKhoan : danhSachTaiKhoanVayMuon) {
            taiKhoan->hienThiThongTin();
            cout << "---------------------------" << endl;
        }
    }
    void chuyenKhoanGiuaTaiKhoanThanhToan(string maTaiKhoanGuiTien, string maTaiKhoanNhanTien, double soTien) {
        // Tìm tài khoản gửi tiền trong danh sách tài khoản thanh toán
        TaiKhoanThanhToan* taiKhoanGuiTien = nullptr;
        for (TaiKhoanThanhToan* taiKhoan : danhSachTaiKhoanThanhToan) {
            if (taiKhoan->getMaTaiKhoan() == maTaiKhoanGuiTien) {
                taiKhoanGuiTien = taiKhoan;
                break;
            }
        }

        // Tìm tài khoản nhận tiền trong danh sách tài khoản thanh toán
        TaiKhoanThanhToan* taiKhoanNhanTien = nullptr;
        for (TaiKhoanThanhToan* taiKhoan : danhSachTaiKhoanThanhToan) {
            if (taiKhoan->getMaTaiKhoan() == maTaiKhoanNhanTien) {
                taiKhoanNhanTien = taiKhoan;
                break;
            }
        }

        // Kiểm tra nếu cả hai tài khoản tồn tại
        if (taiKhoanGuiTien != nullptr && taiKhoanNhanTien != nullptr) {
            // Kiểm tra số dư trong tài khoản gửi tiền
            if (taiKhoanGuiTien->getSoDu() >= soTien) {
                taiKhoanGuiTien->setSoDu(taiKhoanGuiTien->getSoDu() - soTien);
                taiKhoanNhanTien->setSoDu(taiKhoanNhanTien->getSoDu() + soTien);
                // cout << "Chuyen tien thanh cong!" << endl;
                // Time();
            } else {
                cout << "Khong du so du de thuc hien giao dich!" << endl;
            }
        } else {
            cout << "Khong tim thay tai khoan!" << endl;
        }

        ofstream file("lichsuchuyenkhoan.txt", ios::app); 

        if (file.is_open()) {
            file << "Ma tai khoan gui tien: " << maTaiKhoanGuiTien << endl;
            file << "Ma tai khoan nhan tien: " << maTaiKhoanNhanTien << endl;
            file << "So tien chuyen khoan: " << soTien << endl;
            file << "Thoi gian: "; 
            TimewriteFileChuyenKhoan(file); 

            file<<endl;
            
            file.close();

            cout << "Chuyen tien thanh cong!" << endl;
            Time();
        } else {
            cout << "Khong the mo file!" << endl;
        }
    }

    void saveTransaction(const Transaction& transaction) {
        transactionHistory.push_back(transaction);
    }

    void saveTransactionToFile(const string& filename) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cout << "Failed to open the file." << endl;
            return;
        }

        for (const Transaction& transaction : transactionHistory) {
            file << "Ma tai khoan gui: " << transaction.maTaiKhoanGui << endl;
            file << "Ma tai khoan nhan: " << transaction.maTaiKhoanNhan << endl;
            file << "So tien: " << transaction.soTien << endl;
            file << "Thoi gian: " << transaction.timestamp << endl;
            file << "---------------------------" << endl;
        }

        file.close();
    }

};



int main() {
    TaiKhoanThanhToan *tk1 = new TaiKhoanCoTheTinDung("1", "Nguyen Van A", 100.000, 5000);
    TaiKhoanThanhToan *tk2 = new TaiKhoanCoTheTinDung("2", "Nguyen Van B", 100.000, 5000);

    TaiKhoanTietKiem *tk3 = new TaiKhoanCoTheTinDung("3", "Nguyen Van C", 100.000, 5.000,0.08,12);

    TaiKhoanVayMuon *tk4 = new TaiKhoanCoTheTinDung("4", "Nguyen Van D", 100.000, 50.000, 0.03);
    Controller *c1 = new Controller();
    c1->themTaiKhoan(tk1);
    c1->themTaiKhoan(tk2);
    c1->themTaiKhoan(tk3);
    c1->themTaiKhoan(tk4);


    //chuyển tiền
    cout<<"---------Chuyen tien------------"<<endl;
    c1->chuyenKhoanGiuaTaiKhoanThanhToan("1", "2", 10.000);
    cout<<"Tk1 sau khi chuyen tien: "<< fixed << setprecision(3)<<tk1->getSoDu()<<endl;
    cout<<"Tk2 sau khi nhan tien: "<< fixed << setprecision(3)<<tk2->getSoDu()<<endl;

    // gửi tiết kiệm
    cout<<"------------Gui tiet kiem----------"<<endl;
    tk3->guiTietKiem();
    // vay tiền
    cout<<"--------------Vay tien--------"<<endl;
    tk4->VayTien();




    //save file
    // tk4->Vay(2000);
    // tk3->guiTienTietKiem(200);

    


    return 0;
}
    