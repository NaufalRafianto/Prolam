#include <iostream>
#include <vector>
#include <string>


#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

int main(int argc, char** argv)
{
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih;
	int student = 0, lecturer = 0, staff = 0; 

    string id, name, studentID, staffID, department, unit, showGPA, repeat;
    int bornYear, bornMonth, bornDay, yearEntry, education;

	while(1) {
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
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;

		switch (menu_terpilih) {
			case 1:{
                student++;
				id = "std" + to_string(student);
				cout << "Masukkan Nama Mahasiswa: ";
                getline(cin,name);
                cout << "Masukkan Tanggal lahir : ";
                cin >> bornDay;
                cout << "Masukkan Bulan lahir : ";
                cin >> bornMonth;
                cout << "Masukkan Tahun lahir : ";
                cin >> bornYear;
                cout << "Masukkan NRP : ";
                cin >> studentID;
                cout << "Masukkan Departemen : ";
                getline(cin,department);
                cout << "Masukkan Tahun Masuk : ";
                cin >> yearEntry;
                mahasiswa inputStudent = mahasiswa(id, name, bornDay, bornMonth, bornYear, staffID, department, education);
                recMhs.push_back(inputStudent);
			}
				break;
			case 2:{
				lecturer++;
				system("clear");
				id = "lct" + to_string(student);
				cout << "Masukkan Nama Dosen: ";
                cin >> name;
                cout << "Masukkan Nama Mahasiswa: ";
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
				staff++;
				system("clear");
				id = "stf" + to_string(staff);
				cout << "Masukkan Nama tendik : ";
                cin>>name;
                cout << "Masukkan Tanggal lahir : ";
                cin >> bornDay;
                cout << "Masukkan Bulan lahir : ";
                cin >> bornMonth;
                cout << "Masukkan Tahun lahir : ";
                cin >> bornYear;
                cin >> bornMonth;
                cout << "Masukkan NPP : ";
                cin >> staffID;
                cout << "Masukkan Unit : ";
                cin >> unit;
                tendik inputTendik = tendik(id, name, bornDay, bornMonth, bornYear, staffID, unit);
                recTendik.push_back(inputTendik);
			}
				break;
			case 4:{
                system("clear");
                    for (int i = 0; i < recMhs.size(); i++)
					{
						cout << "Nama: " << recMhs[i].getNama() << endl;
						cout << "Tgl lahir: " << recMhs[i].getTglLahir();
						cout << "/" << recMhs[i].getBulanLahir();
						cout << "/" << recMhs[i].getTahunLahir() << endl;
						cout << "NRP: " << recMhs[i].getNRP() << endl;
						cout << "Departemen: " << recMhs[i].getDepartment() << endl << endl;
					}
            }
				break;
			case 5:{
                system("clear");
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
                // membersihkan layar konsol
                system("clear");
                // menampilkan data
                for(int i = 0; i < staff; i++){
                    cout << i+1 << ". data tendik dengan id: " << recTendik[i].getId() << endl;
                    cout << "\tNama        : " << recTendik[i].getNama() << endl;
                    cout << "\tTanggal Lahir    : " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
                    cout << "\tNPP         : " << recTendik[i].getNPP() << endl;
                    cout << "\tUnit        : " << recTendik[i].getUnit() << endl << endl;
                    }
                } break;
		    }
        } 
	return 0;
}
