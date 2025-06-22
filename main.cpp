#include <iostream>
#include <cmath>
#include <clocale>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>

using namespace std;

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    LightGray = 7,
    Gray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    LightYellow = 14,
    White = 15
};

void SetColor(ConsoleColor text, ConsoleColor background = Black) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
}

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    const int BRONZE = 1;
    const int BRASS = 2;
    const int BISMUTH_BRONZE = 3;
    const int BLACK_BRONZE = 4;
    const int MOLYBDENUM_BRONZE = 5;
    const int LEAD_SOLDER = 6;
    const int SILVER_SOLDER = 7;
    const int NICKEL_SILVER = 8;
    const int ELECTRUM = 9;

    struct Alloy {
        wstring name;
        double ratio1;
        wstring ore1;
        double ratio2;
        wstring ore2;
        double ratio3;
        wstring ore3;
    };

    Alloy alloys[] = {
        {L"Бронза", 0.8, L"Медная руда", 0.2, L"Оловянная руда", 0.0, L""},
        {L"Латунь", 0.6, L"Медная руда", 0.4, L"Цинковая руда", 0.0, L""},
        {L"Висмутовая бронза", 0.6, L"Медная руда", 0.25, L"Цинковая руда", 0.15, L"Висмутиновая руда"},
        {L"Чёрная бронза", 0.76, L"Медная руда", 0.12, L"Золотая руда", 0.12, L"Серебряная руда"},
        {L"Молибдохалк", 0.1, L"Медная руда", 0.9, L"Свинцовая руда", 0.0, L""},
        {L"Свинцовый припой", 0.5, L"Свинцовая руда", 0.5, L"Оловянная руда", 0.0, L""},
        {L"Серебряный припой", 0.55, L"Оловянная руда", 0.45, L"Серебряная руда", 0.0, L""},
        {L"Мельхиор", 0.7, L"Медная руда", 0.3, L"Никелевая руда", 0.0, L""},
        {L"Электрум", 0.5, L"Серебряная руда", 0.5, L"Золотая руда", 0.0, L""}
    };

    const int ORE_TO_ALLOY = 5;

    SetColor(LightGreen);
    wcout << L"██╗   ██╗██╗███╗   ██╗████████╗ █████╗  ██████╗ ███████╗    ███████╗████████╗ ██████╗ ██████╗ ██╗   ██╗" << endl;
    wcout << L"██║   ██║██║████╗  ██║╚══██╔══╝██╔══██╗██╔════╝ ██╔════╝    ██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝" << endl;
    wcout << L"██║   ██║██║██╔██╗ ██║   ██║   ███████║██║  ███╗█████╗      ███████╗   ██║   ██║   ██║██████╔╝ ╚████╔╝ " << endl;
    wcout << L"╚██╗ ██╔╝██║██║╚██╗██║   ██║   ██╔══██║██║   ██║██╔══╝      ╚════██║   ██║   ██║   ██║██╔══██╗  ╚██╔╝  " << endl;
    wcout << L" ╚████╔╝ ██║██║ ╚████║   ██║   ██║  ██║╚██████╔╝███████╗    ███████║   ██║   ╚██████╔╝██║  ██║   ██║   " << endl;
    wcout << L"  ╚═══╝  ╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚══════╝    ╚══════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   " << endl;
    wcout << L"                                                                                                       " << endl;
    SetColor(LightBlue);
    wcout << L" ██████╗ █████╗ ██╗      ██████╗██╗   ██╗██╗      █████╗ ████████╗ ██████╗ ██████╗                     " << endl;
    wcout << L"██╔════╝██╔══██╗██║     ██╔════╝██║   ██║██║     ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗                    " << endl;
    wcout << L"██║     ███████║██║     ██║     ██║   ██║██║     ███████║   ██║   ██║   ██║██████╔╝                    " << endl;
    wcout << L"██║     ██╔══██║██║     ██║     ██║   ██║██║     ██╔══██║   ██║   ██║   ██║██╔══██╗                    " << endl;
    wcout << L"╚██████╗██║  ██║███████╗╚██████╗████████║███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║                    " << endl;
    wcout << L" ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝                    " << endl;
    wcout << L"                                                                                                       " << endl;
    wcout << L"By YarlchkaT" << endl << endl;
    SetColor(Gray);
    wcout << L"|=====================================================================================================|" << endl << endl;
    SetColor(White);

    int alloyChoice;
    do {
        wcout << L"Выберите сплав:" << endl << endl;
        SetColor(LightYellow); wcout << L"1. Оловянная Бронза (80% медь, 20% олово)" << endl;
        SetColor(Yellow);  wcout << L"2. Латунь (60% медь, 40% цинк)" << endl;
        SetColor(Yellow);   wcout << L"3. Висмутовая бронза (60% медь, 25% цинк, 15% висмут)" << endl;
        SetColor(Gray);        wcout << L"4. Чёрная бронза (76% медь, 12% золото, 12% серебро)" << endl;
        SetColor(Gray);    wcout << L"5. Молибдохалк (10% медь, 90% свинец)" << endl;
        SetColor(LightGray);      wcout << L"6. Свинцовый припой (50% свинец, 50% олово)" << endl;
        SetColor(White);       wcout << L"7. Серебряный припой (55% олово, 45% серебро)" << endl;
        SetColor(LightYellow);   wcout << L"8. Мельхиор (70% медь, 30% никель)" << endl;
        SetColor(LightYellow); wcout << L"9. Электрум (50% серебро, 50% золото)" << endl << endl;
        SetColor(White);
        wcout << L"Ваш выбор: ";
        wcin >> alloyChoice;

        if (alloyChoice < 1 || alloyChoice > 9) {
            SetColor(LightRed);
            wcout << L"Неверный выбор. Пожалуйста, введите число от 1 до 9." << endl;
            SetColor(White);
        }
    } while (alloyChoice < 1 || alloyChoice > 9);

    Alloy selected = alloys[alloyChoice - 1];

    SetColor(LightCyan);
    wcout << endl << L"Выбран сплав: " << selected.name << endl;
    wcout << L"Соотношение: " << selected.ratio1 * 100 << L"% " << selected.ore1;
    wcout << L", " << selected.ratio2 * 100 << L"% " << selected.ore2;
    if (selected.ratio3 > 0) {
        wcout << L", " << selected.ratio3 * 100 << L"% " << selected.ore3;
    }
    wcout << endl << endl;
    SetColor(White);

    int alloyNeeded;
    wchar_t repeat;

    do {
        wcout << L"Введите необходимое количество сплава (в единицах): ";
        wcin >> alloyNeeded;

        double totalOre = static_cast<double>(alloyNeeded) / ORE_TO_ALLOY;

        double ore1 = totalOre * selected.ratio1;
        double ore2 = totalOre * selected.ratio2;
        double ore3 = totalOre * selected.ratio3;

        int ore1Rounded = static_cast<int>(ceil(ore1));
        int ore2Rounded = static_cast<int>(ceil(ore2));
        int ore3Rounded = static_cast<int>(ceil(ore3));

        SetColor(LightYellow);
        wcout << endl << L"Результаты расчёта:" << endl;
        SetColor(White);
        wcout << L"Всего нужно руды: ";
        SetColor(LightGreen);
        wcout << totalOre << L" кусочков (" << ceil(totalOre) << L" округлённо)" << endl;
        SetColor(White);
        wcout << L"Из них:" << endl;

        SetColor(LightYellow);
        wcout << L"- " << selected.ore1 << L": " << ore1 << L" (" << ore1Rounded << L") кусочков" << endl;
        wcout << L"- " << selected.ore2 << L": " << ore2 << L" (" << ore2Rounded << L") кусочков" << endl;
        if (selected.ratio3 > 0) {
            wcout << L"- " << selected.ore3 << L": " << ore3 << L" (" << ore3Rounded << L") кусочков" << endl;
        }
        SetColor(White);

        wcout << endl << L"Хотите сделать ещё один расчёт? (y/n): ";
        wcin >> repeat;
    } while (repeat == L'y' || repeat == L'Y');

    SetColor(LightGreen);
    wcout << L"Спасибо за использование калькулятора!" << endl;
    SetColor(White);

    return 0;
}
