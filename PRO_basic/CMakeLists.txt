cmake_minimum_required(VERSION 3.16)

project(logging_utils)

set(CMAKE_PREFIX_PATH "D:/Qt/Qt5.12.12/5.12.12/mingw73_64/lib/cmake/Qt5")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# qt_standard_project_setup()

add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.ui
    mainwindow.cpp
    mainwindow.h
    serialworker.cpp
    serialworker.h
    UART_tools.h
    CRC.cpp
    CRC.h
)

# qt_use_modules(${PROJECT_NAME} Widgets Core)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)

# set_target_properties(logging_utils PROPERTIES
#     WIN32_EXECUTABLE ON
#     MACOSX_BUNDLE ON
# )


# при таком CMakeLists.txt
СБОРКА ПРОХОДИТ БЕЗ ОШИБОК:
PS D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE> cmake -B build1
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.20348.0 to target Windows 10.0.19045.
-- The C compiler identification is MSVC 19.38.33030.0
-- The CXX compiler identification is MSVC 19.38.33030.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio/2022/Preview/VC/Tools/MSVC/14.38.33030/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2022/Preview/VC/Tools/MSVC/14.38.33030/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (4.2s)
-- Generating done (0.0s)
-- Build files have been written to: D:/YandexDisk/CPP/Tutorials/Project_Otus_Basic/20240402_logging_UART_CMAKE/build1
 
НО КОМПИЛЯЦИЯ НЕТ:
PS D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE> cmake --build build1
Версия MSBuild 17.8.0-preview-23431-02+3c910ba83 для .NET Framework

  1>Checking Build System
  Automatic MOC for target logging_utils
  Building Custom Rule D:/YandexDisk/CPP/Tutorials/Project_Otus_Basic/20240402_logging_UART_CMAKE/CMakeLists.txt
  mocs_compilation_Debug.cpp
D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE\build1\logging_utils_autogen\include_Debug\EWIEGA46WW\../../../../mainw
indow.h(5,10): fatal  error C1083: Не удается открыть файл включение: QSerialPort: No such file or directory, [D:\YandexDisk\CPP\Tutorials\Project
_Otus_Basic\20240402_logging_UART_CMAKE\build1\logging_utils.vcxproj]
  main.cpp
D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE\mainwindow.h(5,10): fatal  error C1083: Не удается открыть файл включен
ие: QSerialPort: No such file or directory, [D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE\build1\logging_utils.vcxpr
oj]
  mainwindow.cpp
D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE\mainwindow.h(5,10): fatal  error C1083: Не удается открыть файл включен
ие: QSerialPort: No such file or directory, [D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE\build1\logging_utils.vcxpr
oj]
  serialworker.cpp
D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE\serialworker.h(5,10): fatal  error C1083: Не удается открыть файл включ
ение: QSerialPort: No such file or directory, [D:\YandexDisk\CPP\Tutorials\Project_Otus_Basic\20240402_logging_UART_CMAKE\build1\logging_utils.vcx
proj]
  CRC.cpp
  Создание кода...

