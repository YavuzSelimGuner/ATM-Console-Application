#include <iostream>
#include <clocale>     // Dil kütüphanesi
#include <cstdlib>     // Rand fonksiyonunu kullanabilmek için
#include <ctime>     // Srand fonksiyonunu eklemek için

using namespace std;

class Banka {
public:
	long int hesapNo = 0, sifre = 0;
	long double bakiye = 0.0, kredi = 0.0, faiz = 0.1;
	int secim = 0;
	void menu() {
		cout << "Lütfen aşağıdaki menüden yapmak istediğiniz seçeneği işaretleyiniz: " << endl;
		cout << "1. Giriş yapınız " << endl;
		cout << "2. Yeni bir hesap oluşturunuz " << endl;
		cout << "3. Çıkış " << endl;
		cout << "Seçiminiz= ";
		cin >> secim;
	}
	bool girisYapma() {
		long int hesapKontrol, sifreKontrol;
		cout << "Hesap numaranızı giriniz= ";
		cin >> hesapKontrol;
		cout << "Şifrenizi giriniz= ";
		cin >> sifreKontrol;
		if (hesapKontrol == hesapNo && sifreKontrol == sifre) {     // Kullanıcının girdiği değerleri kontrol etmek için
			cout << "Hoş geldiniz! Sisteme bağlandınız. " << endl;
			return true;
		}
		else {
			cout << "Giriş başarısız oldu! Hesap numaranız veya şifreniz yanlış. " << endl;
			return false;
		}
	}
	void hesapOlustur() {
		cout << "Oluşturmak istediğiniz hesap numaranızı giriniz= ";
		cin >> hesapNo;
		cout << "Oluşturmak istediğiniz hesap şifrenizi giriniz= ";
		cin >> sifre;
		cout << "Teşekkürler! Hesabınız oluşturuldu. " << endl;
	}
	void islem() {
		cout << "4. Hesabınıza para yatırma " << endl;
		cout << "5. Hesabınızdan para çekme " << endl;
		cout << "6. Bakiye görüntüleme " << endl;
		cout << "7. Kredi borcu alma " << endl;
		cout << "8. Kredi borcu sorgulama " << endl;
		cout << "9. Kredi borcu ödeme " << endl;
		cout << "10. Fatura işlemleri " << endl;
		cout << "11. Döviz işlemleri " << endl;
		cout << "12. Hesap şifrenizi değiştirme " << endl;
		cout << "13. Giriş ekranına dönme " << endl;
		cout << "İşleminizi seçiniz= ";
		cin >> secim;
	}
	void paraYatirma() {
		long double para;
		cout << "Hesabınıza yatırmak istediğiniz miktarı giriniz: ";
		cin >> para;
		bakiye += para;
		cout << "İşlem başarılı! " << endl;
	}
	void paraCekme() {
		long double para;
		cout << "Hesabınızdan çekmek istediğiniz miktarı giriniz: ";
		cin >> para;
		if (bakiye < para) {
			cout << "Yetersiz bakiye! " << endl;
		}
		else {
			bakiye -= para;
			cout << "İşlem başarılı! " << endl;
		}
	}
	void krediAlma() {
		long int para;
		cout << "%10 faiz uygulanmaktadır! Lütfen, çekmek istediğiniz kredi miktarını giriniz: ";
		cin >> para;
		kredi = kredi + para + (faiz * para);
		bakiye += para;
		cout << "İşlem başarılı! " << endl;
	}
	void krediSorgulama() {
		if (kredi >= 0)
			cout << "Kredi borcunuz: " << kredi << " TL " << endl;
	}
	void krediOdeme() {
		long int para;
		cout << "Ödemek istediğiniz miktarı giriniz: ";
		cin >> para;
		if (bakiye < para) {
			cout << "Yetersiz bakiye! " << endl;
		}
		if (para > kredi) {
			cout << "Kredi tutarınızdan fazla girdiniz! " << endl;
		}
		if (bakiye >= para) {
			kredi = kredi - para;
			bakiye -= para;
			cout << "İşlem başarılı! " << endl;
		}
	}
	double elektrikFaturasi = rand() % 1000;     //Random olması için
	double suFaturasi = rand() % 500;     // Random olması için
	double dogalgazFaturasi = rand() % 3000;     // Random olması için
	void faturaOdeme() {
		long double para = 0.0;
		cout << "Ödenecek fatura türünü seçiniz: " << endl;
		cout << "14. Elektrik faturası " << endl;
		cout << "15. Su faturası " << endl;
		cout << "16. Doğal gaz faturası " << endl;
		cout << "Seçiminiz= ";
		cin >> secim;
		if (secim == 14) {
			cout << "Elektrik fatura tutarınız: " << elektrikFaturasi << " TL " << endl;
			cout << "Ödenecek tutar: ";
			cin >> para;
			if (para <= bakiye) {
				if (para <= elektrikFaturasi) {
					bakiye -= para;
					elektrikFaturasi -= para;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Faturanızdan yüksek miktar girdiniz! " << endl;
				}
			}
			else {
				cout << "Yetersiz bakiye! " << endl;
			}
		}
		else if (secim == 15) {
			cout << "Su fatura tutarınız: " << suFaturasi << " TL " << endl;
			cout << "Ödenecek tutar: ";
			cin >> para;
			if (para <= bakiye) {
				if (para <= suFaturasi) {
					bakiye -= para;
					suFaturasi -= para;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Faturanızdan yüksek miktar girdiniz! " << endl;
				}
			}
			else {
				cout << "Yetersiz bakiye! " << endl;
			}
		}
		else if (secim == 16) {
			cout << "Doğal gaz fatura tutarınız: " << dogalgazFaturasi << " TL " << endl;
			cout << "Ödenecek tutar: ";
			cin >> para;
			if (para <= bakiye) {
				if (para <= dogalgazFaturasi) {
					bakiye -= para;
					dogalgazFaturasi -= para;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Faturanızdan yüksek miktar girdiniz! " << endl;
				}
			}
			else {
				cout << "Yetersiz bakiye! " << endl;
			}
		}
		else {
			cout << "Tanımsız tuşlama! " << endl;
		}
	}
	int dolarMiktari = 0, euroMiktari = 0, sterlinMiktari = 0;     //Müşterinin sahip olduğu döviz miktarları
	void dovizIslemleri() {
		int dolar = 16, euro = 17, sterlin = 18;     //Kur fiyatları
		int dovizSecim = 0, miktar = 0;
		cout << "17. Döviz alma " << endl;
		cout << "18. Döviz satma " << endl;
		cout << "19. Döviz cüzdanı görüntüleme " << endl;
		cout << "Seçiminiz= ";
		cin >> secim;
		if (secim == 17) {
			cout << "Döviz alma " << endl;
			cout << "Sabit kurlar: " << endl;
			cout << "1. Dolar = " << dolar << " TL " << endl;
			cout << "2. Euro = " << euro << " TL " << endl;
			cout << "3. Sterlin = " << sterlin << " TL " << endl;
			cout << "Seçiminiz= ";
			cin >> dovizSecim;
			if (dovizSecim == 1) {
				cout << "Alacağınız dolar miktarını giriniz: ";
				cin >> miktar;
				cout << "Toplam tutar: " << dolar * miktar << " TL " << endl;
				if (bakiye >= dolar * miktar) {
					bakiye -= dolar * miktar;
					dolarMiktari += miktar;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Yetersiz bakiye! " << endl;
				}
			}
			else if (dovizSecim == 2) {
				cout << "Alacağınız euro miktarını giriniz: ";
				cin >> miktar;
				cout << "Toplam tutar: " << euro * miktar << " TL " << endl;
				if (bakiye >= euro * miktar) {
					bakiye -= euro * miktar;
					euroMiktari += miktar;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Yetersiz bakiye! " << endl;
				}
			}
			else if (dovizSecim == 3) {
				cout << "Alacağınız sterlin miktarını giriniz: ";
				cin >> miktar;
				cout << "Toplam tutar: " << sterlin * miktar << " TL " << endl;
				if (bakiye >= sterlin * miktar) {
					bakiye -= sterlin * miktar;
					sterlinMiktari += miktar;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Yetersiz bakiye! " << endl;
				}
			}
			else {
				cout << "Tanımsız tuşlama! " << endl;
			}
		}
		else if (secim == 18) {
			cout << "Döviz satma " << endl;
			cout << "Sabit kurlar: " << endl;
			cout << "1. Dolar = " << dolar << " TL " << endl;
			cout << "2. Euro = " << euro << " TL " << endl;
			cout << "3. Sterlin = " << sterlin << " TL " << endl;
			cout << "Seçiminiz= ";
			cin >> dovizSecim;
			if (dovizSecim == 1) {
				cout << "Satacağınız dolar miktarını giriniz: ";
				cin >> miktar;
				cout << "Toplam tutar: " << dolar * miktar << " TL " << endl;
				if (dolarMiktari >= miktar) {
					bakiye += dolar * miktar;
					dolarMiktari -= miktar;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Hesabınızda bu kadar dolar yok! " << endl;
				}
			}
			else if (dovizSecim == 2) {
				cout << "Satacağınız euro miktarını giriniz: ";
				cin >> miktar;
				cout << "Toplam tutar: " << euro * miktar << " TL " << endl;
				if (euroMiktari >= miktar) {
					bakiye += euro * miktar;
					euroMiktari -= miktar;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Hesabınızda bu kadar euro yok! " << endl;
				}
			}
			else if (dovizSecim == 3) {
				cout << "Satacağınız sterlin miktarını giriniz: ";
				cin >> miktar;
				cout << "Toplam tutar: " << sterlin * miktar << " TL " << endl;
				if (sterlinMiktari >= miktar) {
					bakiye += sterlin * miktar;
					sterlinMiktari -= miktar;
					cout << "İşlem başarılı! " << endl;
				}
				else {
					cout << "Hesabınızda bu kadar sterlin yok! " << endl;
				}
			}
		}
		else if (secim == 19) {
			cout << "Döviz cüzdanınız: " << endl;
			cout << "1. Dolar= " << dolarMiktari << " dolar " << endl;
			cout << "2. Euro= " << euroMiktari << " euro " << endl;
			cout << "3. Sterlin= " << sterlinMiktari << " sterlin " << endl;
		}
		else {
			cout << "Tanımsız tuşlama! " << endl;
		}
	}
	bool yeniSifre() {
		long int yeniSifre = 0, yedek = 0;
		cout << "Eski şifrenizi giriniz= ";
		cin >> yedek;     // Yedek şuanki şifresini belirtiyor
		if (sifre == yedek) {
			cout << "Şifreniz doğru! Yeni şifrenizi giriniz= ";
			cin >> yeniSifre;
			sifre = yeniSifre;     // Yeni şifre artık asıl şifremiz oluyor
			cout << "Şifreniz başarılı bir şekilde değiştirilmiştir! " << endl;
			return true;
		}
		else {
			cout << "Şifreniz yanlış! Tekrar giriniz. " << endl;
			return false;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Turkish");     // Türkçe karakter kullanabilmek için
	srand(time(0));     // Farklı random sayılar üretmek için
	Banka ATM;
	cout << "Merhaba! Zamar Bankasının ATM makinesine hoş geldiniz... " << endl;
	while (1) {
		ATM.menu();
		if (ATM.secim == 1) {
			if (ATM.girisYapma() == true) {
				while (1) {
					ATM.islem();
					if (ATM.secim == 4) {
						ATM.paraYatirma();
					}
					else if (ATM.secim == 5) {
						ATM.paraCekme();
					}
					else if (ATM.secim == 6) {
						cout << "Hesabınızın mevcut bakiyesi: " << ATM.bakiye << " TL " << endl;
					}
					else if (ATM.secim == 7) {
						ATM.krediAlma();
					}
					else if (ATM.secim == 8) {
						ATM.krediSorgulama();
					}
					else if (ATM.secim == 9) {
						ATM.krediOdeme();
					}
					else if (ATM.secim == 10) {
						ATM.faturaOdeme();
					}
					else if (ATM.secim == 11) {
						ATM.dovizIslemleri();
					}
					else if (ATM.secim == 12) {
						while (1) {
							if (ATM.yeniSifre() == true)
								break;
						}
					}
					else if (ATM.secim == 13) {
						cout << "Giriş ekranına dönülüyor... " << endl;
						break;
					}
					else {
						cout << "Tanımsız tuşlama! " << endl;
					}
				}
			}
		}
		else if (ATM.secim == 2) {
			ATM.hesapOlustur();
		}
		else if (ATM.secim == 3) {
			cout << "Çıkış yaptınız. ";
			break;
		}
	}

	return 0;
}