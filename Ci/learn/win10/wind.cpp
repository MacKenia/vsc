
#include <windows.h>
#include <iostream>
 
#define IsKeyDown(VK_NAME) ((GetAsyncKeyState(VK_NAME) & 0x8000) ? true:false)   
 
int main()
{
    POINT point;        // 鼠标所在位置
 
    HWND target;        // 目标窗口句柄
    HWND parent;        // 目标父窗口句柄
    INT width, height;  // 窗口新宽高
 
    // 软件用法
    std::cout << "\n功能：设置目标窗口的大小\n\n";
    std::cout << "用法：输入参数后，将鼠标移到要设置的窗口上，然后按下 Ctrl 键 1 秒钟即可\n";
    std::cout << "      按下 Shift 键可重新输入\n";
    std::cout << "      按下  Alt  键可退出程序\n";
 
    BOOL start = true;  // 是否开始循环
    while(start)
    {
        std::cout << "\n请输入窗口宽度：";
        std::cin >> width;
        std::cout << "请输入窗口高度：";
        std::cin >> height;
        std::cout << "\n移动鼠标，然后按键（Ctrl/Shift/Alt）...\n";
 
        BOOL listen = true;  // 是否开始监听用户按键
        while (listen)
        {
            // Ctrl 键确认窗口
            if IsKeyDown(VK_CONTROL)
            {
                // 获取鼠标位置
                GetCursorPos(&point);
                // 获取鼠标位置的窗口句柄
                target = WindowFromPoint(point);
                // 合法性判断
                if (target != NULL && target != INVALID_HANDLE_VALUE) {
                    // 获取顶层窗口句柄
                    parent = GetParent(target);
                    while (parent != NULL && parent != INVALID_HANDLE_VALUE)
                    {
                        target = parent;
                        parent = GetParent(target);
                    }
                    // 获取窗口原始大小
                    RECT rect;
                    GetWindowRect(target, &rect);
                    // 重新设置窗口大小
                    MoveWindow(target, rect.left, rect.top, width, height, true);
                    // 停止监听
                    listen = false;
                }
            }
            // Shift 键停止监听
            else if (IsKeyDown(VK_SHIFT))
            {
                listen = false;
            }
            // Alt 键退出程序
            else if (IsKeyDown(VK_MENU))
            {
                listen = false;
                start = false;
            }
            Sleep(200);
        }
        std::cout << "\n----------\n";
    }
    return 0;
}