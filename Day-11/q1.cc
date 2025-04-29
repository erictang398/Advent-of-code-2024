#include <bits/stdc++.h>

int main () {
    int num;

    std::vector<long> nums;

    while (std::cin >> num) {
        nums.push_back(num);
    }

    for (int i = 0; i < 25; i++) {
        std::vector<long> tempNums;

        for (int j = 0; j < nums.size(); j++) {
            long tempNum = nums[j];

            if (tempNum == 0) {
                tempNums.push_back(1);
                continue;   
            }

            int numDigits = 0;
            // a / b = c
            while (tempNum) {
                tempNum /= 10;
                numDigits++;
            }

            if (numDigits % 2 == 0) {
                int divisor = std::pow(10, numDigits / 2);

                long firstHalf = nums[j] / divisor;
                long secondHalf = nums[j] % divisor;

                tempNums.push_back(firstHalf);
                tempNums.push_back(secondHalf);

                continue;
            }

            tempNums.push_back(nums[j] * 2024);
        }

        // for (int x : tempNums) {
        //     std::cout << x << " ";
        // }

        // std::cout << std::endl;

        nums = tempNums;
    }

    std::cout << nums.size() << std::endl;

    return 0;
} 