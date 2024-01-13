#include <iostream>
using namespace std;

void tampilanPapan(char papan[3][3]) {
    std::cout << " =====Tic Tac Toe=====" << std::endl;
    std::cout << "       - " << "  - " << "  - " << std::endl; 
    for (int i = 0; i < 3 ; ++i) {
    	std::cout << "     |";
        for (int j = 0; j < 3; ++j) {
            std::cout << " ";
            if (papan[i][j] == ' ') {
                std::cout << " ";
            } else {
                std::cout << papan[i][j];
            }
            std::cout << " ";
            if (j < 3) {
                std::cout << "|"; 
            }
        }
        std::cout << std::endl;
        if (i < 3) {
            std::cout << "       - " << "  - " << "  - " << std::endl; 
        }
    }
    std::cout << std::endl;
    cout << "   =================" << endl;
    cout << "       -   -   - " << endl;
    cout << "     |0 0|0 1|0 2|" << endl;
    cout << "       -   -   - " << endl;
    cout << "     |1 0|1 1|1 2|" << endl;
    cout << "       -   -   - " << endl;
    cout << "     |2 0|2 1|2 2|" << endl;
    cout << "       -   -   - " << endl;
    cout << "   =================" << endl;
}

bool cekPemenang(char papan[3][3], char pemain) {
    for (int i = 0; i < 3; ++i) {
        if ((papan[i][0] == pemain && papan[i][1] == pemain && papan[i][2] == pemain) || (papan[0][i] == pemain && papan[1][i] == pemain && papan[2][i] == pemain)) {
            return true;
        }
    }

    if ((papan[0][0] == pemain && papan[1][1] == pemain && papan[2][2] == pemain) || (papan[0][2] == pemain && papan[1][1] == pemain && papan[2][0] == pemain)) {
        return true;
    }

    return false;
}

bool penuhPenuh(char papan[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (papan[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char papan[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char pemainSekarang = 'X';
	string nama1, nama2;
	
	cout << "Masukan Nama Makhluq X : ";
    cin >> nama1;
    cout << "Masukan Nama Makhluq O : ";
    cin >> nama2;
    std::cout << std::endl;
    cout << "(X) : " << nama1 << endl;
	cout << "(O) : " << nama2 << endl;
	
    while (true) {
        tampilanPapan(papan);

        int baris, kolom;
        std::cout << "Makhluq " << pemainSekarang << " : ";
        std::cin >> baris >> kolom;

        if (baris < 0 || baris >= 3 || kolom < 0 || kolom >= 3 || papan[baris][kolom] != ' ') {
            std::cout << "Salahhh." << std::endl;
            continue;
        }

        papan[baris][kolom] = pemainSekarang;

        if (cekPemenang(papan, pemainSekarang)) {
            tampilanPapan(papan);
            std::cout << "Pemain " << pemainSekarang << " menanggg!" << std::endl;
            break;
        }

        if (penuhPenuh(papan)) {
            tampilanPapan(papan);
            std::cout << "seriii!" << std::endl;
            break;
        }

        pemainSekarang = (pemainSekarang == 'X') ? 'O' : 'X';
    }

    return 0;
}
