cmake_minimum_required(VERSION 3.16)
project(Prophet2026 LANGUAGES C CXX)

# Par defaut: version "Release" (rapide, sans les alertes de developpement de wxWidgets)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------------------------
# Bibliotheques: wxWidgets (interface), RtMidi (MIDI), PortAudio (son),
# libsamplerate (changement de frequence).
#  - PROPHET_BUNDLED_LIBS=ON  : on les telecharge et on les compile en statique
#                               -> un seul .exe autonome (par defaut sous Windows)
#  - PROPHET_BUNDLED_LIBS=OFF : on utilise celles installees sur le systeme (Linux)
# ---------------------------------------------------------------------------
if(WIN32)
  option(PROPHET_BUNDLED_LIBS "Telecharger et compiler les bibliotheques" ON)
else()
  option(PROPHET_BUNDLED_LIBS "Telecharger et compiler les bibliotheques" OFF)
endif()

if(PROPHET_BUNDLED_LIBS)
  include(FetchContent)
  set(FETCHCONTENT_QUIET OFF)

  # Runtime Visual C++ lie statiquement: pas besoin d'installer de redistribuable
  if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set(wxBUILD_USE_STATIC_RUNTIME ON CACHE BOOL "" FORCE)
  endif()
  set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

  # wxWidgets 3.2 (seulement les modules utiles, en statique)
  set(wxBUILD_SHARED OFF CACHE BOOL "" FORCE)
  set(wxBUILD_SAMPLES OFF CACHE STRING "" FORCE)
  set(wxBUILD_TESTS OFF CACHE STRING "" FORCE)
  set(wxBUILD_DEMOS OFF CACHE BOOL "" FORCE)
  set(wxBUILD_BENCHMARKS OFF CACHE BOOL "" FORCE)
  foreach(opt wxUSE_XRC wxUSE_XML wxUSE_HTML wxUSE_WEBVIEW wxUSE_OPENGL wxUSE_MEDIACTRL
              wxUSE_RICHTEXT wxUSE_STC wxUSE_AUI wxUSE_PROPGRID wxUSE_RIBBON wxUSE_DEBUGREPORT
              wxUSE_GLCANVAS wxUSE_WEBVIEW_EDGE)
    set(${opt} OFF CACHE BOOL "" FORCE)
  endforeach()
  FetchContent_Declare(wxWidgets
    URL https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.6/wxWidgets-3.2.6.tar.bz2
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

  # RtMidi 6 (un seul fichier source: on le compile nous-memes)
  FetchContent_Declare(rtmidi
    GIT_REPOSITORY https://github.com/thestk/rtmidi.git GIT_TAG 6.0.0 GIT_SHALLOW TRUE
    SOURCE_SUBDIR do-not-use-its-cmake)

  # PortAudio 19.7
  set(PA_BUILD_SHARED OFF CACHE BOOL "" FORCE)
  set(PA_BUILD_STATIC ON CACHE BOOL "" FORCE)
  set(PA_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(PA_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(portaudio
    GIT_REPOSITORY https://github.com/PortAudio/portaudio.git GIT_TAG v19.7.0 GIT_SHALLOW TRUE)

  # libsamplerate 0.2.2
  set(LIBSAMPLERATE_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(LIBSAMPLERATE_INSTALL OFF CACHE BOOL "" FORCE)
  set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(samplerate
    GIT_REPOSITORY https://github.com/libsndfile/libsamplerate.git GIT_TAG 0.2.2 GIT_SHALLOW TRUE)

  FetchContent_MakeAvailable(wxWidgets rtmidi portaudio samplerate)

  add_library(rtmidi STATIC ${rtmidi_SOURCE_DIR}/RtMidi.cpp)
  target_include_directories(rtmidi PUBLIC ${rtmidi_SOURCE_DIR})
  if(WIN32)
    target_compile_definitions(rtmidi PUBLIC __WINDOWS_MM__)
    target_link_libraries(rtmidi PUBLIC winmm)
  else()
    target_compile_definitions(rtmidi PUBLIC __LINUX_ALSA__)
    target_link_libraries(rtmidi PUBLIC asound pthread)
  endif()

  set(PROPHET_LIBS wx::core wx::base wx::adv rtmidi portaudio_static samplerate)
else()
  find_package(wxWidgets 3.0 REQUIRED COMPONENTS core base adv)
  include(${wxWidgets_USE_FILE})
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(RTMIDI     REQUIRED IMPORTED_TARGET rtmidi)
  pkg_check_modules(PORTAUDIO  REQUIRED IMPORTED_TARGET portaudio-2.0)
  pkg_check_modules(SAMPLERATE REQUIRED IMPORTED_TARGET samplerate)
  set(PROPHET_LIBS ${wxWidgets_LIBRARIES}
      PkgConfig::RTMIDI PkgConfig::PORTAUDIO PkgConfig::SAMPLERATE)
endif()

# ---------------------------------------------------------------------------
# Le programme
# ---------------------------------------------------------------------------
file(GLOB PROPHET_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/SRCDIR/*.cpp)
if(WIN32)
  list(APPEND PROPHET_SOURCES ${CMAKE_SOURCE_DIR}/resources/prophet.rc)
endif()

add_executable(Prophet2026 WIN32 ${PROPHET_SOURCES})
target_include_directories(Prophet2026 PRIVATE ${CMAKE_SOURCE_DIR}/SRCDIR)
target_link_libraries(Prophet2026 PRIVATE ${PROPHET_LIBS})

# Anciennes sources ecrites pour un compilateur plus permissif: on masque les avertissements
if(MSVC)
  target_compile_options(Prophet2026 PRIVATE /W0 /permissive /utf-8 /MP)
  target_compile_definitions(Prophet2026 PRIVATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_WARNINGS)
else()
  target_compile_options(Prophet2026 PRIVATE -fpermissive -w)
endif()
