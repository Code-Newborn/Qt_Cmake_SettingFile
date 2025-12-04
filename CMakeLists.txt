cmake_minimum_required(VERSION 3.30)

project(Qt_Cmake_SettingFile LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.14.2\\5.14.2\\mingw73_64")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Core Gui SerialPort PrintSupport REQUIRED)  # 添加 Qt 模块

# find_package(OpenCV ...
# ...

include_directories(${CMAKE_CURRENT_SOURCE_DIR})        # 包含当前处理的 CMakeLists.txt 文件所在的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3D)     # 包含 ./3D 文件夹
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ui)     # 包含 ./ui 文件夹

file(GLOB SOURCES
  ./*.cpp
)
file(GLOB HEADERS_MOC
  ./*.h
)
file(GLOB FORMS_HEADERS
  ./*.ui
)
file(GLOB RESOURCES_RCC
  ./*.qrc
)

add_executable(${PROJECT_NAME}
  ${SOURCES}
  ${HEADERS_MOC}
  ${FORMS_HEADERS}
  ${RESOURCES_RCC}
)

# ✅ 关键：根据配置把 exe 输出到 ./Debug 或 ./Release
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/$<CONFIG>"
)

# 链接 Qt 库
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::SerialPort Qt5::Gui Qt5::PrintSupport)
