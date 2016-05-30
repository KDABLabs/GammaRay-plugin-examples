find_package(Qt5OpenGL QUIET)

if(Qt5OpenGL_FOUND)
    # probe plugin
    gammaray_add_plugin(gammaray_qtopenglsupport JSON qtopenglsupport.json SOURCES qtopenglsupport.cpp)
    target_link_libraries(gammaray_qtopenglsupport gammaray_core Qt5::OpenGL)

    # test target
    add_executable(openglwidget_test main.cpp)
    target_link_libraries(openglwidget_test Qt5::OpenGL)
endif()
