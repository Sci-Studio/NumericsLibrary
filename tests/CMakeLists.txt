include(AddCatch2)

add_executable(UnitTests test_main.cpp)

target_link_libraries(UnitTests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(UnitTests)