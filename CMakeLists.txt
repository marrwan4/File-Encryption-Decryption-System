cmake_minimum_required(VERSION 3.16)

project(FileEncryptionDecryptionSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(file-crypto
    src/Main.cpp
    src/CaesarCipher.cpp
    src/RouteCipher.cpp
    src/FileService.cpp
)

target_include_directories(file-crypto PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Convenience target: build and run the app via CMake
add_custom_target(run
    COMMAND $<TARGET_FILE:file-crypto>
    DEPENDS file-crypto
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    USES_TERMINAL
)

# Optional: run automatically after every successful build
option(AUTO_RUN_AFTER_BUILD "Run file-crypto automatically after building" OFF)
if (AUTO_RUN_AFTER_BUILD)
    add_custom_command(TARGET file-crypto POST_BUILD
        COMMAND $<TARGET_FILE:file-crypto>
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        USES_TERMINAL
        VERBATIM
    )
endif()