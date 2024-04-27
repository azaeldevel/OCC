
add_executable(generator occ-generetor-main.cc occ.cc Generator.cc A/I/Parser/Generator-AI.cc A/I/Parser/declarartion.cc A/I/Parser/functions.cc A/I/Parser/rules.cc A/I/Parser/rules-instructions.cc A/I/Lexer/Generator-AI.cc A/I/Lexer/declarartion.cc A/I/Lexer/functions.cc A/I/Lexer/rules.cc)
add_custom_target(generator-v1 COMMAND make -f $(CMAKE_SOURCE_DIR)/1/OCC-cmake.mk TARGET_OUTPUT_DIR=$(CMAKE_BINARY_DIR)/1/ all DEPENDS generator COMMENT "Gennerando los archivos de bison y flex")

add_library(${PROJECT_NAME}-AI-1 SHARED A/A.cc A/I/A.cc A/I/Driver.cc A/intel.cc Buffer.cc occ.cc )