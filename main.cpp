#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cctype>  

using namespace std;

char getUserChoice() {
    char choice;
    cout << "A または B を選んでください: ";
    cin >> choice;
    choice = toupper(choice);

    while (choice != 'A' && choice != 'B') {
        cout << "無効な入力です。A または B を入力してください: ";
        cin >> choice;
        choice = toupper(choice);
    }

    return choice;
}

class DokiGame {
private:
    int round;
    vector<char> history;  

public:
    DokiGame() : round(1) {}

    void play() {
        srand(time(0)); 

        while (true) {
            cout << "\n【ラウンド " << round << "】" << endl;

            char userChoice = getUserChoice();
            history.push_back(userChoice);  

            char correctChoice = (rand() % 2 == 0) ? 'A' : 'B';

            if (userChoice == correctChoice) {
                cout << ">>> 当たり！" << endl;
                round++;

                if (round > 10) {
                    cout << "\n🎉 ゲームクリア！10ラウンド成功しました 🎉\n";
                    showHistory();
                    break;
                }
            } else {
                cout << ">>> ハズレ！";
                cout << "ゲームオーバー。ラウンド1から再スタートします。\n";
                showHistory(); 
                reset();
            }
        }
    }

    void reset() {
        round = 1;
        history.clear();
    }

    void showHistory() {
        cout << "\n▶ 選択履歴:\n";
        int r = 1;
        for (auto it = history.begin(); it != history.end(); ++it) {
            cout << "  ラウンド " << r++ << ": " << *it << endl;
        }
    }
};

int main() {
    DokiGame game;
    game.play();

    return 0;
}
