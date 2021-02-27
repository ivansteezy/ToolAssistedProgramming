#include "EntryPoint.h"

int main()
{
    std::cout << "Press any key to begin: " << std::endl;
    std::cin.get();

    std::wstring msg = L"ΨΦΩ, ελη, ABC, abc, 123";

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    for (auto ch : msg)
    {
        INPUT input = { 0 };
        input.type = INPUT_KEYBOARD;
        input.ki.dwFlags = KEYEVENTF_UNICODE;
        input.ki.wScan = ch;

        SendInput(1, &input, sizeof(INPUT));
        input.ki.dwFlags |= KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return 0;
}