cmake_minimum_required(VERSION 3.30)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/Demos)
include_directories(src/GUI)

add_executable(Assignment_1
    src/Demos/CanvasGUI.cpp
    src/Demos/GUIConfig.h
    src/Demos/OnlyConnectGUI.cpp
    src/Demos/PlayingFairGUI.cpp
    src/Demos/PlotterGUI.cpp
    src/Demos/SandpileGUI.cpp
    src/Demos/StackOverflowGUI.cpp
    src/GUI/BarrierGUI.cpp
    src/GUI/BarrierGUI.h
    src/GUI/ConsoleMain.cpp
    src/GUI/ConsoleMain.h
    src/GUI/ConsoleUtils.cpp
    src/GUI/ConsoleUtils.h
    src/GUI/Core.cpp
    src/GUI/Core.h
    src/GUI/EmptyProblemHandler.cpp
    src/GUI/EmptyProblemHandler.h
    src/GUI/Font.cpp
    src/GUI/Font.h
    src/GUI/GColorConsole.cpp
    src/GUI/GColorConsole.h
    src/GUI/GUIMain.cpp
    src/GUI/GUIMain.h
    src/GUI/GUIUtils.cpp
    src/GUI/GUIUtils.h
    src/GUI/MemoryDiagnostics.cpp
    src/GUI/MemoryDiagnostics.h
    src/GUI/MiniGUI.h
    src/GUI/ProblemHandler.cpp
    src/GUI/ProblemHandler.h
    src/GUI/SimpleTest.cpp
    src/GUI/SimpleTest.h
    src/GUI/TemporaryComponent.h
    src/GUI/TestDriver.cpp
    src/GUI/TestDriver.h
    src/GUI/TestingGUI.cpp
    src/GUI/TextUtils.cpp
    src/GUI/TextUtils.h
    src/OnlyConnect.cpp
    src/OnlyConnect.h
    src/PlayingFair.cpp
    src/PlayingFair.h
    src/Plotter.cpp
    src/Plotter.h
    src/Sandpiles.cpp
    src/Sandpiles.h
    src/StackOverflow.cpp
    src/StackOverflow.h)
