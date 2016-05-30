# probe part of the plug-in
gammaray_add_plugin(gammaray_lcdwidget_inspector JSON lcdwidgetinspector.json SOURCES lcdwidgetinspector.cpp)
target_link_libraries(gammaray_lcdwidget_inspector gammaray_core Qt5::Widgets)

# UI part of the plug-in
set(lcdwidget_inspector_ui_srcs
  lcdwidgetinspectorwidget.cpp
)
qt5_wrap_ui(lcdwidget_inspector_ui_srcs
  lcdwidgetinspectorwidget.ui
)
gammaray_add_plugin(gammaray_lcdwidget_inspector_ui JSON lcdwidgetinspector.json SOURCES ${lcdwidget_inspector_ui_srcs})
target_link_libraries(gammaray_lcdwidget_inspector_ui gammaray_ui)

# test target
add_executable(lcdwidget_test main.cpp)
target_link_libraries(lcdwidget_test Qt5::Widgets)

