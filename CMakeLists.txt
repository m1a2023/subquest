cmake_minimum_required(VERSION 4.0)
project(simpletodo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Gui
        Widgets
        Core
        REQUIRED)

qt_add_executable(${PROJECT_NAME} src/main.cpp
        src/widgets/mainwindow.cpp
        src/widgets/mainwindow.h
        src/widgets/todolistwidget.cpp
        src/widgets/todolistwidget.h
        src/models/TodoModel.cpp
        src/models/TodoModel.h
        src/items/TodoItem.cpp
        src/items/TodoItem.h
)

qt_add_resources(RESOURCES resources.qrc)

set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE    TRUE
        MACOSX_BUNDLE       TRUE
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Gui Qt6::Widgets Qt6::Core
)

target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES})

install(TARGETS ${PROJECT_NAME}
        BUNDLE  DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
        TARGET  ${PROJECT_NAME}
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

