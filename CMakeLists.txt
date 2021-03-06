cmake_minimum_required(VERSION 3.16)
project(clamavui VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set up AUTOMOC and some sensible defaults for runtime execution
# When using Qt 6.3, you can replace the code block below with
# qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
include(GNUInstallDirs)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/forms")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_MIN_VERSION "5.15.0")
set(KF_MIN_VERSION "5.83.0")

find_package(ECM ${KF_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)


include(ECMInstallIcons)
include(ECMQtDeclareLoggingCategory)
include(FeatureSummary)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)
find_package(KF5Auth)
find_package(KF5CoreAddons)
find_package(Qt${QT_VERSION_MAJOR} ${QT_MIN_VERSION} REQUIRED COMPONENTS Concurrent Gui)
find_package(Qt${QT_VERSION_MAJOR} ${QT_MIN_VERSION} OPTIONAL_COMPONENTS Widgets)


find_package(KF5 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    ConfigWidgets
    CoreAddons
    Crash
    DBusAddons
    DocTools
    I18n
    XmlGui
)

add_executable(clamavui MACOSX_BUNDLE
    forms/analysis.ui
    forms/clamui.ui
    forms/history.ui
    forms/network.ui
    forms/quarantine.ui
    forms/scan.ui
    forms/scandirectory.ui
    forms/schedule.ui
    forms/settings.ui
    forms/update.ui
    forms/updateassistant.ui
    forms/whitelist.ui
    include/analysis.h
    include/clamui.h
    include/history.h
    include/network.h
    include/quarantine.h
    include/scan.h
    include/scandirectory.h
    include/schedule.h
    include/settings.h
    include/setup.h
    include/update.h
    include/updateassistant.h
    include/whitelist.h
    src/analysis.cpp
    src/clamui.cpp
    src/history.cpp
    src/main.cpp
    src/network.cpp
    src/quarantine.cpp
    src/scan.cpp
    src/scandirectory.cpp
    src/schedule.cpp
    src/settings.cpp
    src/setup.cpp
    src/update.cpp
    src/updateassistant.cpp
    src/whitelist.cpp
)

target_include_directories(clamavui PRIVATE
    /usr/include
    include
)


target_link_libraries(clamavui PRIVATE
    KF5::Auth
    KF5::AuthCore
    Qt::Concurrent
    Qt::Core
    Qt::Gui
)


if((QT_VERSION_MAJOR GREATER 4))
    target_link_libraries(clamavui PRIVATE
        Qt::Widgets
    )
endif()

if(UNIX AND NOT MACOS)
    target_link_libraries(clamavui PRIVATE
        # Remove: L/usr/lib/
        clamav
        freshclam
    )
endif()


install(TARGETS clamavui
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)



add_executable(antivirus
    include/antivirus.h
    src/antivirus.cpp
)


target_include_directories(antivirus PRIVATE
    /usr/include
    include
)

target_link_libraries(antivirus PRIVATE
    KF5::Auth
    KF5::AuthCore
    KF5::CoreAddons
    Qt::Concurrent
    Qt::Core
    Qt::Gui
)

if((QT_VERSION_MAJOR GREATER 4))
    target_link_libraries(antivirus PRIVATE
        Qt::Widgets
    )
endif()

if(UNIX AND NOT MACOS)
    target_link_libraries(antivirus PRIVATE
        # Remove: L/usr/lib/
        clamav
        freshclam
    )
endif()


install(TARGETS antivirus DESTINATION ${KAUTH_HELPER_INSTALL_DIR})


kauth_install_helper_files(antivirus org.tuchavshortah.clamavui.antivirus root)
kauth_install_actions(org.tuchavshortah.clamavui.antivirus org.tuchavshortah.clamavui.antivirus.actions)
# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.

ki18n_install(po)
kdoctools_install(po)


feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

