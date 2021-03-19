// Number_Guessing_Game.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstdlib>  //do generowania "randomowych" liczb oraz aby moc uzyc makra EXIT_SUCCESS do poprawnego zakonczenia programu
#include <ctime>    //biblioteka do czasu
#include <string.h>
#include <string>
#include <limits>
#include <fstream>
#include "class.cpp"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));  //inicjalizacja random number generatora, aby moc wygenerowac potem randomowe wartosci
    //na podstawie podanego seed
    while (1) {
        NumberGuessingGame NewGame;
        NewGame.Introduction();
        NewGame.Start();
        cin.ignore();   //ingoruje wszystkie entery w buforze i nastepnie bedzie czekac na kolejny enter - kod ponizej
        cin.get();  //aby konsola byla otwarta dopoki nie wcisniemy entera
    }
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
