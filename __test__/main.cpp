#include "main.h"

s21::map<int, int> initMap() {
    s21::map<int, int> data;

    data.insert(std::make_pair(1000, 1000));
    data.insert(std::make_pair(1050, 1050));
    data.insert(std::make_pair(950, 950));
    data.insert(std::make_pair(700, 700));
    data.insert(std::make_pair(960, 960));
    data.insert(std::make_pair(1030, 1030));
    data.insert(std::make_pair(1100, 1100));
    data.insert(std::make_pair(1150, 1150));
    data.insert(std::make_pair(1200, 1200));
    data.insert(std::make_pair(1250, 1250));
    data.insert(std::make_pair(1220, 1220));
    data.insert(std::make_pair(600, 600));
    data.insert(std::make_pair(650, 650));

    return data;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
