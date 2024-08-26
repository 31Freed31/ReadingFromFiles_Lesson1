#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUM_SECTORS = 13;

void loadSectorData(string questionFiles[], string answerFiles[]) {
    for (int i = 0; i < NUM_SECTORS; ++i) {
        questionFiles[i] = "question" + to_string(i + 1) + ".txt";
        answerFiles[i] = "answer" + to_string(i + 1) + ".txt";
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");

    string questionFiles[NUM_SECTORS];
    string answerFiles[NUM_SECTORS];
    bool playedSectors[NUM_SECTORS] = { false };

    loadSectorData(questionFiles, answerFiles);

    int currentSector = 0;
    int playerScore = 0;
    int viewerScore = 0;

    while (playerScore < 6 && viewerScore < 6) {
        int offset;
        cout << "Введите смещение (офсет) для выбора сектора: ";
        cin >> offset;

        currentSector = (currentSector + offset) % NUM_SECTORS;

        while (playedSectors[currentSector]) {
            currentSector = (currentSector + 1) % NUM_SECTORS;
        }

        playedSectors[currentSector] = true;

        ifstream questionFile(questionFiles[currentSector]);
        if (!questionFile.is_open()) {
            cout << "Ошибка открытия файла с вопросом!" << endl;
            continue;
        }

        string question;
        getline(questionFile, question);
        cout << "Вопрос: " << question << endl;
        questionFile.close();

        string playerAnswer;
        cout << "Ваш ответ: ";
        cin >> playerAnswer;

        ifstream answerFile(answerFiles[currentSector]);
        if (!answerFile.is_open()) {
            cout << "Ошибка открытия файла с ответом!" << endl;
            continue;
        }

        string correctAnswer;
        answerFile >> correctAnswer;
        answerFile.close();

        if (playerAnswer == correctAnswer) {
            cout << "Правильно! Вы получаете 1 очко." << endl;
            playerScore++;
        }
        else {
            cout << "Неправильно. Очко уходит зрителям." << endl;
            viewerScore++;
        }

        cout << "Счёт: Игроки " << playerScore << " - " << viewerScore << " Зрители" << endl;
    }

    if (playerScore == 6) {
        cout << "Поздравляем! Игроки выиграли!" << endl;
    }
    else {
        cout << "Зрители выиграли. Попробуйте снова!" << endl;
    }
}