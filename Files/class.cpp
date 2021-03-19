#include <iostream>
#include <cstdlib>  //do generowania "randomowych" liczb oraz aby moc uzyc makra EXIT_SUCCESS do poprawnego zakonczenia programu
#include <ctime>    //biblioteka do czasu
#include <string>
#include <fstream>
#include <limits>
using namespace std;
string wyswietlenie, wyswietlenie2;
class NumberGuessingGame
{
public:
    NumberGuessingGame(); //konstruktor
    void Introduction();   //metoda do przywitania sie z graczem
    bool CheckGuess(int& g);    //metoda zwracajac tru albo false, w zaleznosci czy zgadlismy czy nie
    void Start(); //implementacja sprawdza input czy jest liczba

private:
    int RandNumber;   //przechowanie wylosowanej liczby przez program
    int Tries;  //ilosc prob
    float Guess;  //przechowuje nasza zgadywana liczbe
};
//konstruktor, wylosowanie liczby, ustawienie ilosci prob na 0, ustawienie naszego wyboru liczby na 0
//(tworze liste inicjalizujaca poczatkowe wrtosci prywatnych zmiennych)
NumberGuessingGame::NumberGuessingGame() : RandNumber(rand() % 100 + 1), Tries(0), Guess(0)  //generacja liczby z zakresu od 1 do 100, funkcja z <cstdlib>
{}//pusty blok w konstruktorze

void NumberGuessingGame::Introduction() {   //wyseitla zasady gry i wita sie z uzytkownikiem
    cout << "\tWitaj w grze Number_Guessing_Game!\n\n";
    cout << "\t Zasady gry:\nZgadnij liczbe wygenerowana przez komputer z zakresu od 1 do 100.\n";
    cout << "Za kazdym razem jak wpiszesz liczbe, program powie Ci czy jestes nizej czy wyzej nad liczba.\n";
    cout << "W przypadku trafienia, program powiadomi Cie ze zgadles i zapyta o zapis wyniku do pliku i wyswietlenie zawartosci pliku na ekranie.\n";
    cout << "Aby wyjsc z gry, wpisz liczbe 101\n\n";
    cout << "\tPowodzenia!\n\n";
    cout << "Wpisz liczbe:\n";
}

bool NumberGuessingGame::CheckGuess(int& g) {
    if (g < 1) {
        cout << "Podana liczba jest mniejsza od 1, sprobuj jeszcze raz!\n\n";
        return false;
    }
    else if (g > 101) {
        cout << "Podana liczba jest wieksza od 100, sprobuj jeszcze raz!\n\n";
        return false;
    }
    else if (g == 101) {
        cout << "Wyjscie z programu. ";
        exit(EXIT_SUCCESS); //program zakonczyl sie prawidlowo
    }
    else if (g > RandNumber) {
        cout << "Podana liczba jest za duza, sprobuj jeszcze raz!\n\n";
        return false;
    }
    else if (g < RandNumber) {
        cout << "Podana liczba jest za mala, sprobuj jeszcze raz!\n\n";
        return false;
    }
    else if (g == RandNumber) {
        cout << "Gratulacje! zgadles wylosowana liczbe!\n";
        cout << "Zgadles liczbe w " << Tries << " probach.\n";
        cout << "Czy chcesz zapisac wyniki do pliku wyniki.txt?  [y/n]\n";
        cin >> wyswietlenie;
        while (1) {
            if (wyswietlenie == "y") {
                string sciezka, linia;
                ofstream plik;  //tworze plik do ktorego bede zapisywac dane
                sciezka = "wyniki.txt";
                plik.open(sciezka);
                plik << "Wyniki gry Game_Guessing_number:\n";   //zapisuje do pliku wyniki
                plik << "Zgadles liczbe w " << Tries << " probach.\n";
                plik.close();   //zamykam plik
                cout << "\t\t ZAPISANO PLIK: wyniki.txt\n\n";
                cout << "Chcesz wyswietlic zawartosc pliku wyniki.txt?  [y/n]\n";
                //wyswietlenie zawartosci pliku wyniki.txt
                cin >> wyswietlenie2;
                while (1) {
                    if (wyswietlenie2 == "y") {
                        fstream plik2;
                        plik2.open(sciezka);
                        if (plik2.good() == true)
                        {
                            while (!plik2.eof())    //eof - end of line, zwraca true gdy osiagnieto koniec pliku, tu zaprzeczam aby zwrocilo false jak znajdzie koniec
                            {
                                getline(plik2, linia);
                                cout << linia << endl; //wyswietlenie wszystkich linii z pliku
                            }
                            plik2.close();
                        }
                        break;
                    }
                    //nie wyswietla pliku
                    else if (wyswietlenie2 == "n") {
                        break;
                    }
                    //przypadek jak nie wpiszemy ani 'y' ani 'n'
                    else
                    {
                        cout << "Wpisz 'y' albo 'n':\n";
                        cin >> wyswietlenie2;
                        continue;
                    }
                    cout << "Nacisnij enter aby zagrac jeszcze raz!\n\n";
                    break;
                }
            }//plik nie zostal zapisany
            else if (wyswietlenie == "n") {
                cout << "\t\tPLIK NIE ZOSTAL ZAPISANY\n";
                cout << "Nacisnij enter aby zagrac jeszcze raz!\n\n";
                break;
            }//ani 'y' ani 'n' nie zostalo podane
            else {
                cout << "Wpisz 'y' albo 'n':\n";
                cin >> wyswietlenie;
                continue;
            }
            cout << "Nacisnij enter aby zagrac jeszcze raz!\n\n";
            break;  //wyjscie z petli zapisu do pliku
        }
    }
}
void NumberGuessingGame::Start() {
    int x = 0;
    while (1) {
        if (!(cin >> Guess)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Niepoprawne wprowadzenie danych.  Sprobuj ponownie: \n";
        }

        else {
            x = round(Guess);   //zaokraglam liczbe zmiennoprzeciknowa
            ++Tries;
            cout << "Wpisales: " << x << endl;
            if (CheckGuess(x)) {    //jezeli jest true to break
                break;
            }
        }
    }
}