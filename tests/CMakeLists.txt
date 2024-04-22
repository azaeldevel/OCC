

add_executable(OCC-test main-v1-AI.cc v1.cc v1.hh v1-AI.cc ../1/occ.cc ../1/A/A.cc ../1/A/I/A.cc ../1/A/intel.cc)
target_link_libraries(OCC-test cunit)

add_test(OCC-test OCC-test)