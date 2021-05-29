#include "EntryPoint.hpp"
#include "FileManager.hpp"
#include "DataParser.hpp"

int main()
{
    /*std::cout << "Press any key to begin: " << std::endl;
    std::cin.get();

    std::wstring msg = L"ΨΦΩ, ελη, ABC, abc, 123 ←";

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
    
    //Code for emulate a key_up code
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(VK_UP, MAPVK_VK_TO_VSC);
    SendInput(1, &input, sizeof(INPUT));
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    SendInput(1, &input, sizeof(INPUT)); // check for release a key*/



    Tap::FileManager x(Tap::FileInputType::File, "C:\\Users\\Syro\\Desktop\\ExampleListingFile.cpp");
    auto res = x.GetFileLines();

    auto resSize = res.size();

    Tap::DataParser dp(res);
    dp.SortLines();

    return 0;
}