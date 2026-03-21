set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

qt_add_executable(json-visiualizer
    mainwindow.ui
    mainwindow.cpp
    main.cpp
)
target_link_libraries(json-visiualizer PRIVATE Qt6::Widgets)

set_target_properties(json-visiualizer PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
