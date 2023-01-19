#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int zombiOlustur() {
    if (rand() % 67 < 10)
        return 11;

    else
        return rand() % 10 + 1;
}

int main() {
	setlocale(LC_ALL,"Turkish");
    srand(time(NULL));
    char enter;

    // oyun değikenleri
    int oyuncuHayatta = true;
    int oyuncuBeceri = 9;
    int oyuncuSkor = 1;
    string oyuncuAdi = "";
    int zombiSayisi = 0;
    int olenZombi = 0;

    // Başlık
    cout << "Zombie War'a Hoş geldin." << endl << "Başlamak için [ENTER] tuşuna bas.";
    cin.get();

    // Oyuncu Adı
    cout << "Adınızı Girin: ";
    cin >> oyuncuAdi;

	
    // kaç zombi ile savaşmak istediğini sor
    cout << "Kaç tane zombiyle savaşmak istiyorsun? ";
    cin >> zombiSayisi;

    cout << "Hayatın için savaşmaya hazır ol, " << oyuncuAdi << "!" << endl;

    // main game loop
    while (oyuncuHayatta && olenZombi < zombiSayisi) {
        // rastgele bir zombi yarat
        int zombiBeceri = zombiOlustur();

        // savaş dizisi
        if (zombiBeceri > 10) {
            cout << endl << "İşte büyük bir zombi geliyor!" << endl;
        }
        else {
            cout << endl << "İşte zombi geliyor " << olenZombi + 1 << endl;
        }

        cout << "Savaş..." << endl;
        sleep(2);

        // zombi oyuncuyu öldürdüğünde
        if (oyuncuBeceri < zombiBeceri) {
            oyuncuHayatta = false;
            cout << "Öldün." << endl;
        }

        // oyuncu zombiyi öldürdüğünde
        else {
            if (oyuncuBeceri - zombiBeceri > 7) {
                cout << "Zombi kaçtı! Öldürmeyi başaramadın" << endl;
                oyuncuSkor = oyuncuSkor * 2;
            }

            else if (oyuncuBeceri - zombiBeceri > 5) {
                cout << "Zombinin kellesini uçurdun!" << endl;
                oyuncuSkor = oyuncuSkor * 2;
            }

            else if (oyuncuBeceri - zombiBeceri > 0) {
                cout << "Zombiyi öldürdün!" << endl;
                oyuncuSkor = oyuncuSkor * 2;
            }

            else {
                cout << "Zombiyi öldürdün ama yaralandın." << endl;
            }

            olenZombi++;
        }

        cout << endl;
        sleep(1);
    }

    // oyun sonu ekranı
    if (olenZombi == zombiSayisi) {
        // zafer
        cout << "Saldırıdan sağ çıktın!" << endl;
    }
    else {
        // bozgun
        cout << "Zombi savaşında hayatını kaybettin." << endl;
    }

    cout << "Öldürülen zombiler: " << olenZombi << endl;
    cout << "Skor: " << oyuncuSkor << endl << endl;
}

