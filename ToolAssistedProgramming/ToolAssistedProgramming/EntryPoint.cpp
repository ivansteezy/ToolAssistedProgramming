#include "EntryPoint.hpp"
#include "FileManager.hpp"
#include "DataParser.hpp"
#include "DataWriter.hpp"


int MapCommandToVirtualKey(const KeyboardCommand& keyboardCommand)
{
    switch (keyboardCommand)
    {
    case KeyboardCommand::Up:       return VK_UP;     break;
    case KeyboardCommand::Down:     return VK_DOWN;   break;
    case KeyboardCommand::Left:     return VK_LEFT;   break;
    case KeyboardCommand::Right:    return VK_RIGHT;  break;
    case KeyboardCommand::Home:	    return VK_HOME;   break;
    case KeyboardCommand::End:	    return VK_END;    break;
    case KeyboardCommand::Delete:   return VK_DELETE; break;
    case KeyboardCommand::PageUp:       /*TO DO*/	  break;
    case KeyboardCommand::PageDown:     /*TO DO*/     break;
    }
}

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
    input.ki.wScan = 0;
    input.ki.wVk = MapCommandToVirtualKey(KeyboardCommand::Up);
    SendInput(1, &input, sizeof(INPUT));
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    //Sleep(1000);

    input.ki.dwFlags = 0;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.wVk = MapCommandToVirtualKey(KeyboardCommand::Up);
    SendInput(1, &input, sizeof(INPUT));
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));*/



    Tap::FileManager x(Tap::FileInputType::File, "C:\\Users\\Syro\\Desktop\\ExampleListingFile.cpp");
    auto res = x.GetFileLines();


    Tap::DataParser dp(res);
    auto y = dp.GetCommandPayload();

    std::cout << "Press any key to begin: " << std::endl;
    std::cin.get();

    Tap::DataWriter dw(y);
    dw.BeginChoreography();

    return 0;
}