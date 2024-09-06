# CMakeList.txt : CMake project for MSaad_Library_System, include source and define
# project specific logic here.

cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("MSaad_Library_System")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/app")
# Add source to this project's executable.
add_executable(MSaad_Library_System 
  "app/main.cpp" 
  "app/src/book.cpp" 
  "app/src/user.cpp" 
  "app/src/generalFunctions.cpp"
)

target_include_directories(MSaad_Library_System PRIVATE "app/header" "app/database")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MSaad_Library_System PROPERTY CXX_STANDARD 20)
endif()

# Fetch nlohmann/json library
include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2  # Replace with the version you need
)
FetchContent_MakeAvailable(json)

# Link nlohmann/json library to the project
target_link_libraries(MSaad_Library_System PRIVATE nlohmann_json::nlohmann_json)

# TODO: Add tests and install targets if needed.
