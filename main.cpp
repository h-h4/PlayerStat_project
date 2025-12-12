#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

class PlayerStat {
private:
    int Stat[7]{ 0, 0, 0, 0, 0, 0, 0 };
    const int HP_INDEX = 0;
    const int MP_INDEX = 1;
    const int ATTACKP_INDEX = 2;
    const int DEFENSEP_INDEX = 3;
    const int HPP_INDEX = 4;
    const int MPP_INDEX = 5;
    const int LEV_INDEX = 6;

public:
    void setHP(int newHP) { Stat[HP_INDEX] = newHP; }
    void setMP(int newMP) { Stat[MP_INDEX] = newMP; }
    void setATT(int newATT) { Stat[ATTACKP_INDEX] = newATT; }
    void setDEF(int newDEF) { Stat[DEFENSEP_INDEX] = newDEF; }
    void addHP(int addHP) { Stat[HP_INDEX] += addHP; }
    void addMP(int addMP) { Stat[MP_INDEX] += addMP; }
    void addHPP(int newHPP) { Stat[HPP_INDEX] += newHPP; }
    void addMPP(int newMPP) { Stat[MPP_INDEX] += newMPP; }
    void addLEV(int newLEV) { Stat[LEV_INDEX] += newLEV; }

    int getHP() const { return Stat[HP_INDEX]; }
    int getMP() const { return Stat[MP_INDEX]; }
    int getATT() const { return Stat[ATTACKP_INDEX]; }
    int getDEF() const { return Stat[DEFENSEP_INDEX]; }
    int getHPP() const { return Stat[HPP_INDEX]; }
    int getMPP() const { return Stat[MPP_INDEX]; }
    int getLEV() const { return Stat[LEV_INDEX]; }
    void mystat() {
        std::cout << "\n나의 레벨 : " << getLEV();
        std::cout << "\n가지고 있는 포션 : " << getHPP() << " / " << getMPP();
        std::cout << "\n현재 스탯 : \n체력:" << getHP() << "\n마나:" << getMP() << "\n공격력:" << getATT() << "\n방어력:" << getDEF() << std::endl;
    }
};

enum class PotionType {
    HPP, MPP
};
enum class LevelUPType {
    ATT, DEF, LEV
};


void usePotion(PlayerStat& stat, PotionType type) {
    switch (type) {
    case PotionType::HPP:
        if (stat.getHPP() > 0) {
            stat.addHPP(-1);
            stat.addHP(+20);
            std::cout << "HP 포션을 사용해서 체력을 20 회복했습니다!\n [현재 HP 포션은 : " << stat.getHPP() << " 개 남았습니다!]" << std::endl;
        }
        else {
            std::cout << "HP 포션이 남아있지 않습니다!" << std::endl;
        }
        break;

    case PotionType::MPP:
        if (stat.getMPP() > 0) {
            stat.addMPP(-1);
            stat.addMP(+20);
            std::cout << "MP 포션을 사용해서 마나를 20 회복했습니다!\n [현재 MP 포션은 : " << stat.getMPP() << " 개 남았습니다!]" << std::endl;
        }
        else {
            std::cout << "MP 포션이 남아있지 않습니다!" << std::endl;
        }
        break;
    }
}
void LevelUP(PlayerStat& stat, LevelUPType type) {
    switch (type) {
    case LevelUPType::ATT: {
        int newATT = 2 * stat.getATT();
        stat.setATT(newATT);
        std::cout << "공격력이 2배 증가되었습니다!\n현재 공격력은 : " << stat.getATT() << " 입니다!" << std::endl;
        break;
    }

    case LevelUPType::DEF: {
        int newDEF = 2 * stat.getDEF();
        stat.setDEF(newDEF);
        std::cout << "방어력이 2배 증가되었습니다!\n현재 방어력은 : " << stat.getDEF() << " 입니다!" << std::endl;
        break;
    }
    case LevelUPType::LEV: {
        stat.addLEV(1);
        std::cout << "레벨업을 하셨습니다! 현재 레벨은 : " << stat.getLEV() << " 입니다!" << std::endl;
        stat.addHPP(3);
        stat.addMPP(3);
        std::cout << "포션이 지급되었습니다! \n가지고 있는 포션 수 : " << stat.getHPP() << " / " << stat.getMPP() << std::endl;
        break;
    }

    }
}

void displayMenu() {
    std::cout << "\n=============================================" << std::endl;
    std::cout << "|             <스탯 관리 시스템>            |" << std::endl;
    std::cout << "|===========================================|" << std::endl;
    std::cout << "|  1. 체력 포션 사용  |  2. 마나 포션 사용  |" << std::endl;
    std::cout << "|  3. 공격력 UP       |  4. 방어력 UP       |" << std::endl;
    std::cout << "|  5. 현재 능력치     |  6. Level UP        |" << std::endl;
    std::cout << "|  0. 나가기          |                     |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "메뉴 선택 (0-6) : ";
}



int main() {
    PlayerStat player;
    std::string userInput;
    int choice;
    std::cout << "초기 HP와 MP를 입력해주세요 : " << std::endl;

    int inputHP, inputMP;
    while (true) {
        std::getline(std::cin, userInput); 
        std::stringstream split(userInput); 

        if (split >> inputHP && split >> inputMP) {
            if (inputHP >= 50 && inputMP >= 50 && inputHP <= 100 && inputMP <= 100) {
                player.setHP(inputHP);
                player.setMP(inputMP);
                break;
            }
            else {
                std::cout << "초기 HP와 MP는 50 ~ 100 사이로 설정해주세요!\n다시 입력해주세요 : " << std::endl;
            }
        }
        else {
            std::cout << "[경고] 입력 형식이 올바르지 않습니다. 두 개의 숫자를 공백으로 구분하여 입력해주세요. (ex. 60 72)\n" << std::endl;
        }
    }

    std::cout << "초기 공격력과 방어력을 입력해주세요 : " << std::endl;
    int inputATT, inputDEF;
    while (true) {
        std::getline(std::cin, userInput);
        std::stringstream split(userInput); 

        if (split >> inputATT && split >> inputDEF) {
            if (inputATT > 0 && inputDEF > 0 && inputATT < 10 && inputDEF < 10) {
                player.setATT(inputATT);
                player.setDEF(inputDEF);
                break;
            }
            else {
                std::cout << "초기 공격력과 방어력은 1 ~ 10 사이로 설정해주세요!\n다시 입력해주세요 : " << std::endl;
            }
        }
        else {
            std::cout << "[경고] 입력 형식이 올바르지 않습니다. 두 개의 숫자를 공백으로 구분하여 입력해주세요. (ex. 60 72)\n" << std::endl;
        }
    }



    std::cout << "\n[설정 완료]\n";
    player.mystat();
    player.addHPP(5);
    player.addMPP(5);
    std::cout << "[초기 아이템 지급] : HP 포션과 MP 포션을 5개씩 지급받았습니다!\n";
    std::cout << "[시스템] : 잠시 후 스탯 관리 프로그램이 시작됩니다!" << std::endl;
    Sleep(2000);
    do {
        system("cls");
        displayMenu();

        if (!(std::cin >> choice)) {
            choice = -99;
            std::cout << "\n[오류] 잘못된 입력입니다. 정확한 번호를 입력 해 주십시오. \n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "[알림] 계속하려면 Enter키를 입력하십시오...";
            std::cin.get();

            continue;
        }
        std::cin.ignore(10000, '\n');

        switch (choice) {
        case 1:
            usePotion(player, PotionType::HPP);
            break;
        case 2:
            usePotion(player, PotionType::MPP);
            break;
        case 3:
            LevelUP(player, LevelUPType::ATT);
            break;
        case 4:
            LevelUP(player, LevelUPType::DEF);
            break;
        case 5:
            player.mystat();
            break;
        case 6:
            LevelUP(player, LevelUPType::LEV);
            break;
        case 0:
            std::cout << "시스템을 종료합니다." << std::endl;
            break;
        default:
            std::cout << "\n[경고] 메뉴 번호는 0에서 6 사이여야 합니다.\n";
            break;
        }
        if (choice != 0) {
            std::cout << "\n[알림] 확인하셨다면 Enter키를 눌러주세요.";
            std::cin.get();
        }
    } while (choice != 0);
}