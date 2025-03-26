include(AddCatch2)

add_executable(UnitTests test_main.cpp ../delaunay/delaunay.cpp)

target_link_libraries(UnitTests PRIVATE Catch2::Catch2WithMain)

target_include_directories(UnitTests PRIVATE
    ../delaunay
    ../eigen-3.4.0
)

include(CTest)
include(Catch)
catch_discover_tests(UnitTests)