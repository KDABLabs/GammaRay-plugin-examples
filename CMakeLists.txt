project(gammaray-plugin-examples)

cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(FeatureSummary)

find_package(GammaRay 2.5 REQUIRED NO_MODULE)
set_package_properties(GammaRay PROPERTIES
  TYPE REQUIRED
  URL "http://www.kdab.com/gammaray"
  DESCRIPTION "Qt introspection tool"
  PURPOSE "Needed to build custom GammaRay plug-ins."
)

# more aggressive linker flags (for testing the GammaRay-provided development files for completeness)
if(CMAKE_SYSTEM_NAME MATCHES Linux OR CMAKE_SYSTEM_NAME STREQUAL GNU)
  if(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--fatal-warnings -Wl,--no-undefined -lc ${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS "-Wl,--fatal-warnings -Wl,--no-undefined -lc ${CMAKE_MODULE_LINKER_FLAGS}")
  endif()
endif()

add_subdirectory(lcdwidgetinspector)
add_subdirectory(openglsupport)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
