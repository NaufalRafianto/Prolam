#include <iostream>
#include <vector>
#include <string>


#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

void cls(){
    system("cls")&&system("clear");
}

int main()
{
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih;
	int idS = 0, idL = 0, idSt = 0, idUser = 0; 

    string id, name, studentID, staffID, department, unit, showGPA, user, menuAdmin; 
    char repeat, mengeditIP;
    int bornYear, bornMonth, bornDay, yearEntry, education, semester;
    int menu = 0;
    cout << "Login as: ";
    cin >> user;

    if(user == "Admin" or user == "admin"){
        menu = 1;
    } else if(user == "Mahasiswa" or user == "mahasiswa"){
        menu = 2;
    }else if(user == "tendik" or user == "Tendik")
    {
        menu = 3;
    }else if(user == "dosen" or user == "Dosen"){
        menu = 4;
    }else
    {
        cout << "User was not Found" << endl;
    }

    while(1) {
        cls();
		cout << "Selamat datang di Institut Teknologi Suka Suka" << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " mahasiswa" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " mahasiswa" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
        cout << "  7. Ganti User" << endl;
        cout << "  8. Tutup Program" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		switch (menu_terpilih) {
			case 1:{
                cls();
                ++idS;
				cout << "Masukkan Nama Mahasiswa: ";
                getline(cin >> ws ,name);
                cout << "Masukkan Tanggal lahir : ";
                cin >> bornDay;
                cout << "Masukkan Bulan lahir : ";
                cin >> bornMonth;
                cout << "Masukkan Tahun lahir : ";
                cin >> bornYear;
                cout << "Masukkan NRP : ";
                cin >> studentID;
                cout << "Masukkan Departemen : ";
                getline(cin>>ws, department);
                cout << "Masukkan Tahun Masuk : ";
                cin >> yearEntry;
                cout << "Masukkan Semester: ";
                cin >> semester;
                mahasiswa inputStudent = mahasiswa(id, name, bornDay, bornMonth, bornYear, studentID, department, semester);
                recMhs.push_back(inputStudent);
			}
				break;
			case 2:{
                cls();
				idL++;
				cout << "Masukkan Nama Dosen: ";
                cin >> name;
                cout << "Masukkan Tanggal lahir : ";
                cin >> bornDay;
                cout << "Masukkan Bulan lahir : ";
                cin >> bornMonth;
                cout << "Masukkan Tahun lahir : ";
                cin >> bornYear;
                cout << "Masukkan NPP : ";
                cin >> staffID;
                cout << "Masukkan Departemen : ";
                cin >> department;
                cout << "Masukkan Riwayat Pendidikan : ";
                cin >> education;
                dosen inputLecturer = dosen(id, name, bornDay, bornMonth, bornYear, staffID, department, education);
                recDosen.push_back(inputLecturer);
			}
				break;
			case 3:{
                cls();
				idSt++;
				cout << "Masukkan Nama tendik : ";
                cin>>name;
                cout << "Masukkan Tanggal lahir : ";
                cin >> bornDay;
                cout << "Masukkan Bulan lahir : ";
                cin >> bornMonth;
                cout << "Masukkan Tahun lahir : ";
                cin >> bornYear;
                cout << "Masukkan NPP : ";
                cin >> staffID;
                cout << "Masukkan Unit : ";
                getline(cin, unit);
                tendik inputTendik = tendik(id, name, bornDay, bornMonth, bornYear, staffID, unit);
                recTendik.push_back(inputTendik);
			}
				break;
			case 4:{
                    if(recMhs.size() == 0){
                        cout << "Data tidak ditemukan!" << endl;
                        cout << "Tekan apapun untuk kembali ke menu..."<<endl;
                        return main();
                    }else if(recMhs.size() != 0){
                    for (int i = 0; i < recMhs.size(); i++){
                        cout << "Nama: " << recMhs[i].getNama() << "( " << idUser << " )" <<endl;
                    }
                        cout << "Pilih berdasarkan ID: ";
                        cin>> idUser;
                    }
                    if ((idUser > recMhs.size())){
                        cls();
                        cout << "Data tidak ditemukan!" << endl;
                        cout << "Tekan apapun untuk kembali ke menu..." <<endl;
                        return main();
                    }
                    cls();
                    for(int i=0; i<recMhs.size(); i++) {
                    cout << "---------------------------------- Data Mahasiswa --------------------------------" << endl;
                    cout << " ID Mahasiswa: " << idUser << endl;
                    cout << "Nama : " << recMhs[i].getNama() << endl;
                    cout << "Tanggal Lahir : " << recMhs[i].getTglLahir() << "/" << recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir()<<endl;
                    cout << "NRP : " << recMhs[i].getNRP() << endl;
                    cout << "Departemen : " << recMhs[i].getDepartment() << endl;
                    // cout << "Tahun Masuk : " << recMhs[i].getTahunMasuk() << endl;
                    cout << "Semester : " << recMhs[i].getSemester() << endl;
                    cout << "Jumlah SKS yang Lulus : " << recMhs[i].getSKSLulus() << endl;
                    }
                    cout<<"Pilih Salah satu : "<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                    cout<<"Menu IP: ";
                    cout << "  1. Input IP " << endl;
					cout << "  2. Lihat IP " << endl;
					cout << "  3. Edit Data" << endl;
					cout << "  4. Hapus Data" << endl;
					cout << "  5. Kembali ke Menu Utama" << endl;
                    cin>>mengeditIP;
                    
            }       
				break;
			case 5:{
                for (int i = 0; i < recDosen.size(); i++)
					{
						cout << "Nama: " << recDosen[i].getNama() << endl;
						cout << "Tgl lahir: " << recDosen[i].getTglLahir();
						cout << "/" << recDosen[i].getBulanLahir();
						cout << "/" << recDosen[i].getTahunLahir() << endl;
						cout << "NRP: " << recDosen[i].getNPP() << endl;
						cout << "Pendidikan: S" << recDosen[i].getPendidikan() << endl;
						cout << "Departemen: " << recDosen[i].getDepartment() << endl << endl;
					}
            } break;
			case 6:{
                for(int i = 0; i < idSt; i++){
                    cout << i+1 << ". data tendik dengan id: " << recTendik[i].getId() << endl;
                    cout << "\tNama        : " << recTendik[i].getNama() << endl;
                    cout << "\tTanggal Lahir    : " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
                    cout << "\tNPP         : " << recTendik[i].getNPP() << endl;
                    cout << "\tUnit        : " << recTendik[i].getUnit() << endl << endl;
                    }
                } break;
                
        } 
                // cout<<"Apakah Ingin Melanjutkan? (Y/N)";
                // cin >>repeat;
                // if(repeat=='n' or repeat =='N'){
                //     break;
		        // }else if(repeat =='y' or repeat =='Y'){
                //     return main();
                // }
    }
	return 0;
}

